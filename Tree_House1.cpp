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
#include <iomanip>
#include <ios>

using namespace std;

typedef long long ll;

#define endl (char(10))
#define zspace << " " <<
#define areEqual( zst , ost , lgo ) (( zst == ost ) && ( zst == lgo ))
#define iose	ios_base::sync_with_stdio()
#define isAscending( frst , scnd , thrd ) ( ( frst <= scnd ) && ( scnd <= thrd ) )
#define startToEnd( zst )   (zst.begin())  ,  (zst.end())
#define yess cout << "YES" << endl ;
// // // // // // // // // // #define noo cout << "NO" << endl ;
#define pos cout << "POSSIBLE" << endl ;
#define impos cout << "IMPOSSIBLE" << endl ;
// #define yesno( zst ) if( zst ) cout << "YES" << endl ; else cout << "NO" << endl ;
// #define posimpos( zst ) if( zst ) cout << "POSSIBLE" << endl ; else cout << "IMPOSSIBLE" << endl ;
#define _xPutNameHere( frst , scnd , thrd) ( ( frst  scnd )  ( scnd  thrd)
#define xspace(s) zspace (s) zspace

ll mod= (1000000007);
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

long long npowerofm(ll base,ll powerr, ll modd=1000000007)
{
	if(powerr==0)
		return 1;
	ll tempp=(npowerofm(base,powerr/2,modd))%modd;
	return ( ( (tempp*tempp)%modd )*( (powerr%2)?base:1) )%modd;
}

int numOfFactors(ll foo)
{
	int count=0;
	for (long long i=1; i*i<=foo; i++){
		if(foo%i==0){
			count+=(i*i==foo)?1:2;
		}
	}
	return count;
}

ll yelllllow=0;

ll p[1]={};
//Putting it here vs putting it inside main
//Find number of factor works weirdly with square roots
//memset
//Try to do functional programming

unsigned long long add(vector<unsigned long long> &a){
	unsigned long long summ=0;
	// cout << "ADD" << "\n" ;
	unsigned long long n=a.size();
	sort(a.begin(),a.end());
	for (size_t i=0; i<n; i++){
		summ=(summ+(n-i)*a[i]);
	}
	return summ;
}

unsigned long long solve(vector<unsigned long long> *a, int x){
	// cout xspace("first") x << "\n" ;
	int m=a[x].size();
	// cout xspace("second") x << "\n" ;
	if(m==0)
		return 1;
	vector<unsigned long long> temp(m,0);
	// cout xspace("third") x << "\n" ;
	for (long long i=0; i<m-1; i++){
		
		// if(a[x][i]!=0 )
		// {
			// cout << x << "\n" ;
			temp[i]=solve(a,a[x][i]);
		// }
		// cout xspace("third") x zspace i << "\n" ;
		
	}
	// cout << "CALLED" << x << "\n" ;
	return 1+add(temp);
}

void correctt(vector<unsigned long long> *a, int x)
{
	int n=a[x].size();
	for (long long i=0; i<n; i++){
		int y=a[x][i];
		auto it=find( startToEnd(a[y]) ,x );
		*it=0;
		correctt(a,a[x][i]);
	}
}

int main()
{
    unsigned long long t;	cin>>t;
	while(t--){
		unsigned long long n;
		cin >> n ;
		unsigned long long X;
		cin>>X;
		vector<unsigned long long> a[n+1];
		
		for(unsigned long long i=0;i<n-1;i++){
			unsigned long long x,y;
			cin >> x>>y ;
			a[x].push_back(y);
			// a[y].push_back(x);
		}
		// correctt(a,1);
		// for(auto i : a){
		// 	for(auto& j : i){
				// cout << j << " " ;
		// 	}
			// cout  << endl ;
		// }
		cout << ((solve(a,1)%mod)*(X%mod))%mod << "\n" ;
	}
}


