cmake_minimum_required(VERSION 3.5)#最低CMake版本

project(hello_with_header)

set(SOURCES
	src/hello.cpp
	src/main.cpp
)

add_executable(hello ${SOURCES})
#等价于命令：     add_executable(hello_headers src/Hello.cpp src/main.cpp)

target_include_directories(hello
	PRIVATE
		${PROJECT_SOURCE_DIR}/include
)#设置这个可执行文件hello需要包含的库的路径

#PROJECT_SOURCE_DIR指工程顶层目录
#PROJECT_Binary_DIR指编译目录
#PRIVATE指定了库的范围