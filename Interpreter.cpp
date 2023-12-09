#include "Interpreter.hpp"

void Interpreter::validateCode()
{
    std::ifstream file(fileName, std::ios::in);
    if (!file.is_open())
    {
        throw std::runtime_error("The given file couldn't be opened!\n");
    }
    char currentChar{};
    std::stack<size_t> LBrackets;
    while (file.good())
    {
        if (currentChar == '[')
        {
            LBrackets.push(file.tellg().operator std::streamoff() - 1);
        }
        else if (currentChar == ']')
        {
            leftBrackets[LBrackets.top()] = file.tellg().operator std::streamoff() - 1;
            rightBrackets[file.tellg().operator std::streamoff() - 1] = LBrackets.top();
            LBrackets.pop();
        }
        file.get(currentChar);
    }
    if (!LBrackets.empty())
    {
        throw std::runtime_error("The number of '[' doesn't match the number of ']'");
    }
}

void Interpreter::executeOperation(char operation, std::ifstream& file)
{
    size_t operationPosition = file.tellg().operator std::streamoff() - 1;
    switch (operation)
    {
        case '+':
            incrementValue();
            break;
        case '-':
            decrementValue();
            break;
        case '>':
            incrementPointer();
            break;
        case '<':
            decrementPointer();
            break;
        case '.':
            print();
            break;
        case ',':
            read();
            break;
        case '[':
            if (cells[currentCell] == Byte(0))
            {
                file.seekg(leftBrackets[operationPosition] - 1 + 1);
            }
            break;
        case ']':
            file.seekg(rightBrackets[operationPosition] - 1);
            break;
        default:
            break;
    }
}

void Interpreter::keepPointerInBounds() const
{
    if (currentCell == 0)
    {
        throw std::out_of_range("The pointer went out of bounds!");
    }
}

void Interpreter::resize()
{
    Interpreter interpreter(fileName, size * 2);
    interpreter.copy(this->cells, this->size);
    interpreter.currentCell = currentCell;
    *this = interpreter;
}

void Interpreter::deallocate()
{
    delete[] cells;
    cells = nullptr;
    currentCell = 0;
    size = 0;
}

void Interpreter::allocate(size_t numberOfCells)
{
    cells = new Byte[numberOfCells]{};
}

void Interpreter::copy(const Byte* otherCells, size_t otherSize)
{
    if (otherSize == 0)
    {
        return;
    }
    for (unsigned int i{0}; i <= otherSize - 1; ++i)
    {
        cells[i] = otherCells[i];
    }
}

void Interpreter::copy(const Interpreter& other)
{
    deallocate();
    allocate(other.size);
    copy(other.cells, other.size);
    currentCell = other.currentCell;
    size = other.size;
}

Interpreter::Interpreter() : cells(new Byte[30000]{}), currentCell(0), size(30000)
{}

Interpreter::Interpreter(const std::string& _fileName, size_t _size) : fileName(_fileName), cells(new Byte[_size]{}), currentCell(0), size(_size)
{}

Interpreter::Interpreter(const Interpreter& other) : cells(nullptr), currentCell(0), size(0)
{
    copy(other);
}

Interpreter& Interpreter::operator=(const Interpreter& other)
{
    if (this != &other)
    {
        copy(other);
    }
    return *this;
}

Interpreter::~Interpreter()
{
    deallocate();
}

void Interpreter::incrementValue()
{
    ++cells[currentCell];
}

void Interpreter::decrementValue()
{
    --cells[currentCell];
}

void Interpreter::incrementPointer()
{
    ++currentCell;
    if (currentCell > size - 1)
    {
        resize();
    }
}

void Interpreter::decrementPointer()
{
    keepPointerInBounds();
    --currentCell;
}

void Interpreter::print() const
{
    std::cout << cells[currentCell];
}

void Interpreter::read()
{
    std::cin >> cells[currentCell];
}

void Interpreter::executeCode()
{
    validateCode();
    std::ifstream file(fileName, std::ios::in);
    char operation{};
    while (file.good())
    {
        file.get(operation);
        size_t operationPosition = file.tellg().operator std::streamoff() - 1;
        executeOperation(operation, file);
    }
}


