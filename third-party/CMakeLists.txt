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

CPMAddPackage(
  NAME json
  GITHUB_REPOSITORY nlohmann/json
  GIT_TAG v3.11.3
  VERSION 3.11.3
)

if(ftxui_ADDED)
  add_library(ftxui STATIC "${ftxui_SOURCE_DIR}/src")
  target_include_directories(
    ftxui PUBLIC
    "{ftxui_SOURCE_DIR}/include"
  )
  add_library(ftxui::ftxui ALIAS ftxui)
else()
  set(THIRDPARTY_ERROR_TRUE)
  message(SEND_ERROR "Could not import ftxui.")  
endif()

if(NOT json_ADDED)
  message(SEND_ERROR "Could not import json.")
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
  nlohmann_json::nlohmann_json
)

target_compile_definitions(
  rouge_thirdparty INTERFACE
  PROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\"
)
