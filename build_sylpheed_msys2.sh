#!/bin/bash -e

SOURCE_DIR="$(cd "$(dirname "${0}")" && pwd)"
#SOURCE_DIR="$(cygpath -u "${USERPROFILE}/Desktop/sylpheed-windows")"

MSYSTEM_PKG_PREFIX="mingw-w64"
VCVARS_ARCH=""
CRT_ARCH=""
UCRT_ARCH=""
NSIS_ARCH=""
if [ "${MSYSTEM}" == "UCRT64" ] ; then
    MSYSTEM_PKG_PREFIX="${MSYSTEM_PKG_PREFIX}-ucrt-x86_64"
    VCVARS_ARCH="x64"
    CRT_ARCH="x64"
    UCRT_ARCH="x64"
    NSIS_ARCH="x64"
elif [ "${MSYSTEM}" == "MINGW32" ] ; then
    MSYSTEM_PKG_PREFIX="${MSYSTEM_PKG_PREFIX}-i686"
    VCVARS_ARCH="x64_x86"
    CRT_ARCH="x86"
    UCRT_ARCH="x86"
    NSIS_ARCH="x86"
elif [ "${MSYSTEM}" == "MINGW64" ] ; then
    MSYSTEM_PKG_PREFIX="${MSYSTEM_PKG_PREFIX}-x86_64"
    VCVARS_ARCH="x64"
    CRT_ARCH="x64"
    UCRT_ARCH="x64"
    NSIS_ARCH="x64"
elif [ "${MSYSTEM}" == "CLANG32" ] ; then
    MSYSTEM_PKG_PREFIX="${MSYSTEM_PKG_PREFIX}-clang-i686"
    VCVARS_ARCH="x64_x86"
    CRT_ARCH="x86"
    UCRT_ARCH="x86"
    NSIS_ARCH="x86"
elif [ "${MSYSTEM}" == "CLANG64" ] ; then
    MSYSTEM_PKG_PREFIX="${MSYSTEM_PKG_PREFIX}-clang-x86_64"
    VCVARS_ARCH="x64"
    CRT_ARCH="x64"
    UCRT_ARCH="x64"
    NSIS_ARCH="x64"
# elif [ "${MSYSTEM}" == "CLANGARM64" ] ; then
#     MSYSTEM_PKG_PREFIX="${MSYSTEM_PKG_PREFIX}-clang-aarch64"
#     VCVARS_ARCH="x64_arm64"
#     CRT_ARCH="arm64"
#     UCRT_ARCH="arm"
#     NSIS_ARCH=""
else
    echo "Unknown or broken MSYSTEM: ${MSYSTEM}"
    exit 1
fi
pacman -S --needed --noconfirm \
    base-devel \
    autoconf-wrapper \
    automake-wrapper \
    m4 \
    libtool \
    libgpgme-devel \
    zip \
    unzip \
    ${MSYSTEM_PKG_PREFIX}-toolchain \
    ${MSYSTEM_PKG_PREFIX}-gtk2 \
    ${MSYSTEM_PKG_PREFIX}-curl-winssl \
    ${MSYSTEM_PKG_PREFIX}-openssl \
    ${MSYSTEM_PKG_PREFIX}-gtkspell \
    ${MSYSTEM_PKG_PREFIX}-enchant \
    ${MSYSTEM_PKG_PREFIX}-oniguruma \
    ${MSYSTEM_PKG_PREFIX}-libiconv \
    ${MSYSTEM_PKG_PREFIX}-ca-certificates \
    ${MSYSTEM_PKG_PREFIX}-gpgme

function autogenSylpheed {
    local ACLOCAL=aclocal-1.15
    local AUTOMAKE=automake-1.15
    ${ACLOCAL} -I ac \
        && libtoolize --force --copy \
        && autoheader \
        && ${AUTOMAKE} --add-missing --foreign --copy \
        && autoconf
}

