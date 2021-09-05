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

#define eql(  iost  ,  stre  ,  algor  )  (  iost  ==  stre  ) &&  (  iost  ==  algor  )

using namespace std;

int main()
{
    int n;
    int a[n];
    int low,high;
    cin >> low>>high ;
    cin >> n ;
    for (size_t i=0; i<n; i++){
        cin >> a[i] ;
    }
    int sum[n+1];
    sum[0]=0;
    for (size_t i=1; i<n+1; i++){
        sum[i]=sum[i-1]+a[i-1];
    }
    int max=high-1;
    int min=0;
    int maxx=sum[max]-sum[min];
    while (max<n+1){
        if (maxx<sum[max]-sum[min]){
            maxx=sum[max]-sum[min];
        }
        
    }

}