/*
* This file containes the base interface for the serializer
* The functions in this interface should generate the attribute tree
* structure, or altirnitevly convert it and write it to the desired file
* */

#pragma once

#include "serializable.hpp"
#include <attribute_tree.hpp>
#include <fstream>
#include <string>
#include <memory>

namespace serializer
{
    class base_serializer
    {
    public:
        virtual void serialize(std::shared_ptr<serializable> obj) = 0; 

        virtual attribute_tree try_deserialize() = 0;

        void set_file_location(std::string file_location)
        {
            this->file_location = file_location;
        }

    protected:
        std::string file_location;
        std::fstream file;
    };
}

