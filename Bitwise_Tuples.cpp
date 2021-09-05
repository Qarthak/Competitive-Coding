#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define mod (1000000007)
#define eql( zst , ost , lgo ) (( zst == ost ) && ( zst == lgo ))
#define iose	ios_base::sync_with_stdio()

typedef long long ll;

int gcd(int frst, int scnd)
{
	if (scnd == 0)
		return frst;
	return gcd(scnd, frst % scnd);
}

long long npowerof2(ll n)
{
	if(n==0)
		return 1;
	if(n==1)
		return 2;
	ll temp=(npowerof2(n/2))%mod;
	ll x= (((temp*temp)%mod)*(npowerof2(n%2)))%mod;
	return x;
}

long long npowerofm(ll n,ll m)
{
	if(m==0)
		return 1;
	if(m==1)
		return n;
	ll temp=(npowerofm(n,m/2))%mod;
	return (((temp*temp)%mod)*(npowerofm(n,m%2)))%mod;
}

int main()
{
	iose;
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,m;
		cin >> n>>m ;
		ll x=npowerof2(n)-1;
		// cout << x << "\n" ;
		cout << npowerofm(x,m) << "\n" ;

	}
}