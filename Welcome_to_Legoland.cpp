#include <iostream>
using namespace std;

// Shorthand for commonly used types
typedef long long ll;
typedef double ld;

// T T T T T T T *T* F F F F F
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

int main() {
    ll k;
    cin >> k ;
    cout << binary(k) ;
}