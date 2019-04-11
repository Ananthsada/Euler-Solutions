#include <iostream>
#include <set>
#include <iterator>
#include <cmath>

#define DIVISORS_COUNT 500

using namespace std;

bool CalculateDivisors( unsigned long long number )
{
	bool retval = false;
	set<unsigned long long> list;
	
	for( unsigned long long index = 1 ; index <= sqrt( number ) ; index++ )
	{
		if( number % index == 0 )
		{
			list.insert( index );
			list.insert( number / index );
			if( list.size() >= DIVISORS_COUNT )
			{
				retval = true;
				break;
			}
		}
	}
	
	return retval;
}

int main()
{
	unsigned long long num = 1;
	for( unsigned long long i = 1 ; ; i++ )
	{
		num = ( i * ( i + 1 ) / 2 );
		if( CalculateDivisors( num ) == true )
		{
			cout << num <<"\n";
			break;
		}
	}
	
	return 0;
}
