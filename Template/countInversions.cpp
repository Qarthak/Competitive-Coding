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
    if(frst>scnd)
		global+=(frst-scnd);
	return frst<scnd;
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
	vector<int> a={1312,21212,213,4,233212,531,232,61,432,213};
	int answer=0;
	int n=a.size();
	// for (long long i=0; i<n; i++){
	// 	for (long long j=i+1; j<n; j++){
	// 		if(a[j]<a[i])
	// 			answer++;
	// 	}
	// }
	// cout << answer << "\n" ;
	sort(a.begin(),a.end(),customCompare);
	cout << global << "\n" ;
}