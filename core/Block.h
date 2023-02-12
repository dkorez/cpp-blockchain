#ifndef CORE_BLOCK_H_
#define CORE_BLOCK_H_

#include "BlockHeader.h"
#include "BlockData.h"
#include "../util/json.hpp"

using json = nlohmann::json;

class Block {
	BlockHeader header;
	BlockData data;
public:
	Block(BlockHeader header, BlockData data);
	BlockHeader getBlockHeader();
	BlockData getBlockData();

	bool isValidBlock(Block *previous);

	string toString();
	json toJson();
};

#endif /* CORE_BLOCK_H_ */
