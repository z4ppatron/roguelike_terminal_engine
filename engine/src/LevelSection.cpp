#include "math/Matrix.hpp"
#include "nlohmann/json_fwd.hpp"
#include <LevelSection.hpp>
#include <Utils.hpp>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
#include <stdexcept>

LevelSection::LevelSection() : level_data(Matrix<char>(1, 1, {' '})), id(1) {}

LevelSection::LevelSection(size_t rows_, size_t cols_)
    : level_data(Matrix<char>(rows_, cols_, ' ')), id(1) {}

int LevelSection::read_from_json(std::string file_path) {
  namespace fs = std::filesystem;
  using json = nlohmann::json;

  // Define things that are useful. :)
  size_t rows;
  size_t cols;
  std::string level_section_file_path;

  // Get file and set current path to file path.
  std::ifstream file(file_path);
  fs::path path(file_path);
  path = path.parent_path();
  fs::current_path(path);

  // Check if file exists in the first place
  if (!(std::filesystem::exists(file_path))) {
    throw std::runtime_error("File does not exist!");
  }

  // Parse json file
  json json_file = json::parse(file);

  // Get rows and columns from json.
  rows = json_file["size"]["rows"];
  cols = json_file["size"]["cols"];
  level_section_file_path = json_file["level_section_source"];
  this->level_data = Matrix<char>(rows, cols, ' ');

  std::ifstream level_section_file(level_section_file_path);

  // Loop through text file and insert at corresponding place in level data.
  // TODO: Make this work.
  std::string temp;
  size_t i = 0;
  while (std::getline(level_section_file, temp)) {
    for (size_t j = 0; j < cols; ++j) {
      this->level_data.set_entry(i, j, temp[j]);
    }
    i++;
  }

  return EXIT_SUCCESS;
}
