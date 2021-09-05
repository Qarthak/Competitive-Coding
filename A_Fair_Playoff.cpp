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

#define eql( zst , ost , lgo ) ( zst == ost ) && ( zst == lgo )


typedef long long ll;

using namespace std;



int main()
{
    ios_base::sync_with_stdio();
	long long t;
	cin>>t;
	while(t--)
	{
		int n=4;
		long long a[4];

		int maxx=0;
		int max2=1;
		for (size_t i=0; i<n; i++){
			cin >> a[i] ;
			if(a[i]>a[maxx])
			{
				max2=maxx;
				maxx=i;
			}
			else if(a[i]>a[max2]&&i!=maxx)
				max2=i;
		}
		// cout << maxx<<" and "<<max2 << "\n" ;
		// int t=0;
		// t=max(max(max(a[0],a[1]),a[2]),a[3]);
		if(maxx+max2==1)
			cout << "NO" << "\n" ;
		else if(maxx+max2==5)
			 cout << "NO" << "\n" ;
		else
			cout << "YES" << "\n" ;
	}
}