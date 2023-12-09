#ifndef BRAINFUCKINTERPRETER_INTERPRETER_HPP
#define BRAINFUCKINTERPRETER_INTERPRETER_HPP

#include <fstream>
#include <iostream>
#include <limits>
#include <exception>
#include <unordered_map>
#include <queue>
#include <stack>
#include "Byte.hpp"

class Interpreter
{
private:
    std::string fileName{};
    Byte* cells;
    unsigned int currentCell;
    size_t size;
    std::unordered_map<size_t, size_t> leftBrackets;
    std::unordered_map<size_t, size_t> rightBrackets;

    void validateCode();

    void executeOperation(char operation, std::ifstream& ifstream);

    void keepPointerInBounds() const;

    void resize();

    void deallocate();

    void allocate(size_t numberOfCells);

    void copy(const Byte* otherCells, size_t otherSize);

    void copy(const Interpreter& other);

public:
    Interpreter();

    explicit Interpreter(const std::string& _fileName, size_t _size);

    Interpreter(const Interpreter& other);

    Interpreter& operator=(const Interpreter& other);

    ~Interpreter();

    void incrementValue();

    void decrementValue();

    void incrementPointer();

    void decrementPointer();

    void print() const;

    void read();

    void executeCode();
};

#endif //BRAINFUCKINTERPRETER_INTERPRETER_HPP
