//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool detect(int src, vector<int> adjlist[], vector<int> &flag){
        flag[src]=1;
        queue<pair<int,int>>    q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(int i=0;i<adjlist[node].size();++i){
                int adjacentnode=adjlist[node][i];
                //if adjacent is not visited
                if(flag[adjacentnode]==0){
                    flag[adjacentnode]=1;
                    q.push({adjacentnode, node});
                }
                //if adjacent is visited and is not parent
                else if(parent!=adjacentnode){
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adjlist[]) {
        vector<int> flag(V,0);
        for(int i=0;i<V;++i){
            if(flag[i]==0){
                if(detect(i,adjlist,flag)==true)    return true;
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