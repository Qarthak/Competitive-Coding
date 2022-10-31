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
typedef vector<vi> vvi;
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
#define xspace(s) << (s) <<
#define rep(frst, scnd)	for (long long frst=0; frst<scnd; frst++)
// #define errr (1E-18);
// #define moddd (1E9+7);
#define _xPutNameHere( frst , scnd , thrd) ( ( frst  scnd )  ( scnd  thrd) )

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

// template <typename T>
void zprint(vector<int> a){
	for(auto i:a){
		cout << i << " " ;
	}
	cout << endl ;
}

void zprint(){
	cout  << endl ;
}

template<typename T, typename ...Rest>
T zprint(T a, Rest ...rest){
	cout << a << " " ;
	zprint(rest...);
	return a;
}

template<typename T>
T xxx(T a, ...){
	return a;
}

ll prep[1]={};
// Learn more about static and lvalues and rvalues

vi intToVector(ll n){
	vi ans;
	while(n!=0){
		ans.push_back(n%10);
		n/=10;
	}
	reverse(beginToEnd(ans));
	return ans;
}

int main(){
	iose;
	cin.tie(NULL);
	int upper=1E8;
	long long t=0;
	cin>>t;
	while(t--){
		long long x,y;
		cin >> x>>y ;
		vi X=intToVector(y);
		// vi Y=intToVector(y);
		// zprint(X);
		// zprint(Y);
		
		const int n=1000;
		vector<bool> isPrime(n,1);
		isPrime[0]=0;
		isPrime[1]=0;
		for (long long i=2; i<n; i++){
			if(isPrime[i]){
				for(int j=2*i; j<n; j+=i){
					isPrime[j]=0;
				}
			}
		}
		
		// for (long long i=0; i<30; i++){
		// 	cout << isPrime[i] << " " ;
		// }
		
		map<tuple<int,int,bool>,ll> dp;
		
		auto count=[&](int pos, int sum, bool flip, auto&& count)->ll{
			if(pos>=X.size()){
				xxx(sum);
				return isPrime[sum];
			}
			if(dp.count({pos,sum,flip})){
				return dp[{pos,sum,flip}];
			}
			ll tot=0;
			for(int i=0; i<=(xxx(flip?X[pos]:9,">")); i++){
				xxx(i,":");
				tot+= count(pos+1, sum+i, flip*(i==X[pos]), count);
			}
			return dp[{pos,sum,flip}]=tot;
		};
		ll ans=0;
		ans=count(0,0,1,count);
		// X.clear();
		dp.clear();
		X=intToVector(x-1);
		ans-=count(0,0,1,count);
		cout << ans << endl ;
	}
}
