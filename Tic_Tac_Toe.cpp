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
// #include <bits/random.h>
// #include <bits/opt_random.h>
// #include <bits/random.tcc>
// #include <regex>
// #include <bits/stdc++.h> if error

#define eql(  iostr  ,  streea  ,  algori  )  (  (  iostr  ==  streea  ) &&  (  iostr  ==  algori  )  )


using namespace std;

int main(int argc, char const *argv[])
{
    long long t;
	cin>>t;
	while(t--)
	{
		char a[3][3];	//Array storing Xs and Os and _s
		int oc=0;	//O count-
		int xc=0;	//X count
		for (size_t i=0; i<9; i++)
		{
			cin >> a[0][i] ;
			if (a[0][i]=='O')
			{
				oc++;
			}
			else if (a[0][i]=='X')
			{
				xc++;
			}
		}
		if(xc-oc!=1 && xc-oc!=0)	//X starts first so count of X=that of O or one ahead
		{
			cout << "3" << "\n" ;
			continue;
		}

		//check for wins
		unordered_map<char,bool> winner;
		winner['X']=false;
		winner['O']=false;
		for (size_t i=0; i<3; i++)
		{
			if(eql(a[i][0],a[i][1],a[i][2]))	//checks rows
				winner[a[i][0]]=true;
			
			if(eql(a[0][i],a[1][i],a[2][i]))	//checks columns
				winner[a[0][i]]=true;
		}
		if(eql(a[0][0],a[1][1],a[2][2])||eql(a[2][0],a[1][1],a[0][2]))	//check diagonals
		{
			winner[a[1][1]]=true;
		}
		if (winner['X']*winner['O']){	//both can't be winner at once
			cout << "3" << "\n" ;
			continue;
		}
		if(winner['X']&&xc-oc!=1){	//only one winner
			cout << "3" << "\n" ;
			continue; 
		}
		if(winner['O']&&xc!=oc){	//only one winner
			cout << "3" << "\n" ;
			continue;
		}
		if(winner['O']+winner['X']){	//only one winner
			cout << "1" << "\n" ; 
			continue;
		}
		if(oc+xc==9){					//if sum of count of Os and Xs=9 then the board is full and since no winner, game is drawn
			cout << "1" << "\n" ;
			continue;
		}
		cout << "2" << "\n" ;	//board is not full, there are no winner so game continues
	}
}