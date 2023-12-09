#include "HelpterFunctions.hpp"

bool isOperation(char character)
{
    return character == '+' || character == '-' || character == '>' || character == '<' || character == '.' || character == ',' || character == '[' || character == ']';
}
