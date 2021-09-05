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
		cin >> n ;
		int a[n];
		for (size_t i=0; i<n; i++){
			cin >> a[i] ;
		}
		int ans=0;
		int min=a[0];
		for(auto i : a){
			if(i<min)
				min=i;
		}
		for(auto i : a){
			if(i>min)
				ans++;
		}
		cout << ans << "\n" ;
	}
}