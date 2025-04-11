#include <map>
#include <memory>
#include <SFML/Graphics.hpp>
#include <string>

template <typename Resource, typename Identifier>
class ResoureHolder
{
    public:
        void                load(Identifier id,
                                const std::string& filename);
       Resource&            get(Identifier id) const;
       const Resource&      get(Identifier id) const;

    private:
        std::map <Identifier,
            std::unique_ptr <Resource> m_resource_map;
};

#include "ResourceHolder.inl"
