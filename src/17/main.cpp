#include <iostream>
#include <iterator>
#include <map>
#include <cstring>

using namespace std;

map<unsigned int, pair< unsigned short , string > > list;

pair<unsigned int, pair< unsigned short , string > > GetPair( unsigned int number, string num_alp)
{
	unsigned int size_num = num_alp.length();
	pair< unsigned short , string > pair_local = make_pair(size_num, num_alp);
	pair<unsigned int, pair< unsigned short , string > > pair_whole = make_pair(number, pair_local);
	
	cout << "number : " << pair_whole.first << " Size : " << pair_whole.second.first << " Word : " << pair_whole.second.second.c_str() << "\n";
	return pair_whole;
}

void InitList()
{
	list.insert(GetPair(1, "one"));
	list.insert(GetPair(2, "two"));
	list.insert(GetPair(3, "three"));
	list.insert(GetPair(4, "four"));
	list.insert(GetPair(5, "five"));
	list.insert(GetPair(6, "six"));
	list.insert(GetPair(7, "seven"));
	list.insert(GetPair(8, "eight"));
	list.insert(GetPair(9, "nine"));
	list.insert(GetPair(10, "ten"));
	list.insert(GetPair(11, "eleven"));
	list.insert(GetPair(12, "twelve"));
	list.insert(GetPair(13, "thirteen"));
	list.insert(GetPair(14, "fourteen"));
	list.insert(GetPair(15, "fifteen"));
	list.insert(GetPair(16, "sixteen"));
	list.insert(GetPair(17, "seventeen"));
	list.insert(GetPair(18, "eighteen"));
	list.insert(GetPair(19, "nineteen"));
	list.insert(GetPair(20, "twenty"));
	list.insert(GetPair(30, "thirty"));
	list.insert(GetPair(40, "forty"));
	list.insert(GetPair(50, "fifty"));
	list.insert(GetPair(60, "sixty"));
	list.insert(GetPair(70, "seventy"));
	list.insert(GetPair(80, "eighty"));
	list.insert(GetPair(90, "ninety"));
	list.insert(GetPair(100, "onehundred"));
	list.insert(GetPair(200, "twohundred"));
	list.insert(GetPair(300, "threehundred"));
	list.insert(GetPair(400, "fourhundred"));
	list.insert(GetPair(500, "fivehundred"));
	list.insert(GetPair(600, "sixhundred"));
	list.insert(GetPair(700, "sevenhundred"));
	list.insert(GetPair(800, "eighthundred"));
	list.insert(GetPair(900, "ninehundred"));
	list.insert(GetPair(1000, "onethousand"));
}

void FormList()
{
	unsigned int number = 21;
	unsigned int digit = 0;
	string word;
	
	while( number < 1000 )
	{
		word = "";
		digit = number;
		if( number < 100 )
		{
			map<unsigned int, pair< unsigned short , string > >::iterator itr;
			itr = list.find( ( digit / 10 ) * 10 );
			if( itr != list.end() )
			{
				word = word + itr->second.second;
			}
			digit = digit % 10;
			
			itr = list.find( digit );
			if( itr != list.end() )
			{
				word = word + itr->second.second;
			}			
		}
		else
		{
			map<unsigned int, pair< unsigned short , string > >::iterator itr;
			itr = list.find( ( digit / 100 ) * 100 );
			if( itr != list.end() )
			{
				word = word + itr->second.second;
			}
			digit = digit % 100;	
			
			//cout << "digit : " << digit << "\n";
			itr = list.find( digit );
			if( itr != list.end() )
			{
				word = word + "and";
				word = word + itr->second.second;
				//cout << "length of word : " << itr->second.second.length() << "\n";	
			}								
		}
		//cout << "Number : " << number << " Word : " << word.c_str() << "\n";
		list.insert(GetPair(number, word));
		++number;
	}
}

unsigned int GetLetterCount(unsigned int max)
{
	unsigned int count = 1;
	unsigned int sum = 0;
	map<unsigned int, pair< unsigned short , string > >::iterator itr = list.begin();
	
	while( ( count <= max ) && ( itr != list.end() ) )
	{
		//cout << "number : " << count << " Size : " << itr->second.first << " Word : " << itr->second.second.c_str() << "\n";
		sum = sum + itr->second.first;
		count++;
		itr++;
	}
	
	return sum;
}

void PrintList()
{
	map<unsigned int, pair< unsigned short , string > >::iterator itr = list.begin();
	
	while( itr != list.end() )
	{
		cout << "number : " << itr->first << " Size : " << itr->second.first << " Word : " << itr->second.second.c_str() << "\n";
		++itr;
	}
}

int main()
{
	InitList();
	FormList();
	cout << "List size() : " << list.size() << "\n";
	
	//cout << "****************************************************\n";
	
	//PrintList();
	
	cout << "Letter Count : " << GetLetterCount(1000) << endl;
	
	return 0;
}
