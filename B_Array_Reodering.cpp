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
		ll evenCnt=0;
		cin >> n ;
		ll a[n];
		for (size_t i=0; i<n; i++){
			cin >> a[i] ;
			if(a[i]%2==0)
			{
				evenCnt++;
				a[i]=1;
			}
		}
		ll ans=((2*n-evenCnt-1)*evenCnt)/2;
		for (size_t i=0; i<n; i++){
			for (size_t j=i+1; j<n; j++){
				if(gcd(a[i],a[j])!=1)
				{
					ans++;
				}
			}
		}
		cout << ans << "\n" ;
	}
}