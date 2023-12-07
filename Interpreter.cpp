#include "Interpreter.hpp"

void Interpreter::keepPointerInBounds() const
{
    if (currentCell == 0)
    {
        throw std::out_of_range("The pointer went out of bounds!");
    }
}

void Interpreter::resize()
{
    Interpreter interpreter(size * 2);
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
    cells = new int[numberOfCells]{};
}

void Interpreter::copy(const int* otherCells, size_t otherSize)
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

Interpreter::Interpreter() : cells(new int[30000]{}), currentCell(0), size(30000)
{}

Interpreter::Interpreter(size_t _size) : cells(new int[_size]{}), currentCell(0), size(_size)
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
    --currentCell;
    keepPointerInBounds();
}

void Interpreter::print() const
{
    printf("%c", cells[currentCell]);
}

void Interpreter::read()
{
    scanf("%d", &cells[currentCell]);
}
