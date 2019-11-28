#include <stdio.h>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <string.h>
#include <map>

using namespace std;

int main() {
	auto freqs = std::map<char, int>();

	auto is = ifstream("./clear.txt");
	char c;

	while (is.get(c)) {
		// If the character isn't in the map yet,
		// set its value to 1 and leave
		if (freqs.find(c) == freqs.end()) {
			freqs[c] = 1;
			continue;
		}

		// ...otherwise, increment it
		freqs[c] += 1;
	}

	for (auto f : freqs) {
		printf("%c %i\n", f.first, f.second);
	}
}

//TODO: Actual project says to write it to a file
