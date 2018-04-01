#include "world.h"


namespace lithe {
    world::world(
        lithe::container* container_,
        lithe::uid_manager* uids_
    ):
        container(container_),
        uids(uids_)
    {

    }


    void world::delete_system(lithe::system* sys) {
        systems.erase(std::find(systems.begin(), systems.end(), sys));
    }


    lithe::entity world::create_entity() {
        auto id = uids->withdraw();
        entities.insert(id);
        return {id, *container};
    }


    void world::delete_entity(const lithe::entity& entity) {
        uids->deposit(entity.uid);
        entities.erase(entity.uid);
    }


    void world::update() {
        for (const auto& entity: entities) {
            const lithe::metadata& meta = container->get<lithe::metadata>(entity);

            for (const auto& sys: systems) {
                if (lithe::compare_bitmasks(meta.tag, sys->tag))
                    sys->update_entities(entity, *container);
            }
        }
    }
}