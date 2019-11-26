#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
bool isprimer(int n)
{
	if (n == 1) 
		return false;
	for (int d = 2; d*d <= n; d++) 
		{
		if (n%d==0)
			return false;
		}

	return true;
}

//to figure out who will win we have to count the prime numbers
//because if one player removes one prime number he also removes allof its multiples from set
//and our result is divided by 2, it means Bob wins, otherwise Alice wins.

// finding prime numbers with sieve of eratosthenes
string count_prime(int n) {
	int count = 0;
	int *a = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
		a[i] = i;
	for (int p = 2; p < n + 1; p++)
	{
		if (a[p] != 0)
		{
			
			++count;
			for (int j = p; j < n + 1; j += p)
				a[j] = 0;
		}
	}
	
	if (count % 2 == 0)
		return "Bob";
	else return "Alice";
}
int main() {
	int n;
	cin >> n;
	cout<<count_prime(n);
	system("pause");
	return 0;
}