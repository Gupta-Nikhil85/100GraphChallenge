// Link to the problem :- https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/
class Solution {
public:
    void dfs(vector<int>& vis, set<int> st[], int node, vector<int> adj[]){
        vis[node]++;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(vis,st,it,adj);
            }
            st[node].insert(it);
            for(auto i : st[it]){
                st[node].insert(i);
            }
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto edge : edges){
            adj[edge[1]].push_back(edge[0]);
        }
        set<int> st[n];
        vector<int> vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(vis, st, i,adj);
            }
        }
        vector<vector<int>> ans(n);
        for(int i=0; i<n; i++){
            ans[i]=vector<int>(st[i].begin(),st[i].end());
        }
        return ans;        
    }
};