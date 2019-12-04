#include "utility.h"

int main() {
	auto ct = map<string, char>();
	auto codetable_input = ifstream("codetable.txt");

	string ln;

	while (getline(codetable_input, ln)) {
		char strArray[ln.size() + 1];
		strcpy(strArray, ln.c_str());

		char c;
		int offset;
		if (strArray[0] == 'L' && strArray[1] == 'F') {
			c = '\n';
			offset = 3 * sizeof(char);
		} else {
			c = strArray[0];
			offset = 2 * sizeof(char);
		}

		auto code = strArray + offset;
		cout << flush;

		auto strcode = string(code);

		ct[strcode] = c;
		printf("ct[%s] = %c\n", strcode.c_str(), c);
	}

	codetable_input.close();

	auto coded_input = ifstream("coded.txt");
	auto decoded_output = ofstream("decoded.txt");
	char c;

	string sofar = "";
	string written = "";
	while (coded_input.get(c)) {
		sofar = sofar + c;
		if (ct.find(string(sofar)) != ct.end()) {
			// the string we've built up is in the codetable
			printf("%s => %c\n", sofar.c_str(), ct[sofar]);
			char found = ct[sofar];
			decoded_output.put(found);
			written = written + found;
			sofar = "";
		}
	}

	coded_input.close();
	decoded_output.close();
	return 0;
}
