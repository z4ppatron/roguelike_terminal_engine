cmake_minimum_required (VERSION 3.18)
cmake_policy(SET CMP0048 NEW)
set (CMAKE_CXX_STANDARD 20)

project(
  rouge 
  LANGUAGES CXX 
  DESCRIPTION "Dumb project."
  VERSION 1.0.0
)
 
# include(FetchContent)
# set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
# FetchContent_Declare(ftxui
  # GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  # GIT_TAG main # Important: Specify a version or a commit hash here.
# )
# FetchContent_MakeAvailable(ftxui)

add_subdirectory(engine)
add_subdirectory(third-party)

add_executable(
  ${PROJECT_NAME}
  engine/main.cpp
)

target_link_libraries(${PROJECT_NAME} rouge::engine)
set_target_properties(
  ${PROJECT_NAME} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${PROJECT_NAME}"
)

# add_executable(roguelike_terminal_engine src/main.cpp)
#
# target_include_directories(roguelike_terminal_engine PUBLIC "${PROJECT_SOURCE_DIR}/include/")
#
# target_link_libraries(roguelike_terminal_engine
  # PRIVATE ftxui::screen
  # PRIVATE ftxui::dom
  # PRIVATE ftxui::component # Not needed for this example.
# )

