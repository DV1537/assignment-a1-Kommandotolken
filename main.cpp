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
	int avr;
	int a = 0;
	int counter = 0;
	int sum = 0;
	const int startingSize = 1;
	int * arrayPtr = new int[startingSize];
	std::ifstream myReadFile;

	myReadFile.open("datafile.txt");
	if (myReadFile.fail()) {
		std::cout << "Sorry, there was an error.";
		std::getchar();
	}
	while (myReadFile >> a)
	{
		if (counter >= startingSize)
		{

			int *arrayPtr2 = new int[counter + startingSize];
			for (int i = 0; i < (counter); i++)
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

	for (int i = 0; i < counter; i++)
	{
		if (*(arrayPtr + i) > avr)
			std::cout << *(arrayPtr + i) << " ";

	}



	return 0;
}


