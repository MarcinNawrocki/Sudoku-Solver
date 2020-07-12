#ifndef GENERATOR_H
#define GENERATOR_H
#include"Sudoku.h"
#include<fstream>


class Generator
{

    private:
    std::ifstream file_solved;
    const Sudoku *ptr_toSudoku;

    //readSudokuFromFile()
    bool openFile();
    int generateRandomNumber(int max);

    public:
    sampleContainer generatedSudoku;
    sampleContainer Generate();
    Generator(){};

};

#endif // GENERATOR_H
