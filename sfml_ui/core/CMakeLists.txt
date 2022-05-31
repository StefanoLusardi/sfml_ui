set(TARGET_NAME core)
add_library(${TARGET_NAME} SHARED
	include/core/core.hpp
	src/core.cpp)

find_package(Poco)
target_include_directories(${TARGET_NAME} PUBLIC include)
target_link_libraries(${TARGET_NAME}
	PRIVATE ui
	PRIVATE Poco::Poco)