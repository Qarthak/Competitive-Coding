#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long value[n];
    int isBinarySubtree[n];
    for(long long i=0;i<n;i++)
    {
        cin>>value[i];
        isBinarySubtree[i]=0;   //Assume 0/False by default
    }
    long long subtreeSum[n];
    for(long long i=0;i<n;i++)
        subtreeSum[i]=LONG_LONG_MIN;    //Initialize to lowest value and change to own value for leaves later


    //start
    //make all leaves have isBinarySubtree= true and sum=their own value
    //We can leave the sum of others as max_neg and find it out based on the below sums and own value
    for(long long i=n-1;i>=(n)/2;i--)
    {
        subtreeSum[i]=value[i];
        isBinarySubtree[i]=1;
    }

    //actual logic
    // Iterating over all non-leaf nodes, if it's left and right child are binary trees and left is smaller, right is greater
    for(long long i=(n)/2-1;i>=0;i--)
    {
        if(( value[i]>value[2*i+1] || value[2*i+1]== -9999999) &&   //Left is smaller or doesn't exist
           ( value[i]<value[2*i+2] || value[2*i+2]==-9999999)  &&   //Right is greater or doesn't exist
           ( isBinarySubtree[2*i+1] && isBinarySubtree[2*i+2])    //Both left and right themselves are binary subtrees
       &&  ( value[i]!= -9999999 )
           )    
           {
                isBinarySubtree[i]=1;
                // if( value[i]== -9999999 )
                //Do value + left child sum (if it exists) + right child sum       (if it exists)
                    subtreeSum[i]=value[i]+(value[2*i+1]!=-9999999&&value[2*i+2]!=-9999999)*(subtreeSum[2*i+1]+subtreeSum[2*i+2]);
           }
           else if(value[i]== -9999999 && isBinarySubtree[2*i+1]==1 && isBinarySubtree[2*i+2]==1)
           {
               isBinarySubtree[i]=1;
           }
    }
    //Checking code
    // for(int i=0;i<n;i++)
    //     cout<<value[i]<<" "<<subtreeSum[i]<<" "<<isBinarySubtree[i]<<endl;
    // // Sum up  code
    long long max=LONG_LONG_MIN;
    for(int i=0;i<n;i++)
    {
        if(subtreeSum[i]>max && isBinarySubtree[i]) //Don't consider nodes which aren't roots of binary trees for sum
            max=subtreeSum[i];
    }
    cout<<max;
    return 0;
}