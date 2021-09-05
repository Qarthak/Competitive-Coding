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
    ll n,k;
	cin>>n>>k;
	k%=n;
	ll a[n];
	for (long long i=0; i<n; i++){
		if(i+k<n)
			cin>>a[i+k];
		else{
			cin>>a[i+k-n];
		}
	}
	for (long long i=0; i<n; i++){
		cout << a[i] << " " ;
	}

}