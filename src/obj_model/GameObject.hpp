#ifndef HEATWAVE_OBJMODEL_GAMEOBJECT_HPP
#define HEATWAVE_OBJMODEL_GAMEOBJECT_HPP

#include "Heatwave.hpp"

namespace hw {
namespace obj {

typedef u16 Type;

// GameComponent handle
struct Handle {
	u16 pool_index;
	u16 generation;
#ifdef DBG_CHECKED_HANDLES
	Type type;
#endif
};

struct GameComponent {
	u16 roster_index;
	u16 generation;
};

struct GameObject {
	Handle components;
};

template<typename T>
T* allocate()
{

}

template<typename T>
T* resolveHandle(Handle h);

}
}

#endif // HEATWAVE_OBJMODEL_GAMEOBJECT_HPP
