#include "pch.h"
#include <iostream>
#include <fstream>
#include <cmath>

/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, const char * argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	char fileName[30]; //array for the filename
	if (argc < 2)
	{
		std::cout << "You forgot to enter a filename.";
		return 1;
	}
	strcpy_s(fileName, argv[1]); //Copy the name from argv to fileName.
	float avr;
	float a = 0;
	int counter = 0;
	float sum = 0;
	const int startingSize = 1;
	float * arrayPtr = new float[startingSize];
	float * arrayPtr2 = new float[startingSize];
	std::ifstream myReadFile;

	myReadFile.open(fileName);
	if (myReadFile.fail()) {
		std::cout << "Sorry, there was an error opening the file. Press ENTER";
		std::getchar();
		exit(1);
	}
	while (myReadFile >> a)
	{
		int i;
		myReadFile >> i;
		if (itoa(i) == 46)
		{
			std::cout << "This is a dot";
		}
		if (counter >= startingSize)
		{

			arrayPtr2 = new float[counter + startingSize];
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
	if (counter == 0)
	{
		std::cout << "No number was in the file";
		return 1;
	}

	avr = (sum / static_cast<float>(counter));
	int roundedAvr = (int)(avr * 1000);
	avr = ((double(roundedAvr) / 1000));
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

