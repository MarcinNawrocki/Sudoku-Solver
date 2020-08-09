#include "Generator.h"

#include <fstream>
#include <ctime>
#include <string>
#include <memory>


#define path "././././src/solved.in"
#define solved_sudokus 50
#define number_of_digits 17

//Read random sudoku from file and choose 17 random indexes, which creates valid sudoku board
bool Generator::Generate() 
{
    //generate random number to get one of previosly solved sudokus
    int line = generate_random_number(solved_sudokus);

    int act_line{ 0 };
    std::string readLine;
    this->open_file();

    //read solved sudoku with drawn number
    while ((act_line != line) && (std::getline(this->file_solved, readLine)))
    {
        act_line++;
    }
    std::getline(this->file_solved, readLine);

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
        //error handling
        return false;
}

//generate random number from 0 to max
int Generator::generate_random_number(int max){
    srand((int) time (0));
    return rand()%max;
}

/*
//row permutation
auto permutations = get_permutation();

//we have 3 only three groups of rows/columns that could be permutated
for (int i = 1; i < 4; ++i)
{
    //each group contains 3 rows/columns but we need only check two permutations
    for (int j = 1; j < 3; ++j)
    {
        if (i < permutations.at(i))
            //swap two rows
            ptr_sudoku_board->get_row(i).swap(ptr_sudoku_board->get_row(permutations.at(i)));
    }
}
//make changes in other containers
 ptr_sudoku_board->make_two_dim_containers(s);

std::vector<int>& Generator::get_permutation(int elements=3)
{
    std::vector <int> permutations(elements);
    std::iota(permutations.begin(), permutations.end(), elements);

    //get random number of permutations
    int number_of_permutations = generate_random_number(factorial(elements));

    //generate permutated vector
    while (number_of_permutations > 0)
        std::next_permutation(permutations.begin(), permutations.end());

    //permutations as class member?
    return permutations;

}

int factorial(int n)
{
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;

}
*/