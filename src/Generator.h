#ifndef GENERATOR_H
#define GENERATOR_H
#include"Sudoku.h"
#include<fstream>


class Generator
{
    std::ifstream file_solved;
    const Sudoku *ptr_to_sudoku;

    //readSudokuFromFile()
    bool open_file();
    int generate_random_number(int max);

    public:
    Generator() = default;
    virtual ~Generator()
    {
        ptr_to_sudoku = nullptr;
        delete ptr_to_sudoku;
    }
    one_dim_container generated_sudoku;
    one_dim_container generate();
    

};

#endif // GENERATOR_H
