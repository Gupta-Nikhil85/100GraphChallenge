class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // Using bellman Ford
        //Relaxing it k+1 times
        vector<int> prev(n, 1e8);
        prev[src]=0;
        for(int i=0; i<=k; i++){
            vector<int> cur= prev;
            for(auto e : flights){
                cur[e[1]]= min(cur[e[1]], prev[e[0]]+ e[2]);
            }
            prev=cur;
        }
        return prev[dst]==1e8 ? -1: prev[dst];
    }
};

// Using BFS implementation of djikstra's algo


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto f : flights){
            adj[f[0]].push_back({f[1], f[2]});
        }
        vector<int> dis(n,1e8);
        queue<pair<int,int>>q;
        dis[src]=0;
        q.push({src,0});
        int level=0;
        while(!q.empty() && level<=k){
            int size= q.size();
            for(int i=0; i<size; i++){
                auto [node, dT]= q.front();
                q.pop();
                for(auto [it, d] : adj[node]){
                    if(dis[it] > dT+ d){
                        dis[it]=dT+d;
                        q.push({it, dis[it]});
                    }
                }
            }
            level++;
        }
        return dis[dst]==1e8 ? -1 : dis[dst];
    }
};