#include <iostream>
#include <set>
#include <iterator>
#include <cstdio>
#include <ctime>
#include <cmath>

using namespace std;

bool CheckPalindrome(const unsigned long long& data)
{
	bool retval = false;
	unsigned long long local = 0, temp = data;
	
	while( temp > 0 )
	{
		local = local * 10;
		local = local + temp % 10 ;
		temp = temp / 10;
	}
	if( local == data )
	{
		retval = true;
	}
	
	return retval;
}

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
	unsigned long long num = 998001;
	set<unsigned long long> palindrome_list;
	set<unsigned long long> revised_list;
			
	/** 
	 * find palindrome 
	 * */
	for( unsigned long long i = num; i > 10000 ; i-- )
	{
		if( CheckPalindrome( i ) == true )
		{
			palindrome_list.insert( i );
		}
	}

	/**
	 * find all divisors 
	 * */
	set<unsigned long long>::iterator list_itr;
	for( list_itr = palindrome_list.begin() ; list_itr != palindrome_list.end() ; list_itr++ )
	{
		for( unsigned long long i = 100 ; i <= sqrt(*list_itr) ; i++ )
		{
			if( ( ( *list_itr % i ) == 0  ) &&
				( ( *list_itr / i ) > 100 ) && 
				( ( *list_itr / i ) < 1000 ) )
			{
				revised_list.insert( *list_itr );
				cout << "Num : " << *list_itr << endl;
				break;
			}
		}
	}
	
	//cout << palindrome_list.size() << " " << revised_list.size() << endl;
	return 0;
}
