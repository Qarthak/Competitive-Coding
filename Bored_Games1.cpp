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

#define eql( zst , ost , lgo ) ( zst == ost ) && ( zst == lgo )
#define iose     ios_base::sync_with_stdio()
#define iff( zst , ost )		if  ( zst == ost )
#define between( frst , scnd, thrd )	frst >= scnd  && frst <= thrd

typedef long long ll;

int gcd(int frst, int scnd)
{
    if (scnd == 0)
        return frst;
    return gcd(scnd, frst % scnd);
}

ll cache[100000]={};

ll m=100;
ll mod=10E8+7;


long long answer(ll n)
{
	if(n<m)
	{
		return 1;
	}
	if(cache[n]==0)
		cache[n]= ( answer(n-m)%mod + answer(n-1)%mod ) %mod;
	return cache[n]%mod;

}

int main()
{
    iose;
    long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin >> n>>m ;
		// cin >> n ;
		for (long long i=0; i<=n; i++){
			cache[i]=0;
		}
		cout << answer(n) << "\n" ;
	}
}