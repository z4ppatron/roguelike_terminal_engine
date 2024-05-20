#include <fstream>
#include <math/Matrix.hpp>

class Level {
  private:
    Matrix<char> level_data;
    unsigned short id;

  public:
    Level();
    ~Level() = default;

    void read_from_file(ifstream& file);
};


