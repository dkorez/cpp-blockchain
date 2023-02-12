#ifndef CORE_BLOCKCHAIN_H_
#define CORE_BLOCKCHAIN_H_

#include <iostream>
#include <vector>
#include <memory>
#include "Block.h"
#include "../util/json.hpp"

using json = nlohmann::json;

class BlockChain {
private:
	//vector<unique_ptr<Block>> chain;
	vector<Block> chain;

	void createGenesisBlock();
public:
	BlockChain();
	Block* getLastBlock();
	void addBlock(Block block);

	string toString();
	json toJson();
};

#endif /* CORE_BLOCKCHAIN_H_ */
