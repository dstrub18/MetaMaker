cmake_minimum_required(VERSION 3.14)
project(CLion)

set(CMAKE_CXX_STANDARD 14)

add_executable(CLion
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/Makefile
        cmake-build-debug/Project.cbp
        CMakeLists.txt
        Debug-Info-App.plist
        PkgInfo
        Release-Info-App.plist)
