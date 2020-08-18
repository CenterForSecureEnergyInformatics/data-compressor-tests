# Tests for the data-compressor
This folder contains automated tests for the [Data Compressor](https://github.com/CenterForSecureEnergyInformatics/data-compressor)
The tests can be used manually, but are intended for a CI system (buildbot).
The proper environment for building and testing is chosen automatically.

## prerequisites
On Windows, you have to have installed:
- Git including Git Bash. Download the current version here: https://git-scm.com/download/win
- Microsoft C++ Build Tools 2019. Download: https://visualstudio.microsoft.com/de/downloads/

On Linux, you need gcc for your platform.
Currently, the versions shipped with Raspian / Ubuntu 18.04 / Alpine are used.

The source files for the [Data Compressor](https://github.com/CenterForSecureEnergyInformatics/data-compressor) and [checkBitSize](../checkBitSize) have to be next to the folder containing ths project.
Other locations can be specified via the variables `checkBitSizePath` and `dataCompressorPath` in the scripts.

## buildAndTest.sh

- Linux `buildAndTest.sh <i386|x86_64|armhf|arm|win32|x64> <IO_SIZE_BITS>`
- Raspberry Pi `buildAndTest.sh arm <IO_SIZE_BITS>`
- Windows `buildAndTest.sh <win32|x64> <IO_SIZE_BITS>`

First, the [Data Compressor](https://github.com/CenterForSecureEnergyInformatics/data-compressor) is built for the platform specified via the first argument.
The second argument specifies `IO_SIZE_BITS`.

After compilation, testdata (contained in the data-compressor repository) is compressed and decompressed with the following methods:
- dega
- lzmh

The resulting data is compared to the input via diff.
If input and output differs for some tests, the script will return an error.

## checkBits.sh
- Linux `checkBits.sh <i386|x86_64|armhf|arm|win32|x64>`
- Raspberry Pi: `checkBits.sh arm`
- Windows: `checkBits.sh <win32|x64>`

This script compiles and runs the program [checkBitSize](../checkBitSize) on the specified platform.
