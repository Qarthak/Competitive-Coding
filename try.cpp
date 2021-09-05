// #include <bits/stdc++.h>
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
	int n=26;
	for (long long i=0; i<n; i++){
		for (long long j=0; j<n; j++){
			char b1='a'+i;
			char b0='a'+j;
			cout << b1<<b0 ;
		}
	}
}