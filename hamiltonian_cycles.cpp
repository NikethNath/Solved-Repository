#include <bits/stdc++.h>
using namespace std;    

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using pqi = priority_queue<int>;
using pqpii = priority_queue<pii>;

#define pb push_back
#define all(x) (x).begin(), (x).end()
const int inf = 1e9;
const ll INF = 1e18;

int numberofcycles(int node, int mask,int start,vector<vector<int>> &adj){
    if(mask==((1<<(adj.size()-1))-1)){
        for(int nbr : adj[node]){
            if(nbr==start) return 1;
        }
        return 0;
    }
    int ans=0;

    for(int nbr : adj[node]){
        if((mask & 1<<(nbr-1))==0){
            ans+=numberofcycles(nbr,mask | (1<<(nbr-1)),start,adj);
            
        }
    }
    return ans;
}



int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0 ; i<m; i++){
        int a,b;
        cin>>a;
        cin>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cout<<numberofcycles(1,1,1,adj);


    return 0;
}
