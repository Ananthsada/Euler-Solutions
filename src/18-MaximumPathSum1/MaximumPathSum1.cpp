#include <iostream>
#include <set>
#include <iterator>
#include <map>
#include <cstdlib>

using namespace std;

struct CompareCondition
{
	/*
	 * swap if returned false 
	 * */
	bool operator()(const unsigned int& lhs, const unsigned int& rhs )
	{
		return lhs > rhs;
	}
};

map< unsigned int, set< unsigned int, CompareCondition> > list;

void ParseMainArguments( char** source, unsigned int count)
{
	int num = -1;
	int index = 1;
	int oddvalue = 1;
	cout << "No of numbers : " << count << "\n";
	
	set< unsigned int, CompareCondition > LocalSet;
	
	
	for( int i = 1 ; i < count ; i++ )
	{	
		num = atoi(source[i]);
		//cout << num << "\n";
		LocalSet.insert(num);
		
		if( i == index )
		{
			set< unsigned int, CompareCondition >::iterator itr = LocalSet.begin();
			pair< unsigned int, set< unsigned int, CompareCondition > > pair_to_insert = make_pair( *itr, LocalSet );
			list.insert( pair_to_insert );
			LocalSet.clear();
			oddvalue = oddvalue + 1;
			index = index + oddvalue;
		}
	}
}

void PrintListContent()
{
	map< unsigned int, set< unsigned int, CompareCondition > >::iterator map_itr;
	
	for( map_itr = list.begin(); map_itr != list.end(); map_itr++ )
	{
		cout << "\nLargest : " << map_itr->first ;
		set< unsigned int>::iterator set_itr;
		cout << " Contents : " ;
		for( set_itr = map_itr->second.begin(); set_itr != map_itr->second.end(); set_itr++ )
		{
			cout << " " << *set_itr;
		}
	}
	cout << "\n";
}

void PrintSum()
{
	unsigned int sum = 0;
	map< unsigned int, set< unsigned int, CompareCondition > >::iterator map_itr;
	
	for( map_itr = list.begin(); map_itr != list.end(); map_itr++ )
	{
		sum = sum + map_itr->first;
	}	
	cout << "Resulted Sum : " << sum << "\n";
}
