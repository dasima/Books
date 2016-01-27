#include <iostream>
#include <string>
#include <vector>
/*
 * replace the blank in string(Used in URL analysis)
 * str: string to be analysised
 * length: the 
 */
void replaceBlank(char str[], int length)
{
    if(str == NULL && length <= 0) //? &&
    {
        return;
    }

    //count the number of blank
    int original_length = 0;// original length of str
    int number_of_blank = 0;
    int index = 0;
    while(str[index] != '\0')
    {
        ++original_length;
        if(str[index] == ' ')
            ++number_of_blank;
        ++index;
    }

    int new_length = original_length + number_of_blank * 2;
    if(new_length > length)
        return;

    int index_of_original = original_length;
    int index_of_new = new_length;
    while(index_of_original >= 0 && index_of_new > index_of_original)
    {
        if(str[index_of_original] == ' ')
        {
            str[index_of_new--] = '0';
            str[index_of_new--] = '2';
            str[index_of_new--] = '%';
        }
        else
            str[index_of_new--] = str[index_of_original];
        --index_of_original;
    }
}

// unit test
void replaceBlankTest(char str[], int length)
{
    if(str == NULL)
        return;
    replaceBlank(str, length);
    std::cout << "After replace blank str:" << str << std::endl;
}

void testNormal()
{
    const int length = 100;
    char str[length] = "hello world";
    replaceBlankTest(str, length);
}

void testFront()
{
    const int length = 100;
    char str[length] = " helloworld";
    replaceBlankTest(str, length);
}

void testEnd()
{
    const int length = 100;
    char str[length] = "helloworld ";
    replaceBlankTest(str, length);
}

void testMore()
{
    const int length = 100;
    char str[length] = "hell owor ld";
    replaceBlankTest(str, length);
}

void testNULL()
{
    replaceBlankTest(NULL, 0);
}

void testEmpty()
{
    const int length = 100;
    char str[length] = "";
    replaceBlankTest(str, length);
}

void testOnlyOneBlank()
{
    const int length = 100;
    char str[length] = "hello world";
    replaceBlankTest(str, length);
}

void testNoBlank()
{
    const int length = 100;
    char str[length] = "helloworld";
    replaceBlankTest(str, length);
}

void testAllBlank()
{
    const int length = 100;
    char str[length] = "    ";
    replaceBlankTest(str, length);
}

int main(int argc, const char *argv[])
{
    //unit test
    testNormal();// blank is in the middle of the sentence 
    testFront();// front
    testEnd();// end
    testNULL();// NULL 
    testEmpty();// empth
    testOnlyOneBlank();// only one blank
    testNoBlank();// no blank
    testAllBlank();// all is blank

    return 0;
}
