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
#define spaced( frst , scnd , thrd )  cout << frst <<" "<<scnd<<" "<<thrd<< "\n"


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

// Find number of factor works weirdly with square roots
// Accumulate(start,end,0) why?

int main()
{
	iose;
	cin.tie(NULL);
	long long t=0;
	cin>>t;
	while(t--)
	{
		long long n;
		cin >> n ;
		int a[n];
		for (long long i=0; i<n; i++){
			cin >> a[i] ;
		}
		if(n==3)
		{
			if eql(a[0],a[1],a[2])
			{
				if(a[0]==0)
				{
					cout << -1 << "\n" ;
					continue;
				}
				cout << 1 << "\n" ;
				cout << 0<<" "<<2<<" "<<1 << "\n" ;
			}
			else if(0==a[1])
			{
				cout << 1 << "\n" ;
				spaced(0,1,2);
			}
			else if(a[0]==a[2])
				cout << 0 << "\n" ;
			else
				cout << -1 << "\n" ;
		}
		else if(n==1)
			cout << 0 << "\n" ;
		else if(n==2)
		{
			if(a[0]==a[1])
				cout << -1 << "\n" ;
			else
				cout << 0 << "\n" ;
		}
		else
		{
			if(a[0]!=a[2])
			{
				for (long long i=1; i<n; i+=2){
					spaced(0,2,i);
				}
				for (long long i=0; i<n; i+=2){
					spaced(1,3,i);
				}
				cout << n << "\n" ;
			}
			else if(a[0]!=0)
			{
				for (long long i=1; i<n; i+=2){
					spaced(0,2,i);
				}
				for (long long i=4; i<n; i+=2){
					spaced(0,1,i);
				}
				cout << n << "\n" ;
			}
			else
			{
				int j;
				for (j=0; j<n; j++){
					if(a[j]!=a[0]){
						break;
					}
				}
				if(j==n)
					cout << -1 << "\n" ;
				else
				{
					
					if( (j) %2==0)
					{
						cout << n << "\n" ;
						for (long long i=1; i<n; i+=2){
							spaced(0,j,i);
						}
						for (long long i=0; i<n; i+=2){
							spaced(1,3,i);
						}
					}
					else
					{
						cout << n-1 << "\n" ;
						for (long long i=1; i<n; i++){
							if(i!=j)
							{
								spaced(j,0,i);
							}
						}
						for (long long i=4; i<n; i++){
							spaced(0,2,i);
						}
					}
				}
			}
		}
	}
}