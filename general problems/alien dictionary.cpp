// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/
vector<bool> visited;
stack<int> st;
void dfs(int src,vector<int> adj[])
{
    visited[src]=true;
    for(auto it:adj[src])
    {
        if(!visited[it])
        dfs(it,adj);
    }
    st.push(src);
}
int kosaraju(int V, vector<int> adj[])
{   
    int cnt=0;
    visited.resize(V,false);
    dfs(0,adj);
    for(int i=0;i<V;i++)
    if(!visited[i])
    {
        
        dfs(i,adj);
        
    }
    visited.clear();
    vector<int> adj1[V];
    for(int i=0;i<V;i++)
    {
        for(auto it:adj[i])
        {
            adj1[it].push_back(i);
        }
    }
    visited.resize(V,false);
    
    while(!st.empty())
    {
        int tp=st.top();
        st.pop();
        if(!visited[tp])
        {
            
            dfs(tp,adj1);
            cnt++;
        }
    }
    
    visited.clear();
    return cnt;
    
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int> adj[a];
        for (int i = 0; i < b; i++) {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
    }
    return 0;
}
  // } Driver Code Ends
