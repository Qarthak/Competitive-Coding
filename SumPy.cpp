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
typedef unsigned int usi;

#define mod (1000000007)
#define eql( zst , ost , lgo ) (( zst == ost ) && ( zst == lgo ))
#define iose	ios_base::sync_with_stdio()
#define frr( indx , strt , lst )	for ( long long indx = strt ; indx < lst ; ++indx )

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



int const n=1000000;
ll psqrt=sqrt(n);
unsigned long long p[n+100]={};
unsigned long long sum[n+100]={};
	
int main()
{
	// n=20;
	iose;
	cin.tie(NULL);
	for (int i=1; i<=n; i++){
		for (int j=i; j<=n; j+=i){
			p[j]+=i;
		}
	}
	
	for (int i=1; i<=n; i++){
		sum[i]=sum[i-1]+p[i];
		// if(sum[i]>=INT_MAX/2)
		// 	cout << "WARN" << "\n" ;
		// if(sum[i]<=sum[i-1])
		// 	cout << "NO"<<i << "\n" ;
	}
	// cout << p[100] << "\n" ;
	// cout << sum[n]<<" "<< INT_MAX << "\n" ;
	// for (long long i=n-30; i<n; i++){
	// 	cout << sum[i] << "\n" ;
	// }
	long long t=0;
	cin>>t;
	while(t--)
	{
		long long l,r;
		cin >> l>>r ;
		cout << sum[r]-sum[l-1] << "\n" ;
		// ll ans=0;
		// for (long long i=1; i<=r-l; i++){
		// 	if((r%i)<=(r-l))
		// 			ans+=(i*   ( (r-l-r%i)/i + 1  ) )  ;
		// }
		// for (long long i=(r-l)+1; i<=r/2; i++){
		// 	if((r%i)<=(r-l))
		// 		ans+=i;
		// }
		// if(r/2+1>l||l<r-l+1)
		// 	l=max(r/2+1,r-l+1);
		// ans+=((r-l+1)*(l+r))/2;
		// cout << ans << "\n" ;
	}
}