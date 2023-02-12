#include "BlockData.h"
#include <sstream>
#include "../util/hash.h"

using namespace std;

BlockData::BlockData(const string &data): blockData(data) {
	string tmpDataHash = generateHash(data);
	this->dataHash = tmpDataHash;
}

string BlockData::getData() {
	return this->blockData;
}

string BlockData::getDataHash() {
	return dataHash;
}

string BlockData::toString() {
	stringstream ss;
	ss << "[blockData: " << this->blockData << ", "
			<< "dataHash: " << this->dataHash << "]" << endl;

	return ss.str();
}

json BlockData::toJson() {
	json obj;
	obj["blockData"] = this->blockData;
	obj["dataHash"] = this->dataHash;

	return obj;
}
