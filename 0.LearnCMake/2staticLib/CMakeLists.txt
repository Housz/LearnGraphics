cmake_minimum_required(VERSION 3.5)
project(hello_static_library)

#######################################
# create a library

# 库的源文件 hello.cpp 生成静态库 hello_static_library
add_library(hello_static_library STATIC
	src/hello.cpp
)

target_include_directories(hello_static_library
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
)
# target_include_directories 为一个目标（可能是一个库library也可能是可执行文件）添加头文件路径。

############################################################
# create a executable

#指定用哪个源文件生成可执行文件
add_executable(hello
	src/main.cpp
)

#链接可执行文件 和 静态库

target_link_libraries(hello
	PRIVATE
		hello_static_library
)