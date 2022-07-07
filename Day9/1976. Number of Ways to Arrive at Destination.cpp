// Link to the problem :- https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
typedef pair<long long,int> ppi;
class Solution {
public:
    int mod = 1e9+7;
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it : roads){
            adj[it[0]].emplace_back(it[1],it[2]);
            adj[it[1]].emplace_back(it[0],it[2]);
        }
        priority_queue<ppi, vector<ppi>, greater<ppi>> q;
        vector<long long> dis(n,LONG_MAX);
        vector<int> path(n,0);
        path[0]=1;
        dis[0]=0;
        q.push({0,0});
        while(!q.empty()){
            auto [nodeDis, node]= q.top();
            q.pop();
            for(auto [it, itDis] : adj[node]){
                if(dis[it] > dis[node] + itDis){
                    dis[it]= dis[node]+itDis;
                    q.emplace(dis[it], it);
                    path[it]=path[node]%mod;
                }
                else if(dis[it]==nodeDis+itDis){
                    path[it]+=path[node];
                    path[it]%=mod;
                }
            }
        }
        return path[n-1]%mod;
    }
};