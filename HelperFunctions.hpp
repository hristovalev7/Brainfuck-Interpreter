#ifndef BRAINFUCKINTERPRETER_HELPERFUNCTIONS_HPP
#define BRAINFUCKINTERPRETER_HELPERFUNCTIONS_HPP

#include <fstream>

bool isOperation(char character);

void ensureFileIsOpen(std::ifstream& file);

void ensureFileIsOpen(std::ofstream& file);

#endif //BRAINFUCKINTERPRETER_HELPERFUNCTIONS_HPP
