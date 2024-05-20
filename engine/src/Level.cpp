#include <Level.hpp>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <Utils.hpp>

Level::Level() : level_data(Matrix<char>(1, 1, {'a'})), id(1) {}

void Level::read_from_file(ifstream& file) {
  // line 1 defines size, begin on line 3
  size_t rows;
  size_t cols;

  if (!file.is_open()) {
    throw std::runtime_error("File not open!");
    return;
  }
  // first line
  std::string line1;
  std::getline(file, line1);

  if (line1.rfind("SIZE:", 0) != 0) {
    throw std::runtime_error("Incorrect syntax, first line should be SIZE: x, y.");
  }

  // Super hacky, but im not doing a token parser. Laziness 100.
  std::string line1_stripped = line1.substr(5, line1.length());
  std::stringstream line1_stripped_stream(line1_stripped);
  line1_stripped_stream >> rows >> cols;

  // Create matrix with correct size using whitespaces. 
  this->level_data = Matrix<char>(rows, cols, ' ');

  // Goto line 3 and check value.
  goto_line(file, 3);
  std::string is_begin;
  std::getline(file, is_begin);
  if (!(is_begin.compare("BEGIN"))) {
    throw std::runtime_error("Incorrect syntax, should be BEGIN ...");
  }

  // write to matrix. Love hardcoded values.
  std::string temp;
  for (size_t i = 0; i < rows; i++) {
    goto_line(file, i + 4);
    std::getline(file, temp);
    std::cout << temp << std::endl;
    for (size_t j = 0; j < cols; j++) {
      this->level_data.set_entry(i, j, temp.at(j));
    }
  }
  file.close();
  std::cout << this->level_data << std::endl;
  return;
}
