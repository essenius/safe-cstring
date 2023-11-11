# safe-cstring

Safer versions of `strcat`, `strcpy`, and `sprintf` that prevent buffer overflows. They provide the same interface as the 
original versions, but they will not write across the boundaries of the buffer.

Pointer implementations of `strcpy` and `sprintf` are provided as well (using a reference to the underlying buffer).

I'm doing this as the classic `const char*` strings are still used a lot in Arduino land since the `String` implementation often 
fragments the heap too much, and the classic implementation is much more stable. That is, unless you get into buffer overflows.

The goal of this project was to learn how to create an Arduino library, and be able to test it on the host machine 
(in my case Windows 11). I'm using Visual Studio 2022 as develompent environment so therefore you will also see
`.sln` and `.vcxproj` files.

This library is a simple header-only one that does not use any Arduino specific functions, so it is a good first use case.

I've set it up as a solution with an `src` project and a `test` project. This allows for meeting the Arduino requirement that 
the `src` folder is directly under the root. I made the `examples` folder a separate project. 
All files in the root are solution items that are needed for Visual Studio (`CodeCoverage.runsettings`, `post-build.cmd`), 
Git (`.gitignore`, `LICENSE`, `README.md`) or to meet the Arduino library specification (`library.properties`, `keywords.txt`).

The test project is a Google Test project that can be run in Test Explorer of Visual Studio, so you can do all unit testing on the host.

The advantage of this structure is that it is now possible to use this repo directly as an Arduino library.

If you want to test it locally, a ZIP file `publish\SafeCString.zip` is created after a `Release` build via a post build step (`post-build.cmd`), 
which you can import into the Arduino IDE via Sketch / Include Library / Add .ZIP Library. Don't forget to restart the IDE after doing this, 
otherwise the example won't show.

