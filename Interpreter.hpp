#ifndef BRAINFUCKINTERPRETER_INTERPRETER_HPP
#define BRAINFUCKINTERPRETER_INTERPRETER_HPP

#include <fstream>
#include <cstdio>
#include <limits>
#include <exception>

class Interpreter
{
private:
    int* cells;
    unsigned int currentCell;
    size_t size;

    void keepPointerInBounds() const;

    void resize();

    void deallocate();

    void allocate(size_t numberOfCells);

    void copy(const int* otherCells, size_t otherSize);

    void copy(const Interpreter& other);

public:
    Interpreter();

    explicit Interpreter(size_t _size);

    Interpreter(const Interpreter& other);

    Interpreter& operator=(const Interpreter& other);

    ~Interpreter();

    void incrementValue();

    void decrementValue();

    void incrementPointer();

    void decrementPointer();

    void print() const;

    void read();
};

#endif //BRAINFUCKINTERPRETER_INTERPRETER_HPP
