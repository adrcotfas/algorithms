cmake_minimum_required (VERSION 2.6)
project (SimpleATM)

include_directories(include)
file(GLOB SOURCES 
	"src/*.cpp"
	"include/*.h")

add_executable(SimpleATM ${SOURCES})
