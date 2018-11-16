#include "pch.h"
#include <iostream>
#include <fstream>

/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, const char * argv[])
{
	char fileName[30]; //array for the filename
	if (argc < 2)
	{
		std::cout << "You forgot to enter a filename.";
		return 1;
	}
	strcpy_s(fileName, argv[1]); //Copy the name from argv to fileName.
	int avr;
	int a = 0;
	int counter = 0;
	int sum = 0;
	const int startingSize = 1;
	int * arrayPtr = new int[startingSize];
	int * arrayPtr2 = new int[startingSize];
	std::ifstream myReadFile;

	myReadFile.open(fileName);
	if (myReadFile.fail()) {
		std::cout << "Sorry, there was an error opening the file. Press ENTER";
		std::getchar();
		exit(1);
	}
	while (myReadFile >> a)
	{

		if (counter >= startingSize)
		{

			arrayPtr2 = new int[counter + startingSize];
			for (int i = 0; i < counter; i++)
			{
				arrayPtr2[i] = arrayPtr[i];

			}
			delete[]arrayPtr;
			arrayPtr = arrayPtr2;

			arrayPtr[counter] = a;




		}
		else if (counter < startingSize)
		{
			arrayPtr[counter] = a;

		}

		sum += a;
		counter++;


	}
	myReadFile.close();


	avr = (sum / counter);
	std::cout << "The avarage is: " << sum << "/" << counter << ": " << avr << "\n";
	std::cout << "Numbers above avarage are: \n";
	for (int i = 0; i < counter; i++)
	{
		if (*(arrayPtr + i) > avr)
			std::cout << *(arrayPtr + i) << " ";

	}

	delete[] arrayPtr2;

	return 0;
}

