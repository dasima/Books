// fun command : g++ interview_3.cpp -std=c++0x
// to generate the executable file

#include <iostream>

/*
 * function: if number if exist in array matrix
 * matrix: two-dimensional array(the element after which has a higher row or column is bigger)
 * rows: row numbers
 * columns: column numbers
 * number: number to be found
 */
bool isFind(int *matrix, int rows, int columns, int number);
bool isFound(int *matrix, int rows, int columns, int number);
void function_test(int *matrix, int rows, int columns, int number, bool expected);

int main(int argc, const char *argv[])
{
    // function test
    int matrix[][4] = 
    {
        {1, 2, 8, 17},
        {2, 16, 19, 22},
        {14, 37, 40, 33},
        {25, 39, 41, 45}
    };

    // exist
    std::cout << "function test\n";
    bool is_find = isFind((int*)matrix, 4, 4, 40);
    std::cout << "is number 3 found? :" << std::boolalpha << is_find << "\n";
    // exist
    is_find = isFind((int*)matrix, 4, 4, 16);
    std::cout << "is number 7 found? :" << std::boolalpha << is_find << "\n";
    // not exist
    is_find = isFind((int*)matrix, 4, 4, 35);
    std::cout << "is number 5 found? :" << std::boolalpha << is_find << "\n";
    // the least
    is_find = isFind((int*)matrix, 4, 4, 1);
    std::cout << "is number 14 found? :" << std::boolalpha << is_find << "\n";
    // the biggest
    is_find = isFind((int*)matrix, 4, 4, 45);
    std::cout << "is number 14 found? :" << std::boolalpha << is_find << "\n";
    // smaller than least
    is_find = isFind((int*)matrix, 4, 4, 0);
    std::cout << "is number 14 found? :" << std::boolalpha << is_find << "\n";
    // bigger than biggest
    is_find = isFind((int*)matrix, 4, 4, 60);
    std::cout << "is number 14 found? :" << std::boolalpha << is_find << "\n";
    // null pointer
    is_find = isFind(NULL, 0, 0, 60);
    std::cout << "is number 14 found? :" << std::boolalpha << is_find << "\n";


    // function isFound test
    function_test((int*)matrix, 4, 4, 33, true);// exist
    function_test((int*)matrix, 4, 4, 15, false);// not exist
    function_test((int*)matrix, 4, 4, 1, true);// least
    function_test((int*)matrix, 4, 4, 45, true);// biggest
    function_test((int*)matrix, 4, 4, 0, false);// smaller than least
    function_test((int*)matrix, 4, 4, 50, false);// bigger than biggest
    function_test((int*)matrix, 4, 4, -1, false);// smaller than least, negative
    function_test(NULL, 0, 0, 40, false);// null pointer


    return 0;
}

// because if compare from the top_left or right_end corner, after one compare, cann't discard one row or one column, 
// but if compare from top_right corner, after one compare, we can discard one row and/or one colune.
bool isFind(int *matrix, int rows, int columns, int number)
{
    bool is_found = false;
    if(matrix != NULL && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns - 1;
        while(row < rows && column >= 0)
        {
            if(matrix[row * columns + column] == number)
            {
                is_found= true;
                break;
            }
            else if(matrix[row * columns + column] > number)
            {
                column--;
            }
            else
                row++;
        }
    }

    return is_found;
}

// find from left bottom;
// use c++11
bool isFound(int *matrix, int rows, int columns, int number)
{
    auto is_found = false;
    if(matrix != NULL && rows > 0 && columns > 0)
    {
        auto row = rows - 1, column = 0;
        while(row >= 0 && column < columns)
        {
            if(matrix[row * columns + column] == number)
            {
                is_found = true;
                break;
            }
            else if(matrix[row * columns + column] < number)
                ++column;
            else 
                --row;
        }

    }

    return is_found;
}

void function_test(int *matrix, int rows, int columns, int number, bool expected)
{
    auto result = isFound(matrix, rows, columns, number);
    std::cout << "Find number:" << number 
        << " in matrix:" << result 
        << "---" << std::boolalpha << expected <<" expected"
        << std::endl;
}
