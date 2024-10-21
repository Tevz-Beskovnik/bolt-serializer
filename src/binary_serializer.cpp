#include <binary_serializer.hpp>

namespace serializer {
    void binary_serializer::serialize(std::shared_ptr<serializable> obj)
    {

    }

    attribute_tree binary_serializer::try_deserialize()
    {
        return attribute_tree();
    }
}
