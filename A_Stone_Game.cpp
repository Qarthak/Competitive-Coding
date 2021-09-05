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

typedef long long ll;

int gcd(int frst, int scnd)
{
    if (scnd == 0)
        return frst;
    return gcd(scnd, frst % scnd);
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
		ll a[n];
		for (size_t i=0; i<n; i++){
			cin >> a[i] ;
		}
		int minn=0;
		int maxx=0;
		for (size_t i=0; i<n; i++){
			if (a[minn]>a[i])
			{
				minn=i;
			}
			if (a[maxx]<a[i])
			{
				maxx=i;
			}
		}
		int sum=max(maxx,minn)+1;
		
		if(sum>n-min(maxx,minn))
			sum=n-min(maxx,minn);
		if(sum>n-minn+maxx+1)
			sum=n-minn+maxx+1;
		if(sum>n-maxx+minn+1)
			sum=n-maxx+minn+1;
		cout << sum << "\n" ;

	}
}