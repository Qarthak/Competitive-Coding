#include<bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin>>t;
	for(int i = 0; i < t; ++i){
		int n;
		cin>>n;
		vector<int>a(n);
		for(int i = 0; i < n; ++i) cin>>a[i];
		int maxi = INT_MIN, best = INT_MIN;
		for(auto x : a){
			maxi = max(x, a[i] + x);
			best = max(best, maxi);
		}
		cout<<best<<"\n";
	}

}
