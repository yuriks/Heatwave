#include "Heatwave.hpp"
#include "ObjectPool.hpp"

#include "GameObjectFunctions.hpp"

namespace hw {
namespace obj {

// roster_memory should have a length of pool_size entries
// pool_memory should be at least instance_size*pool_size bytes
ObjectPool::ObjectPool(size_t instance_size, u16 pool_size, u16* roster_memory, u8* pool_memory) :
	instance_size(instance_size),
	pool_size(pool_size),
	roster(roster_memory),
	pool(pool_memory),
	partition(0)
{
	for (u16 i = 0; i < pool_size; ++i) {
		roster_memory[i] = i;
	}
	for (u8* p = pool_memory; p != pool_memory + instance_size*pool_size; p += instance_size) {
		reinterpret_cast<GameComponent*>(p)->generation = 0;
	}
}

GameComponent* ObjectPool::allocate(Handle& h)
{
	HW_ASSERT(partition < pool_size, "Component pool full.");

	int pool_index = roster[partition];
	GameComponent* new_component = index(pool_index);
	new_component->roster_index = partition;

	partition += 1;

	h.generation = new_component->generation;
	h.pool_index = pool_index;
#if DBG_CHECKED_HANDLES
	h.pool = this;
#endif

	return new_component;
}

void ObjectPool::free(const Handle& h)
{
	HW_ASSERT(isHandleValid(h, this), "Tried to free invalid handle.");

	GameComponent* component = index(h.pool_index);
	component->generation += 1;
	u16 roster_index = component->roster_index;
	partition -= 1;
	std::swap(roster[roster_index], roster[partition]);
}

}
}
