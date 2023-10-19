//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adjlist[]) {
        // Code here
        vector<int> flag(V,0);
        int start=0;
        vector<int> ans;
        recursion(start,adjlist,flag,ans);
        return ans;
    }
    void recursion(int node,vector<int>adjlist[],vector<int> &flag,vector<int> &ans){
        flag[node]=1;
        ans.push_back(node);
        for(int i=0;i<adjlist[node].size();++i){
            int it=adjlist[node][i];
            if(flag[it]==0)
                recursion(it,adjlist,flag,ans);
        }
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends