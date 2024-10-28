#pragma once
#include <attribute_tree.hpp>
#include <cstddef>
#include <cstdint>
#include <sstream>
#include <string>

namespace serializer
{
    enum class TokenType
    {
        L_SQUIG = 0,
        R_SQUIG = 1,
        EQ = 2,
        COMM = 3,
        WORD = 4,
        STRING = 5,
    };

    enum class SymbolType : size_t
    {
        L_SQUIG = 0,
        R_SQUIG = 1,
        EQUAL = 2,
        COMMA = 3,
        QUOTE = 4,
        NUMBER = 5,
        LETTER = 6,
        BACK_SLASH = 7,
        OTHER_SYMB = 8,
    };

    struct mapping {
        SymbolType symbol;
        uint32_t from;
        int32_t to;
    };

    struct token {
        TokenType type;
        std::string value;
    };

    void init_mappings();

    attribute_tree parse(std::stringstream& ss);
}
