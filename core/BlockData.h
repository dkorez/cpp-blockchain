#ifndef CORE_BLOCKDATA_H_
#define CORE_BLOCKDATA_H_

#include <iostream>
#include "../util/json.hpp"

using namespace std;
using json = nlohmann::json;

class BlockData {
	string blockData;
	string dataHash;
public:
	BlockData(const string &data);
	string getData();
	string getDataHash();

	string toString();
	json toJson();
};

#endif /* CORE_BLOCKDATA_H_ */
