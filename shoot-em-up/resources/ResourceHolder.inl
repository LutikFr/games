template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id,
    const std::string& filename, const Parameter& second_param)
{
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename, second_param))
        throw std::runtime_error("ResourceHolder::load - Failed to 
        load " + filename);
    auto inserted = m_resource_map.insert(
        std::make_pair(id, std::move(resource))); 
    assert(inserted.second);
}

template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get
    (Identifier id) const
{
    auto found = m_texture_map.find(id);
    assert(found != m_texture_map.end());

    return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get
    (Identifier id) const
{
    auto found = m_texture_map.find(id);
    assert(found != m_texture_map.end());

    return *found->second;
}
