// Link to the Problem :- https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n+1],back[n+1];
        for(auto c : connections){
            adj[c[0]].push_back(c[1]);
            back[c[1]].push_back(c[0]);
        }
        queue<int> q;
        q.push(0);
        vector<int> vis(n+1,0);
        vis[0]++;
        int ans=0;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            for(auto a : adj[node]){
                if(!vis[a]){                    
                    q.push(a);
                    ans++;
                    vis[a]++;
                }
            }
            for(auto b : back[node]){
                if(!vis[b]){
                    q.push(b);
                    vis[b]++;
                }
            }
        }
        return ans;
    }
};