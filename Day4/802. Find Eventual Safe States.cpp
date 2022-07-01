// Link to the problem :- https://leetcode.com/problems/find-eventual-safe-states/
class Solution {
public:
    bool endsOnTerminating(vector<int> & vis, int node, vector<vector<int>>& graph, unordered_set<int> &zero){
        if(zero.find(node)!=zero.end()) return true;
        if(vis[node]) return false;
        vis[node]++;
        for(auto it : graph[node]){
            if(!endsOnTerminating(vis,it,graph,zero)) return false;
        }
        zero.insert(node);
        return true;       
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        unordered_set<int> zero;
        for(int i=0; i<n; i++){
            if(graph[i].size()==0) zero.insert(i);
        }
        vector<int> ans;
        if(zero.size()==0) return ans;
        
        for(int i=0; i<n; i++){
            vector<int> vis(n,0);
            if(endsOnTerminating(vis,i,graph,zero)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>& color,int node)
    {
        color[node]=1;
        
        for(auto cur : graph[node])
            if((color[cur]==0 && dfs(graph,color,cur)) || color[cur]==1)
                return true;
        
        color[node]=2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> color(graph.size()),result;
		
        for(int i=0;i<graph.size();i++)
            if(color[i]==2 ||  !dfs(graph,color,i))
                result.push_back(i);
                
        return result;
    }
};