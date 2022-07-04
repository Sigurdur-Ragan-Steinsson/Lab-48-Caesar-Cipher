#include <iostream>
#include <fstream>

using namespace std;

char CaesarCipher(char input, int offs)
{
  char output;
  //checking to make sure the offset doesn't go over limit
  if(offs > 25)
  {
    offs = offs % 25;
  }
  if(offs < 1)
  {
    offs = 1;
  }
  // forcing lowercase 
  input = tolower(input);
  // using ascii and trying to prevent voerflow into non-alphabet chars
  if(input + offs > 122)
  {
    input -= 26;
  }
  output = input + offs; 
  return output;
}

// *inFile should include data you'd like to encode

// Display a greeting.
// Prompt for and read inFile, the name of the input file.
// Ask for an offset for encoding
// Create an ifstream named inStream connecting our program to inFile.
// Check that inStream opened correctly.
// Prompt for and read outFile, the name of the output file.
// Create an ofstream named outStream connecting our program to outFile.
// Check that outStream opened correctly.
// Loop through the following steps:
// Read a character from the input file.
// If the end-of-file was reached, then terminate repetition.
// Encode the character.
// Write the encoded character to the output file.
// End loop.
// Close the input and output connections.
// Display a "successful completion" message.
int main() {
  cout << "Hello, welcome to a caesar cipher" << endl;
  string offsetString;
  int offset;
  cout << "Please input the shift you would like to use (1-25)" << endl;
  cin >> offsetString;
  offset = stoi(offsetString);
  // did you want infile already created w/ the data in it?
  // string data = "cab";
  // cout << "Please enter the data you want to enter into the file" << endl;
  //getline(cin, data);
  //initialize data in file
  // ofstream inputFile("inFile.txt");
  // inputFile << data;
  ifstream input("inFile.txt");
  if(input.is_open())
  {

  ofstream file("outFile.txt");
  if(file.is_open())
    {
    string encrypt;
    char ch;      
      while(input.get(ch))
      {
        if(isalpha(ch))
        {
          ch = CaesarCipher(ch, offset);
        }
        encrypt += ch;
      }
      // not writing the data
      file << encrypt;
      file.close();
    }
  }
  input.close();
  cout << "successful completion" << endl;
}