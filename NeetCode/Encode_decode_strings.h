#pragma once
#include <vector>
#include <sstream>
using namespace std;

void encode(vector<string> &input, string &output) {
	for (auto& word : input) {
		stringstream ss;
		ss << word.length() << "#" << word;
		output.append(ss.str());
	}
}

void decode(string &input, vector<string> &output) {
	for (int i = 0; i < input.size(); i++) {
		int ascii = input.at(i);
		if (ascii >= 48 &&
			ascii <= 57 &&
			input.at(i + 1) == '#') {
			int num = ascii - '0';
			string str = input.substr(i+2, num);
			output.push_back(str);
		}
	}
}