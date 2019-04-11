#include <iostream>

#define NUM_TO_CAL 100

using namespace std;

long long GetSumofSquare(long long count)
{
	return ( count * ( count + 1 ) * ( ( 2 * count  ) + 1 ) / 6 );
}

long long GetSquareofSum(long long count)
{
	long long retval = ( count * ( count + 1 ) / 2 );
	return retval * retval;
}

int main()
{
	long long diff = 0;
	
	diff = GetSquareofSum( NUM_TO_CAL ) - GetSumofSquare( NUM_TO_CAL );
	
	cout << diff << "\n";
	
	return 0;
}
