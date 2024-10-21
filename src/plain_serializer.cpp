#include <fstream>
#include <plain_serializer.hpp>
#include <sstream>
#include <stdexcept>

namespace serializer {
    void plain_serializer::serialize(std::shared_ptr<serializable> obj)
    {
        if(obj == nullptr)
            throw std::runtime_error("Object passed to serializer is null");

        auto obj_tree = obj->serialize();
        
        std::ofstream file(file_location);
        file << obj_tree.serialize();
    }

    attribute_tree plain_serializer::try_deserialize()
    {
        std::ifstream file(file_location);
        std::stringstream ss;
        ss << file.rdbuf();

        return attribute_tree::deserialize(ss);
    }
}
