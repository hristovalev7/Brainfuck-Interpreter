#ifndef BRAINFUCKINTERPRETER_BYTE_HPP
#define BRAINFUCKINTERPRETER_BYTE_HPP

#include <iostream>

class Byte
{
private:
    unsigned char value;

public:
    Byte();

    explicit Byte(unsigned char _value);

    void setValue(unsigned char _value);

    [[nodiscard]] unsigned char getValue() const;
};

std::istream& operator>>(std::istream& istream, Byte& byte);

std::ostream& operator<<(std::ostream& ostream, const Byte& byte);

Byte operator+(const Byte& byte1, const Byte& byte2);

Byte operator-(const Byte& byte1, const Byte& byte2);

Byte& operator++(Byte& byte);

Byte& operator--(Byte& byte);

bool operator==(const Byte& byte1, const Byte& byte2);

bool operator!=(const Byte& byte1, const Byte& byte2);

#endif //BRAINFUCKINTERPRETER_BYTE_HPP
