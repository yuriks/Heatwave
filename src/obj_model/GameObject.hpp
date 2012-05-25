#ifndef HEATWAVE_OBJMODEL_GAMEOBJECT_HPP
#define HEATWAVE_OBJMODEL_GAMEOBJECT_HPP

#include "Heatwave.hpp"

namespace hw {
namespace obj {

class ObjectPool;

typedef u16 Type;

// GameComponent handle
struct Handle {
	u16 pool_index;
	u16 generation;
#ifdef DBG_CHECKED_HANDLES
	ObjectPool* pool;
#endif
};

struct GameComponent {
	u16 roster_index;
	u16 generation;
	Type type;
};

struct GameObject {
	Handle components;
};

}
}

#endif // HEATWAVE_OBJMODEL_GAMEOBJECT_HPP
