#include<bits/stdc++.h>
// stuff
#define for0(i,n) for (int i =0;i < (int)(n);++i) // 0 based indexing
#define for1(i,n) for (int i =1;i <=(int)(n);++i) // 1 based indexing
#define forc(i,l,r) for (int i =(int)(l);i <=(int)(r);++i) // closed interver from l to r r inclusive
#define forr0(i,n) for (int i =(int)(n) - 1;i >=0;--i) // reverse 0 based.
#define forr1(i,n) for (int i =(int)(n);i >=1;--i) // reverse 1 based
#define forg0(i,a,cond) for (int i =a;cond;i++)
#define forg1(i,a,cond) for (int i =a;cond;i--)

//short hand for usual tokens
#define pb push_back
#define fi first
#define se second

// Shorthand for commonly used types
typedef double ld;

using namespace std;

vector<int> dijkstra(int startv,vector<vector<tuple<int,int,int>>> adjlist) {
    int n =adjlist.size();
    vector<int> d(n,INT_MAX);

    d[startv]=0;
    set<pair<int,int>> q;
    q.insert({0,startv});
    while (!q.empty()) {
        int v =q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adjlist[v]) {
            int to =get<0>(edge);
            int len =get<1>(edge);

            if (d[v]+len < d[to]) {
                q.erase({d[to],to});
                d[to]=d[v]+len;
                q.insert({d[to],to});
            }
        }
    }
    return d;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<tuple<int,int,int>>> adjlist(n+1);
        for(int i=0;i<m;i++) {
            int u,v,w;cin>>u>>v>>w;
            adjlist[u].push_back(make_tuple(v,w,u));
            adjlist[v].push_back(make_tuple(u,w,v));
        }
        int b;
        cin>>b;
        for(int i=0;i<b;i++) {
            int x;cin>>x;
            adjlist[0].push_back(make_tuple(x,0,0));
            adjlist[x].push_back(make_tuple(0,0,x));
        }

        vector<int> d =dijkstra(0,adjlist);
        for(int i=1;i<d.size();i++)
            cout<<d[i]<<" ";
        cout<<endl;
    }

    return 0;
}