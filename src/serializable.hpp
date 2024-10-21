#pragma once

#include <attribute_tree.hpp>

namespace serializer
{
    class serializable
    {
    public:
        virtual void try_deserialize(attribute_tree& tree) = 0;

        virtual attribute_tree serialize() = 0;
    };
}

