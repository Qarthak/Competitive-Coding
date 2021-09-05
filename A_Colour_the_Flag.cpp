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
using namespace std;

#define eql( zst , ost , lgo ) ( zst == ost ) && ( zst == lgo )
#define iose	ios_base::sync_with_stdio()
#define iff( zst , ost )		if  ( zst == ost )

typedef long long ll;

int gcd(int frst, int scnd)
{
	if (scnd == 0)
		return frst;
	return gcd(scnd, frst % scnd);
}


int main()
{
	iose;
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,m;
		cin >> n>> m;
		char a[n][m];
		bool valid=1;
		char dual[2]={0,0};
		for (long long i=0; i<n; i++){
			for (long long j=0; j<m; j++){
				cin>>a[i][j];
				if (a[i][j]!='.'){
					if (!dual[(i+j)%2]){
						dual[(i+j)%2]=a[i][j];
					}
					else if(dual[(i+j)%2]!=a[i][j]){
						valid=0;
					}
				}
			}
		}
		if(valid)
		{
			if(dual[0]==0)
			{
				dual[1]='W'+'R'-dual[0];
			}
			if(dual[1]==0)
			{
				dual[0]='W'+'R'-dual[0];
			}
			cout << "YES" << "\n" ;
			for (long long i=0; i<n; i++){
				for (long long j=0; j<m; j++){
					cout << dual[(i+j)%2];
				}
				cout << "\n" ;
			}
		}
		else{
			cout << "NO" << "\n" ;
		}
		
	}

}