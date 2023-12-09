#include "Byte.hpp"

Byte::Byte() : value(0)
{}

Byte::Byte(unsigned char _value) : value(_value)
{}

unsigned char Byte::getValue() const
{
    return value;
}

void Byte::setValue(unsigned char _value)
{
    value = _value;
}

std::istream& operator>>(std::istream& istream, Byte& byte)
{
    unsigned char input;
    istream >> input;
    byte.setValue(input);
    return istream;
}

std::ostream& operator<<(std::ostream& ostream, const Byte& byte)
{
    return ostream << byte.getValue();
}

Byte operator+(const Byte& byte1, const Byte& byte2)
{
    return Byte(byte1.getValue() + byte2.getValue());
}

Byte operator-(const Byte& byte1, const Byte& byte2)
{
    return Byte(byte1.getValue() - byte2.getValue());
}

Byte& operator++(Byte& byte)
{
    byte = byte + Byte(1);
    return byte;
}

Byte& operator--(Byte& byte)
{
    byte = byte - Byte(1);
    return byte;
}

bool operator==(const Byte& byte1, const Byte& byte2)
{
    return byte1.getValue() == byte2.getValue();
}

bool operator!=(const Byte& byte1, const Byte& byte2)
{
    return byte1.getValue() != byte2.getValue();
}