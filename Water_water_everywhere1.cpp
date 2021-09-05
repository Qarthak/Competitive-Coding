#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
	if (b==0)
	return a;
	return gcd(b, a%b);
}

long long solve(long long m, long long n, long long d)
{
	if (m > n)
		swap(m, n);
	if (d > n+m)
		return 0;
	if ((d % gcd(n,m)) != 0)
		return 0;

	return 1;
}

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long a,b,n;
		cin >> a>>b>>n ;
		if(solve(a,b,n))
		{
			cout << "Possible" << "\n" ;
		}
		else{
			cout << "Not Possible" << "\n" ;
		}
		
	}
	return 0;
}
