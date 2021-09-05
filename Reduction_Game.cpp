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
#define startToEnd( zst )   zst.start()  ,  zst.end()
#define yess cout << "YES" << endl ;
#define noo cout << "NO" << endl ;
#define pos cout << "POSSIBLE" << endl ;
#define impos cout << "IMPOSSIBLE" << endl ;
#define yesno( zst ) if( zst ) cout << "YES" << endl ; else cout << "NO" << endl ;
#define posimpos( zst ) if( zst ) cout << "POSSIBLE" << endl ; else cout << "IMPOSSIBLE" << endl ;
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

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n,k;
	    cin >> n >> k;
	    int a[n];
	    // if(n == 1){
	    //     int a;
	    //     cin >> a;
	    //     cout << a << '\n';
	    //     continue;
	    // }
	    for(int i = 0; i < n; i++){
	        cin >> a[i];
	    }
	    
	    sort(a, a+n);
	    
		int i=upper_bound(a,a+n,k)-a;
		
		if(n-i==1 || n==i){
			cout << accumulate(a,a+n,0) << "\n" ;
		}
		else if(n-i==2)
		{
			cout << accumulate(a,a+n,0)-2*a[n-2]+2*k << "\n" ;
		}
		else{
			if(accumulate(a+i,a+n-2,0)-(n-2-i)*k  <  a[n-2]-k){
				for (; i<n-2; i++){
					a[n-2]-=(a[i]-k);
					a[i]=k;
				}
				a[n-1]-=(a[n-2]-k);
				a[n-2]=k;
				cout << accumulate(a,a+n,0) << "\n" ;
			}
			else{
				if(
					
					( accumulate(a+i,a+n-1,0)%2 && ((n-1-i)*k)%2)
					||
					( accumulate(a+i,a+n-1,0)%2==0 && ((n-1-i)*k)%2==0)
					
					)
				{
					cout << accumulate(a,a+i,0)+(n-1-i)*k+a[n-1] << "\n" ;
				}
				else
				{
					cout << accumulate(a,a+i,0)+(n-1-i)*k+a[n-1]  -1 << "\n" ;
				}
			}
		}
	    // long long int sum = 0;
	    // for(int i = 0; i < n; i++){
	    //     sum += a[i];
	    // }
	    // cout << sum << '\n';
	}
	return 0;
}
		// int j=n-2;
	    // for(; i < j; i++){
	    //     for (j=n-2; j>i; j--){
		// 		while(a[i]>k && a[j]>k){
		// 			a[i]--;
		// 			a[j]--;
		// 		}
		// 		if(a[i]==k)
		// 			break;
		// 		else{
		// 			continue;
		// 		}
		// 	}
	    // }
		// if(i!=n-1)
		// {
		// 	a[n-1]=a[n-1]-(a[i]-k);
		// 	a[i]=k;
		// }
		
		
		




// int main()
// {
// 	iose;
// 	cin.tie(NULL);
// 	long long t=0;
// 	cin>>t;
// 	while(t--)
// 	{
// 		long long n,k;
// 		cin >> n>>k ;
// 		int a[n];
// 		for (long long i=0; i<n; i++){
// 			cin>>a[i];
// 		}
// 		int max=0;
// 		for (long long i=0; i<n; i++){
// 			if(a[i]>a[max])
// 				max=i;
// 		}
// 		swap(a[max],a[n-1]);
// 		int j=1;
// 		// for (long long i=0; i<n-1; i++){
// 		// 	if(a[i]>a[j])
// 		// 		swap(a[i],a[j]);
// 		// 	if(a[])
			
// 		// 	a[j]=a[j]-(a[i]-k);
// 		// 	a[i]=k;
// 		// }
// 		cout << accumulate() << "\n" ;
// 	}
// }