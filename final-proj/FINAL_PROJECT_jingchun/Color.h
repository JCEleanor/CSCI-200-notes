#ifndef COLOR_H
#define COLOR_H

#include <string>

// This namespace holds the ANSI escape codes for styling terminal output.
namespace Color
{
    const std::string RESET = "\033[0m";
    const std::string BOLD = "\033[1m";
    const std::string UNDERLINE = "\033[4m";

    //  Foreground (Text) Colors
    namespace FG
    {
        const std::string BLACK = "\033[30m";
        const std::string RED = "\033[31m";
        const std::string GREEN = "\033[32m";
        const std::string YELLOW = "\033[33m";
        const std::string BLUE = "\033[34m";
        const std::string MAGENTA = "\033[35m";
        const std::string CYAN = "\03d[36m";
        const std::string WHITE = "\033[37m";
        const std::string DEFAULT = "\033[39m";

        // Bright Colors
        const std::string BRIGHT_RED = "\033[91m";
        const std::string BRIGHT_GREEN = "\033[92m";
        const std::string BRIGHT_YELLOW = "\033[93m";
        const std::string BRIGHT_BLUE = "\033[94m";
    }

    //  Background Colors
    namespace BG
    {
        const std::string BLACK = "\033[40m";
        const std::string RED = "\033[41m";
        const std::string GREEN = "\033[42m";
        const std::string YELLOW = "\033[43m";
        const std::string BLUE = "\033[44m";
        const std::string DEFAULT = "\033[49m";
    }
}

#endif
