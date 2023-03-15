# CMAKE package export example.
This is a (supposedly) minimal cmake project that exports a library as a cmake package to be included in external projects using `find_package()`.

## Build
- `mkdir build`
- `cmake .. -DCMAKE_INSTALL_PREFIX=install` (install locally)
- `make`