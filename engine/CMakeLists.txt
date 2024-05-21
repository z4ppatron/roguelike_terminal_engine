include_guard(DIRECTORY)

project(
  rouge-engine
  VERSION 0.0.1
  LANGUAGES CXX
)

add_library(
  rouge_engine STATIC
  src/math/Vector2.cpp
  src/math/Point.cpp
  src/LevelSection.cpp
)

add_library(rouge::engine ALIAS rouge_engine)
target_link_libraries(rouge_engine PUBLIC rouge::thirdparty)
target_include_directories(
  rouge_engine
  PUBLIC include
)

target_compile_options(
  rouge_engine PRIVATE
  -Wall -Wextra -Wpedantic
  -Wno-reorder-ctor
  -Wno-unused-private-field
)
