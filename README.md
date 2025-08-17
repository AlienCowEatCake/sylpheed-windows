# Sylpheed for Windows

## About Sylpheed
[Sylpheed](https://sylpheed.sraoss.jp/en/) is a simple, lightweight but featureful, and easy-to-use e-mail client.
Sylpheed is a free software distributed under the [GNU GPL](https://www.gnu.org/licenses/old-licenses/gpl-2.0.html).

## About Sylpheed for Windows
This project provides unofficial builds of Sylpheed with updated libraries and toolchain:
* Support for native 64-bit
* Support for native ARM64 (experimental)
* Support for spell checking (Windows 8+)
* Support for native Windows toast notifications (Windows 8+)
* Support for color emoji and other features of modern unicode
* Other bugfixes and improvements

## Building from Source
Prerequisites:
- [MSYS2](https://www.msys2.org/)
- [Visual Studio 2022](https://visualstudio.microsoft.com/vs/) for CRT and UCRT redistributables

You need to open MSYS2 terminal for `UCRT64`, `MINGW64`, `CLANG64` or `CLANGARM64` environment and run following command:
```sh
cd sylpheed-windows
./build_sylpheed_msys2.sh
```

## See also
* https://sylpheed.sraoss.jp/en/
* https://sylpheed.sraoss.jp/sylpheed/win32/
* https://github.com/sylpheed-mail/sylpheed
* https://github.com/AlienCowEatCake/sylpheed-macos
* https://github.com/AlienCowEatCake/WinToastLibC
