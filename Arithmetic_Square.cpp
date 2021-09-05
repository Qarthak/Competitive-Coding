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
#define _xPutNameHere( frst , scnd , thrd) ( ( frst  scnd )  ( scnd  thrd) )
#define evenEquals( frst , scnd ) (( (frst)%2)?(scnd):(frst))

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


int main(){
	iose;
	cin.tie(NULL);
	long long t=0;
	cin>>t;
	ll tt=0;
	int locall=0;
	while(t--){
		tt++;
		long long n,m;
		n=3,m=3;
		ll a[n][m];
		for (long long i=0; i<n*m; i++){
			if(i==4)
				continue;
			cin >> a[0][i] ;
		}
		a[1][1]=1E15;
		ll count=0;
		if(a[0][0]+a[0][2]==2*a[0][1]){
			count++;
		}
		if(a[2][0]+a[2][2]==2*a[2][1]){
			count++;
		}
		if(a[0][2]+a[2][2]==2*a[1][2]){
			count++;
		}
		if(a[0][0]+a[2][0]==2*a[1][0]){
			count++;
		}
		int tot=abs(accumulate(a[0],a[0]+9,0));
		ll poss[4];
		poss[0]=((a[1][0]+a[1][2])%2)?(1E15+tot):(a[1][0]+a[1][2]);
		poss[1]=evenEquals(a[0][1]+a[2][1],1E15+tot+23);
		poss[2]=evenEquals(a[0][0]+a[2][2],1E15+tot+25352);
		poss[3]=evenEquals(a[2][0]+a[0][2],1E15+tot+4324326);
		sort(poss,poss+4);
		if(poss[0]<a[1][1])
			a[1][1]=poss[0];
		for (long long i=1; i<4; i++){
			if(poss[i]==poss[i-1]){
				a[1][1]=poss[i]/2;
				while(i<4&&poss[i]==poss[i-1]){
					count++;
					i++;
				}
				goto endd;
			}
		}
		endd:
		if(a[1][1]<1E15){
			count++;
		}
			cout <<"Case #"<<tt<<": "<< count << endl ;
		// if(count==0){
		// 	locall++;
		// 	cout << tt << endl ;
		// 	for(auto i : a){
		// 		cout << i[0] zspace i[1] zspace i[2] << endl ;
		// 	}
		// 	cout  << endl ;
		// }
	}
	// cout << locall << endl ;
}