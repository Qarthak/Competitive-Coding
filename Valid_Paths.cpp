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

#define eql(  iost  ,  stre  ,  algor  )  (  iost  ==  stre  ) &&  (  iost  ==  algor  )

using namespace std;

int main()
{
    long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin >> n ;
		vector<pair<int,bool>> a[n];
		while (n--){
			int x,y;
			cin >> x>>y ;
			a[x].push_back(make_pair(y,0));
			a[y].push_back(make_pair(x,0));
		}
		
	}
}