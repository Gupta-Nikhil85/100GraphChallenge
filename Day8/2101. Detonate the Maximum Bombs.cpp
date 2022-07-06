// Link to the problem :- https://leetcode.com/problems/detonate-the-maximum-bombs/
class Solution {
public:
    void dfs(int node, vector<int> &vis, int &cnt, vector<vector<int>> &graph){
        vis[node]++;
        cnt++;
        for(auto it : graph[node]){
            if(!vis[it]){
                dfs(it, vis, cnt, graph);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> graph(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j){
                    long long x=abs(bombs[i][0]-bombs[j][0]);
                    long long y=abs(bombs[i][1]-bombs[j][1]);
                    long long r1= bombs[i][2];
                    if(x*x + y*y <= r1*r1){
                        graph[i].push_back(j);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            vector<int> vis(n,0);
            int cnt=0;
            dfs(i,vis,cnt,graph);
            ans=max(cnt,ans);
        }
        return ans;
    }
};