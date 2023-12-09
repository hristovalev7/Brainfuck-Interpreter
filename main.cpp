#include "Interpreter.hpp"

int main()
{
    std::string file;
    std::cout << "File to interpret: ";
    std::cin >> file;
    Interpreter interpreter(file, 30000);
    interpreter.executeCode();
    return 0;
}
