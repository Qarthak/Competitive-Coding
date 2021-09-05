#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define for0(i,n) for (int i = 0; i < (int)(n); ++i)            // 0 based indexing
#define for1(i,n) for (int i = 1; i <= (int)(n); ++i)           // 1 based indexing
#define forc(i,l,r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i,n) for (int i = (int)(n)-1; i >= 0; --i)        // reverse 0 based.
#define forr1(i,n) for (int i = (int)(n); i >= 1; --i)          // reverse 1 based
#define forg0(i,a,cond) for (int i = a; cond; i++)
#define forg1(i,a,cond) for (int i = a; cond; i--)

void coun(int a[],int n,int const max){
    int c[max + 1]={0};
    for0(i,n){         //create frequency array
        c[a[i]]++;
    }
    int j = 0;          //track index of count array
    for0(i,n){
        if (c[j] != 0){
            a[i] =j;
            c[j]--;
        }
        else{
            while (c[j] == 0){
                j++;
            }
            a[i]=j;
            c[j]--;
        }
    }
}

int main(int argc,char const *argv[])
{
    int n = 11;
    int a[11] = {4,3,2,6,2,3,1,3,2,4,2};

    int max = a[0];
    int min = a[0];
    for (int i : a)
        if (i > max)
            max = i;
    coun(a,n,max);
    for0(i,n)
        cout<<a[i]<<" ";
    return 0;
}