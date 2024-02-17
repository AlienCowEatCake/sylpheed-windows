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
elif [ "${MSYSTEM}" == "CLANGARM64" ] ; then
    MSYSTEM_PKG_PREFIX="${MSYSTEM_PKG_PREFIX}-clang-aarch64"
    VCVARS_ARCH="arm64"
    CRT_ARCH="arm64"
    UCRT_ARCH="arm64"
    NSIS_ARCH="x64"
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
    intltool \
    ${MSYSTEM_PKG_PREFIX}-toolchain \
    ${MSYSTEM_PKG_PREFIX}-gtk2 \
    ${MSYSTEM_PKG_PREFIX}-curl-winssl \
    ${MSYSTEM_PKG_PREFIX}-openssl \
    ${MSYSTEM_PKG_PREFIX}-oniguruma \
    ${MSYSTEM_PKG_PREFIX}-libiconv \
    ${MSYSTEM_PKG_PREFIX}-ca-certificates \
    ${MSYSTEM_PKG_PREFIX}-gpgme \
    ${MSYSTEM_PKG_PREFIX}-sqlite3 \
    ${MSYSTEM_PKG_PREFIX}-meson

function autogenSylpheed {
    local ACLOCAL=aclocal-1.15
    local AUTOMAKE=automake-1.15
    ${ACLOCAL} -I ac \
        && libtoolize --force --copy \
        && autoheader \
        && ${AUTOMAKE} --add-missing --foreign --copy \
        && autoconf \
        && ./configure "${@}"
}

DIST_PREFIX="${PWD}/sylpheed-3.8.0beta1-${MSYSTEM,,?}"
rm -rf "${DIST_PREFIX}"
mkdir -p "${DIST_PREFIX}/lib/pkgconfig" "${DIST_PREFIX}/include" "${DIST_PREFIX}/bin"
export PATH="${DIST_PREFIX}/bin:${PATH}:"
export LD_LIBRARY_PATH="${DIST_PREFIX}/lib:${LD_LIBRARY_PATH}:"
export PKG_CONFIG_PATH="${DIST_PREFIX}/lib/pkgconfig:${PKG_CONFIG_PATH}:"

BUILD_DIR="${PWD}/build_${MSYSTEM}"
rm -rf "${BUILD_DIR}"
mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

g++ -O3 -std=c++14 -shared -fPIC -o "${DIST_PREFIX}/bin/libenchant-2.dll" -Wall \
    -Wl,--out-implib="${DIST_PREFIX}/lib/libenchant-2.dll.a" \
    -Wl,--export-all-symbols -Wl,--enable-auto-import \
    -Wl,--whole-archive "${SOURCE_DIR}/enchant/enchant.cpp" -Wl,--no-whole-archive \
    -DNDEBUG -lole32 -s
mkdir -p "${DIST_PREFIX}/include/enchant-2"
cp -a "${SOURCE_DIR}/enchant/enchant.h" "${DIST_PREFIX}/include/enchant-2/"
cat << EOF > "${DIST_PREFIX}/lib/pkgconfig/enchant-2.pc"
prefix=${DIST_PREFIX}
exec_prefix=\${prefix}
libdir=\${exec_prefix}/lib
includedir=\${prefix}/include

Name: libenchant
Description: A spell checking library
Version: 2.6.7
Libs: -L\${libdir} -lenchant-2
Cflags: -I\${includedir}/enchant-2
EOF

