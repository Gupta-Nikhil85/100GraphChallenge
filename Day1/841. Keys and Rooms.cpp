// Link for the problem :-https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    void dfs(vector<bool> &vis, int node, vector<vector<int>>&rooms){
        vis[node]=1;
        for(auto it : rooms[node]){
            if(!vis[it]){
                dfs(vis, it, rooms);
            }
        }
    }
    
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n= rooms.size();
        vector<bool> vis(n,false);
        int node=0;
        vis[node]=true;
        for(auto i : rooms[node]){
            if(!vis[i]){
                dfs(vis, i, rooms);
            }
        }
        for(auto i : vis){
            if(!i) return false;
        }
        return true;
    }
};