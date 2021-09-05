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

#define eql( zst , ost , lgo ) ( zst == ost ) && ( zst == lgo )

using namespace std;

int main()
{
    long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin >> n;
		int a[n];
		for (size_t i=0; i<n; i++){
			cin >> a[i] ;
		}
		sort(a,a+n);
		int minDif=INT_MAX;
		for (size_t i=0; i<n-1&&a[i+1]<=0; i++){
			if(a[i+1]-a[i]<minDif){
				minDif=a[i+1]-a[i];
			}
		}

		int ans=0;
		for(auto i : a){
			if(i<=0)
				ans++;
			else{
				if(i<=minDif)
					ans++;
				break;
			}
		}
		cout << ans+(ans==0)*1 << "\n" ;
	}
}