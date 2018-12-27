//inserting items that are integers into a dictionary (Hash table)
//Hunter Congress
//Hashprogram.cpp

#include <iostream>
using namespace std;

const int MAXSIZE = 7;

int hashFunction(int item);
void print(int hasTable[]);
void input (int hashTable[]);

int main()
{
	int hashTable[MAXSIZE];
	cout<<input(hashTable[MAXSIZE]);
	cout<<print(hashTable[MAXSIZE]);
	
	
	
	return 0;
}

int hashFunction(int item)
{
	return item % MAXSIZE;
}
void print(int hashTable[])
{
	for(int i = 0; i < MAXSIZE; i++)
	{
		cout << i << " : " << hashTable[i] << endl;
	}
}
void input (int hashTable[])
{
	int item;
	for (int i = 0; i < 3 ; i++)
	{
		cout<< "Enter an integer: ";
		cin >> item;
		hashTable[hashFunction(item)] = item;
	}
}