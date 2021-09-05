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


// float_mod(long double x, long long mod)
// {
// 	if(x<mod)
// 		return x;
	
// }

int main()
{
    unsigned long long n;
	cin>>n;

	long double x3=731.85643895701594;
	x3*=n;
	x3-=((size_t(x3*n))/998244353)*998244353;
	x3*=n;
	x3-=((size_t(x3*n))/998244353)*998244353;
	x3*=n;
	
	int y=(size_t(round(x3*n)));
	x3=x3-((size_t(round(x3*n)))
	/998244353)
	*998244353;
	
	long double x2=4390.63702638383260000;
	x2*=n;
	x2-=((size_t(x2*n))/998244353)*998244353;
	x2*=n;
	x2-=((size_t(x2*n))/998244353)*998244353;
	
	long double x1=8050.91440101980700000000000;
	x1*=n;
	x1-=((size_t(x1*n))/998244353)*998244353;
	
	cout<<(size_t
	(-4390.6332797139185+x1-x2+x3))%998244353
	 << "\n" ;
	
	// cout<<
	// (size_t
	// (-4390.6332797139185+
	// 8050.9144010198070*n+
	// -4390.6370263838326*+
	// x3

	// // ((size_t)(x+0.5))%998244353
	
	// ))
	// %998244353
	//  << "\n" ;
}