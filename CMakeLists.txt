cmake_minimum_required(VERSION 3.6)
project(CPrimary)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp 7/FriendTest.h 7/FriendTestB.h 12/MemoryTest.cpp 12/MemoryTest.h 12/StrBlob.cpp 12/StrBlob.h 12/StrBlobPtr.cpp 12/StrBlobPtr.h 13/SalesData.cpp 13/SalesData.h 13/HasPtr.cpp 13/HasPtr.h)
add_executable(CPrimary ${SOURCE_FILES})