// Link to the problem :- https://leetcode.com/problems/network-delay-time/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto v : times){
            adj[v[0]].push_back(make_pair(v[1],v[2]));
        }
        vector<int> dist(n+1,1e8); //1 based indexing
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            pair<int,int> node= pq.top();
            pq.pop();
            for(auto it : adj[node.second]){
                if(dist[it.first]>it.second + node.first){
                    dist[it.first]=it.second + node.first;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1; i<=n; i++){
            ans=max(ans,dist[i]);
        }
        return ans>=1e8 ? -1 : ans;
    }
};