// Link to the problem :- https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
class Solution {
public:
    vector<int> parent;
    
    int find(int val){
        if(parent[val]==-1) parent[val]=val;
        if(val==parent[val]) return val;
        return parent[val]=find(parent[val]);
    }
    
    void unionn(int v1, int v2){
        int p1= find(v1), p2=find(v2);
        parent[p1]=p2;
    }
    
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n,-1);
        for(auto e : edges){
            unionn(e[0], e[1]);
        }
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            m[find(i)]++;
        }
        long long ans=0;
        for(auto it : m){
            ans+= (long long) it.second * (long long) (n-it.second);
        }
        return ans/2;        
    }
};

//Using DFS

class Solution {
public:
    void dfs(int node, int & cnt, vector<int> &vis, vector<int> adj[]){
        vis[node]++;
        cnt++;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,cnt,vis,adj);
            }
        }
    }

    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> res;
        vector<int> vis(n,0);
        for(int i=0; i<n ;i++){
            if(!vis[i]){
                int cnt=0;
                dfs(i, cnt, vis, adj);
                res.push_back(cnt);
            }
        }
        long long ans=0, presum=0;
        for(auto it : res){
            ans+= it* presum;
            presum+=it;
        }
        return ans;
    }
};