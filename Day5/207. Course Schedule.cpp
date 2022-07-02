// Link to the problem :- https://leetcode.com/problems/course-schedule/
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> deg(n,0);
        vector<int> adj[n];
        for(auto& g : prerequisites){
            adj[g[0]].push_back(g[1]);
            deg[g[1]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++) if(!deg[i]) q.push(i);
        int cnt=0;
        while(!q.empty()){
            int node= q.front();
            cnt++;
            q.pop();
            deg[node]--;
            for(auto it : adj[node]){
                deg[it]--;
                if(!deg[it]) q.push(it);
            }
        }
        return cnt==n;
    }
};