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
#include <climits>
using namespace std;

typedef long long ll;

#define mod (1000000007)
#define eql( zst , ost , lgo ) (( zst == ost ) && ( zst == lgo ))
#define iose	ios_base::sync_with_stdio()
#define isAscending( frst , scnd , thrd ) ( ( frst <= scnd ) && ( scnd <= thrd ) )

ll cache[1]={};
ll global=0;

int gcd(int frst, int scnd)
{
	if (scnd == 0)
		return frst;
	return gcd(scnd, frst % scnd);
}

struct EnterStructName{
	ll EnterFirstElementName;
};

bool compareStruct(EnterStructName i1, EnterStructName i2)
{
    return (i1.EnterFirstElementName < i2.EnterFirstElementName);
}

bool customCompare(ll frst,ll scnd)
{
    return (frst < scnd);
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

ll p[1]={};
//Putting it here vs putting it inside main
//reassigning answer after getting it right is a huge issue. Break if possible
int main()
{
	iose;
	cin.tie(NULL);
	long long t=0;
	cin>>t;
	while(t--)
	{
		int n;
		cin >> n ;
		int a[n];
		int ans=0;
		int sum=0;
		for (long long i=0; i<n; i++){
			cin >> a[i] ;
			if(isAscending(1,a[i],7))
				sum+=a[i];
			if(sum==28 && ans==0 )
				ans=i+1;
		}
		cout << ans << "\n" ;
	}
}