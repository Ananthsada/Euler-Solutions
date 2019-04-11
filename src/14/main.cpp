#include <iostream>

using namespace std;

int main()
{
	unsigned long long max = 0,count = 0,num = 0;
	
	for( unsigned long long j = 1000000 ; j > 2; j-- )
	{
		count = 0;
		unsigned long long i = j;
		cout << "\n" <<  j ;
		while( i != 1 )
		{
			count = count + 1;
			if( i % 2 == 0 )
			{
				i = i / 2;
			}
			else
			{
				i = ( 3 * i ) + 1;
			}
			cout << " -> " << i;
		}
		if( count > max )
		{
			max = count;
			num = j;
		}
		cout << "\n";
	}
	
	cout << "Maximum Number : " << num << "\n";
	return 0;
}
