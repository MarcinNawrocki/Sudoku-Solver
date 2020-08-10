#pragma once

#include <array>
#include <iostream>
#include "Structs.h"
#include "SudokuBoard.h"

class I_OneTaskClass {

public:
    virtual bool Proceed_operation() = 0;
};

class SudokuHandler{

private:

    SudokuBoard Board;                  //sudoku containers and get/set mothods to it

    bool Call_one_task_class(I_OneTaskClass* ptr);

public:
    //constructors
    SudokuHandler()
        :Board() 
    {
        //initialize with zeros
        this->Clear_board();
        this->empty_board = true;
    }
    SudokuHandler(one_dim_container& s)
        :Board(s){}
    SudokuHandler(two_dim_container& s)
        :Board(s) {}

    //public fields
    bool solved{ false };                   
    bool empty_board{ false };

    //public methods 
    bool Solve();
    bool Check();
    bool Generate();
    void Clear_board();

    //operator overload
    friend std::ostream& operator<<(std::ostream& os, const SudokuHandler& rhs);
};



