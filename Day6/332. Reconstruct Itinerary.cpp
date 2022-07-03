// Link to the problem :- https://leetcode.com/problems/reconstruct-itinerary/
class Solution {
public:
    void eulerPathDFS(string node, vector<string>&ans,unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& adj){
        
        auto & edges=adj[node];
        while(!edges.empty()){
            string it = edges.top();
            edges.pop();
            eulerPathDFS(it,ans,adj);
        }
        ans.push_back(node);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>> > adj;
        for(auto t : tickets){
            adj[t[0]].push(t[1]);
        }
        string node= "JFK";
        vector<string> ans;
        eulerPathDFS(node, ans, adj);
        reverse(ans.begin(),ans.end());
        return ans;        
    }
};