#include <iostream>

using namespace std;

extern void ParseMainArguments( char** source, unsigned int count);
extern void PrintListContent();
extern void PrintSum();

int main(int argc, char** argv)
{
	if( argc > 1 )
	{
		ParseMainArguments(argv, argc);
		PrintListContent();
		PrintSum();
	}
	else
	{
		cout << "No argument is given " << "\n";
	}
	
	return 0;
}
