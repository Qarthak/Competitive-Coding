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

// bool compareInterval(Interval i1, Interval i2)
// {
//     return (i1.start < i2.start);
// }

long long npowerofm(ll n,ll m)
{
	if(m==0)
		return 1;
	ll temp=(npowerofm(n,m/2))%mod;
	return (((temp*temp)%mod)*(m%2?n:1))%mod;
}

int main()
{
	iose;
	

}