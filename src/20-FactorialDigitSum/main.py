
def GetSumofNumber(number):
	sum_local = 0;
	print("Required Number : %r, to get sum" %(number))
	while( number > 0 ):
		sum_local = sum_local + ( number % 10 );
		number = number / 10;
	return sum_local
	
def Factorial(num):
	if( num <= 1 ):
		return 1;
	else:
		return num * Factorial(num - 1 );

def main():
	FactorialOut = Factorial(100);
	FactorialSum = GetSumofNumber(FactorialOut);
	print("Sum of digits of 100! : %r" %( FactorialSum ) );
	
main();
