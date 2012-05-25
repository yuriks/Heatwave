#include "Heatwave.hpp"
#include "Chain.hpp"

namespace hw {
namespace obj {

struct Chain {
	static const int CHAIN_LINK_SIZE = 10;

	Handle handles[CHAIN_LINK_SIZE];
	Type types[CHAIN_LINK_SIZE];

	// Next link's id in the chain, else 0xFFFF
	ChainId next_link;
	// Index of the first free component entry in the array
	// If 0xFF, link slot is free and next_link points to next free slot
	u8 free_index;

	u8 pad;
};

static const int MAX_CHAIN_LINKS = 256;
static Chain chain_links[MAX_CHAIN_LINKS];
static ChainId next_free_link = 0;

void initializeChainPool()
{
	for (int i = 0; i < MAX_CHAIN_LINKS; ++i) {
		chain_links[i].free_index = 0xFF;
		chain_links[i].next_link = i+1;
	}
}

ChainId allocateChain()
{
	ChainId new_link_id = next_free_link;
	HW_ASSERT(new_link_id < MAX_CHAIN_LINKS, "Chain link pool full.");

	Chain& new_link = chain_links[new_link_id];
	next_free_link = new_link.next_link;
	new_link.next_link = 0xFFFF;
	new_link.free_index = 0;

	return new_link_id;
}

void freeChain(ChainId id)
{
	HW_ASSERT(id < MAX_CHAIN_LINKS, "Tried to free invalid chain.");

	// Walk the chain freeing all links
	while (id != 0xFFFF) {
		ChainId next_link = chain_links[id].next_link;

		chain_links[id].free_index = 0xFF;
		chain_links[id].next_link = next_free_link;
		next_free_link = id;

		id = next_link;
	}
}

void addToChain(const Handle& h, Type h_type, ChainId chain_id)
{
	HW_ASSERT(chain_id < MAX_CHAIN_LINKS, "Invalid chain id.");

	Chain& chain = chain_links[chain_id];
	int free_i = chain.free_index;
	HW_ASSERT(free_i != 0xFF, "Invalid chain.");

	if (free_i < Chain::CHAIN_LINK_SIZE) {
		chain.handles[free_i] = h;
		chain.types[free_i] = h_type;
		chain.free_index += 1;
	} else {
		ChainId new_link_id = allocateChain();
		chain.next_link = new_link_id;
		addToChain(h, h_type, new_link_id);
	}
}

void removeFromChain(const Handle& h, Type h_type, ChainId chain_id)
{
	HW_ASSERT(chain_id < MAX_CHAIN_LINKS, "Invalid chain id.");

	while (chain_id != 0xFFFF) {
		Chain& chain = chain_links[chain_id];

		int free_i = chain.free_index;
		for (int i = 0; i < free_i; ++i) {
			if (chain.types[i] == h_type && chain.handles[i] == h) {
				// Found it
				chain.handles[i] = chain.handles[free_i-1];
				chain.types[i] = chain.types[free_i-1];
				chain.free_index -= 1;
				return;
			}
		}

		chain_id = chain.next_link;
	}
}

}
}
