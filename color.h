#include <ostream>

namespace Color
{
    enum Code
    {
        // foreground
        FG_RED = 31,
        FG_GREEN = 32,
        FG_YELLOW = 33,
        FG_BLUE = 34,
        FG_MAGENTA = 35,
        FG_CYAN = 36,
        FG_LIGHT_GRAY = 37,
        FG_LIGHT_GREY = 37,
        FG_DEFAULT = 39,

        FG_DARK_GRAY = 90,
        FG_DARK_GREY = 90,
        FG_LIGHT_RED = 91,
        FG_LIGHT_GREEN = 92,
        FG_LIGHT_YELLOW = 93,
        FG_LIGHT_BLUE = 94,
        FG_LIGHT_MAGENTA = 95,
        FG_LIGHT_CYAN = 96,
        FG_WHITE = 97,

        // background
        BG_RED = 41,
        BG_GREEN = 42,
        BG_YELLOW = 43,
        BG_BLUE = 44,
        BG_MAGENTA = 45,
        BG_CYAN = 46,
        BG_LIGHT_GRAY = 47,
        BG_LIGHT_GREY = 47,
        BG_DEFAULT = 49,

        BG_DARK_GRAY = 100,
        BG_DARK_GREY = 100,
        BG_LIGHT_RED = 101,
        BG_LIGHT_GREEN = 102,
        BG_LIGHT_YELLOW = 103,
        BG_LIGHT_BLUE = 104,
        BG_LIGHT_MAGENTA = 105,
        BG_LIGHT_CYAN = 106,
        BG_WHITE = 107,

        // formatting
        BOLD = 1,
        DIM = 2,
        UNDERLINED = 4,
        BLINK = 5,
        INVERTED = 7,
        HIDDEN = 8,

        RESET = 0,
        RESET_BOLD = 21,
        RESET_DIM = 22,
        RESET_UNDERLINED = 24,
        RESET_BLINK = 25,
        RESET_INVERTED = 27,
        RESET_HIDDEN = 28,
    };

    class Modifier {
        Code code;

    public:
        Modifier(Code code) {
            this->code = code;
        }

        friend std::ostream& operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }

        std::string toUnixColor()
        {
            return "\033[" + std::to_string(code) + "m";
        }
    };
};
