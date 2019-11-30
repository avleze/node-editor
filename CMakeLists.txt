cmake_minimum_required(VERSION 3.16)

project(node-editor)

find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0) 


link_directories(${GTKMM_LIBRARY_DIRS} libs)
include_directories(${GTKMM_INCLUDE_DIRS} include)

add_executable(node-editor ${PROJECT_SOURCE_DIR}/src/main.cpp
		${PROJECT_SOURCE_DIR}/src/node_viewer/node_viewer.cpp
		${PROJECT_SOURCE_DIR}/src/node_viewer/node.cpp
		${PROJECT_SOURCE_DIR}/src/node_viewer/node_viewer.cpp
		${PROJECT_SOURCE_DIR}/src/node_editor/node_editor.cpp
)

target_link_libraries(node-editor ${GTKMM_LIBRARIES})
