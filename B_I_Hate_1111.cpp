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
		if(n>=1110)
		{
			cout << "YES" << "\n" ;
		}
		else
		{
			int range=n/111;
			if(n%11<=range)
			{
				cout << "YES" << "\n" ;
			}
			else
			{
				cout << "NO" << "\n" ;
			}
		}
		
	}
    
}