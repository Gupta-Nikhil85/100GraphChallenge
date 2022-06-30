// Link to the problem :- https://leetcode.com/problems/find-if-path-exists-in-graph/

class Solution {
public:
    
    bool dfs(vector<int> &vis, int src, int dest, vector<int> adj[]){
        if(src==dest) return true;
        vis[src]=1;
        for(auto i : adj[src]){
            if(!vis[i]){
                if(dfs(vis, i, dest, adj)) return true;
            }
        }
        return false;
    }
    
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> vis(n,0);
        vector<int> adj[n];
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(vis, source, destination, adj);
    }
};