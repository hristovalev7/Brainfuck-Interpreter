#ifndef BRAINFUCKINTERPRETER_BYTE_HPP
#define BRAINFUCKINTERPRETER_BYTE_HPP

#include <iostream>

class Cell
{
private:
    short int value;

public:
    Cell();

    explicit Cell(short int _value);

    void setValue(short int _value);

    [[nodiscard]] short int getValue() const;
};

std::istream& operator>>(std::istream& istream, Cell& byte);

std::ostream& operator<<(std::ostream& ostream, const Cell& byte);

Cell operator+(const Cell& byte1, const Cell& byte2);

Cell operator-(const Cell& byte1, const Cell& byte2);

Cell& operator++(Cell& byte);

Cell& operator--(Cell& byte);

bool operator==(const Cell& byte1, const Cell& byte2);

bool operator!=(const Cell& byte1, const Cell& byte2);

#endif //BRAINFUCKINTERPRETER_BYTE_HPP
