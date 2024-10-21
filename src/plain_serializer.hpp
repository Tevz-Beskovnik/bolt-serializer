#include "serializable.hpp"
#include <memory>
#include <serializer.hpp>

namespace serializer 
{
    class plain_serializer : public base_serializer
    {
        plain_serializer();

        void serialize(std::shared_ptr<serializable> obj) override;

        attribute_tree try_deserialize() override;
    };
}
