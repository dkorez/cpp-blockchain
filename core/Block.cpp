#include "Block.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include "../util/hash.h"

using namespace std;

Block::Block(BlockHeader header, BlockData data) :
		header(header), data(data) {
}

BlockHeader Block::getBlockHeader() {
	return header;
}

BlockData Block::getBlockData() {
	return data;
}

bool Block::isValidBlock(Block *previous) {
	BlockHeader header = this->header;
	BlockData data = this->data;
	BlockHeader prevHeader = previous->header;

	string dataToHash = prepareRawData(header.getBlockNumber(), header.getTimestamp(), header.getLastHash(), data.getDataHash(), header.getNonce(), header.getDifficulty());
	string tmpBlockHash = generateHash(dataToHash);

	if (header.getLastHash() != prevHeader.getBlockHash()) {
		//hashes doesn't match!!!
		cout << "block's last hash doesn't match previous block's hash" << endl;
		return false;
	}

	if (header.getBlockNumber() != prevHeader.getBlockNumber() + 1) {
		//invalid block number!!!
		cout << "block's number is not equal to previous block's number + 1" << endl;
		return false;
	}


	if (tmpBlockHash != header.getBlockHash()) {
		cout << "Invalid block hash!" << endl;
		return false;
	}

	long difficultyDiff = header.getDifficulty() - prevHeader.getDifficulty();
	if (abs(difficultyDiff) > 1) {
		cout << "block's difficulty invalid" << endl;
		return false;
	}

	string binaryHash = hexToBinary(header.getBlockHash());
	if (binaryHash.substr(0, header.getDifficulty()) != string(header.getDifficulty(), '0')) {
		cout << "block's hash doesn't match difficulty criteria" << endl;
		return false;
	}

	return true;
}

string Block::toString() {
	stringstream ss;
	ss << "[header: " << this->header.toString() << "]" << endl
			<< "[data: " << this->data.toString() << "]" << endl;

	return ss.str();
}

json Block::toJson() {
	json obj;
	obj["header"] = this->header.toJson();
	obj["data"] = this->data.toJson();

	return obj;
}
