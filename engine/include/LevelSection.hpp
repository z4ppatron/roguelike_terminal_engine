#include <string>
#include <math/Matrix.hpp>
#include <nlohmann/json.hpp>

class LevelSection {
private:
  Matrix<char> level_data;
  unsigned short id;

public:
  LevelSection();
  LevelSection(size_t rows_, size_t cols_);
  ~LevelSection() = default;

  int read_from_json(std::string file_path);
};
