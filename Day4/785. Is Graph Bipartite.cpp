Link to the problem:-https://leetcode.com/problems/is-graph-bipartite/submissions/

class Solution {
public:
    bool dfs(vector<vector<int>>&graph, vector<int> &color, int node){
        for(auto it : graph[node]){
            if(color[it]==color[node]) return false;
            else if(color[it]==-1){
                color[it]=1-color[node];
                if(!dfs(graph,color,it)) return false;
            }
        }
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0; i<n ;i++){
            if(color[i]==-1){
                color[i]=0;
                if(!dfs(graph, color, i))return false;
            }
        }
        return true;
    }
};



class Solution {
public:    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0; i<n ;i++){
            if(color[i]==-1){
                color[i]=0;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int node= q.front();
                    q.pop();
                    for(auto it : graph[node]){
                        if(color[it]==color[node]) return false;
                        else if(color[it]==-1){
                            color[it]=1-color[node];
                            q.push(it);
                        }
                    }
                }
            }
        }
        return true;
    }
};