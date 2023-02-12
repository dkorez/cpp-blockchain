#include <iostream>
#include "core/BlockChain.h"
#include "core/Miner.h"

using namespace std;

int main() {

	BlockChain chain;
	Miner miner;

	cout << "Miner started!!" << endl;

	int nBlocks = 10;
	cout << "How many block do you wish to mine: ";
	while (!(cin >> nBlocks)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}

	Block block1 = miner.mineBlock(&chain, "First block");
	chain.addBlock(block1);
	cout << "BLOCK ADDED!" << endl;
	cout << block1.toJson().dump(4) << endl << endl;


	// mine random x blocks
	for (int i=0; i<nBlocks; i++) {
		Block tmp = miner.mineBlock(&chain, "random block " + to_string(i));
		chain.addBlock(tmp);

		cout << "BLOCK ADDED: ";
		cout << tmp.toJson().dump(4) << endl << endl;
	}


	cout << "Miner ended!!" << endl;
	//cout << chain.toJson().dump(4) << endl;

	return 0;
}

