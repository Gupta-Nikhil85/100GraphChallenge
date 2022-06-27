// Link for the problem :- https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    
    void dfs(vector<vector<int>> &ans, vector<int> &temp, vector<vector<int>>& adj, int node, int target){
        if(node==target){
            if(temp.size()!=1)
                ans.push_back(temp);
            return;
        }
        for(auto it : adj[node]){
            temp.push_back(it);
            dfs(ans, temp, adj, it, target);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n=graph.size();
        vector<int> temp;
        temp.push_back(0);
        dfs(ans, temp, graph, 0, n-1);
        return ans;
    }
};