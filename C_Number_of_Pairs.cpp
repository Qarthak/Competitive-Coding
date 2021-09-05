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

#define zspace << " " <<
#define eql( zst , ost , lgo ) (( (zst) == (ost) ) && ( (zst) == (lgo) ))
#define iose     ios_base::sync_with_stdio()
#define iff( zst , ost )		if  ( (zst) == (ost) )
#define between( frst , scnd, thrd )	((frst) >= (scnd)  && (frst) <= (thrd))

typedef long long ll;

int gcd(int frst, int scnd)
{
    if (scnd == 0)
        return frst;
    return gcd(scnd, frst % scnd);
}

//    FFFFFFFTTTTTTTTTFFFFFFFFF
//           l       u         

ll l,r;


//Predicate
bool predicate(long long *a, long long i, long long j)
{
	return between(a[i]+a[j],l,r);
}

//binary search
long long binarySearchLow(long long i,long long *a,long long n)
{
	return 0;
}




int main()
{
	vector<int> v;
    iose;
    long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin >> n>>l>>r ;
		ll a[n];
		for (long long i=0; i<n; i++){
			cin >> a[i] ;
		}
		ll answer=0;
		for (long long i=0; i<n; i++){
			for (long long j=i+1; j<n; j++){
				if(between(a[i]+a[j],l,r))
					answer++;
			}
		}
		// cout << answer << "\n" ;

		sort(a,a+n);

		ll count=0;

		for (long long i=0; i<n-1; i++){
			ll low=lower_bound(a+i+1,a+n,l-a[i])-a;
			ll high=upper_bound(a+i+1,a+n,r-a[i])-a;
			
			count+=(high-low);


			// cout <<i zspace count zspace low zspace high << "\n" ;
		}

		cout << count << "\n" ;









		// for (long long i=0; i<n-1; i++)
		// {
		// 	high=n-1;
		// 	low=i+1;
		// 	highh=n-1;
		// 	loww=i+1;
		// 	ll mid=(low+high)/2;
		// 	if(a[i]+a[high]<=r && a[i]+a[low]>=l){
		// 		count+=(high-low+1);
		// 		continue;
		// 	}
		// 	else if(a[i]+a[high]<=r)
		// 	{
		// 		while(!( between(a[i]+a[low],l,r) && 
		// 		!between(a[i]+a[low-1],l,r) ))
		// 		{
		// 			if(a[i]+a[mid]<l)
		// 				low=mid+1;
		// 			else if(a[i]+a[mid]>r)
		// 				low=mid-1;
		// 			else
		// 			{
		// 				high=mid-1;
		// 			}
		// 			mid=(high+low)/2;
		// 			if(mid<=low)
		// 			{
		// 				low=mid;
		// 				break;
		// 			}
		// 		}
		// 		highh=n-1;
		// 		loww=low;
		// 	}

		// 	else if(a[i]+a[low]>=l)
		// 	{
		// 		while(!
		// 		( between(a[i]+a[high],l,r) && 
		// 		!between(a[i]+a[high+1],l,r) )){
		// 			if(a[i]+a[mid]<l)
		// 				high=mid+1;
		// 			else if(a[i]+a[mid]>r)
		// 				high=mid-1;
		// 			else{
		// 				low=mid+1;
		// 			}
		// 			mid=(high+low)/2;
		// 			if(mid>=high)
		// 			{
		// 				high=mid;
		// 				break;
		// 			}
		// 		}
		// 		highh=high;
		// 		loww=i+1;
		// 	}
		// 	else
		// 	{
		// 		while(!
		// 		( between(a[i]+a[low],l,r) && 
		// 		!between(a[i]+a[low-1],l,r) ))
		// 		{
		// 			if(a[i]+a[mid]<l)
		// 				low=mid+1;
		// 			else if(a[i]+a[mid]>r)
		// 				low=mid-1;
		// 			else{
		// 				high=mid-1;
		// 			}
		// 			mid=(high+low)/2;
		// 			if(mid<=low)
		// 			{
		// 				low=mid;
		// 				break;
		// 			}
		// 		}
		// 		high=n-1;
		// 		highh=n-1;
		// 		loww=low;
		// 		mid=(high+low)/2;
		// 		while(!( between(a[i]+a[high],l,r) && 
		// 		!between(a[i]+a[high+1],l,r) )){
		// 			if(a[i]+a[mid]<l)
		// 				high=mid+1;
		// 			else if(a[i]+a[mid]>r)
		// 				high=mid-1;
		// 			else{
		// 				low=mid+1;
		// 			}
		// 			mid=(high+low)/2;
		// 			if(mid>=high)
		// 			{
		// 				high=mid;
		// 				break;
		// 			}
		// 		}
		// 		highh=high;
		// 	}
		// 	// cout <<a[i]<<" "<< a[loww]<<" "<<a[highh] << "\n" ;
		// 	if(between(a[i]+a[loww],l,r) && between(a[i]+a[highh],l,r))
		// 		count+=(highh-loww+1);
		// 	else if(between(a[i]+a[loww-1],l,r) && between(a[i]+a[highh],l,r)&&between(loww-1,i+1,highh))
		// 		count+=(highh-loww+2);
		// 	else if(between(a[i]+a[loww+1],l,r) && between(a[i]+a[highh],l,r)&&between(loww+1,i+1,highh))
		// 		count+=(highh-loww);
		// 	else if(between(a[i]+a[loww],l,r) && between(a[i]+a[highh-1],l,r)&&between(highh-1,loww,n-1))
		// 		count+=(highh-loww);
		// 	else if(between(a[i]+a[loww],l,r) && between(a[i]+a[highh+1],l,r)&&between(highh+1,loww,n-1))
		// 		count+=(highh-loww+2);

		// 	else if(between(a[i]+a[loww+1],l,r) && between(a[i]+a[highh+1],l,r)&&

		// 	between(highh+1,loww+1,n-1)&&between(loww+1,i+1,highh+1))
		// 		count+=(highh-loww+1);


		// 	else if(between(a[i]+a[loww-1],l,r) && between(a[i]+a[highh-1],l,r)&&

		// 	between(highh-1,loww-1,n-1)&&between(loww-1,i+1,highh-1))
		// 		count+=(highh-loww+1);


		// 	else if(between(a[i]+a[loww-1],l,r) && between(a[i]+a[highh+1],l,r)&&

		// 	between(highh+1,loww-1,n-1)&&between(loww-1,i+1,highh+1))
		// 		count+=(highh-loww+3);


		// 	else if(between(a[i]+a[loww+1],l,r) && between(a[i]+a[highh-1],l,r)&&

		// 	between(highh-1,loww+1,n-1)&&between(loww+1,i+1,highh-1))
		// 		count+=(highh-loww-1);
		// }

		// cout << count << "\n" ;
	}
}