#include "Miner.h"
#include "../util/hash.h"

Miner::Miner() {

}

Block Miner::mineBlock(BlockChain *chain, string data) {
	Block *lastBlock = chain->getLastBlock();

	unsigned long blockNumber = lastBlock->getBlockHeader().getBlockNumber() + 1;
	string lastHash = lastBlock->getBlockHeader().getBlockHash();
	time_t timestamp = time(0);

	unsigned long difficulty = calculateDifficulty(lastBlock->getBlockHeader().getDifficulty(),
				lastBlock->getBlockHeader().getTimestamp());
	unsigned long nonce = 0;

	BlockData newData(data);

	string dataToHash = prepareRawData(blockNumber, timestamp, lastHash, newData.getDataHash(), nonce, difficulty);
	string blockHash = generateHash(dataToHash);

	// blockHash must start with n amount of zeros (n = difficulty)
	// we are comparing hash in binary form for more accurate data
	string hashStart(difficulty, '0');
	string binaryHash = hexToBinary(blockHash);
	while(binaryHash.substr(0, difficulty) != hashStart) {
		nonce++;
		timestamp = time(0);

		dataToHash = prepareRawData(blockNumber, timestamp, lastHash, newData.getDataHash(), nonce, difficulty);
		blockHash = generateHash(dataToHash);
		binaryHash = hexToBinary(blockHash);
	}

	BlockHeader newHeader(blockNumber, nonce, difficulty, timestamp, blockHash, lastHash);
	Block newBlock(newHeader, newData);

	return newBlock;
}

unsigned long Miner::calculateDifficulty(unsigned long lastDiff, time_t lastTime) {
	const auto cLastTime =  chrono::system_clock::from_time_t(lastTime);
	chrono::duration<double> cDiffSec = chrono::system_clock::now() - cLastTime;
	double diffSec = cDiffSec.count();

	if(diffSec < Miner::MINE_RATE) {
		return lastDiff + 1;
	}

	if ((lastDiff - 1) > 0) {
		return lastDiff - 1;
	}

	return 1;
}
