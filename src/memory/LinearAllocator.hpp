#ifndef HEATWAVE_MEMORY_LINEARALLOCATOR_HPP
#define HEATWAVE_MEMORY_LINEARALLOCATOR_HPP

#include "Heatwave.hpp"

#include <cstddef>

namespace hw {
namespace memory {

class LinearAllocator {
public:
	LinearAllocator(u8* memory_area, size_t max_size) :
		memory_start(memory_area),
		memory_cur(memory_area),
		max_size(max_size)
	{
	}

	u8* allocate(size_t size) {
		u8* p = memory_cur;
#ifdef DBG_CHECKED_ALLOCATORS
		HW_DBG_ASSERT(p < memory_start + max_size);
#endif
		memory_cur += size;
		return p;
	}

	u8* rewind() {
		memory_cur = memory_start;
	}

private:
	u8 *const memory_start;
	u8* memory_cur;
	const size_t max_size;
};

}
}

#endif // HEATWAVE_MEMORY_LINEARALLOCATOR_HPP
