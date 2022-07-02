// Link to the problem :- https://leetcode.com/problems/path-with-maximum-probability/
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        for(int i=0; i<edges.size(); i++){
            vector<int> edge=edges[i];
            adj[edge[0]].push_back({edge[1],succProb[i]});
            adj[edge[1]].push_back({edge[0],succProb[i]});
        }
        vector<double>dist(n,(double)0.0);
        dist[start]=(double)1.0;
        
        priority_queue<pair<double,int>> pq;
        pq.push({(double)1.0,start});
        while(!pq.empty()){
            pair<double,int> p=pq.top();
            pq.pop();
            int node=p.second;
            double probab=p.first;
            for(auto it : adj[node]){
                if(it.second*probab > dist[it.first]){
                    dist[it.first]=it.second*probab;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        return dist[end];
    }
};