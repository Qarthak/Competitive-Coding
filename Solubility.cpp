#include <iostream>
#include <algorithm>    //sort
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

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int x,a,b;
		cin>>x>>a>>b;
		cout<<(a+(100-x)*b)*10<<endl;
	}
}