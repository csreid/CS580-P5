#include "utility.h"
//Team 6: Cameron Reid and Kaley Rittichier

struct BinaryNode {
	string character;
	int frequency;
	struct BinaryNode *left, *right; 
};

struct CompareFrequency {
	bool operator()(BinaryNode* n1, BinaryNode* n2){
		return n1->frequency > n2->frequency;
	}
};

struct BinaryNode* addNode(string character, int frequency, BinaryNode* left, BinaryNode* right) {
	struct BinaryNode* node = new struct BinaryNode;
	node->character= character;
	node->frequency = frequency;
	node->left = left;
	node->right = right;
	return node;
}

void writeToFile(string file_name, map<int, string, greater<int>>& codeMap) {
	ofstream file;
	file.open(file_name);
	if (file.is_open()) {
		for (int i = 0; i < codeMap.size(); i++) {
			if (!codeMap[i].empty()) {
				if (i == 10) {
					file << "LF" << " "<< codeMap[i] << endl;
				}
				else {
					file << static_cast <char>(i) << " " << codeMap[i] << endl;
				}
			}
		}
		
	}
	else cout << "Unable to open/create file";
}

priority_queue<BinaryNode*, vector<BinaryNode*>, CompareFrequency> generateTree(priority_queue<BinaryNode*, vector<BinaryNode*>, CompareFrequency> nodes) {
	int length = nodes.size();
	for (int i = 1; i < length; i++) {
		BinaryNode *x = nodes.top();
		nodes.pop();
		BinaryNode *y = nodes.top();
		nodes.pop();
		nodes.push(addNode("NU", x->frequency + y->frequency, x, y));
		}
	return nodes;
}

void generateEncoding(BinaryNode* root, string binaryString, map<int, string, greater<int>> &codeMap) {
	if (root->right != nullptr) {
		generateEncoding(root->right, binaryString + "1", codeMap);
	}
	if (root->left != nullptr) {
		generateEncoding(root->left, binaryString + "0", codeMap);
	}
	if (root->left==nullptr && root->right == nullptr) {
		int index;
		if (root->character == "LF") {
			index =  10;
		}
		else index = static_cast <int>(root->character[0]);
		codeMap[index] = binaryString;
		cout << root->character << " : " << codeMap[index] << endl;
		cout << "Index: " << index << endl;
		return;
	}
}

priority_queue<BinaryNode*, vector<BinaryNode*>, CompareFrequency> readInFile() {
	ifstream in_stream;
	in_stream.open("freq.txt");
	if (in_stream.fail()) {
		cout << "Unable to find input file.";
		exit(1);
	}
	string str, character, number;
	int freq = 0;
	priority_queue<BinaryNode*, vector<BinaryNode*>, CompareFrequency> nodes;
	BinaryNode* n;
	while (getline(in_stream, str)) {
		if (isspace(str[2])) {
			character = str.substr(0, 2);
			number = str.substr(3, str.size());
		}
		else {
			character = str[0];
			number = str.substr(2, str.size());
		}
		stringstream toInt(number);
		toInt >> freq;
		nodes.push(addNode(character, freq, nullptr, nullptr));
	}
	in_stream.close();
	return nodes;
}

int main() {
	priority_queue<BinaryNode*, vector<BinaryNode*>, CompareFrequency> nodes = generateTree(readInFile());
	BinaryNode* root = nodes.top();
	map<int, string, greater<int>> codeMap;
	generateEncoding(root, "", codeMap);
	writeToFile("codetable.txt", codeMap);
	return 0;
}	
