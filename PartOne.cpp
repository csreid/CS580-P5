#include "utility.h"
//Team 6: Cameron Reid and Kaley Rittichier

void makeFile(string file_name,  int items[]) {
	ofstream file;
	file.open(file_name);
	if (file.is_open()) {
		for (int i = 0; i < 128; i++) {
			if(items[static_cast <int>(static_cast <char> (i))] > 0){
				char c = static_cast <char> (i);
				int freq = items[static_cast <int>(c)];
				if (static_cast <int>(i) == 10) {
					file << "LF" << " " << freq << endl;
				}
				else {
					file << c << " "<< freq << endl;
				}
			}
		}
	}
	else cout << "Unable to open/create file";
}

int main() {
	ifstream in_stream;
	in_stream.open("clear.txt");
	if (in_stream.fail()) {
		cout << "Unable to find input file.";
		exit(1);
	}
	char c = NULL;
	int freq = 0;
	int items[128];
	for (int i = 0; i < 128; i++) {
		items[i] = 0;
	}
	while (!in_stream.eof()) {//I'm not reading "the entire file into memory", correct? 
		in_stream.get(c);
		items[static_cast <int>(c)]++;
	}
	in_stream.close();
	makeFile("freq.txt", items);
	return 0;
}
