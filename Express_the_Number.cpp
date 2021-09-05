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
 
int getMostWork(vector<int> folders, int workers) {
  int n = folders.size();
  int lo = * max_element(folders.begin(), folders.end());
  int hi = accumulate(folders.begin(), folders.end(), 0);
 
  while (lo < hi) {
    int x = lo + (hi - lo) / 2;
 
    int required = 1, current_load = 0;
    for (int i = 0; i < n; ++i) {
      if (current_load + folders[i] <= x) {
        // the current worker can handle it
        current_load += folders[i];
      } else {
        // assign next worker
        ++required;
        current_load = folders[i];
      }
    }
 
    if (required <= workers)
      hi = x;
    else
      lo = x + 1;
  }
 
  return lo;
}
 
ll prep[1]={};
//Putting it here vs putting it inside main
//Find number of factor works weirdly with square roots
//memset
//Try to do functional programming
//Use good names
//What is heap and stack and static memory
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
	long long t=0;
	cin>>t;
	while(t--){
		long long N,x;
		cin >> N>>x ;
		bool bitHash[31]={};
		bool bitHasha[31]={};
		long long a1=0;
		if(N%2 && x==0){
			cout << -1 << endl ;
			continue;
		}
		if(N%2){
			N--;
			a1+=1;
		}
		int n=N-x;
		for (long long i=0; i<31 && n!=0; i++){
			bitHash[i]+=(n%2);
			n/=2;
		}
		for (long long i=0; i<31 && N!=0; i++){
			bitHasha[i]+=(N%2);
			N/=2;
		}
		int start;
		for(int i=31;i>=0;i--){
			if(bitHasha[i]==1){
				start=i;
				while(bitHash[i]==bitHasha[i]){
					i--;
				}
				cout << start-i << endl ;
			}
		}
		
		
		
		
    // bool is_ans = true;
    // int ans_count = 0;
		// cout <<"a1="<< a1 << endl ;
    // for(int i=0; i<31; i+=2){
	// 	if(bitHash[i]){
	// 		if(a1+(1<<i)<=x){
	// 			int count=0;
	// 			for(int j=i-1; j>=0; j-=2){
	// 				if(bitHash[j]){
	// 					count++;
	// 				}
	// 			}
	// 			if(count>=2){
	// 				for(int j=i-1; j>=0; j-=2){
	// 					if(bitHash[j]){
	// 						bitHash[j]=0;
	// 						a1+=(1<<j);
	// 					}
	// 				}
	// 			}
	// 			if(a1+(1<<i)<=x){
	// 				a1+=(1<<i);
	// 				bitHash[i]=0;
	// 			}
	// 			else{
	// 				bitHash[i]=0;
	// 				ans_count+=2;
	// 			}
	// 		}
	// 		else
	// 		{
	// 			bitHash[i]=0;
	// 			ans_count+=2;
	// 		}
	// 	}
	// }
 
    // for(int i=1; i<31; i+=2){
	// 		if(bitHash[i]){
	// 			if(a1+(1<<i)<=x){
	// 				a1+=(1<<i);
	// 				bitHash[i]=0;
	// 			}
	// 		}
	// 	}
	// for(auto i : bitHash){
	// 	ans_count+=i;
	// }
	// cout << ans_count+(a1!=0) << '\n';
 
	}
}