#include "Cell.hpp"

Cell::Cell() : value(0)
{
}

Cell::Cell(short int _value) : value(_value)
{
}

short int Cell::getValue() const
{
    return value;
}

void Cell::setValue(short int _value)
{
    value = _value;
}

std::istream& operator>>(std::istream& istream, Cell& byte)
{
    unsigned char input;
    istream >> input;
    byte.setValue(input);
    return istream;
}

std::ostream& operator<<(std::ostream& ostream, const Cell& byte)
{
    return ostream << static_cast<unsigned char>(byte.getValue());
}

Cell operator+(const Cell& byte1, const Cell& byte2)
{
    return Cell(byte1.getValue() + byte2.getValue());
}

Cell operator-(const Cell& byte1, const Cell& byte2)
{
    return Cell(byte1.getValue() - byte2.getValue());
}

Cell& operator++(Cell& byte)
{
    byte = byte + Cell(1);
    return byte;
}

Cell& operator--(Cell& byte)
{
    byte = byte - Cell(1);
    return byte;
}

bool operator==(const Cell& byte1, const Cell& byte2)
{
    return byte1.getValue() == byte2.getValue();
}

bool operator!=(const Cell& byte1, const Cell& byte2)
{
    return byte1.getValue() != byte2.getValue();
}
