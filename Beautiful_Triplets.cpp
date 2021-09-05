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

typedef long long ll;

#define mod (1000000007)
#define eql( zst , ost , lgo ) (( zst == ost ) && ( zst == lgo ))
#define iose	ios_base::sync_with_stdio()
#define max3( frst , scnd , thrd )		max( max ( frst , scnd ) , thrd )


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

// Find number of factor works weirdly with square roots
// Accumulate(start,end,0) why?
//int to bool to int 
// 10E7 vs 1E7
int main()
{
	iose;
	cin.tie(NULL);
	ll n,d;
	cin>>n>>d;
	int a[20000]={};
	for (long long i=0; i<n; i++){
		int temp;
		cin >> temp ;
		a[temp]++;
	}
	ll ans=0;
	for (long long i=0; i<20000-2*d; i++){
		ans+=a[i]*a[i+d]*a[i+d+d];
		
	}
	cout << ans << "\n" ; 
}