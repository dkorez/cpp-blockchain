#include "BlockChain.h"
#include <sstream>
#include "../util/hash.h"

using namespace std;

BlockChain::BlockChain() {
	createGenesisBlock();
}

Block* BlockChain::getLastBlock() {
	return &chain.back();
}

void BlockChain::addBlock(Block newBlock) {
	bool isValid = newBlock.isValidBlock(this->getLastBlock());
	if (isValid) {
		this->chain.push_back(newBlock);
	}
	else {
		cout << "block invalid" << endl;
	}
}

void BlockChain::createGenesisBlock() {
	string genesisData = "--GENESIS--";
	string lastHash = generateHash(string(16, '0'));
	string blockHash = generateHash(genesisData);

	BlockHeader header(0, 1, 1, time(0), blockHash, lastHash);
	BlockData data(genesisData);
	Block genesis(header, data);
	this->chain.push_back(genesis);
}

string BlockChain::toString() {
	stringstream ss;
	for (auto &block: chain) {
		ss << block.toString() << endl;
	}

	return ss.str();
}

json BlockChain::toJson() {
	json obj;
	for (auto &block : chain) {
		obj.push_back(block.toJson());
	}

	return obj;
}
