#ifndef HEATWAVE_OBJMODEL_GAMEOBJECTFUNCTIONS_HPP
#define HEATWAVE_OBJMODEL_GAMEOBJECTFUNCTIONS_HPP

#include "Heatwave.hpp"
#include "GameObject.hpp"
#include "TypeRegistry.hpp"
#include "ObjectPool.hpp"

namespace hw {
namespace obj {

template<typename T>
Handle allocate()
{
	ObjectPool* pool = getTypePool(T::type);
	return allocate(pool);
}

template<typename T>
Handle allocate(ObjectPool* pool)
{
	Handle h;
	GameComponent* new_component = pool->allocate(h);

	new_component->type = T::type;

	return h;
}

inline bool isHandleNull(const Handle& h)
{
	return h.pool_index == 0xFFFF;
}

template<typename T>
bool isHandleValid(const Handle& h)
{
	ObjectPool* pool = getTypePool(T::type);
	return isHandleValid(h, pool);
}

inline bool isHandleValid(const Handle& h, const ObjectPool* pool)
{
#if DBG_CHECKED_HANDLES
	if (h.pool != pool)
		return false;
#endif
	return pool->index(h.pool_index)->generation == h.generation;
}

template<typename T>
T* resolveHandle(const Handle& h)
{
	ObjectPool* pool = getTypePool(T::type);
	return resolveHandle(h, pool);
}

template<typename T>
T* resolveHandle(const Handle& h, const ObjectPool* pool)
{
	HW_ASSERT(isHandleValid(h, pool), "Tried to resolved invalid handle.");

	return pool->pool[h.pool_index].generation == h.generation;
}

}
}

#endif // HEATWAVE_OBJMODEL_GAMEOBJECTFUNCTIONS_HPP
