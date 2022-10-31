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

template <typename T>
void printt(vector<T> a){
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

vector<int> intToVector(ll n){
	vector<int> N;
	while(n!=0){
		N.push_back(n%10);
		n/=10;
	}
	reverse(N.begin(), N.end());
	return N;
}


int main(){
	iose;
	cin.tie(NULL);
	const int max_nonzero=3;
	long long t=0;
	cin>>t;
	while(t--){
		long long n,m;
		cin >> n>>m ;
		n-=1;
		vector<int> N(intToVector(n));
		
		map<tuple<int,int,bool>,ll> dp;
		
		auto count=[&](auto &&count, ll pos, ll rem, bool flip) -> ll{
			if(N.empty()){
				return 1;
			}
			if(rem==-1){
				return 0;
			}
			if(pos>=N.size()){
				// cout << endl ;
				return 1;
			}
			if(dp.count({pos,rem,flip})){
				return dp[{pos,rem,flip}];
			}
			
			ll summ=0;
			for(int i=0; i<=(flip?N[pos]:9); i++){
				summ+= count(count, pos+1, rem-(i!=0), (i==N[pos])*flip );
			}
			return dp[{pos,rem,flip}] = summ;
		};
		
		
		ll ans = count(count,0,max_nonzero, 1);
		
		dp.clear();
		
		// cout <<"ans="<< ans << endl ;
		
		N=intToVector(m);
		ans-=count(count, 0, max_nonzero, 1);
		ans*=-1;
		cout << ans << endl ;
	}
	
}
