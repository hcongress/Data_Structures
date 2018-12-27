// Michael Hepburn and Hunter Congress
// DICTIONARYHASH
// 2-4-18
// Clientprogram.cpp
// dropoff using mhepburn
//
// A main class to demostrate the capabilities of the Dictionar.cpp class.
// The entire file reads from "inut.dat", which is setup to contain the data in
//  the precise order this program needs it.
// First the program uses dictionary's >> operator to get data and outputs that data.
//

#include <fstream>
#include <iostream>
#include <cstdlib>
#include "Item.h"
#include "Dictionary.h"
using namespace std;

void openInputFile(ifstream& infile);

int main(){
	Dictionary theDictionary;
	Key akey, bkey, ckey, dkey;
	Item aitem, bitem, citem;
	char space;
	bool isFull, isFound, isDone;
	ifstream infile;

	// reads four Items from file
	openInputFile(infile);
	infile >> theDictionary;
	cout << "This is the dictionary after reading four Items:" << endl << theDictionary;

	// Reads three more files and inserts them
	infile >> aitem;
	infile >> bitem;
	infile >> citem;
	theDictionary.insert(aitem, isFull);
	theDictionary.insert(bitem, isFull);
	theDictionary.insert(citem, isFull);
	cout << "This is the dictionary after reading three additional items:" << endl << theDictionary;

	// Searches for two different Keys that are found in the dictionary
	infile >> akey;
	infile >> bkey;
	cout << "Searching dictionary for " << akey << " and " << bkey << endl;
	theDictionary.search(akey, aitem, isFound);
	if(isFound)
		cout << akey << " was found." << endl;
	theDictionary.search(bkey, bitem, isFound);
	if(isFound)
		cout << bkey << " was found." << endl;
	cout << "The found items are: " << endl << aitem << bitem;

	// Removes the second phone number from part b) (1112111 John Isner)
	infile >> ckey;
	theDictionary.remove(ckey, isDone);
	cout << "The removed phone number is: " << ckey << endl;
	cout << "The dictionary now reads: " << endl << theDictionary;

	// Searches for the last phone number in b) (2111111 Andy Murray)
	infile >> dkey;
	theDictionary.search(dkey, citem, isFound);
	if(isFound){
		cout << dkey << " was found even though a key earlier in linear probing was removed." << endl;
		cout << "Found item is: " << citem;
	}

	return 0;
}


// Open the file to be read from in the main program
// pre infile is not open to a file
// post infile can be used to read from a file
// usage openInputFile(infile);
void openInputFile(ifstream& infile){
  infile.open("Input.dat");
  if(infile.fail()){
    cout << "ERROR IN OPENING 'Input.dat'" ;
    exit(1);
  }
}
