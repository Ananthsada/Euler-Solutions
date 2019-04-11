#include <iostream>

#define GRID_SIZE 21

unsigned int count = 0;

using namespace std;

void CalculatePath( unsigned int row, unsigned int column )
{
	if( ( row * column ) == ( ( GRID_SIZE - 1 ) * ( GRID_SIZE - 1 ) ) ) 
	{
		count = count + 1;
		cout << count << "\n";
		return;
	}
	if( column < ( GRID_SIZE - 1 ) )
	{
		CalculatePath( row, column + 1 );
	}
	if( row < ( GRID_SIZE - 1 ) )
	{
		CalculatePath( row + 1, column );
	}
}

int main()
{	
	CalculatePath( 0, 0 );
	cout << count << "\n";
	return 0;
}
