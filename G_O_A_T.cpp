#include <iostream>
// #include <algorithm>    //sort
// #include <deque>
// #include <iterator>
// #include <list>
// #include <map>
// #include <queue>
// #include <set>
// #include <stack>
// #include <string>

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

bool predicate(ll a[], ll mid, ll target)
{
    ll square=mid*mid;
    if(square>target)
        return 0;
    return mid*mid*mid<=target;
}

ll binary(ll a[], ll n, int target)
{
    ll high=n-1;
    ll low=0;
    ll n=high/2;
    while(high>low)
    {
        if(predicate(a,n,target)){
            if(!predicate(a,n+1,target)){
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

using namespace std;

// Shorthand for commonly used types
typedef pair<int, int> ii;
typedef long long ll;
typedef double ld;

int main() {
    ll t;
    while(t--)
    {
        
    }
}