/*
Douglas	Rollman
CS 135
4/5/23
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	

	// Open some_f_stream with the name hello.txt.
	ofstream newFile("hello.txt");
	fstream some_f_stream;
	some_f_stream.open("hello.txt");
	if (some_f_stream.fail())
	{
		cout << "Error opening file"<< endl;
		return -1;
	}
	// write "Hello, World!" in the some_f_stream.
	some_f_stream << "Hello, World!";

	// Close file.
	some_f_stream.close();
	some_f_stream.open("hello.txt");
	if (some_f_stream.fail())
	{
		cout << "Error opening file" << endl;
		return -1;
	}

	// read some_f_stream and print contents.
	string output;
	getline(some_f_stream, output);
	cout << output << endl;
	some_f_stream.close();
	return 0;

}