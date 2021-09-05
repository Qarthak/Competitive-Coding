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
using namespace std;

#define zspace << " " <<
#define areEqual( zst , ost , lgo ) (( zst == ost ) && ( zst == lgo ))
#define iose	ios_base::sync_with_stdio(); 	cin.tie(NULL); cout.tie(NULL);
#define isAscending( frst , scnd , thrd ) ( ( frst <= scnd ) && ( scnd <= thrd ) )
#define startToEnd( zst )   zst.start()  ,  zst.end()
#define yess cout << "YES" << "\n" ;
#define noo cout << "NO" << "\n" ;
#define pos cout << "POSSIBLE" << "\n" ;
#define impos cout << "IMPOSSIBLE" << "\n" ;
#define yesno( zst ) if( zst ) cout << "YES" << "\n" ; else cout << "NO" << "\n" ;
#define posimpos( zst ) if( zst ) cout << "POSSIBLE" << "\n" ; else cout << "IMPOSSIBLE" << "\n" ;
#define _xPutNameHere( frst , scnd , thrd) ( ( frst  scnd )  ( scnd  thrd)

int mod= (1000000007);
int cache[1]={};
int global=0;

int gcd(int frst, int scnd)
{
	if (scnd == 0)
		return frst;
	return gcd(scnd, frst % scnd);
}

struct EnterStructName{
	int EnterFirstElementName;
};

bool compareStruct(EnterStructName i1, EnterStructName i2)
{
    return (i1.EnterFirstElementName < i2.EnterFirstElementName);
}

bool customCompare(int frst,int scnd)
{
    return (frst < scnd);
}


int p[1]={};

//!Putting it here vs putting it inside main
//!Find number of factor works weirdly with square roots

int numOfFactors(int n)
{
	int count=0;
	for (int i=1; i*i<=n; i++){
		if(n%i==0){
			count+=(i*i==n)?1:2;
		}
	}
	return count;
}

int sumOfPowersOfFactors(int n){
	int count=0;
	while(n%2==0){
		n/=2;
		count+=1;
	}
	for (int i=3; i*i<=n; i+=2){
		while(n%i==0){
			n/=i;
			count+=1;
		}
	}
	if(n>1)
		count++;
	return count;
}

int main()
{
	iose;
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,k;
		cin >> a>>b>>k ;
		if(a<b)	swap(a,b);
		if(k==1){
			// cout <<t<<" "<<a zspace b zspace k<<" " ;
			yesno(a!=b && (!(a%b)));
		}
		else{
			// cout <<t<<" "<<a zspace b zspace k<<" " ;
			yesno(sumOfPowersOfFactors(a)+sumOfPowersOfFactors(b)>=k)
		}
	}
}