curl -LO https://gtkspell.sourceforge.io/download/gtkspell-2.0.16.tar.gz
tar -xvpf gtkspell-2.0.16.tar.gz
cd gtkspell-2.0.16
find "${SOURCE_DIR}/patches/gtkspell-2.0.16" \( -name '*.patch' -o -name '*.diff' \) | sort | while IFS= read -r item ; do patch -p1 --binary -i "${item}" ; done
./configure --prefix="${DIST_PREFIX}" --enable-shared --disable-static
make -j$(getconf _NPROCESSORS_ONLN)
make install
rm -rf "${DIST_PREFIX}/share/gtk-doc"
if [ -f "${DIST_PREFIX}/lib/libgtkspell.a" ] ; then
    mkdir temp
    cd temp
    ar x "${DIST_PREFIX}/lib/libgtkspell.a"
    gcc -shared -o "${DIST_PREFIX}/bin/libgtkspell-0.dll" \
        -Wl,--out-implib="${DIST_PREFIX}/lib/libgtkspell.dll.a" \
        -Wl,--export-all-symbols -Wl,--enable-auto-import \
        -Wl,--whole-archive *.o -Wl,--no-whole-archive \
        $(pkgconf --libs gtk+-2.0) $(pkgconf --libs enchant-2)
    rm -rf "${DIST_PREFIX}/lib/libgtkspell.a" "${DIST_PREFIX}/lib/libgtkspell.la"
    cd ..
fi
cd ..

curl -LO http://ftp.xemacs.org/pub/xemacs/aux/compface-1.5.2.tar.gz
tar -xvpf compface-1.5.2.tar.gz
cd compface-1.5.2
find "${SOURCE_DIR}/patches/compface-1.5.2" -name '*.patch' | sort | while IFS= read -r item ; do patch -p1 --binary -i "${item}" ; done
./configure --prefix="${DIST_PREFIX}"
make -j$(getconf _NPROCESSORS_ONLN)
make install
cd ..

