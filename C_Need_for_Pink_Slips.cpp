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
typedef long double ld;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

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
	int totall=0;
	for (long long i=1; i*i<=foo; i++){
		if(foo%i==0){
			totall+=(i*i==foo)?1:2;
		}
	}
	return totall;
}

int dfs(vector<int> *AdjacencyList, int Node, int parent)
{
	vector<int> nodeList=AdjacencyList[Node];
    if(nodeList.size() == 1 and nodeList[0] == parent)
        return 1;
	int sum=0;
    for(int v: nodeList)
    {
        if(v == parent)
            continue;
        sum+=dfs(AdjacencyList,v,Node);
    }
	return sum;
}

ll prep[1]={};
//Putting it here vs putting it inside main
//Find number of factor works weirdly with square roots
//memset
//Try to do functional programming

ld errr=1E-18;
ll checkk=0;
ld recurse(ld c, ld m, ld p, ld v, int n, ld prob){
	checkk++;
	// printf("c=%Le m=%Le p=%Le v=%Le n=%d prob=%Le\n",c,m,p,v,n,prob);
	if(prob<=errr)
		return 0.00000000000;
	ld c1=max(c-v,c-c);
	ld m1=max(m-v,c-c);
	if(c>errr and m>errr)
		return n*prob*p+recurse(c1,m+(c-c1)/2,p+(c-c1)/2,v,n+1,prob*c)+recurse(c+(m-m1)/2,m1,p+(m-m1)/2,v,n+1,prob*m);
	else if(c>errr)
		return n*prob*p+recurse(c1,0,p+(c-c1),v,n+1,prob*c);
	else if(m>errr)
		return n*prob*p+recurse(0,m1,p+(m-m1),v,n+1,prob*m);
	else
		return n*prob*p;
}

int main(){
	iose;
	cin.tie(NULL);
	long long t=0;
	// ld a=0.142857142857142857142857142857;
	// cout << "actual       0.142857142857142857142857142857" << endl ;
	// ld a=1;
	// cout <<fixed<<setprecision(30)<<"long double  "<< (a/7)*8 << endl ;
	// double y=1;
	// cout <<fixed<<setprecision(30)<<"double       "<< (y/7)*8 << endl ;
	// float x=1;
	// cout <<fixed<<setprecision(30)<<"float        "<< (x/7)*8 << endl ;
	
	cin>>t;
	while(t--){
		checkk=0;
		long double c,m,p,v;
		cin >> c>>m>>p>>v ;
		cout<<fixed<<setprecision(12)<< recurse(c,m,p,v,1.00,1.00) <<endl;
		// cout << checkk << endl ;
	}
}