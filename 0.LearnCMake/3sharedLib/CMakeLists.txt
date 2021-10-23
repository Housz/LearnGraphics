cmake_minimum_required(VERSION 3.5)
project(hello_library)

############################################################
# Create a library

# 根据Hello.cpp生成动态库
add_library(hello_library SHARED
	src/hello.cpp
)

#给动态库hello_library起一个别的名字hello::library
# add_library(hello::library ALIAS hello_library)

target_compile_definitions(hello_library PRIVATE BUILD_DLL)


#为这个库目标，添加头文件路径，PUBLIC表示包含了这个库的目标也会包含这个路径
target_include_directories(hello_library
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
)

############################################################
# Create an executable
add_executable(hello_bin
	src/main.cpp
)
target_compile_definitions(hello_bin PRIVATE USE_DLL)
#链接库和可执行文件，使用的是这个库的别名。PRIVATE 表示
target_link_libraries(hello_bin
	PRIVATE
		hello_library
)


# https://zhuanlan.zhihu.com/p/392750572 Windows平台dll