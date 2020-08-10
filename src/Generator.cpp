#include "Generator.h"

#include <fstream>
#include <ctime>
#include <string>
#include <memory>


#define path "././././src/solved.in"
#define solved_sudokus 50
#define number_of_digits 17

//Read random sudoku from file and choose 17 random indexes, which creates valid sudoku board
bool Generator::Proceed_operation() 
{
    //generate random number to get one of previosly solved sudokus
    int line = generate_random_number(solved_sudokus);

    int act_line{ 0 };
    std::string readLine;
    if (this->open_file())
    {
        //read solved sudoku with drawn number
        try {
            while ((act_line != line) && (std::getline(this->file_solved, readLine)))
            {     
                act_line++;
            }
            if (line == act_line)
                std::getline(this->file_solved, readLine);
            else          
                throw std::runtime_error("File has less Sudokus than declared");
        }
        catch (const std::ifstream::failure& e) {
            std::cout << "Exception reading file"<<e.what()<<"\n";
            return false;
        }
        catch (const std::exception& ex)
        {
            std::cout << ex.what()<<"\n";
            return false;
        }

        //closing file
        file_solved.close();

        unique_random_numbers(number_of_digits);

        for (int i = 0; i < 81; ++i)
        {
            int row = i / 9;
            int col = i % 9;
            //check if elements is in the set
            auto it = this->unique_randoms.find(i);
            if (it != this->unique_randoms.end())
            {
                //save readed element in sudoku board
                int elem = std::stoi(readLine.substr(i, 1));
                ptr_sudoku_board->modify_element(elem, row, col);
            }
            else
            {
                ptr_sudoku_board->modify_element(0, row, col);
            }

        }
            return true;
    }

    else
    {
        std::cout << "Problem with opening file\n";
        return false;
    }

}

//generate specified number of random numbers in unorered set
void Generator::unique_random_numbers(int quantity)
{
    while (this->unique_randoms.size() < quantity)
    {
        this->unique_randoms.insert(generate_random_number(81));
    }
}

//open file with sudoku boards
bool Generator::open_file()
{
    this->file_solved.open(path);
    if (file_solved.good())
        return true;
    else
        return false;
}

//generate random number from 0 to max
int Generator::generate_random_number(int max){
    srand((int) time (0));
    return rand()%max;
}