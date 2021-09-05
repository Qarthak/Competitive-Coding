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
typedef long long ll;

using namespace std;


int main()
{
	int n;
    cin >> n ;
	long long a[n];
	for (int i=0; i<n; i++){
		cin >> a[i] ;
	}
	ll max=0;
	int tek=0;
	priority_queue<int> mini;
	for(int i:a){
		if(i>=0)
		{
			max+=i;
			tek++;
		}
		else if(max+i>=0)
		{
			tek++;
			mini.push((-1)*i);
			max+=i;
		}
		else if( !mini.empty() && mini.top()+i>0 )
		{
			max+=(i+mini.top());
			mini.pop();
			mini.push((-1)*i);
		}
	}
	cout << tek << "\n" ;
}