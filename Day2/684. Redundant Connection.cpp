// Problem Link:- https://leetcode.com/problems/redundant-connection/

class Solution {
public:    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent(n+1);
        
        for(int i=1; i<=n; i++) parent[i]=i;
        
        for(auto edge : edges){
            int p1=edge[0], p2=edge[1];
            while(p1!=parent[p1]) p1=parent[p1];
            while(p2!=parent[p2]) p2=parent[p2];
            if(p1==p2) return edge;
            parent[p1]=p2;
        }
        return {};        
    }
};