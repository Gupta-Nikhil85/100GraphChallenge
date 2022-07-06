// Link to the problem:- https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/
class Solution {
public:
    int mod = (int) (1e9)+7;
    int f(int node, vector<pair<int,int>> adj[], vector<int> &dp, vector<int> &dis){
        if(node==1) return 1;
        if(dp[node]!=-1) return dp[node];
        long long sum=0;
        for(auto [it, w] : adj[node]){
            if(dis[it]> dis[node]){
                sum= (sum%mod + f(it, adj, dp, dis)%mod)%mod;
            }
        }
        return dp[node]= sum%mod;
    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(auto e : edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        vector<int> dis(n+1,INT_MAX);
        dis[n]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,n});
        while(!q.empty()){
            auto [d,node]= q.top();
            q.pop();
            for(auto [it, curD] : adj[node]){
                if(dis[node] + curD < dis[it]){
                    dis[it]=dis[node]+curD;
                    q.push({dis[it], it});
                }
            }
        }
        vector<int> dp(n+1, -1);
        return f(n, adj, dp, dis)%mod;        
    }
};