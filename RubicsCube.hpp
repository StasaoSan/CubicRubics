#pragma once
#include <iostream>
#include <array>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <stack>
#include <string>
#include <utility>
#include <filesystem>
#include <random>

enum Color { WHITE, YELLOW, BLUE, GREEN, RED, ORANGE };

class RubiksCube {
private:
    std::array<std::array<std::array<Color, 3>, 3>, 6> cube;
    std::stack<int> Rotations;

    std::string CreateAllCode(Color NumWise, int CurPos, char CurColor );
    std::string CreatePosCode(int CurPos, char CurColor);
    void RotateFaceClockwise(int face);
    void RotateFaceCounterclockwise(int face);
    void RotateCenterVC(int face);
    void RotateCenterVCC(int face);
    void RotateCenterHC(int face);
    void RotateCenterHCC(int face);
    std::string GetCreateCubeCode();
    void SetCubeState(std::string RawData);
    Color GetSTRWiseCode(const std::string &RawData, int pos);
    Color GetSTRColor(const std::string &RawData, int pos);
    std::pair<int, int> GetSTRPairPos(const std::string &RawData, int pos);
    void DisplaySolve();
    int GenerateRandomSpin();

public:
    RubiksCube();
    void Display();
    void SpiningCube(std::filesystem::path FilePath);
    void SetCubeFromFile(std::filesystem::path FilePath);
    void SolveCube(std::filesystem::path FilePath);
    void CheckCorrectCube(std::filesystem::path FilePath);
    void GenerateSpinCube(std::filesystem::path FilePath, int CountSpin);
};
