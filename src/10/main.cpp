#include <iostream>
#include <set>
#include <iterator>
#include <cstdio>
#include <cmath>

#define MAX_COUNT 2000000

using namespace std;


int main(int argc,char** argv)
{
	unsigned long long num = 1;
	unsigned long long prime = 2;
	unsigned long long sum = 0;
	unsigned long long j;
	
	sum = sum + 2;
	
	while( ( num + 2 ) < MAX_COUNT )
	{
		num = num + 2;
		for( j = 2; j < sqrt( num ) ; j++ )
		{
			if( num % j == 0 )
			{
				break;
			}
		}
		if( j > sqrt( num ))
		{
			prime = num;
			sum = sum + num;
			//cout << "prime : " << prime << " sum : " << sum << "\n";
		}
	}
	
	cout << "\n" << prime << " " << sum << "\n";
	
	return 0;
}
