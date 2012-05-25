#ifndef HEATWAVE_OBJMODEL_GAMEOBJECT_HPP
#define HEATWAVE_OBJMODEL_GAMEOBJECT_HPP

#include "Heatwave.hpp"

namespace hw {
namespace obj {

#ifdef DBG_CHECKED_HANDLES
class ObjectPool;
#endif

typedef u16 Type;

// GameComponent handle
struct Handle {
	u16 pool_index;
	u16 generation;
#ifdef DBG_CHECKED_HANDLES
	ObjectPool* pool;
#endif
};

inline bool operator== (const Handle& a, const Handle& b) {
	return a.pool_index == b.pool_index && a.generation == b.generation;
}

struct GameComponent {
	u16 roster_index;
	u16 generation;
	Type type;
};

}
}

#endif // HEATWAVE_OBJMODEL_GAMEOBJECT_HPP
