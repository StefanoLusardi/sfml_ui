set(TARGET_NAME ui)
add_library(${TARGET_NAME} SHARED
	include/ui/color.hpp
	include/ui/rect_t.hpp
	include/ui/text_t.hpp
	include/ui/window_manager_fake.hpp
	include/ui/window_manager_interface.hpp
	include/ui/window_manager.hpp
	src/color_adapter.hpp
	src/layer_interface.hpp
	src/layer_rect.cpp
	src/layer_rect.hpp
	src/layer_text.cpp
	src/layer_text.hpp
	src/window_manager.cpp
)

find_package(SFML)
target_include_directories(${TARGET_NAME} PUBLIC include)
target_link_libraries(${TARGET_NAME}
	PRIVATE sfml::sfml
)