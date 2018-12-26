/*
char enter;
Key targetPhoneNumber;
if (option == 'f')
{
  cout << "Please enter a phone.> ";
  cin >> targetPhoneNumber;
    try
     {
      tree.search(targetPhoneNumber, theItem);
      cout << theItem;
     }
     catch (Exception search)
     {
      PrintExceptionMessage(search, outfile);
     }
}
else if (option == 'i')
{
  cout << "Please enter 7 digits and then a name.> ";
  cin >> theItem;
    try
     {
      tree.insert(theItem);
      cout<<"The contact has been stored"<< endl;
     }
     catch (Exception insert)
     {
      PrintExceptionMessage(insert, outfile);
     }
}
else if(option == 'l')
{
  tree.BinaryTree::inorderTraverse();
}
else if(option == 'p')
{
  tree.prettyDisplay();
}
else if (option == 'r')
{
  cout << "Please enter a phone.> ";
  cin >> targetPhoneNumber;
    try
     {
      tree.remove(targetPhoneNumber);
      cout <<" The Item has been removed" << endl;
     }
     catch (Exception remove)
     {
      PrintExceptionMessage(remove, outfile);
     }
}
else if (option == 's')
{
  saveFile(outfile, "Input.dat", tree);
}
*/
