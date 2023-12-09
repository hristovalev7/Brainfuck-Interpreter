#include "HelperFunctions.hpp"

bool isOperation(char character)
{
    return character == '+' || character == '-' || character == '>' || character == '<' || character == '.' || character == ',' || character == '[' || character == ']';
}

void ensureFileIsOpen(std::ifstream& file)
{
    if (!file.is_open())
    {
        throw std::runtime_error("The given file couldn't be opened for reading!");
    }
}

void ensureFileIsOpen(std::ofstream& file)
{
    if (!file.is_open())
    {
        throw std::runtime_error("The given file couldn't be opened for writing!");
    }
}
