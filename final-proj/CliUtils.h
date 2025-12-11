#ifndef CLI_UTILS_H
#define CLI_UTILS_H

#include <iostream>
#include <string>
#include "Color.h"

namespace CliUtils
{

    // Prints an error message in red to std::cerr
    inline void printError(const std::string &message)
    {
        std::cerr << Color::FG::RED << message << Color::RESET << std::endl;
    }

    // Prints an instructional message in blue to std::cout
    inline void printInstruction(const std::string &message)
    {
        std::cout << Color::FG::BLUE << message << Color::RESET << std::endl;
    }

    // Prints a success message in green to std::cout
    inline void printSuccess(const std::string &message)
    {
        std::cout << Color::FG::GREEN << message << Color::RESET << std::endl;
    }

    // Prints a general message to std::cout
    inline void printMessage(const std::string &message)
    {
        std::cout << message << std::endl;
    }

    // Prints a message in bold to std::cout
    inline void printBold(const std::string &message)
    {
        std::cout << Color::BOLD << message << Color::RESET << std::endl;
    }
}

#endif // CLI_UTILS_H
