// HuffmanCoding.cpp : Defines the entry point for the console application.
//
////
// Author: James Day
// Section: A
// Assignment: Huffman Encoding
// Description: This program takes a String or a text file and converts it to binary and 
//				condenses the file size down without loosing any data.
//
// Problems: My only issue is rebuilding the tree with a key. everything works properly,
//			but I can't find a way to read in the end of line character without messing 
//			up the process of rebuilding the tree. Other than that one character,
//			everything else about the rebuilding of the tree works. for now I'm using the original tree 
//			that is created when encoding the file.
////
#include "stdafx.h"
#include "HuffmanTree.h"
#include <string>
#include <fstream>
#include <streambuf>
#include <queue>
#include <functional>

using namespace std;

int main() {
			
	// example code for priority_queue....play with it and then remove/comment out
	cout << "priority_queue test area: \n";
	priority_queue<int, vector<int>, greater<int> > pq;
	
	pq.push(111);
	pq.push(1111);
	pq.push(1011);
	pq.push(100);
	pq.push(1110);
	pq.push(101);

	cout << "Top: " << pq.top() << endl;
	pq.push(10);
	cout << "New Top: " << pq.top() << endl;

	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
	cout << endl << endl;

	// example code for unordered_map....play with it and then remove/comment out
	//  an unordered_map can be used to store the char and its encoded 
	//  values after you have built the tree
	cout << "unordered_map test area: \n";
	unordered_map<char, string> exampleMap;
	exampleMap['a'] = "apple";
	exampleMap['b'] = "ballon";
	exampleMap['c'] = "compiler";
	exampleMap['d'] = "10010";

	cout << "c has: " << exampleMap['c'] << endl;

	exampleMap['c'] = "changed";
	for (auto pair : exampleMap) {
		cout << pair.first << " = " << pair.second << endl;
	}
	cout << "Number of items stored in map: " << exampleMap.size();
	cout << endl << endl;


	
	//Test 1        
	cout << "\n\nTest 1\n";
	cout << "\n\nBuilding the tree from: HHHHEELLLLLLLOO WOOOOORRLLLLLLDP\n";
	HuffmanTree tree("HHHHEELLLLLLLOO WOOOOORRLLLLLLDP");
	
	cout << "\n\nprintTree: \n";
	tree.printTree();

	cout << "\n\nprintCodes:\n";
	tree.printCodes();
	cout << endl << endl; 

	cout << "Code L :" <<tree.getCode('L') << endl;
	cout << "Code D :" << tree.getCode('D') << endl;
	
	//Test 2
	cout << "\n\nTest 2\n";
	vector<char> encoded = tree.encode("HELP"); 
	tree.printCodes();
	tree.printBinary(encoded);
	cout << endl;
	
	cout << tree.decode(encoded) << ":" << endl;

	//Test 3
	cout << "\n\nTest 3\n";
	std::ifstream frequencyStream("Bigo.txt"); //ios::in | ios::binary
	HuffmanTree tree2(frequencyStream);
	
	tree2.compressFile("BigO.bin", "Bigo.txt", true);


	tree2.printCodes();
	tree2.uncompressFile("BigO.bin", "BigORebuilt.txt");
	tree2.printTree();
	tree2.printCodes();

	////Test 4
	cout << "\n\nTest 4\n";
	std::ifstream frequencyStream2("20000leagues.txt");
	HuffmanTree tree3(frequencyStream2);
	tree3.printTree();
	tree3.printCodes();
	cout << "Code L :" << tree3.getCode('L') << endl;
	cout << "Zipping and unzipping, please wait...";
	tree3.compressFile("20000leaguesComp.bin" ,"20000leagues.txt",true);
	tree3.uncompressFile("20000leaguesComp.bin", "20000leaguesRebuilt.txt");
	tree3.printTree();
	tree3.printCodes();

	// Try Other Files
	

	cout <<endl;
	system("pause");
    return 0;
}

