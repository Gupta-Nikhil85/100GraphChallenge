// Link to the problem:- https://leetcode.com/problems/shortest-path-with-alternating-colors/
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    vector<vector<pair<int,int>>> adj(n);
        for(auto i : redEdges){
            adj[i[0]].push_back({i[1],0});
        }
        for(auto j : blueEdges){
            adj[j[0]].push_back({j[1],1});
        }
        vector<vector<int>> dis(n,vector<int>(2,-1));
        dis[0]={0,0};
        queue<pair<int,int>> q;//node, color
        q.push({0,0});
        q.push({0,1});
        while(!q.empty()){
            int node =q.front().first;
            int color= q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(color==it.second || dis[it.first][it.second]!=-1) continue;
                dis[it.first][it.second]= dis[node][color]+1;
                q.push(it);
            }
        }
        vector<int> ans;
        for(auto v : dis){
            if(v[0]==-1 || v[1]==-1) ans.push_back(max(v[0],v[1]));
            else ans.push_back(min(v[0],v[1]));
        }
        return ans;
    }
};