# @note --tls-max 1.2: https://github.com/curl/curl/issues/9431
curl --tls-max 1.2 -LO "https://github.com/AlienCowEatCake/WinToastLibC/releases/download/v0.3/wintoastlibc_${VCVARS_ARCH##*_}.zip"
unzip "wintoastlibc_${VCVARS_ARCH##*_}.zip"
cd "$(echo "wintoastlibc_${VCVARS_ARCH##*_}.zip" | sed 's|\.zip$||')"
cp -a *.h "${DIST_PREFIX}/include/"
cp -a *.dll "${DIST_PREFIX}/bin/"
gendef "wintoastlibc.dll"
dlltool.exe -d "wintoastlibc.def" -D "wintoastlibc.dll" -l "${DIST_PREFIX}/lib/libwintoastlibc.dll.a"
cd ..

USE_OPENSSL_APPLINK="true"
echo -e '#include <openssl/applink.c>\nint main(int argc, char *argv[]){return 0;}' > "test_applink.c"
gcc "test_applink.c" $(pkg-config --cflags openssl) $(pkg-config --libs openssl) -o "test_applink.exe" >/dev/null 2>/dev/null || USE_OPENSSL_APPLINK="false"
rm -f "test_applink.c" "test_applink.exe"
echo -e "\nUSE_OPENSSL_APPLINK=${USE_OPENSSL_APPLINK}\n"

# @note https://github.com/AlienCowEatCake/sylpheed-windows/issues/4
curl -LO https://www.gnupg.org/ftp/gcrypt/gpgme/gpgme-1.23.2.tar.bz2
tar -xvpf gpgme-1.23.2.tar.bz2
cd gpgme-1.23.2
autoreconf -ivf
DOXYGEN=/usr/bin/doxygen \
PYTHON=${MINGW_PREFIX}/bin/python3 \
CFLAGS="${CFLAGS} -O3 -DNDEBUG -Wno-int-conversion -Wno-incompatible-function-pointer-types" \
./configure \
    --prefix="${DIST_PREFIX}" \
    --libexecdir="${DIST_PREFIX}/bin" \
    --disable-static \
    --enable-languages='' \
    --disable-gpgconf-test \
    --disable-gpg-test \
    --disable-gpgsm-test \
    --disable-g13-test \
    --disable-fd-passing \
    --disable-w32-glib
cd src
make -j$(getconf _NPROCESSORS_ONLN)
make install-strip
cd ../..

# @note https://github.com/AlienCowEatCake/sylpheed-windows/issues/6
if ! pkg-config cairo-win32-dwrite-font ; then
    if pkg-config cairo-dwrite-font && pkg-config --max-version 1.50.14 pangocairo ; then
        curl -LO https://download.gnome.org/sources/pango/1.50/pango-1.50.14.tar.xz
        curl -Lo pango-0001-9b9e8662.patch https://gitlab.gnome.org/GNOME/pango/-/commit/9b9e86629eae7c757a467d8c825c3929f27ebc3c.patch
        curl -Lo pango-0002-b446637f.patch https://gitlab.gnome.org/GNOME/pango/-/commit/b446637f4a4cbc8018151d1a7186644cdcad8455.patch
        curl -Lo pango-0003-c573c642.patch https://gitlab.gnome.org/GNOME/pango/-/commit/c573c642cae54a57697d72ade3a17259a928fc8f.patch
        curl -Lo pango-0004-d701e622.patch https://gitlab.gnome.org/GNOME/pango/-/commit/d701e622f26ed19b986611d6a8a1601f8ebc881c.patch
        tar -xvpf pango-1.50.14.tar.xz
        cd pango-1.50.14
        find .. -maxdepth 1 -name '*.patch' | sort | while IFS= read -r item ; do patch -p1 --binary -i "${item}" ; done
        mkdir build
        cd build
        meson setup \
            --prefix="${DIST_PREFIX}" \
            --default-library shared \
            --auto-features=enabled \
            -Dgtk_doc=false \
            -Dxft=disabled \
            --wrap-mode=nofallback \
            -Dintrospection=disabled \
            ..
        meson compile
        meson install
        cd ../..
    fi
fi

curl -LO https://sylpheed.sraoss.jp/sylpheed/v3.8beta/sylpheed-3.8.0beta1.tar.bz2
tar -xvpf sylpheed-3.8.0beta1.tar.bz2
cd sylpheed-3.8.0beta1
find "${SOURCE_DIR}/patches_sylpheed" -name '*.patch' | sort | while IFS= read -r item ; do patch -p1 --binary -i "${item}" ; done
autogenSylpheed \
    --prefix="${DIST_PREFIX}" \
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
if "${USE_OPENSSL_APPLINK}" ; then
    echo -e '\n#include <openssl/applink.c>\n' >> "src/main.c"
    echo -e '\n#include <openssl/applink.c>\n' >> "src/syl-auth-helper.c"
fi
make -j$(getconf _NPROCESSORS_ONLN)
make install-strip
(cd plugin/attachment_tool; make install-plugin)
strip "${DIST_PREFIX}/lib/sylpheed/plugins/attachment_tool.dll"
# (cd plugin/test; make install-plugin)
# strip "${DIST_PREFIX}/lib/sylpheed/plugins/test.dll"
cd ..

curl -Lo qdbm-1.8.78.tar.gz https://snapshot.debian.org/archive/debian/20111016T212433Z/pool/main/q/qdbm/qdbm_1.8.78.orig.tar.gz
tar -xvpf qdbm-1.8.78.tar.gz
cd qdbm-1.8.78
./configure --prefix="${DIST_PREFIX}" --enable-stable --enable-pthread --enable-zlib --enable-iconv
for i in $(cat Makefile.in | grep -E '^MYLIBOBJS = ' | sed 's|MYLIBOBJS = || ; s|\.o||g') ; do
    gcc -c -O3 -DQDBM_STATIC -I. -DMYPTHREAD -DMYZLIB -DMYICONV -DNDEBUG -fPIC "${i}.c" -o "${i}.o"
done
ar rcs "${DIST_PREFIX}/lib/libqdbm.a" *.o
for i in $(cat Makefile.in | grep -E '^MYHEADS = ' | sed 's|MYHEADS = ||') ; do
    cp -a "${i}" "${DIST_PREFIX}/include/"
done
cat << EOF > "${DIST_PREFIX}/lib/pkgconfig/qdbm.pc"
Name: QDBM
Description: a high performance embedded database library
Version: 1.8.78
Libs: -L${DIST_PREFIX}/lib ${DIST_PREFIX}/lib/libqdbm.a -lz -lpthread -liconv
Cflags: -I${DIST_PREFIX}/include -DQDBM_STATIC
EOF
cd ..

curl -LO http://sylpheed.sraoss.jp/sylfilter/src/sylfilter-0.8.tar.gz
tar -xvpf sylfilter-0.8.tar.gz
cd sylfilter-0.8
find "${SOURCE_DIR}/patches_sylfilter" -name '*.patch' | sort | while IFS= read -r item ; do patch -p1 --binary -i "${item}" ; done
./configure --prefix="${DIST_PREFIX}" --enable-shared --disable-static --enable-sqlite --enable-qdbm --disable-gdbm --with-libsylph=sylpheed \
    CFLAGS=-O3 \
    CPPFLAGS="-I${DIST_PREFIX}/include -I${DIST_PREFIX}/include/sylpheed" \
    LDFLAGS="-L${DIST_PREFIX}/lib"
if "${USE_OPENSSL_APPLINK}" ; then
    echo -e '\n#include <openssl/applink.c>\n' >> "src/sylfilter.c"
fi
gcc -O3 -DNDEBUG \
    lib/*.c lib/filters/*.c src/*.c \
    -I. -I./lib -I./lib/filters -I${DIST_PREFIX}/include/sylpheed -lsylph-0 \
    $(pkg-config --cflags glib-2.0 qdbm sqlite3) $(pkg-config --libs glib-2.0 qdbm sqlite3) \
    -o "${DIST_PREFIX}/bin/sylfilter"
cd ..

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

rm -rf "${DIST_PREFIX}/bin/compface.exe" "${DIST_PREFIX}/bin/uncompface.exe" \
    "${DIST_PREFIX}/bin/gpgme-config" "${DIST_PREFIX}/bin/gpgme-json.exe" "${DIST_PREFIX}/bin/gpgme-tool.exe" \
    "${DIST_PREFIX}/bin/pango-list.exe" "${DIST_PREFIX}/bin/pango-segmentation.exe" "${DIST_PREFIX}/bin/pango-view.exe"
mv "${DIST_PREFIX}/bin/"* "${DIST_PREFIX}/"
cp -a "${DIST_PREFIX}/sylfilter.exe" "${DIST_PREFIX}/sylfilter-cui.exe"
mv "${DIST_PREFIX}/lib/sylpheed/plugins" "${DIST_PREFIX}/"
mv "${DIST_PREFIX}/share/sylpheed" "${DIST_PREFIX}/doc"
rm -rf "${DIST_PREFIX}/bin" "${DIST_PREFIX}/include" "${DIST_PREFIX}/lib/"* "${DIST_PREFIX}/man" "${DIST_PREFIX}/share/applications" "${DIST_PREFIX}/share/pixmaps"

mkdir -p "${DIST_PREFIX}/etc/ssl/certs"
if [ -f "${MSYSTEM_PREFIX}/etc/ssl/certs/ca-bundle.crt" ] ; then
    cp -a "${MSYSTEM_PREFIX}/etc/ssl/certs/ca-bundle.crt" "${DIST_PREFIX}/etc/ssl/certs/certs.crt"
elif [ -f "${MSYSTEM_PREFIX}/ssl/certs/ca-bundle.crt" ] ; then
    cp -a "${MSYSTEM_PREFIX}/ssl/certs/ca-bundle.crt" "${DIST_PREFIX}/etc/ssl/certs/certs.crt"
else
    echo "Can't find certs bundle"
    exit 1
fi
cp -a "${MSYSTEM_PREFIX}/etc/gtk-2.0" "${DIST_PREFIX}/etc/"
echo 'gtk-theme-name = "MS-Windows"' > "${DIST_PREFIX}/etc/gtk-2.0/gtkrc"

cp -a "${MSYSTEM_PREFIX}/lib/gdk-pixbuf-2.0" "${DIST_PREFIX}/lib/"
cp -a "${MSYSTEM_PREFIX}/lib/gtk-2.0" "${DIST_PREFIX}/lib/"
if pkg-config --atleast-version 3.0.0 openssl ; then
    cp -a "${MSYSTEM_PREFIX}/lib/engines-3" "${DIST_PREFIX}/lib/"
else
    cp -a "${MSYSTEM_PREFIX}/lib/engines-1_1" "${DIST_PREFIX}/lib/"
fi
find "${DIST_PREFIX}" \( -name '*.a' -o -name '*.la' \) -delete
find "${DIST_PREFIX}" -name 'include' | sort | while IFS= read -r item ; do rm -rf "${item}" ; done

cp -a "${MSYSTEM_PREFIX}/bin/curl.exe" "${DIST_PREFIX}/"
if [ ! -f "${DIST_PREFIX}/gpgme-w32spawn.exe" ] ; then
    cp -a "${MSYSTEM_PREFIX}/bin/gpgme-w32spawn.exe" "${DIST_PREFIX}/"
fi
find "${MSYSTEM_PREFIX}/bin" \( -name "gspawn*helper.exe" -o -name "gspawn*helper-console.exe" \) -exec cp -a \{\} "${DIST_PREFIX}/" \;
cp -a "${MSYSTEM_PREFIX}/share/themes" "${DIST_PREFIX}/share/"

function getDepsImpl() {
    find "${DIST_PREFIX}" \( -name '*.exe' -o -name '*.dll' \) -not -name 'bsfilterw.exe' -exec objdump --private-headers \{\} \; | grep 'DLL Name:' | sort | uniq | sed 's|.* ||'
}

function getDeps() {
    # @note https://github.com/AlienCowEatCake/ImageViewer/issues/8
    local DEPS="$(getDepsImpl)"
    if echo "${DEPS}" | xargs | grep -i "api-ms-win-crt-" > /dev/null ; then
        DEPS="$(echo -e "${DEPS}\nucrtbase.dll" | sort | uniq)"
    fi
    echo "${DEPS}"
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

function getVCVARSPath() {
    local VCVARS_HELPER="$(cygpath -w "${SOURCE_DIR}/scripts/find_vcvarsall.bat")"
    local VCVARS_VER="2022"
    cat << EOF | cmd | tail -3 | head -1
call "${VCVARS_HELPER}" ${VCVARS_VER}
echo %VS${VCVARS_VER}_VCVARSALL%
EOF
}

function fixupExes() {
    pushd "${DIST_PREFIX}" > /dev/null
    cat << EOF | cmd
set VCVARS="$(getVCVARSPath)"
call %VCVARS% ${VCVARS_ARCH}
$(find . -maxdepth 1 \( -name 'curl.exe' -o -name 'sylfilter.exe' \) | sed 's|^\./|editbin /subsystem:windows |')
EOF
    popd > /dev/null
}

function getCRTPath() {
    cat << EOF | cmd | tail -3 | head -1
set VCVARS="$(getVCVARSPath)"
call %VCVARS% ${VCVARS_ARCH}
echo %VCToolsRedistDir%${CRT_ARCH}\Microsoft.VC143.CRT
EOF
}

function getUCRTPath() {
    cat << EOF | cmd | tail -3 | head -1
set VCVARS="$(getVCVARSPath)"
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
find "${MSYSTEM_PREFIX}/share/locale/" -type f -name 'gtk20.mo' | while IFS= read -r item ; do
    loc="${item%/LC_MESSAGES/*}"
    loc="${loc##*/}"
    mkdir -p "${DIST_PREFIX}/share/locale/${loc}/LC_MESSAGES/"
    cp -a "${item}" "${DIST_PREFIX}/share/locale/${loc}/LC_MESSAGES/"
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
