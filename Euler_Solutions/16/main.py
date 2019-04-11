
def GetSumofNumber(number):
	sum_local = 0;
	print("GetSumofNumber : 2^1000 - %r" %(number))
	while( number > 0 ):
		sum_local = sum_local + ( number % 10 );
		number = number / 10;
	return sum_local

def main():
	number = 1;
	sum_local = 0
	for each in range(1000):
		number = number * 2;
	print("2^1000 - %r" %(number))
	sum_local = GetSumofNumber(number)
	print("sum of digits %r" %(sum_local))

main()
