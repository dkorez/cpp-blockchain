#ifndef BLOCKHEADER_H_
#define BLOCKHEADER_H_

#include <iostream>
#include <ctime>
#include "../util/json.hpp"

using namespace std;
using json = nlohmann::json;

class BlockHeader {
private:
	unsigned long blockNumber;
	unsigned long nonce;
	unsigned long difficulty;
	time_t timestamp;

	string blockHash;
	string lastHash;
public:
	BlockHeader(unsigned long blockNumber, unsigned long nonce, unsigned long difficulty, time_t timeStamp, string hash, string lastHash);

	unsigned long getBlockNumber();
	unsigned long getNonce();
	unsigned long getDifficulty();
	time_t getTimestamp();
	string getBlockHash();
	string getLastHash();

	string toString();
	json toJson();
};

#endif /* BLOCKHEADER_H_ */
