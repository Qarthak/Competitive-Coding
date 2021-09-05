#include <iostream>

using namespace std;
#define pb push_back
#define fi first
#define se second
#define for0(i,n) for (int i = 0; i < (int)(n); ++i)            // 0 based indexing
#define for1(i,n) for (int i = 1; i <= (int)(n); ++i)           // 1 based indexing
#define forc(i,l,r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i,n) for (int i = (int)(n)-1; i >= 0; --i)        // reverse 0 based.
#define forr1(i,n) for (int i = (int)(n); i >= 1; --i)          // reverse 1 based
#define forg0(i,a,cond) for (int i = a; cond; i++)
#define forg1(i,a,cond) for (int i = a; cond; i--)
#define fin(i,a) for(auto i:a)

void buckcoun(int a[],int n,int const max,int k){

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

void bucketsort(int a[], int n, int max)
{
    int temp=max;
    int k=0;
    while(temp%=10)
        k++;
    buckcoun(a,n,max,k);
}

int main(int argc, char const *argv[])
{
    int const n=10;
    int a[n]={94,38,29,48,29,57,47,23,19,99};
    int max=a[0];
    fin(i,a){
        if(max<i)
            max=i;
    }
    bucketsort(a,n,max);
}
