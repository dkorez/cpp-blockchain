#include "hash.h"

using namespace std;

string prepareRawData(unsigned long id, time_t time, string prevHash, string dataHash, long nonce, long diff) {
	stringstream ss;

	ss << id << time << prevHash << dataHash << nonce << diff;
	return ss.str();
}

string generateHash(const string str) {
	unsigned char hash[SHA256_DIGEST_LENGTH];

	SHA256_CTX sha256;
	SHA256_Init(&sha256);
	SHA256_Update(&sha256, str.c_str(), str.size());
	SHA256_Final(hash, &sha256);

	stringstream ss;

	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
		ss << hex << setw(2) << setfill('0') << static_cast<int>(hash[i]);
	}
	return ss.str();
}

const char* hexCharToBinary(char c) {
    switch(toupper(c)) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
        default: return "";		// TODO: throw error
    }
}

string hexToBinary(const string &hex) {
	string binary;
	for (unsigned i = 0; i < hex.length(); i++) {
		binary += hexCharToBinary(hex[i]);
	}
	return binary;
}
