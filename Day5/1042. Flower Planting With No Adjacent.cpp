// Link to the problem :- https://leetcode.com/problems/flower-planting-with-no-adjacent/
class Solution {
public:
    //SIMILAR TO M COLORING GRAPH PROBLEM
    bool isValid(int garden,  int flower, vector<vector<int>>&paths, vector<int>&color){     
        for(auto i : paths[garden]){
            if(color[i]==flower) return false;
        }
        return true;
    }    
    bool solve(int n, vector<vector<int>>&paths, int garden, vector<int> &color){
        if(garden==n){
            return true;
        }
        for(int flower=1; flower<=4; flower++){
            if(isValid(garden, flower, paths, color)){
                color[garden]=flower;
                if(solve(n, paths, garden+1, color)) return true;
                else
                    color[garden]=0;
            }
        }
        return false;
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> route(n);
        for(int i=0; i<paths.size(); i++){
            route[paths[i][0]-1].push_back(paths[i][1]-1);
            route[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        vector<int> color(n,0);
        solve(n, route, 0, color);
        return color;
    }
};

// Since we have 4 flowers and we have only 3 nodes incoming
// Lets plant the flowers greedily as we always have one option.

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> color(n,0);
        vector<vector<int>> adj(n);
        
        for(auto p : paths){
            adj[p[0]-1].push_back(p[1]-1);
            adj[p[1]-1].push_back(p[0]-1);
        }
        
        for(int i=0; i<n; i++){
            vector<int> flower(5,0);
            
            for(auto it : adj[i]) flower[color[it]]=1;
            
            for(int j=1; j<=4; j++){
                if(!flower[j]){
                    color[i]=j;
                }
            }
        }
        return color;
    }
};