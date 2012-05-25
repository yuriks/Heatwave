#include "Heatwave.hpp"

#include <cstddef>

namespace hw {
namespace memory {

template<typename T>
class PoolAllocator {
	static_assert(sizeof(T) >= sizeof(u16), "sizeof(T) needs to be at least sizeof(u16).");

	u16& id_at_index(u16 i)
	{
		return *reinterpret_cast<u16*>(&memory[i]);
	}

public:
	PoolAllocator(T* memory_area, u16 num_items) :
		memory(memory_area),
		num_items(num_items),
		next_free_obj(0)
	{
		for (u16 i = 0; i < num_items; ++i) {
			id_at_index(i) = i+1;
		}
	}

	u16 allocate()
	{
		u16 new_obj_id = next_free_obj;
#if DBG_CHECKED_ALLOCATORS
		HW_ASSERT(new_obj_id < num_items, "Pool allocator full.");
#endif

		next_free_obj = id_at_index(new_obj_id);

		return new_obj_id;
	}

	void free(u16 id)
	{
		HW_DBG_ASSERT(id < num_items/*, "Tried to free invalid pool item."*/);

		id_at_index(id) = next_free_obj;
		next_free_obj = id;
	}

	T& operator[] (u16 id)
	{
		HW_DBG_ASSERT(id < num_items/*, "Out of bounds pool access."*/);
		return memory[id];
	}

private:
	T *const memory;
	const u16 num_items;
	u16 next_free_obj;
};

}
}
