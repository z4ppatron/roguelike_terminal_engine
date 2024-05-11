include_guard(DIRECTORY)
include(CPM.cmake)
cmake_minimum_required(VERSION 3.18)

add_library(rouge_thirdparty INTERFACE)
add_library(rouge::thirdparty ALIAS rouge_thirdparty)

CPMAddPackage(
  NAME ftxui
  GITHUB_REPOSITORY ArthurSonzogni/FTXUI
  GIT_TAG v5.0.0
  VERSION 5.0.0
  OPTIONS
  "FTXUI_DEV_WARNINGS ON"
)

if(ftxui_ADDED)
  # add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)

  add_library(ftxui STATIC "${ftxui_SOURCE_DIR}/src")
  target_include_directories(
    ftxui PUBLIC
    "{ftxui_SOURCE_DIR}/include"
  )
  add_library(ftxui::ftxui ALIAS ftxui)

  # add_library(ftxui::screen ALIAS ftxui_screen)
  # set(FTXUI_SCREEN_SRC "${ftxui_SOURCE_DIR}/src/ftxui/screen" PARENT_SCOPE)
#
  # add_library(ftxui::dom ALIAS ftxui_dom)
  # set(FTXUI_DOM_SRC "${ftxui_SOURCE_DIR}/src/ftxui/dom" PARENT_SCOPE)
#
  # add_library(ftxui::component ALIAS ftxui_component)
  # set(FTXUI_COMPONENT_SRC "${ftxui_SOURCE_DIR}/src/ftxui/component" PARENT_SCOPE)
else()
  set(THIRDPARTY_ERROR_TRUE)
  message(SEND_ERROR "Could not locate ftxui.")
endif()

if(THIRDPARTY_ERROR)
    message(FATAL_ERROR "Failed to add third party libraries.")
endif()

set_target_properties(
  ftxui PROPERTIES LINKER_LANGUAGE CXX
)

target_link_libraries(
  rouge_thirdparty INTERFACE
  ftxui::screen
  ftxui::dom
  ftxui::component
)

target_compile_definitions(
  rouge_thirdparty INTERFACE
  PROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\"
)
