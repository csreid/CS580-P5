#include "utility.h"
//Team 6: Cameron Reid and Kaley Rittichier

void writeEncodedFile(string arr[128]) {
	ifstream in_stream;
	in_stream.open("clear.txt");
	if (in_stream.fail()) {
		cout << "Unable to find input file.";
		exit(1);
	}
	char c = NULL;
	ofstream writeFile;
	writeFile.open("coded.txt");
	if (writeFile.is_open()) {
		while(in_stream.get(c)){
			printf("Got char %c\n", c);
			writeFile << arr[static_cast <int>(c)];
		}
	} else cout << "Unable to open/create file";
	in_stream.close();
}

int main() {
	ifstream in_stream;
	in_stream.open("codetable.txt");
	if (in_stream.fail()) {
		cout << "Unable to find input file.";
		exit(1);
	}
	string str, binaryCode;
	int i;
	string arr[128];
	while (getline(in_stream, str)) {
		if (isspace(str[2])) {
			i = 10;
			binaryCode = str.substr(3, str.size());
		}
		else {
			i = static_cast <int>(str[0]);
			binaryCode = str.substr(2, str.size());
		}
		arr[i] = binaryCode;
	}
	in_stream.close();
	writeEncodedFile(arr);
	return 0;
}
