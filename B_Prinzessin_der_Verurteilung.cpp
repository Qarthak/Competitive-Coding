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

#define eql( zst , ost , lgo ) ( zst == ost ) && ( zst == lgo )
#define iose     ios_base::sync_with_stdio()
#define iff( zst , ost )		if  ( zst == ost )

typedef long long ll;

int gcd(int frst, int scnd)
{
    if (scnd == 0)
        return frst;
    return gcd(scnd, frst % scnd);
     
}


int main()
{
    iose;
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin >> n ;
		int a[n];
		for (long long i=0; i<n; i++){
			char temp;
			cin >> temp ;
			a[i]=temp-'a';
		}
				bool h1[26]={};
		bool h2[26*26]={};
		bool h3[26*26*26]={};
		for (long long i=0; i<n; i++){
			h1[a[i]]=1;
			if(i!=n-1)
			{
				int j=i+1;
				h2[26*a[i]+a[j]]=1;
				if(j!=n-1)
				{
					int k=j+1;
					h3[26*26*a[i]+26*a[j]+a[k]] = 1;
				}
			}
		}
		int ans=0;
		for(auto i : h1){
			if(i==0)
			{
				goto donee;
			}
			ans++;
		}
		for(auto i : h2){
			if(i==0)
			{
				goto donee;
			}
			ans++;
		}
		for(auto i : h3){
			if(i==0)
			{
				goto donee;
			}
			ans++;
		}
		donee:
		// cout << ans << "\n" ;
		if(ans<26){
			char b;
			b='a'+ans;
			cout << b << "\n" ;
		}
		else if(ans<26*26)
		{
			ans-=26;
			char b1;
			char b0;
			b0='a'+ans%26;
			b1='a'+ans/26;
			cout << b1<<b0 << "\n" ;
		}
		else{
			ans-=26;
			ans-=26*26;
			char b2='a'+ ans/676;
			char b1='a'+ (ans/26)%26;
			char b0='a'+ ans%26;
			cout << b2<<b1<<b0 << "\n" ;
		}
		// cout << ans << "\n" ;
	}
}

