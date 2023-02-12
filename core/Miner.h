#ifndef CORE_MINER_H_
#define CORE_MINER_H_

#include <iostream>
#include "BlockChain.h"

using namespace std;

class Miner {
private:
	unsigned long calculateDifficulty(unsigned long lastDiff, time_t lastTime);
public:
	Miner();
	Block mineBlock(BlockChain *chain, string data);

	//mine rate in seconds
	static const int MINE_RATE = 5;
};

#endif /* CORE_MINER_H_ */
