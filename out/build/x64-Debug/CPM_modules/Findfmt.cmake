include("C:/development/tim/out/build/x64-Debug/cmake/CPM.cmake")
CPMAddPackage("NAME;fmt;GITHUB_REPOSITORY;fmtlib/fmt;GIT_TAG;10.2.1;OPTIONS;FMT_DOC OFF;FMT_TEST OFF;FMT_INSTALL OFF;FMT_PEDANTIC OFF;FMT_WERROR OFF;FMT_USE_CCACHE OFF;FMT_USE_FIND_PACKAGE OFF;FMT_USE_CONFIG OFF;FMT_USE_PKG_CONFIG OFF;FMT_USE_CONAN OFF;FMT_USE_VCPKG OFF;FMT_USE_ASAN OFF;FMT_USE_UBSAN OFF;FMT_USE_MSAN OFF;FMT_USE_TSAN OFF;FMT_USE_CODE_ANALYSIS OFF;FMT_USE_CPPCHECK OFF")
set(fmt_FOUND TRUE)