//clientguy

#include "BinaryTree.h"
#include "Exception.h"
#include <string>
#include <fstream>
using namespace std;

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file
//      else an error message is printed
//usage OpenInputFile(infile, filename);
void OpenInputFile(ifstream& inputFile, string filename);

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void PrintExceptionMessage(const Exception& except);

int main()
{
   BinaryTree mytree, otherTree, testTree;
   ifstream infile;

   OpenInputFile(infile, "Input.dat");

   cout << "Creating tree one..." << endl;
   try
   {
      mytree.makeTreeOne(infile);
      mytree.preorderTraverse();
      mytree.prettyDisplay();
   }
   catch (Exception exceptTreeOne)
   {
     PrintExceptionMessage(exceptTreeOne);
   }

   cout << "Creating tree two..." << endl;
   try
   {
     otherTree.makeTreeTwo(infile);
   }
   catch (Exception exceptTreeTwo)
   {
     PrintExceptionMessage(exceptTreeTwo);
   }
   otherTree.preorderTraverse();
   otherTree.prettyDisplay();

  cout << "Testing operator=..." << endl;
  try
  {
    testTree = mytree;
    testTree.preorderTraverse();
  }
  catch (Exception exceptTestTree)
  {
    PrintExceptionMessage(exceptTestTree);
  }

   return 0;
}

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file
//      else an error message is printed
//usage OpenInputFile(infile, filename);
void OpenInputFile(ifstream& inputFile, string filename)
{
   inputFile.open(filename);
   if (inputFile.fail())
   {
      cout << "File failed to open!!!!" << endl;
      exit(1);
   }
}

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void PrintExceptionMessage(const Exception& except)
{
   cout << endl << endl;
   cout << except.What();
   cout << endl << endl;
}	
   