DIST_PREFIX="${PWD}/sylpheed-3.8.0beta1-${MSYSTEM,,?}"
export LD_LIBRARY_PATH="${DIST_PREFIX}/lib"
export PKG_CONFIG_PATH="${DIST_PREFIX}/lib/pkgconfig"

BUILD_DIR="${PWD}/build_${MSYSTEM}"
rm -rf "${DIST_PREFIX}"
rm -rf "${BUILD_DIR}"
mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

curl -LO http://ftp.xemacs.org/pub/xemacs/aux/compface-1.5.2.tar.gz
tar -xvpf compface-1.5.2.tar.gz
cd compface-1.5.2
find "${SOURCE_DIR}/patches/compface-1.5.2" -name '*.patch' | sort | while IFS= read -r item ; do patch -p1 --binary -i "${item}" ; done
./configure --prefix="${DIST_PREFIX}"
make -j4
make install
cd ..

# @note --tls-max 1.2: https://github.com/curl/curl/issues/9431
curl --tls-max 1.2 -LO "https://github.com/AlienCowEatCake/WinToastLibC/releases/download/v0.2/wintoastlibc_${VCVARS_ARCH##*_}.zip"
unzip "wintoastlibc_${VCVARS_ARCH##*_}.zip"
cd "$(echo "wintoastlibc_${VCVARS_ARCH##*_}.zip" | sed 's|\.zip$||')"
cp -a *.h "${DIST_PREFIX}/include/"
cp -a *.dll "${DIST_PREFIX}/bin/"
gendef "wintoastlibc.dll"
dlltool.exe -d "wintoastlibc.def" -D "wintoastlibc.dll" -l "${DIST_PREFIX}/lib/libwintoastlibc.dll.a"
cd ..

curl -LO https://sylpheed.sraoss.jp/sylpheed/v3.8beta/sylpheed-3.8.0beta1.tar.bz2
tar -xvpf sylpheed-3.8.0beta1.tar.bz2
cd sylpheed-3.8.0beta1
find "${SOURCE_DIR}/patches_sylpheed" -name '*.patch' | sort | while IFS= read -r item ; do patch -p1 --binary -i "${item}" ; done
autogenSylpheed
./configure --prefix="${DIST_PREFIX}" \
    --with-localedir=share/locale \
    --with-themedir=share/icons \
    --enable-oniguruma --enable-threads \
    --enable-gpgme --disable-jpilot \
    --disable-ldap --enable-ssl \
    --enable-compface --enable-gtkspell \
    --enable-libcurl --enable-ipv6 \
    --enable-shared --disable-static \
    CFLAGS=-O3 \
    CPPFLAGS="-I${DIST_PREFIX}/include" \
    LDFLAGS="-L${DIST_PREFIX}/lib"
echo -e '\n#include <openssl/applink.c>\n' >> "src/main.c"
echo -e '\n#include <openssl/applink.c>\n' >> "src/syl-auth-helper.c"
make -j4
make install-strip
(cd plugin/attachment_tool; make install-plugin)
strip "${DIST_PREFIX}/lib/sylpheed/plugins/attachment_tool.dll"
cd ..

curl -LO http://fallabs.com/qdbm/qdbm-1.8.78.tar.gz
tar -xvpf qdbm-1.8.78.tar.gz
cd qdbm-1.8.78
./configure --prefix="${DIST_PREFIX}" --enable-stable --enable-pthread --enable-zlib --enable-iconv
make -j4 libqdbm.a
make install-strip || mkdir -p "${DIST_PREFIX}/lib/pkgconfig" && cat << EOF > "${DIST_PREFIX}/lib/pkgconfig/qdbm.pc"
Name: QDBM
Description: a high performance embedded database library
Version: 1.8.78
Libs: -L${DIST_PREFIX}/lib -lqdbm -lz -lpthread -liconv
Cflags: -I${DIST_PREFIX}/include
EOF
cd ..

curl -LO http://sylpheed.sraoss.jp/sylfilter/src/sylfilter-0.8.tar.gz
tar -xvpf sylfilter-0.8.tar.gz
cd sylfilter-0.8
# find "${SOURCE_DIR}/patches_sylfilter" -name '*.patch' | sort | while IFS= read -r item ; do patch -p1 --binary -i "${item}" ; done
./configure --prefix="${DIST_PREFIX}" --enable-shared --disable-static --disable-sqlite --enable-qdbm --disable-gdbm --with-libsylph=sylpheed \
    CFLAGS=-O3 \
    CPPFLAGS="-I${DIST_PREFIX}/include -I${DIST_PREFIX}/include/sylpheed" \
    LDFLAGS="-L${DIST_PREFIX}/lib"
make -j4
make install-strip
cd ..

g++ -O3 -std=c++14 -shared -fPIC -o "${DIST_PREFIX}/bin/libenchant-2.dll" -Wall \
    -Wl,--export-all-symbols -Wl,--enable-auto-import \
    -Wl,--whole-archive "${SOURCE_DIR}/enchant/enchant.cpp" -Wl,--no-whole-archive \
    -DNDEBUG -lole32 -s

curl -Lo libwab-master.tar.gz https://github.com/pboettch/libwab/archive/refs/heads/master.tar.gz
tar -xvpf libwab-master.tar.gz
cd libwab-master
gcc cencode.c libwab.c pstwabids.c tools.c uerr.c wabread.c \
    $(pkg-config --cflags iconv) $(pkg-config --libs iconv) \
    -O3 -DHAVE_ICONV -DNDEBUG -o "${DIST_PREFIX}/bin/wabread.exe" -s
cd ..

curl -LO https://sylpheed.sraoss.jp/sylpheed/others/bsfilter-1.0.17.rc4.tgz
tar -xvpf bsfilter-1.0.17.rc4.tgz
cd bsfilter-1.0.17.rc4
cp -a bsfilter/bsfilter bsfilter/bsfilterw.exe "${DIST_PREFIX}/bin/"
cp -a htdocs "${DIST_PREFIX}/share/sylpheed/bsfilter"
cd ..

rm -rf "${DIST_PREFIX}/bin/compface.exe" "${DIST_PREFIX}/bin/uncompface.exe"
mv "${DIST_PREFIX}/bin/"* "${DIST_PREFIX}/"
cp -a "${DIST_PREFIX}/sylfilter.exe" "${DIST_PREFIX}/sylfilter-cui.exe"
mv "${DIST_PREFIX}/lib/sylpheed/plugins" "${DIST_PREFIX}/"
mv "${DIST_PREFIX}/share/sylpheed" "${DIST_PREFIX}/doc"
rm -rf "${DIST_PREFIX}/bin" "${DIST_PREFIX}/include" "${DIST_PREFIX}/lib/"* "${DIST_PREFIX}/man" "${DIST_PREFIX}/share/applications" "${DIST_PREFIX}/share/pixmaps"

mkdir -p "${DIST_PREFIX}/etc/ssl/certs"
cp -a "${MSYSTEM_PREFIX}/ssl/certs/ca-bundle.crt" "${DIST_PREFIX}/etc/ssl/certs/certs.crt"
cp -a "${MSYSTEM_PREFIX}/etc/gtk-2.0" "${DIST_PREFIX}/etc/"
echo 'gtk-theme-name = "MS-Windows"' > "${DIST_PREFIX}/etc/gtk-2.0/gtkrc"

cp -a "${MSYSTEM_PREFIX}/lib/gdk-pixbuf-2.0" "${DIST_PREFIX}/lib/"
cp -a "${MSYSTEM_PREFIX}/lib/gtk-2.0" "${DIST_PREFIX}/lib/"
cp -a "${MSYSTEM_PREFIX}/lib/engines-1_1" "${DIST_PREFIX}/lib/"
find "${DIST_PREFIX}" \( -name '*.a' -o -name '*.la' \) -delete
find "${DIST_PREFIX}" -name 'include' | sort | while IFS= read -r item ; do rm -rf "${item}" ; done

cp -a "${MSYSTEM_PREFIX}/bin/curl.exe" "${DIST_PREFIX}/"
cp -a "${MSYSTEM_PREFIX}/bin/gpgme-w32spawn.exe" "${DIST_PREFIX}/"
find "${MSYSTEM_PREFIX}/bin" \( -name "gspawn*helper.exe" -o -name "gspawn*helper-console.exe" \) -exec cp -a \{\} "${DIST_PREFIX}/" \;
cp -a "${MSYSTEM_PREFIX}/share/themes" "${DIST_PREFIX}/share/"

function getDeps() {
    find "${DIST_PREFIX}" \( -name '*.exe' -o -name '*.dll' \) -not -name 'bsfilterw.exe' -exec objdump --private-headers \{\} \; | grep 'DLL Name:' | sort | uniq | sed 's|.* ||'
}

function checkDll() {
    find "${DIST_PREFIX}" -name "${1}" | grep -E '*' >/dev/null 2>/dev/null
}

function copyDlls() {
    local CHANGED
    local RESOLVED
    while true ; do
        CHANGED=false
        for i in $(getDeps) ; do
            RESOLVED=false
            if checkDll "${i}" ; then
                continue
            fi
            for j in "${@}" ; do
                if find "${j}" -maxdepth 1 -name "${i}" -print -exec cp -a \{\} "${DIST_PREFIX}/" \; | grep -E '*' ; then
                    CHANGED=true
                    RESOLVED=true
                    break
                fi
            done
            if ! ${RESOLVED} ; then
                echo "Unresolved: ${i}"
            fi
        done
        if ! ${CHANGED} ; then
            break
        fi
    done
}

function fixupExes() {
    pushd "${DIST_PREFIX}" > /dev/null
    cat << EOF | cmd
set VCVARS="C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat"
call %VCVARS% ${VCVARS_ARCH}
$(find . -maxdepth 1 \( -name 'curl.exe' -o -name 'sylfilter.exe' \) | sed 's|^\./|editbin /subsystem:windows |')
EOF
    popd > /dev/null
}

function getCRTPath() {
    cat << EOF | cmd | tail -3 | head -1
set VCVARS="C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat"
call %VCVARS% ${VCVARS_ARCH}
echo %VCToolsRedistDir%${CRT_ARCH}\Microsoft.VC143.CRT
EOF
}

function getUCRTPath() {
    cat << EOF | cmd | tail -3 | head -1
set VCVARS="C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat"
call %VCVARS% ${VCVARS_ARCH}
echo %UniversalCRTSdkDir%Redist\%UCRTVersion%\ucrt\DLLs\\${UCRT_ARCH}
EOF
}

function stripAll() {
    find "${DIST_PREFIX}" \( -name '*.exe' -o -name '*.dll' \) -not -name 'bsfilterw.exe' | while IFS= read -r item ; do
        strip --strip-all "${item}" || strip "${item}" || true
    done
}

copyDlls "${MSYSTEM_PREFIX}/bin"
fixupExes
stripAll
copyDlls "$(cygpath -u "$(getCRTPath)")" "$(cygpath -u "$(getUCRTPath)")"

cp -a "${SOURCE_DIR}/misc/mime.types" "${DIST_PREFIX}/etc/"
cp -a "${SOURCE_DIR}/misc/README-win32-es.txt" "${DIST_PREFIX}/"
cp -a "${SOURCE_DIR}/misc/README-win32-ja.txt" "${DIST_PREFIX}/"
cp -a "${SOURCE_DIR}/misc/README-win32.txt" "${DIST_PREFIX}/"
cp -a "${SOURCE_DIR}/misc/sample-sylpheed.ini" "${DIST_PREFIX}/"
base64 -d "${SOURCE_DIR}/misc/oauth2.ini.b64" > "${DIST_PREFIX}/oauth2.ini"
find "${DIST_PREFIX}/share/locale" -mindepth 1 -maxdepth 1 -type d | while IFS= read -r item ; do
    loc="${item##*/}"
    cp -a "${MSYSTEM_PREFIX}/share/locale/${loc}/LC_MESSAGES/gtk20.mo" "${DIST_PREFIX}/share/locale/${loc}/LC_MESSAGES/" || true
done
cd sylpheed-3.8.0beta1
cp -a "sylpheed.png" "sylpheed-64x64.png" "sylpheed-128x128.png" "${DIST_PREFIX}/"
cp -a "sylpheed-mailto-protocol_admin.reg" "sylpheed-mailto-protocol_user.reg" "${DIST_PREFIX}/"
mkdir -p "${DIST_PREFIX}/doc/plugins"
cp -a "plugin/attachment_tool/README" "${DIST_PREFIX}/doc/plugins/README.attachment_tool.txt"
for i in AUTHORS ChangeLog ChangeLog.ja COPYING COPYING.LIB INSTALL INSTALL.ja LICENSE NEWS NEWS-2.0 PLUGIN.ja.txt PLUGIN.txt README README.es README.ja TODO TODO.ja ; do
    cp -a "${i}" "${DIST_PREFIX}/doc/${i}"
    unix2dos "${DIST_PREFIX}/doc/${i}"
done
cd ..
cd sylfilter-0.8
mkdir -p "${DIST_PREFIX}/doc/sylfilter"
for i in NEWS README COPYING ; do
    cp -a "${i}" "${DIST_PREFIX}/doc/sylfilter/${i}.txt"
    unix2dos "${DIST_PREFIX}/doc/sylfilter/${i}.txt"
done
cd ..

export PATH="${SOURCE_DIR}/nsis:${PATH}"
cd sylpheed-3.8.0beta1/nsis
makensis plugin-updater.nsi
mv plugin-updater.exe "${DIST_PREFIX}/"
makensis update-manager.nsi
mv update-manager.exe "${DIST_PREFIX}/"
cp -a "${DIST_PREFIX}" Sylpheed
mkdir -p plugins/doc
mv Sylpheed/plugins plugins/
mv Sylpheed/doc/plugins plugins/doc/
mkdir -p sylfilter/doc
mv Sylpheed/sylfilter.exe Sylpheed/sylfilter-cui.exe sylfilter/
mv Sylpheed/doc/sylfilter sylfilter/doc/
mkdir -p bsfilter/doc
mv Sylpheed/bsfilter Sylpheed/bsfilterw.exe bsfilter/
mv Sylpheed/doc/bsfilter bsfilter/doc/
find Sylpheed -mindepth 1 -maxdepth 1 -type f | sed 's|.*/\(.*\)$|  Delete "$INSTDIR\\\1"|' > sylpheed-un_sylpheed.nsh
MSYS2_ARG_CONV_EXCL="*" makensis /DARCH_${NSIS_ARCH} sylpheed.nsi
find . -mindepth 1 -maxdepth 1 -type f -name 'Sylpheed*_setup.exe' | while IFS= read -r item ; do
    name="${item##*/}"
    mv "${name}" "${DIST_PREFIX}/../$(echo "${name}" | sed "s|\(.*\)\(\.exe\)|\1_${MSYSTEM,,?}\2|")"
done
cd ../..

pushd "${DIST_PREFIX}" > /dev/null
cd ..
zip -9r "${DIST_PREFIX##*/}.zip" "${DIST_PREFIX##*/}"
popd > /dev/null

cd "${SOURCE_DIR}"
rm -rf "${BUILD_DIR}" "${DIST_PREFIX}"
