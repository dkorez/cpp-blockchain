#include "BlockHeader.h"
#include <sstream>

BlockHeader::BlockHeader(unsigned long blockNumber, unsigned long nonce, unsigned long difficulty, time_t timeStamp, string blockHash, string lastHash) {
	this->blockNumber = blockNumber;
	this->nonce = nonce;
	this->difficulty = difficulty;
	this->timestamp = timeStamp;

	this->blockHash = blockHash;
	this->lastHash = lastHash;
}

unsigned long BlockHeader::getBlockNumber() {
	return this->blockNumber;
}

unsigned long BlockHeader::getNonce() {
	return this->nonce;
}

unsigned long BlockHeader::getDifficulty() {
	return this->difficulty;
}

time_t BlockHeader::getTimestamp() {
	return this->timestamp;
}

string BlockHeader::getLastHash() {
	return this->lastHash;
}

string BlockHeader::getBlockHash() {
	return this->blockHash;
}

string BlockHeader::toString() {
	stringstream ss;
	ss << "[blockNumber: " << this->blockNumber << ", "
			<< "timestamp: " << this->timestamp << ", "
			<< "nonce: " << this->nonce << ", "
			<< "difficulty: " << this->difficulty << ", "
			<< "blockHash: " << this->blockHash << ", "
			<< "lastHash: " << this->lastHash << "]" << endl;

	return ss.str();
}

json BlockHeader::toJson() {
	json obj;
	obj["blockNumber"] = this->blockNumber;
	obj["timestamp"] = this->timestamp;
	obj["nonce"] = this->nonce;
	obj["difficulty"] = this->difficulty;
	obj["blockHash"] = this->blockHash;
	obj["lastHash"] = this->lastHash;

	return obj;
}
