# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/development/tim/out/build/x64-Debug/_deps/serial-src"
  "C:/development/tim/out/build/x64-Debug/_deps/serial-build"
  "C:/development/tim/out/build/x64-Debug/_deps/serial-subbuild/serial-populate-prefix"
  "C:/development/tim/out/build/x64-Debug/_deps/serial-subbuild/serial-populate-prefix/tmp"
  "C:/development/tim/out/build/x64-Debug/_deps/serial-subbuild/serial-populate-prefix/src/serial-populate-stamp"
  "C:/development/tim/out/build/x64-Debug/_deps/serial-subbuild/serial-populate-prefix/src"
  "C:/development/tim/out/build/x64-Debug/_deps/serial-subbuild/serial-populate-prefix/src/serial-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/development/tim/out/build/x64-Debug/_deps/serial-subbuild/serial-populate-prefix/src/serial-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/development/tim/out/build/x64-Debug/_deps/serial-subbuild/serial-populate-prefix/src/serial-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
