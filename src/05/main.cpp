#include <iostream>
#include <set>
#include <iterator>

using namespace std;

long long getremovable( set<long long>& data, long long count)
{
	long long ret_val = 1;
	
	for( long long i = count ; i > 2 ; i-- )
	{
		for( long long j = 2 ; j < i ; j++ )
		{
			if( i%j == 0 )
			{
				cout << "\n " << i << " " << j << " \n";
				data.insert( j );
			}
		}
	}
	
	cout << "\n";
	set<long long>::iterator list;
	for( list = data.begin(); list != data.end(); list++ )
	{
		cout << *list << " " ;
		ret_val = ret_val * (*list);
	}
	cout << "\n";
	
	return ret_val;
}

int main()
{
	long long num = 1;
	long long index = 0;
	
	for( num = 40 ; ; )
	{
		cout << num << "\n " ;
		for( index = 2; index < 21 ; index++ )
		{
			if( ( num % index ) != 0 )
			{
				break;
			}
		}
		if( index == 21 )
		{
			break;
		}
		num = num + 20;
	}
	
	cout << num - 1 << "\n";
	
	return 0;
}
