#include <bits/stdc++.h>
using namespace std;

bool sumin(long long a[],long long n,long long p,long long y)
{
    long long sum=0;
    for(size_t i = 0; i < n; i++)
    {
        sum+=max(a[i]-p,(long long)0);
    }
    return sum-y>=0;
}

int main()
{
    // freopen("input.txt","sum",stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n,c,y;
    //candy-types, kids-count, least remainder
    cin>>n>>c>>y;
    long long a[n];
    for(long long i=0;i<n;i++)
        cin>>a[i];
    long long p=0,sum=0;
    //input over

    //sort descending
    sort(a,a+n,greater<long long>());

    //count dups
    long long dup=0;
    for(long long i=n-1;i>=n-c-dup&&i>0;i--)
    {
        while(a[i]==a[i-1]&&i>0)
        {
            dup++;
            i--;
        }
    }
    //dup counted

    for(long long i=0;i<n;i++)
        if(i<n-c-dup)
            a[i]-=a[n-c-dup];
        else
            a[i]=0;
    for(long long i=n-1;i>=0;i--)
    {
        cout<<a[i];
        if(i==0)
            cout<<endl;
        else
            cout<<" ";
    }
    for(long long i=0;i<n-c-dup;i++)
        sum+=a[i];
    if(sum<y)
        cout<< -1;
    else
    {
        //Subpart 2
        long long low=(sum-y)/(n-c-dup);
        long long high=a[0];
        int nu=n-c-dup;
        p=(high+low)/2;
        while(high>low)
        {
            if(sumin(a,nu,p,y))
            {
                if(sumin(a,nu,p+1,y))
                {
                    low=p+1;
                }
                else
                    break;
            }
            else
            {
                high=p-1;
            }
            p=(high+low)/2;
        }
        long long sum=0;
        for (size_t i = 0; i < nu; i++)
        {
            sum+=max(a[i]-p,(long long)0);
        }
        
        cout<<p<<" "<<sum;
    }
}


