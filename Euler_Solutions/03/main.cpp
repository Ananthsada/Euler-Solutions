#include <iostream>
#include <set>
#include <iterator>
#include <cstdio>
#include <ctime>
#include <cmath>

using namespace std;

unsigned long long GetCurrentTime()
{
	unsigned long long ReturnValue = 0;
	struct timespec CurrentTime;
	
	clock_gettime( CLOCK_REALTIME , &CurrentTime );
	ReturnValue = CurrentTime.tv_sec * 1000 + ( CurrentTime.tv_nsec / ( 1000 * 1000 ) );
	
	return ReturnValue;
}

int main(int argc,char** argv)
{
	unsigned long long num = 600851475143;
	set<unsigned long long> dividers;
	set<unsigned long long> prime_factors;
	
	/**
	 * find all divisors 
	 * */
	cout << "a " << GetCurrentTime() << "\n" ;
	for( unsigned long long i = 1 ; i <=  sqrt( num ) ; i++ )
	{
		if( ( num % i ) == 0 )
		{
			cout << i << " " << num/i << " ";
			fflush(stdout);
			dividers.insert(i);
			dividers.insert(num/i);
		}
	}
	cout << "\nb " << GetCurrentTime() << "\n";
	
	/** 
	 * find prime numbers in divisor list 
	 * */
	set<unsigned long long>::iterator inner;
	for( inner = dividers.begin() ; inner != dividers.end() ; inner++ )
	{
		for( unsigned long long i = 2 ; i < *inner ; i++ )
		{
			if( ( *inner % i ) == 0 )
			{
				dividers.erase(inner);
				break;
			}
		}
	}
	
	/**
	 * find divisors 
	 * */
	cout << "\n";
	set<unsigned long long>::iterator inner1;
	for( inner1 = dividers.begin() ; inner1 != dividers.end(); inner1++ )
	{
		cout << *inner1 << " " ;
	}
	cout << "\n";
	
	return 0;
}
