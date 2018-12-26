//inserting items that are integers into a dictionary (Hash table)
//Hunter Congress
//Hashprogram.cpp

#include<iostream>
const MAXSIZE = 7;

int hashFunction(int item);
void print(int hasTable[]);
void input (int hashTable[]);

int main()
{
	int HashTable[MAXSIZE];
	
	
	return 0;
}

int hashFunction(int item)
{
	return item % MAXSIZE;
}
void print(int hasTable[])
{
	for(int i = 0; i < MAXSIZE; I++)
	{
		cout << i << " : " << HashTable[i] << endl;
	}
}
void input (int hashTable[])
{
	int item;
	for (int i = 0; i < 3 ; i++)
	{
		cout<< "Enter an integer: ";
		cin >> item;
		hasTable[hashFunction(item)] = item;
	}
}