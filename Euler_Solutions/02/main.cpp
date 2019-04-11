#include <iostream>

using namespace std;

int main()
{
	unsigned int current = 1;
	unsigned int next = 2;
	unsigned int temp;
	unsigned int sum = 0;
	
	while( next < 4000000 )
	{
		if( ( next % 2 ) == 0 )
		{
			sum = sum + next;
		}
		temp = next;
		next = next + current;
		current = temp;
	}
	cout << "\nSum : " << sum << "\n";
	return 0;
}
