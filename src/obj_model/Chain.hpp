#pragma once

#include "Heatwave.hpp"
#include "GameObject.hpp"

namespace hw {
namespace obj {

typedef u16 ChainId;

void initializeChainPool();
ChainId allocateChain();
void freeChain(ChainId id);
void addToChain(const Handle& h, Type h_type, ChainId chain_id);
void removeFromChain(const Handle& h, Type h_type, ChainId chain_id);

}
}
