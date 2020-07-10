# checkBitSize
This little program tells you the size of size_t and void*
# Compilation
## Linux
On Linux, just run gcc on your platform:

gcc -o checkbitsize checkBitSize.c

Some examples for cross-compiling:

arm: arm-linux-gnueabihf-gcc -o checkbitsize checkBitSize.c

i386: gcc -m32 -o checkbitsize checkBitSize.c

## Windows
For MSVC, the targets Win32 and x64 are provided in the solution file. Examples:

/path/to/MSBuild.exe build/MSVC/checkBitSize.sln //t:Rebuild //p:Configuration=Release //p:Platform=Win32

/path/to/MSBuild.exe build/MSVC/checkBitSize.sln //t:Rebuild //p:Configuration=Release //p:Platform=x64
