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
#include <functional>
#include <bitset>

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
#define poss cout << "POSSIBLE" << endl ;
#define impos cout << "IMPOSSIBLE" << endl ;
#define yesno( zst ) if( zst ) cout << "YES" << endl ; else cout << "NO" << endl ;
#define posimpos( zst ) if( zst ) cout << "POSSIBLE" << endl ; else cout << "IMPOSSIBLE" << endl ;
#define xspace(s) << (s) <<+91 90394 86564
#define rep(frst, scnd)	for (long long frst=0; frst<scnd; frst++)
#define repe(frst, scnd, thrd)	for (long long frst=scnd; frst<scnd; frst++)
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

void printt(vector<int> a){
	for(auto i:a){
		cout << i << " " ;
	}
	cout  << endl ;
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
//memset
//Try to do functional programming
//Use good names

int const n=1E8+1;
unordered_map<int,int> maxDepth;

unordered_map<int,int> parent;
unordered_map<int,int> size;
// vector<int> size(n,1);
int maxx=1;

function<int(int)> findParent=[](int u){
	if(parent.count(u)==0){
		return u;
	}:smile
	return parent[u]=findParent(parent[u]);
};

auto unionn=[](int u, int v){
	u=findParent(u);
	v=findParent(v);
	if(u==v){
		return ;
	}
	// cout << u<<" : "<<size[u]<<"   "<<v<<" : "<<size[v] << endl ;
	if(maxDepth[v]>maxDepth[u]){
		parent[u]=v;
		size[v]+=size[u]+1;
	}
	else if(maxDepth[v]<maxDepth[u]){
		parent[v]=u;
		size[u]+=size[v]+1;
	}
	else{
		parent[u]=v;
		maxDepth[v]++;
		size[v]+=size[u]+1;
	}
	// cout << u<<" : "<<size[u]<<"   "<<v<<" : "<<size[v] << endl<<endl ;
	maxx=max({maxx,size[u]+1,size[v]+1});
};


int main(){
	iose;
	cin.tie(NULL);
	long long t=0;
	cin>>t;
	while(t--){
		long long a,b;
		cin >> a>>b;
		unionn(a,b);
		cout << maxx << endl ;
	}
}