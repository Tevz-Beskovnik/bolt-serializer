#pragma once

#include <cstddef>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace serializer 
{

struct attribute_tree
{
    template<typename T>
    T operator[](size_t id);

    template<>
    int operator[](size_t id);

    template<>
    double operator[](size_t id);

    template<>
    float operator[](size_t id);

    template<typename T>
    T get_value();
   
    template<>
    std::string get_value();

    template<>
    int get_value();

    template<>
    double get_value();

    template<>
    float get_value();

    attribute_tree& operator[](const std::string& key);

    void operator+=(std::string value);

    void operator+=(int value);

    void operator+=(float value);

    void operator+=(double value);

    std::string serialize();

    static attribute_tree deserialize(std::stringstream& input);

    std::unordered_map<std::string, size_t> id_map; 
    std::vector<attribute_tree> attributes;

    std::vector<std::string> values;
};
}
