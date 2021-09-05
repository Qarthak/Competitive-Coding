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
#define poss cout << "POSSIBLE" << endl ;
#define impos cout << "IMPOSSIBLE" << endl ;
#define yesno( zst ) if( zst ) cout << "YES" << endl ; else cout << "NO" << endl ;
#define posimpos( zst ) if( zst ) cout << "POSSIBLE" << endl ; else cout << "IMPOSSIBLE" << endl ;
#define xspace(s) << (s) <<
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
//Putting it here vs putting it inside main
//Find number of factor works weirdly with square roots
//memset
//Try to do functional programming
//Use good names
//What is heap and stack and static memory

pair<int,int> MaxDist(int *x, int *y, int N)
{
//     // Vectors to store maximum and
//     // minimum of all the four forms
    vector<pair<int,int>> V(N), V1(N);
 
    for (int i = 0; i < N; i++) {
        V[i].first = x[i] + y[i];
		V[i].second=i;
        V1[i].first = x[i] - y[i];
		V1[i].second=i;
    }
	
//     // Sorting both the vectors
    sort(V.begin(), V.end());
    sort(V1.begin(), V1.end());
	int Vmax=V.back().first-V.front().first;
	int V1max=V1.back().first-V1.front().first;
	pair<int,int> answ;
	if(Vmax>=V1max){
		answ=make_pair(V.back().second,V.front().second);
	}
	else{
		answ=make_pair(V1.back().second,V1.front().second);
	}
    //  point = max(V.back() - V.front(), V1.back() - V1.front());
 
    return answ;
}

int manDis(int i1,int i2, int *x, int *y){
	return abs(x[i1]-x[i2])+abs(y[i1]-y[i2]);
}

int main(){
	iose;
	cin.tie(NULL);
	long long t=0;
	cin>>t;
	while(t--){
		long long n;
		cin >> n ;
		int x[n],y[n];
		for (long long i=0; i<n; i++){
			cin >> x[i] ;
			cin >> y[i] ;
		}
		pair<int,int> maxD=MaxDist(x,y,n);
		// cout << maxD.first <<" "<<maxD.second << endl ;
		int index1=maxD.first;
		int index2=maxD.second;
		int max1=0;
		int max2=0;
		for (long long i=0; i<n; i++){
			int distn2=manDis(index2,i,x,y);
			int distn1=manDis(index1,i,x,y);
			if(distn1>distn2){
				max2=max(distn2,max2);
			}
			else{
				max1=max(distn1,max1);
			}
		}
		double maxx=max(max1,max2);
		cout <<setprecision(10)<<fixed<< maxx/2 << endl ;
	}
}
