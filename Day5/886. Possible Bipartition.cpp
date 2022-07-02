// Link to the problem :- https://leetcode.com/problems/possible-bipartition/
class Solution {
public:
    bool dfs(vector<int>&color, vector<int> adj[], int node){
        for(auto it : adj[node]){
            if(color[it]==color[node]) return false;
            else if(color[it]==-1){
                color[it]=1-color[node];
                if(!dfs(color, adj, it)) return false;
            }
        }
        return true;
    }
    
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1,-1);
        vector<int> adj[n+1];
        for(auto d : dislikes){
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }
        for(int i=1; i<=n; i++){
            if(color[i]==-1){
                color[i]=0;
                if(!dfs(color, adj, i)) return false;
            }
        }
        return true;
    }
};