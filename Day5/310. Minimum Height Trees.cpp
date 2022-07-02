// Link to the problem :- https://leetcode.com/problems/minimum-height-trees/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size()==0) return {0};
        unordered_set<int> adj[n];
        for(auto it : edges){
            adj[it[0]].insert(it[1]);
            adj[it[1]].insert(it[0]);
        }
        unordered_set<int> q;
        for(int i=0; i<n; i++){
            if((int)adj[i].size()==1) q.insert(i);
        }
        while(n>2){
            n-=(int) q.size();
            unordered_set<int> nq;
            for(auto i : q){
                int par= *(adj[i].begin());
                adj[par].erase(i);
                if((int) adj[par].size()==1) nq.insert(par);
            }
            q=nq;
        }
        vector<int> ans;
        for(auto it : q) ans.push_back(it);
        return ans;      
    }
};