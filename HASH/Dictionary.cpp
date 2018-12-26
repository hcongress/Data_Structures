// Implementation of ADT Dictionary
//     data object: a bunch of contacts (phone number and name)
//     data structure: a header record in the heap with number of items and
//                     a dynamic array of Item objects as a hash table with linear probing
//     operations: create, destroy
//                 search the dictionary for an item given its phone number
//                 insert a new item into the dictionary
//                 remove an item from the dictionary given its phone number

#include "Dictionary.h"

struct DictionaryRecord{
	int numberOfItems;
	Item *hashPtr;
};

const int TABLESIZE = 11;


// turns a Key or Item into an address that can be plugged into the table
// pre theKey exists
// post a hash address within the TABLESIZE is returned
// usage int hashNum = hashFunction(someKey);
int hashFunction (const Key& theKey){
	return theKey.sumDigits()%TABLESIZE;
}

// displays a dictionary
// pre: output has been opened if it is a file
//      rightHandSideDictionary has been assigned items
// post: output contains each item on a separate line in the format with headings.
//       for example
//       address	phone       name
//       0				123-4567 Frosty Snowguy
//     	 1			  111-2222 Icy Dog
// usage: outfile << myDictionary;
ostream& operator<< (ostream& output, const Dictionary& rightHandSideDictionary)
{
	Item nextItem;
	for (int address = 0; address < TABLESIZE; address++){
		nextItem = rightHandSideDictionary.dictionaryPtr -> hashPtr[address];
		output << address << " " << nextItem;
	}
}

// inputs items into a dictionary
// pre: input has been opened if it is a file
//      items are arranged in the following format
//			2
//      1234567 Frosty Snowguy
//      1112222 Icy Dog
// post: if there is room,
//       all items in the input have been stored in rightHandSideDictionary
// usage: infile >> myDictionary;
istream& operator>> (istream& input, Dictionary& rightHandSideDictionary)
{
	int numberItems;
	bool isFull;
	char enter, space, numItems;
	input.get(numItems);
	numberItems = numItems;
	numberItems -= '0';
	input.get(enter);


	for(int i = 0; i < numberItems; i++){
		Item newItem;
		input >> newItem;

		rightHandSideDictionary.insert(newItem, isFull);

	}

}

// creates a new dictionary
// post: Dictionary object exists but is empty
// usage: Dictionary myDictionary;
Dictionary::Dictionary()
{
	dictionaryPtr = new DictionaryRecord;
	dictionaryPtr->numberOfItems = 0;
	dictionaryPtr->hashPtr = new Item[TABLESIZE];
}

// destroys a dictionary
// pre: Dictionary object exists
// post: all memory for Dictionary object has been freed
// usage: automatically done at the end of scope
Dictionary::~Dictionary()
{
	delete [] dictionaryPtr;
	dictionaryPtr = NULL;
}

// searchs for a contact with a particular phone number
// pre targetPhone has been assigned a 7-digit phone number
// post if an item with phone number the same as targetPhone is found then
//          isFound is true and theItem is that item
//       else isFound is false
// usage  contacts.search(targetPhone, anItem, isFound);
void Dictionary::search (const Key& targetPhone, Item& theItem, bool& isFound)
{
	int count = 1;
	isFound = false;
	int hashNum = hashFunction(targetPhone);
	Item itemInTable;
	itemInTable = dictionaryPtr->hashPtr[hashNum];
	while(not itemInTable.isEmpty() && not isFound && count <= TABLESIZE){
		if(itemInTable == targetPhone){
			theItem = itemInTable;
			isFound = true;
		}
		else {
			hashNum = (hashNum + 1) % TABLESIZE;
			itemInTable = dictionaryPtr->hashPtr[hashNum];
			count++;
		}
	}
}

// inserts a new contacts' item into the dictionary
// pre: newItem has been assigned
// post: if there is room in the Dictionary object, isFull is false
//            and newItem is appropriately added
//       else isFull is false
// usage: myDictionary.insert(myItem, isFull);
void Dictionary::insert (const Item& newItem, bool& isFull)
{
	int hashAddress, index;

	isFull = (dictionaryPtr -> numberOfItems == TABLESIZE);
	if(not isFull){
		hashAddress = hashFunction(newItem);
		index = hashAddress;
		while (not dictionaryPtr -> hashPtr[index].isEmpty() &&  not dictionaryPtr -> hashPtr[index].hasBeenUsed()){
			index = (index + 1) % TABLESIZE;
		}
		dictionaryPtr -> hashPtr[index] = newItem;
		dictionaryPtr -> numberOfItems = dictionaryPtr -> numberOfItems + 1;
	}
}


void Dictionary::remove (const Key& targetPhone, bool& isDone)
{
	isDone = false;
	int hashNum = hashFunction(targetPhone);
	Item newEmptyItem;
	while(not dictionaryPtr->hashPtr[hashNum].isEmpty() && not isDone){
		if(dictionaryPtr->hashPtr[hashNum] == targetPhone){
			newEmptyItem.setUsed();
			dictionaryPtr -> hashPtr[hashNum] = newEmptyItem;
			isDone = true;
		}
		else {
			hashNum = (hashNum + 1)% TABLESIZE;
		}
	}
}
