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


typedef long long ll;

long long gcd(long long frst, long long scnd)
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
		ll temp=0;
		ll temp2=0;
		// char* a;
		// int n=200000 ;
		string a;
		cin >> a ;
		ll n=a.size();
		ll ans=0;
		size_t j=1;
		for (size_t i=0; i<n; i++){
			if( i==0 && a[i]=='?')
			{
				ll j=i;
				while(j<n && a[j]=='?')
				{
					j++;
				}
				if(j==n)
				{
					ans=(n*(n+1))/2;
					goto fullQuestionMark;
				}
				else{
					i=j;
					while(j!=0)
					{
						a[j-1]='1'*(a[j]=='0')+'0'*(a[j]=='1');
						j--;
					}
				}
			}
			else if(a[i]=='?')
			{
				ll count;
				ll j=i;
				while(j<n && a[j]=='?')
				{
					j++;
				}
				if(j==n)
				{
					while(i!=n)
					{
						a[i]='1'*(a[i-1]=='0') + '0'*(a[i-1]=='1');
						i++;
					}
				}
				else{
					ll dif=abs(a[i-1]-a[j]);
					if((j-i)%2!=dif)
					{
						while(i!=j)
						{
							a[i]='1'*(a[i-1]=='0') + '0'*(a[i-1]=='1');
							i++;
						}
					}
				}
				i=j;
			}
		}
		ans;
		for (size_t i=0; i<n; i=temp){
			for (; j<n ; j++){
				if(a[j]=='?'){
					temp=j;
					while(a[j]=='?')
					{
						j++;
					}
					break;
				}
				else if(a[j]==a[j-1])
				{
					temp=j;
					break;
				}
			}
			if(j==n)
				temp=j;
			ans+=((j-i)*(j-i+1))/2;
			if(a[j]==a[j-1])
				j++;
		}
		//removing overcounting
		for (size_t i=0; i<n; i++){
			if(a[i]=='?')
			{
				ll temp=i;
				while(a[i]=='?')
				{
					i++;
				}
				ans-=((i-temp)*(i-temp+1))/2;
			}
		}

		fullQuestionMark:
		if(ans==672747168)
		{
			// cout <<"n = "<<n <<" ans= "<<ans<<" j= "<<j <<" a= "<< a  << "\n" ;
		size_t sizz=0;
		ll sas=0;
		for (; sizz<n&&sas<2*n; sizz++,sas++){
		}
		cout << sizeof(sizz)<<" "<< sizeof(size_t)<<" "<<sizeof(sas)<<" "<<sizeof(long long) << "\n" ;
		}	
		cout << ans << "\n" ;
	}
}