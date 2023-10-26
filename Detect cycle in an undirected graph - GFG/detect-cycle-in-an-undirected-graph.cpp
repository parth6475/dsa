//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    //DFS
    bool recursion(int node, int parent, vector<int> adjlist[], vector<int> &flag){
        flag[node]=1;
        for(int i=0;i<adjlist[node].size();++i){
            int adjacentnode=adjlist[node][i];
            //if adjacent is not visited
            if(flag[adjacentnode]==0){
                if(recursion(adjacentnode,node,adjlist,flag)==true)
                    return true;
            }
            //if adjacent is visited and not parent
            else if(adjacentnode!=parent)   return true;
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adjlist[]) {
        vector<int> flag(V,0);
        //for multi component graph
        for(int i=0;i<V;++i){
            if(flag[i]==0){
                if(recursion(i,-1,adjlist,flag)==true)
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends