// Link to the problem:- https://leetcode.com/problems/loud-and-rich/

class Solution {
public:
    int dfs(vector<int> &ans, vector<vector<int>>&adj, vector<int>& quiet, int node){
        if(ans[node]!=-1) return ans[node];
        ans[node]=node;
        
        for(auto it : adj[node]){
            if(quiet[ans[node]] > quiet[dfs(ans,adj,quiet,it)]){
                ans[node]=ans[it];
            }
        }
        return ans[node];
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>> adj(n);
        for(auto edge : richer){
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> ans(n,-1);
        
        for(int i=0; i<n; i++){
            dfs(ans, adj, quiet, i);
        }
        return ans;
    }
};