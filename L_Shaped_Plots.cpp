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
#include <cstring>

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
#define repe(frst, scnd)	for (long long frst=0; frst<scnd; frst++)
// #define errr (1E-18);
// #define moddd (1E9+7);
#define _xPutNameHere( frst , scnd , thrd) ( ( frst  scnd )  ( scnd  thrd)

ll modd= (1000000007);
ld errr=1E-18;
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

// int check(int **a, int  )

int main(){
	iose;
	cin.tie(NULL);
	long long t=0;
	cin>>t;
	while(t--){
		long long r,c;
		cin >> r>>c ;
		bool a[r][c];
		ll n=r*c;
		for (long long i=0; i<n; i++){
			cin >> a[0][i] ;
		}
		ll count=0;
		// int len=0;
		int rowprefix[r][c]={};
		int rowsuffix[r][c]={};
		int colprefix[r][c]={};
		int colsuffix[r][c]={};
		repe(col,c) repe(row,r){
			if(a[col][row]){
				rowprefix[col][row]=(row-1>=0)?rowprefix[col][row-1]+a[col][row]:1;
				rowsuffix[col][row]=(row+1<n)?rowsuffix[col][row+1]+a[col][row]:1;
			}
		}
		repe(row,r) repe(col,c){
			if(a[col][row]){
				colprefix[col][row]=(col-1>=0)?colprefix[col-1][row]+a[col][row]:1;
				colsuffix[col][row]=(col+1<n)?colsuffix[col+1][row]+a[col][row]:1;
			}
		}
		repe(col,c) repe(row,r){
			if((rowprefix>1)){

			}
		}
	}
}