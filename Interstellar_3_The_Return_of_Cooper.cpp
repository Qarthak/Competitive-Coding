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
#include <vector>
#include <numeric>

using namespace std;

// int main() {
//     int n,m;
// 	cin>>n>>m;
// 	long long a[n];
// 	for(int i=0;i<n;i++)
// 		cin>>a[i];
// 	sort(a,a+n);
// 	long long b[n];
// 	//b stores int ratios of a[i] to a[i-1]. 
// 	//This helps in determining if we should continue halving an element or move to the next one
// 	//b[0]=1 cus n elements wilong long have n-1 ratios
// 	b[0]=;
// 	for(int i=1;i<n;i++)
// 	{
// 		b[i]=a[i]/a[i-1];
// 	}
// 	for(int i=n-1;i>=0&&m!=0;i--)
// 	{
// 		while(b[i]>=1&&m!=0)
// 		{
// 			a[i]/=2;
// 			b[i]/=2;
// 			m--;
// 		}
// 	}
// 	//Sum
// 	long long sum=0;
// 	for(int i=0;i<n;i++)
// 	{
// 		sum+=a[i];
// 	}
// 	cout<<sum;
// }

// int main() {
//     int n,m;
// 	cin>>n>>m;
// 	long long a[n];
// 	for(int i=0;i<n;i++)
// 		cin>>a[i];
// 	sort(a,a+n);
// 	while(m)
// 	{
// 		a[n-1]/=2;
// 		m--;
// 		for(int i=1;i<n;i++)
// 		{
// 			if(a[n-i]<a[n-i-1])
// 			{
// 				swap(a[n-i],a[n-i-1]);
// 			}
// 		}
// 	}
// 	long long sum=0;
// 	for(int i=0;i<n;i++)
// 	{
// 		sum+=a[i];
// 	}
// 	cout<<sum;
// }

// int main() {
//     long long n,m;
//     cin>>n>>m;
//     priority_queue<long long> a;
//     for(int i=0;i<n;i++) 
// 	{
//         long long w;
//         cin>>w;
//         a.push(w);
//     }
//     for( ;m!=0;m--)
// 	{
//         long long x=a.top();
//         a.pop();
//         if(x/=2) {
//             a.push(x);
//         }
//     }
//     long long sum=0;
//     while(a.empty()==0) 
// 	{
//         sum+=a.top();
//         a.pop();
//     }
//     cout<<sum;
// }

int main() {
    long long n,m;
    cin>>n>>m;
    map<long long,long long,greater <long long>> a;
    for(long long i=0;i<n;i++) 
	{
        long long w;
        cin>>w;
        a[w]++;
    }
    for( ;m!=0;m--)
	{
        long long x=a.begin()->first;
        a[x]--;
        if(x/=2) {
            a[x]++;
        }
    }
    long long sum=0;
    for(auto i:a)
    {
        sum+=i.first*i.second;
    }
    cout<<sum;
}