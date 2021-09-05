#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define for0(i,n) for (int i = 0; i < (int)(n); ++i)            
#define for1(i,n) for (int i = 1; i <= (int)(n); ++i)           
#define forc(i,l,r) for (int i = (int)(l); i <= (int)(r); ++i) 
#define forr0(i,n) for (int i = (int)(n)-1; i >= 0; --i)        
#define forr1(i,n) for (int i = (int)(n); i >= 1; --i)          
#define forg0(i,a,cond) for (int i = a; cond; i++)
#define forg1(i,a,cond) for (int i = a; cond; i--)

void coun(pair<int,int> a[],int n,int const max){
    int c[max+1]={0};
    for0(i,n)
    {         
        c[(a[i]).first]++;
    }
    int cu[max+2]={0};
    cu[0]=0;
    for1(i,max+1)
    {
        cu[i+1]=cu[i]+c[i];
    }
    // for(int i:cu)
    //     cout << i<<" " ;
    pair<int,int> b[n];
    for0(i,n)
    {
        b[cu[a[i].first]]=a[i];
        cu[a[i].first]++;
    }
    for0(i,n){
        cout<<b[i].first<<" "<<b[i].second<<endl;
    }
}

int main(int argc,char const *argv[])
{
    int n = 6;
    pair<int,int> a[n] = {make_pair(4,1),make_pair(3,1),make_pair(6,2),make_pair(3,2),make_pair(3,3),make_pair(4,2)};
    int max = a[0].first;
    int min = a[0].first;
    for (auto i : a)
        if (i.first > max)
            max = i.first;
    coun(a,n,max);
    // for0(i,n)cout<<a[i].first<<" ";
    return 0;
}