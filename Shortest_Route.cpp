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
using namespace std;

#define mod (1000000007)
#define eql( zst , ost , lgo ) (( zst == ost ) && ( zst == lgo ))
#define iose	ios_base::sync_with_stdio()

typedef long long ll;

int gcd(int frst, int scnd)
{
	if (scnd == 0)
		return frst;
	return gcd(scnd, frst % scnd);
}

long long npowerofm(ll n,ll m)
{
	if(m==0)
		return 1;
	if(m==1)
		return n;
	ll temp=(npowerofm(n,m/2))%mod;
	return (((temp*temp)%mod)*(npowerofm(n,m%2)))%mod;
}

int main()
{
	iose;
	cin.tie(NULL);
	vector<int> v;
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,m;
		cin >> n >>m;
		int a[n],b[m];
		for (long long i=0; i<n; i++){
			cin>>a[i];
			if(a[i]==2)
				a[i]=-1;
		}
		ll time[n]={};
		ll temp=-1;
		bool possible=0;
		int i=0;
		for (long long i=0; i<n; i++){
			if(a[i]==1)
			{
				possible=1;
				temp=0;
				time[i]=temp;
			}
			else if(possible)
			{
				temp++;
				time[i]=temp;
			}
			else{
				if(i!=0)
					time[i]=-1;
			}
		}
		possible=0;
		for (long long i=n; i>=0; i--){
			if(a[i]==-1)
			{
				possible=1;
				temp=0;
				if(time[i]>temp||time[i]==-1)
					time[i]=temp;
			}
			else if(possible)
			{
				temp++;
				if(time[i]>temp||time[i]==-1)
					time[i]=temp;
			}
		}
		for (long long i=0; i<m; i++){
			int temp;
			cin >> temp;
			cout << time[temp-1] << " " ;
		}
		cout  << "\n" ;
	}
}