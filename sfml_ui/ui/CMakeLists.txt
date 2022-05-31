set(TARGET_NAME ui)
add_library(${TARGET_NAME} SHARED
	include/ui/ui.hpp
	src/ui.cpp)

find_package(sfml)
target_include_directories(${TARGET_NAME} PUBLIC include)
target_link_libraries(${TARGET_NAME}
	PRIVATE sfml::sfml)