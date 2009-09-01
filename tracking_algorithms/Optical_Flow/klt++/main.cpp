// main.cpp : Defines the entry point for the console application.
//

#include <stdio.h>  // printf

#include "examples.h"

#include <iostream>
using namespace std;

/**
extern "C" {
	void RunExample1();
	void RunExample2();
	void RunExample3();
	void RunExample4();
	void RunExample5();
	void RunSeries();
}
**/

int main(int argc, char* argv[])
{
	// select which example to run here
	const int which = 1;

	bool menu = true;
	while (menu)
	{	
		int option = 0;
		cout << "\n\n";
		cout << "1. Find 100 and write features to file\n";
		cout << "2. Find 100 and replace lost features\n";
		cout << "3. Find 150 and write features to file\n";
		cout << "4. Reads data from #3\n";
		cout << "5. Tweak run-time parms\n";
		cout << "6. Run series\n";
		cout << "7. Exit\n";
		cout << "\n\nWhich example to run?\n\n --> ";
		cin >> option;
		if (option == 1) RunExample1();
		if (option == 2) RunExample2();
		if (option == 3) RunExample3();
		if (option == 4) RunExample4();
		if (option == 5) RunExample5();
		if (option == 6) RunSeries2();
		if (option == 7) menu = false;

	}

	/**
	// run the appropriate example
	switch (which) {
		case 1:  RunExample1();  break;
		case 2:  RunExample2();  break;
		case 3:  RunExample3();  break;
		case 4:  RunExample4();  break;  // Note:  example4 reads output from example 3
		case 5:  RunExample5();  break;
		default:  printf("There is no example number %d\n", which);
	}
	**/

	return 0;
}

