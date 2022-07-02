// Link to the problem :- https://leetcode.com/problems/course-schedule-ii/
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& graph) {
        vector<int> indegree(n,0);
        vector<int> adj[n];
        for(auto e : graph){
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(!indegree[i]) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto it : adj[node]){
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }
        return ans.size()==n ? ans : vector<int>();        
    }
};