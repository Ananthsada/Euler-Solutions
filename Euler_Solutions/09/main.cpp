#include <iostream>

using namespace std;

int main()
{
	int a,b,c; 
	
	for( int i = 1 ; i < 998 ; i++ )
	{
		for( int j = ( 1000 - i - 1 ) ; j >= 1 ; j-- )
		{
			int k = 1000 - i - j;
			
			if( ( ( i * i ) + ( j * j ) ) == ( k * k ) )
			{
				a = i;
				b = j; 
				c = k;
				break;
			}
		}
	}
	cout << a*b*c << "\n";
	return 0;
}
