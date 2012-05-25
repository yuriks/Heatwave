#ifndef HEATWAVE_OBJMODEL_OBJECTPOOL_HPP
#define HEATWAVE_OBJMODEL_OBJECTPOOL_HPP

#include "Heatwave.hpp"
#include "GameObject.hpp"
#include <limits>
#include <algorithm>

namespace hw {
namespace obj {

class ObjectPool {
public:
	// roster_memory should have a length of pool_size entries
	// pool_memory should be at least instance_size*pool_size bytes
	ObjectPool(size_t instance_size, u16 pool_size, u16* roster_memory, u8* pool_memory);

	GameComponent* allocate(Handle& h);
	void free(const Handle& h);

	inline GameComponent* index(u16 i) const {
		HW_DBG_ASSERT(i < pool_size);
		return reinterpret_cast<GameComponent*>(pool + i * instance_size);
	}

	u16 *const roster;
	u8 *const pool;

	const size_t instance_size;
	const u16 pool_size;

	u16 partition;
};

}
}

#endif // HEATWAVE_OBJMODEL_OBJECTPOOL_HPP
