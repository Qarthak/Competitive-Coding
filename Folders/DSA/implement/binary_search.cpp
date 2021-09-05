#include <iostream>
#include <vector>

// stuff
#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based
#define forg0(i,a,cond) for (int i = a; cond; i++)
#define forg1(i,a,cond) for (int i = a; cond; i--)

//short hand for usual tokens
#define pb push_back
#define fi first
#define se second

// Shorthand for commonly used types
typedef pair<int, int> ii;
typedef long long ll;
typedef double ld;

using namespace std;

bool predicate(ll mid, ll target)
{
    ll square=mid*mid;
    if(square>target)
        return 0;
    return mid*mid*mid<=target;
}

ll binary(ll k)
{
    ll high=k;
    ll low=0;
    ll n=high/2;
    while(high>low)
    {
        if(predicate(n,k)){
            if(!predicate(n+1,k)){
                break;
            }
            low=n+1;
        }
        else
            high=n-1;
        n=(high+low)/2;
    }
    return n;
}

int main(int argc, char const *argv[])
{
    
}