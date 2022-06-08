set(TARGET_NAME core)
add_library(${TARGET_NAME} SHARED
	include/core/engine.hpp
	src/base_module.cpp
	src/base_module.hpp
	src/engine.cpp
	src/module_a.cpp
	src/module_a.hpp
	src/module_b.cpp
	src/module_b.hpp
)

find_package(Poco)
target_include_directories(${TARGET_NAME} PUBLIC include)
target_link_libraries(${TARGET_NAME}
	PRIVATE ui
	PRIVATE Poco::Poco
)