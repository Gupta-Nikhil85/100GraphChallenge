// Link to the problem:- https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

//Dijkstra's solution

class Solution {
public:
    struct comp{
      bool operator()(pair<int,int> &p1, pair<int,int> &p2){
          return p1.second > p2.second;
      }  
    };
    void findDis(int src, vector<int>&dist, vector<pair<int,int>> adj[]){
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp > pq;
        pq.push({src, 0});
        while(!pq.empty()){
            pair<int,int> cur=pq.top();
            pq.pop();
            for(auto it : adj[cur.first]){
                if(cur.second + it.second < dist[it.first]){
                    dist[it.first]=cur.second+ it.second;
                    pq.push({it.first, dist[it.first]});
                }
            }
        }
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        pair<int,int> p={0,n+1};
        vector<pair<int,int>> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(make_pair(it[1],it[2]));
            adj[it[1]].push_back(make_pair(it[0],it[2]));
        }
        for(int i=0; i<n;i++){
            vector<int> dist(n,1e9);
            vector<int> vis(n,0);
            dist[i]=0;
            findDis(i, dist, adj);
            int cnt=0;
            for(auto d : dist){
                if(d!=0 && d<=distanceThreshold) cnt++;
            }
            if(p.second>=cnt){
                p.first=i;
                p.second=cnt;
            }
        }
        return p.first;
    }
};


//Floyd-Warshall
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> adj[n];
        vector<vector<int>> dp(n,vector<int>(n,1e8));
        
        for(auto edge : edges){
            dp[edge[0]][edge[1]]=edge[2];
            dp[edge[1]][edge[0]]=edge[2];
        }
        
        for(int i=0; i<n; i++){
            dp[i][i]=0;
        }
        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    dp[i][j]= min(dp[i][j], dp[i][k] + dp[k][j]);
        
        int cur=n+1;
        int ans=0;
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(dp[i][j]<=distanceThreshold) cnt++;
            }
            if(cnt<=cur){
                cur=cnt;
                ans=i;
            }
        }
        return ans;       
    }
};