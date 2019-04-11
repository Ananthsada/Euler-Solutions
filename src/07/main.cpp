#include <iostream>
#include <set>
#include <iterator>
#include <cstdio>
#include <cmath>

#define POSITION 10001

using namespace std;


int main(int argc,char** argv)
{
	unsigned long long num = 16;
	unsigned long long count = 6;
	unsigned long long j;
	
	while( count < POSITION )
	{
		num++;
		for( j = 2; j < sqrt( num ) ; j++ )
		{
			if( num % j == 0 )
			{
				break;
			}
		}
		if( j > sqrt( num ))
		{
			count += 1;
		}
	}
	
	cout << num << "\n";
	
	return 0;
}
