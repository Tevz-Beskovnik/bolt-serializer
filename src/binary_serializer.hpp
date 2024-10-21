#include "serializable.hpp"
#include <memory>
#include <serializer.hpp>

namespace serializer
{
    class binary_serializer : public base_serializer
    {
        void serialize(std::shared_ptr<serializable> obj) override;

        attribute_tree try_deserialize() override;
    };
}
