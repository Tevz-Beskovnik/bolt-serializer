#include <algorithm>
#include <attribute_tree.hpp>
#include <sstream>
#include <stdexcept>
#include <string>
#include <strstream>

namespace serializer
{

template<typename T>
T attribute_tree::operator[](size_t id)
{
    if(values.size() > id)
        return values[id];

    values.push_back("");
    return values[values.size()-1];
}

template<>
int attribute_tree::operator[](size_t id)
{
    if(values.size() > id)
        return std::stoi(values[id]);

    values.push_back("0");
    return std::stoi(values[values.size() - 1]);
}

template<>
double attribute_tree::operator[](size_t id)
{
    if(values.size() > id)
        return std::stod(values[id]);

    values.push_back(std::to_string((double)0.0));
    return std::stod(values[values.size() - 1]);
}

template<>
float attribute_tree::operator[](size_t id)
{
    if(values.size() > id)
        return std::stof(values[id]);

    values.push_back(std::to_string((float)0.0f));
    return std::stof(values[values.size() - 1]);
}

attribute_tree& attribute_tree::operator[](const std::string& key)
{
    if(id_map.find(key) != id_map.end())
        return attributes[id_map[key]];

    id_map[key] = attributes.size();
    attributes.push_back(attribute_tree());
    return attributes[id_map[key]];
}

void attribute_tree::operator+=(std::string value)
{
    values.push_back(value);
}

void attribute_tree::operator+=(int value)
{
    values.push_back(std::to_string(value));
}

void attribute_tree::operator+=(float value)
{
    values.push_back(std::to_string(value));
}

void attribute_tree::operator+=(double value)
{
    values.push_back(std::to_string(value));
}

template<typename T>
T attribute_tree::get_value()
{
    if(values.size() > 0)
        return values[0];

    values.push_back("");
    return values[0];
}

template <>
std::string attribute_tree::get_value()
{
    if(values.size() > 0)
        return values[0];

    values.push_back("");
    return values[0];
}
    
template<>
int attribute_tree::get_value()
{
    if(values.size() > 0)
        return std::stoi(values[0]);

    values.push_back("0");
    return std::stoi(values[0]);
}

template<>
double attribute_tree::get_value()
{
    if(values.size() > 0)
        return std::stod(values[0]);

    values.push_back("0.0");
    return std::stod(values[0]);
}

template<>
float attribute_tree::get_value()
{
    if(values.size() > 0)
        return std::stof(values[0]);

    values.push_back("0.0");
    return std::stof(values[0]);
}

std::string attribute_tree::serialize()
{
    std::stringstream values_str;

    if(values.size() > 0)
    {
        values_str << "\"" << values[0] << "\"";
        
        std::for_each(values.begin() + 1, values.end(), [&values_str = values_str](const std::string& val){
            values_str << ",\"" << val << "\"";
        });
        
        values_str << "\n";
    }

    if(id_map.size() > 0)
    {
        values_str << "{\n";

        std::for_each(id_map.begin(), id_map.end(), [&values_str = values_str, this](const std::pair<std::string, size_t>& val){
             values_str << val.first << "=" << attributes[val.second].serialize();
        });
        values_str << "}\n";
    }
    
    return values_str.str();
}

void check_next_and_remove(std::stringstream& input, char next)
{
    if(input.peek() != next)
        throw std::runtime_error("Invalid character in next position of string");

    input >> next;
}

attribute_tree attribute_tree::deserialize(std::stringstream& input)
{
    char trash;
    std::string trash_str;
    attribute_tree tree;
    if(input.peek() == '"')
    {
        std::string value;
        input >> trash;
        std::getline(input, value, '"');
        tree += value;

        check_next_and_remove(input, '"');
        while(input.peek() == ',')
        {
            input >> trash;
            check_next_and_remove(input, '"');
            std::getline(input, value, '"');
            tree += value;

            check_next_and_remove(input, '"');
        }
    }
    else if(input.peek() == '{')
    {
         
    }
}

}
