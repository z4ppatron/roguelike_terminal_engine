#include <fstream>
#include <ios>
#include <limits>
inline std::ifstream& goto_line(std::ifstream& file, unsigned num) {
    file.seekg(std::ios::beg); 
    for (int i = 0; i < num - 1; ++i) {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return file;
}