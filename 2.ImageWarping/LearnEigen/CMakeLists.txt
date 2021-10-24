cmake_minimum_required(VERSION 3.5)

project(hello_eigen)

add_executable(hello src/main.cpp)

target_include_directories(hello
	PRIVATE
		${PROJECT_SOURCE_DIR}
)

