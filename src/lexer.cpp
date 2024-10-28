#include <cstdint>
#include <lexer.hpp>

#define TERMINATION_TOKEN(num, token) case num: \
    { \
        token_ref = token; \
        return true; \
    }

#define MAP_MAX_NODES 22
#define MAP_MAX_SYMBOL_TYPES 9

#define MAPPING(symbol, from, to) mappings[(size_t)symbol][from] = to

#define _EXPAND(args) args
#define COND1(a) if(a)
#define OR_COND2(a, b) if(a || b)
#define OR_COND3(a, b, c) if(a || b || c)
#define OR_COND4(a, b, c, d) if(a || b || c || d)
#define GET_OR_COND(_1, _2, _3, _4, OR_CONDN, ...) OR_CONDN
#define OR_COND(...) 

#define TOKEN_L_SQUIG { TokenType::L_SQUIG, "{" }
#define TOKEN_R_SQUIG token{ TokenType::R_SQUIG, "}" }
#define TOKEN_EQ token{ TokenType::EQ, "=" }
#define TOKEN_COMM token{ TokenType::COMM, "," }
#define TOKEN_WORD(value) token{ TokenType::WORD, value }
#define TOKEN_STRING(value) token{ TokenType::STRING, value }

namespace serializer
{
    int32_t mappings[MAP_MAX_SYMBOL_TYPES][MAP_MAX_NODES];

    inline void init_mappings()
    {
        for(uint16_t i = 0; i < MAP_MAX_SYMBOL_TYPES; i++)
            for(uint16_t j = 0; j < MAP_MAX_NODES; j++)
                mappings[i][j] = -1;

        // Zero mappings
        MAPPING(SymbolType::L_SQUIG, 0, 1);
        MAPPING(SymbolType::R_SQUIG, 0, 2);
        MAPPING(SymbolType::EQUAL, 0, 3);
        MAPPING(SymbolType::COMMA, 0, 4);
        MAPPING(SymbolType::LETTER, 0, 5);
        MAPPING(SymbolType::QUOTE, 0, 8);
        
        MAPPING(SymbolType::LETTER, 5, 6);
        MAPPING(SymbolType::NUMBER, 5, 7);

        MAPPING(SymbolType::LETTER, 6, 6);
        MAPPING(SymbolType::NUMBER, 6, 7);
        MAPPING(SymbolType::NUMBER, 7, 7);
        MAPPING(SymbolType::LETTER, 7, 6);

        // And now for the loops
        for(uint16_t i = 8; i < 19; i++) 
        {
            // string mappings for any letter
            MAPPING(SymbolType::LETTER, i, 9);
            MAPPING(SymbolType::NUMBER, i, 10);
            // Mappings for all other characters excluding specail characters
            MAPPING(SymbolType::BACK_SLASH, i, 11);
            MAPPING(SymbolType::COMMA, i, 12);
            MAPPING(SymbolType::EQUAL, i, 13);
            MAPPING(SymbolType::L_SQUIG, i, 14);
            MAPPING(SymbolType::R_SQUIG, i, 15);
            MAPPING(SymbolType::OTHER_SYMB, i, 16);
        }

        MAPPING(SymbolType::LETTER, 11, -1);
        MAPPING(SymbolType::NUMBER, 11, -1);
        // Mappings for all other characters excluding specail characters
        MAPPING(SymbolType::BACK_SLASH, 11, -1);
        MAPPING(SymbolType::COMMA, 11, -1);
        MAPPING(SymbolType::EQUAL, 11, -1);
        MAPPING(SymbolType::L_SQUIG, 11, -1);
        MAPPING(SymbolType::R_SQUIG, 11, -1);
        MAPPING(SymbolType::OTHER_SYMB, 11, -1);
        // Special symbols
        MAPPING(SymbolType::QUOTE, 11, 17);
        MAPPING(SymbolType::BACK_SLASH, 11, 18);
        
        for(uint16_t i = 9; i < 19; i++)
        {
            MAPPING(SymbolType::QUOTE, 9, 19);
        }

        MAPPING(SymbolType::QUOTE, 11, -1);
    }

    SymbolType map_char_to_symbol(char next)
    {
        
    }

    attribute_tree parse(std::stringstream& ss)
    {

    }

    bool try_terminate(uint32_t state, std::string& val, token& token_ref)
    {
        switch(state) {
            TERMINATION_TOKEN(1, TOKEN_L_SQUIG)
            TERMINATION_TOKEN(2, TOKEN_R_SQUIG)
            TERMINATION_TOKEN(3, TOKEN_EQ)
            TERMINATION_TOKEN(4, TOKEN_COMM)
            TERMINATION_TOKEN(5, TOKEN_WORD(val))
            TERMINATION_TOKEN(6, TOKEN_WORD(val))
            TERMINATION_TOKEN(7, TOKEN_WORD(val))
            TERMINATION_TOKEN(19, TOKEN_STRING(val))
            default:
                return false;
        }
    }
}
