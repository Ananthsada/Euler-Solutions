#include <iostream>
#include <map>
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
	unsigned long long num = 10000;
	unsigned long long sum_of_amicable = 0;
	map<unsigned long long, unsigned long long> divider_sum_list;
	pair<unsigned long long, unsigned long long> pair_to_insert;
	
	/**
	 * find all divisors 
	 * */
	pair_to_insert = make_pair(1,1);
	divider_sum_list.insert(pair_to_insert);
	
	cout << "Before Calculating Divisors :  " << GetCurrentTime() << "\n" ;
	for( unsigned long long j = 2 ; j <= num ; j++ )
	{
		unsigned long long sum = 0;
		for( unsigned long long i = 1 ; i <= ( j / 2 ) ; i++ )
		{
			if( ( j % i ) == 0 )
			{
				sum = sum + i;
			}
		}
		pair_to_insert = make_pair(j,sum);
		divider_sum_list.insert(pair_to_insert);		
	}
	cout << "Divisors Calculated : " << GetCurrentTime() << "\n";
	
	/** 
	 * print list 
	 * */
	{
		cout << "List as follows " << "\n" << "************************************\n";
		
		map<unsigned long long, unsigned long long>::iterator print_itr;
	
		for( print_itr = divider_sum_list.begin() ; print_itr != divider_sum_list.end() ; print_itr++ )
		{
			cout << "( " << print_itr->first << ", " << print_itr->second << " )\n";
		}	
		
		cout << "************************************\n";
	}	
	
	/**
	 * find Amicable Numbers 
	 * */
	map<unsigned long long, unsigned long long>::iterator parse_itr;
	
	for( parse_itr = divider_sum_list.begin() ; parse_itr != divider_sum_list.end() ; parse_itr++ )
	{
		map<unsigned long long, unsigned long long>::iterator itr;
		
		itr = divider_sum_list.find( parse_itr->second );
		if( ( itr != divider_sum_list.end() ) && ( itr -> first != parse_itr->first ) )
		{
			if( itr->second == parse_itr->first )
			{
				cout << "Amicable Numbers found : ( " << parse_itr->first << ", " << parse_itr->second << " )\n";
				sum_of_amicable = sum_of_amicable + parse_itr->first;
			}
		}
	}
	
	cout << "Amicable Numbers Sum : " << sum_of_amicable << "\n";
	return 0;
}
