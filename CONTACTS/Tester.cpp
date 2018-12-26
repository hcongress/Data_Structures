//testing class for class Key

#include "Key.h"

int main()
{
	Key akey,bkey;
	
	cout << "Enter a seven digit phone number without spaces or dashes: ";
	cin >> akey;
	cout << akey<< endl;
	
	cout << "Enter a seven digit phone number without spaces or dashes: ";
	cin >> bkey;
	cout << bkey<< endl;
	
	cout<< akey << ", " << bkey <<endl;
	cout<<"Here is the sum of the first phone number: " << akey.sumDigits()<<endl;
	cout<<"Here is the sum of the second phone number: " << bkey.sumDigits()<<endl;
	
	return 0;
	
}