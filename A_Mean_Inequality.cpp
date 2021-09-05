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
	vector<int> a;
	ios_base::sync_with_stdio();
    long long t;
	cin>>t;
	while(t--)
	{
		
		long long n;
		cin >> n ;
		int a[2*n];
		for (size_t i=0; i<2*n; i++){
			cin >> a[i] ;
		}
		sort(a,a+2*n);
		int begin=0;
		int end=2*n-1;
		while(begin<end)
		{
			if(begin==end-1)
			{
				cout << a[begin]<<" "<<a[end] << "\n" ;
				break;
			}
			cout << a[begin] <<" "<<a[end]<<" " ;
			begin++;
			end--;
		}
	}
}