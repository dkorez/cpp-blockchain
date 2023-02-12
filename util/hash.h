#ifndef UTIL_HASH_H_
#define UTIL_HASH_H_

#include <iostream>
#include <iomanip>
#include <sstream>

extern "C" {
#include <openssl/sha.h>
}

using namespace std;

string prepareRawData(unsigned long id, time_t time, string prevHash, string dataHash, long nonce, long diff);
string generateHash(const string str);
string hexToBinary(const string &hex);

#endif
