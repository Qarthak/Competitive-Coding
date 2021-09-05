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

struct point{
	ll x,y;
};

bool customComparex(point p1, point p2)
{
    return (p1.x < p2.x);
}

bool customComparey(point p1, point p2)
{
    return (p1.y < p2.y);
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
		long long n;
		cin >> n ;
		point a[n];
		point sortx[n];
		point sorty[n];
		for (long long i=0; i<n; i++){
			cin>>(a[i]).x>>(a[i]).y;
			(sortx[i]).x=(a[i]).x;
			(sortx[i]).y=(a[i]).y;
			(sorty[i]).x=(a[i]).x;
			(sorty[i]).y=(a[i]).y;
		}
		sort(sortx,sortx+n,customComparex);
		sort(sorty,sorty+n,customComparey);
		ll gapx=0,gapy=0;
		for(auto i : sortx){
			if(i.x>gapx)
				gapx=i.x;
		}
		for(auto i : sorty){
			if(i.y>gapy)
				gapy=i.y;
		}
		ll rangex=(sortx[n-1]).x-(sortx[0]).x;
		ll rangey=(sorty[n-1]).y-(sorty[0]).y;
		


	}
}