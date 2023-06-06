#include "RubicsCube.hpp"

int main() {
    RubiksCube cube;
    std::filesystem::path FilePath1 = "CUBIC.txt";
    std::filesystem::path FilePath2 = "CUBIC2.txt";
    cube.GenerateSpinCube(FilePath1, 5);
    cube.SolveCube(FilePath1);
    return 0;
}
