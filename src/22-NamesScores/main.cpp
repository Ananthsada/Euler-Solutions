#include <iostream>
#include <map>
#include <iterator>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
       
#define WORD_UNKNOWN	0
#define WORD_START 		1
#define WORD_END   		2

#define FILE_NAME 		"./names.txt"

#define BYTES_TO_READ 	1

using namespace std;

int fd = -1;
map<string, unsigned int> list;

void InsertList( char* buffer, unsigned int sum )
{
	pair<string, unsigned int> pair_to_insert;
	string name( reinterpret_cast<const char*>(buffer) );
	
	pair_to_insert = make_pair(name,sum);
	list.insert(pair_to_insert);
	
}

void PrintList()
{
	map<string, unsigned int>::iterator itr;
	
	for( itr = list.begin() ; itr != list.end() ; itr++ )
	{
		cout << "Name : " << itr->first.c_str() << " Letter Sum : " << itr->second << "\n";
	}
}

void CalculateNameScores()
{
	unsigned long long NameScore = 0;
	unsigned int index = 1;
	map<string, unsigned int>::iterator itr;
	
	for( itr = list.begin() ; itr != list.end() ; itr++ )
	{
		NameScore = NameScore + ( index * itr->second );
		++index;
	}	
	cout << "NameScore : " << NameScore << "\n";
}

int process_file()
{
	int WordStatus = WORD_UNKNOWN;
	int read_bytes = -1;
	unsigned int index = 0;
	unsigned int sum = 0;
	char buffer[2];
	char word[50];
	
	(void)memset(&word[0], 0, 50);
	
	while(true)
	{
		read_bytes = read( fd, &buffer[0], BYTES_TO_READ);
		if( read_bytes < BYTES_TO_READ )
		{
			if( read_bytes == -1 )
			{
				cout << "File read failed " << strerror(errno) << "\n";
			}
			else
			{
				cout << "File read completed " << strerror(errno) << "\n";
				break;
			}
		}
		else
		{
			if( WordStatus == WORD_UNKNOWN )
			{
				if( buffer[0] == '"' )
				{
					WordStatus = WORD_START;
				}
				else
				{
					cout << "Invalid Sequence occured, WordStatus : " << WordStatus << " Character read : " << buffer[0] << "\n";
				}
			}
			else if( WordStatus == WORD_START )
			{
				if( buffer[0] == '"' )
				{
					InsertList(&word[0],sum);
					index = 0;
					sum = 0;
					(void)memset(&word[0], 0, 50);
					WordStatus = WORD_END;
				}
				else
				{
					word[index] = buffer[0];
					sum = sum + ( word[index] - 64 );
					++index;
				}				
			}
			else
			{
				if( buffer[0] == '"' )
				{
					WordStatus = WORD_START;
				}
				else
				{
					/**
					 * Nothing to do just continue preprocessing
					 * */
				}
			}
		}
		
	}
}

int main()
{
	fd = open(FILE_NAME,O_RDONLY);
	if( fd < 0 )
	{
		cout << "Not able to open file " << FILE_NAME << "\n";
	}
	else
	{
		process_file();
		PrintList();
		CalculateNameScores();
	}
	return 0;
}
