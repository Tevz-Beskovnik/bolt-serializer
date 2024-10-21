#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_map>
#include <attribute_tree.hpp>
#include <serializable.hpp>
#include <iostream>
#include <string>

template<std::size_t N>
struct fixed_string
{
    char str[N];

    constexpr explicit fixed_string(const char (&s)[N])
    { 
        std::copy(str, std::end(str), s); 
    };
};

template<fixed_string attribute, auto field_address>
struct field
{
    template<typename T>
    static void try_from_json(T& obj, std::ifstream file)
    {
              
    }
};

int main()
{
    serializer::attribute_tree tree;

    tree["test"]["n1"] += "hello";
    tree["test"]["n2"] += " wrold";
    tree["test"]["n2"] += "bruhe";

    tree["bruh"]["nr"] += 3.14;

    tree["test"] += 5;

    std::cout << (tree["test"]["n1"].get_value<std::string>()) << (tree["test"]["n2"].get_value<std::string>()) << " " << tree["bruh"]["nr"].get_value<double>() << std::endl;

    std::cout << tree.serialize() << std::endl;
}
