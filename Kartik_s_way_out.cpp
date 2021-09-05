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
#define beginToEnd( zst )   (zst.begin())  ,  (zst.end())
#define yess cout << "YES" << endl ;
#define noo cout << "NO" << endl ;
#define pos cout << "POSSIBLE" << endl ;
#define impos cout << "IMPOSSIBLE" << endl ;
#define yesno( zst ) if( zst ) cout << "YES" << endl ; else cout << "NO" << endl ;
#define posimpos( zst ) if( zst ) cout << "POSSIBLE" << endl ; else cout << "IMPOSSIBLE" << endl ;
#define xspace(s) << (s) <<
#define _xPutNameHere( frst , scnd , thrd) ( ( frst  scnd )  ( scnd  thrd)

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


ll p[1]={};
//Putting it here vs putting it inside main
//Find number of factor works weirdly with square roots
//memset
//Try to do functional programming

void treeDoubleToSingle(vector<int> *a, int x/* , int *p */)
{
	int n=a[x].size();
	if(n==0)
		return;
	for (long long i=0; i<n; i++){
		int child=a[x][i];
		ll j;
		int m=a[child].size();
		for (j=0; j<m; j++){
			if(a[child][j]==x)
			{
				a[child].erase(a[child].begin()+j);
				break;
			}
		}
		treeDoubleToSingle(a,child);
	}
}




int n,k;

ll dfs(vector<int> *a, bool *trap, ll x, ll c){
	c=(trap[x]==1)?c+1:0;
	if(c>k) return 0;
	if(a[x].empty()) return 1;
	int n=a[x].size();
	ll sum=0;
	for (long long i=0; i<n; i++){
		sum+=dfs(a,trap,a[x][i],c);
	}
	return sum;
}



int main(){
	iose;
	cin.tie(NULL);
	cin >> n>>k ;
	bool trap[n+1];
	for (long long i=1; i<n+1; i++){
		cin >> trap[i] ;
	}
	vector<int> a[n+1];
	for (long long i=0; i<n; i++){
		int x,y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	treeDoubleToSingle(a,1);
	cout<<dfs(a,trap,1,0);
	
}