#include <cstdint>
#include <lexer.hpp>

#define TERMINATION_TOKEN(num, token) case num: \
    { \
        token_ref = token; \
        return true; \
    }

#define MAPPING(symbol, from, to) mappings[(size_t)symbol][from] = to

#define TOKEN_L_SQUIG { TokenType::L_SQUIG, "{" }
#define TOKEN_R_SQUIG token{ TokenType::R_SQUIG, "}" }
#define TOKEN_EQ token{ TokenType::EQ, "=" }
#define TOKEN_COMM token{ TokenType::COMM, "," }
#define TOKEN_WORD(value) token{ TokenType::WORD, value }
#define TOKEN_STRING(value) token{ TokenType::STRING, value }

namespace serializer
{
    int32_t mappings[9][13];

    inline void init_mappings()
    {
        // Zero mappings
        MAPPING(SymbolType::L_SQUIG, 0, 1);
        MAPPING(SymbolType::R_SQUIG, 0, 2);
        MAPPING(SymbolType::EQUAL, 0, 3);
        MAPPING(SymbolType::COMMA, 0, 4);
        MAPPING(SymbolType::LETTER, 0, 5);
        MAPPING(SymbolType::QUOTE, 0, 8);
        
        MAPPING(SymbolType::LETTER, 5, 6);
        MAPPING(SymbolType::NUMBER, 5, 7);

        // Strings - any letter
        MAPPING(SymbolType::LETTER, 8, 9);
        MAPPING(SymbolType::NUMBER, 8, 10);
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
            TERMINATION_TOKEN(12, TOKEN_STRING(val))
            default:
                return false;
        }
    }
}
