#include "utility.h"

int main() {
	auto ct = map<string, char>();
	auto codetable_input = ifstream("codetable.txt");

	string ln;

	while (getline(codetable_input, ln)) {
		char strArray[ln.size() + 1];
		strcpy(strArray, ln.c_str());

		auto c = strtok(strArray, " ")[0];
		auto code = string(strtok(NULL, " "));

		ct[code] = c;
		printf("%c\n", ct["111"]);
	}

	codetable_input.close();

	auto coded_input = ifstream("coded.txt");
	auto decoded_output = ofstream("decoded.txt");
	char c;

	string sofar = "";
	while (coded_input.get(c)) {
		sofar = sofar + c;

		if (ct.find(string(sofar)) != ct.end()) {
			// the string we've built up is in the codetable
			char found = ct[sofar];
			decoded_output.put(found);
			sofar = "";
			printf("%c\n", found);
		}
	}

	coded_input.close();
	decoded_output.close();
	return 0;
}
