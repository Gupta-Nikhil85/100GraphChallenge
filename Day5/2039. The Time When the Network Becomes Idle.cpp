// Link to the problem :- https://leetcode.com/problems/the-time-when-the-network-becomes-idle/
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        //no of messages= 2* (min dist)/patience = m
        //total time = 2*(min dist)-> first one, 2*(min dist) + (m-1)*patience ->(lastone)
        int n= patience.size();
        vector<int> adj[n];
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<pair<int,int>> q;
        vector<int> dist(n,1e8);
        dist[0]=0;
        q.push({0,0});
        while(!q.empty()){
            pair<int,int> node= q.front();
            q.pop();
            for(auto it : adj[node.first]){
                if(dist[it] > node.second + 1){
                    dist[it]=node.second +1;
                    q.push({it, dist[it]});
                }
            }
        }
        int ans=0;
        for(int i=1; i<n; i++){
            int m= (2*dist[i]-1)/patience[i];
            int totalTime= 2*(dist[i]);
            totalTime+= (m)*patience[i];
            ans=max(ans, totalTime);
        }
        return ans+1;
    }
};