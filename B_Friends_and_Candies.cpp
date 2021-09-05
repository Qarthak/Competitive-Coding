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
		ll sum=0;
		for(auto i : a){
			sum+=i;
		}
		if(sum%n!=0)
		{
			cout << -1 << "\n" ;
			continue;
		}
		ll av=sum/n;
		int count=0;
		for(auto i : a){
			if(i>av)
				count++;
		}
		cout << count << "\n" ;
	}
}