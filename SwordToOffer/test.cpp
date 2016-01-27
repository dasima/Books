#include <iostream>

bool isFound(int *matrix, int rows, int columns, int number);
void function_test(int *matrix, int rows, int columes, int number, bool expected);

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

// find from left bottom;
// use c++11
bool isFound(int *matrix, int rows, int columns, int number)
{
    //auto is_found = false;
    bool is_found = false;
    if(matrix != NULL && rows > 0 && columns > 0)
    {
        //auto row = rows - 1, column = 0;
        int row = rows - 1, column = 0;
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
    //auto result = isFound(matrix, rows, columns, number);
    bool result = isFound(matrix, rows, columns, number);
    std::cout << "Find number:" << number 
        << " in matrix:" << result 
        << "---" << std::boolalpha << expected <<" expected"
        << std::endl;
}
