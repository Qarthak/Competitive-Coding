#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,k,n;
		cin>>n>>x>>k;
		if(x%k==0||(n+1-x)%k==0)
		{
			cout << "YES" <<endl;
			continue;
		}
		cout << "NO"<<endl ;
	}
}