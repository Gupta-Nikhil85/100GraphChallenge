// Link to the problem :- https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_map<string, unordered_set<string>> graph; // connection = ingredient->recipe
        unordered_map<string, int> indegree; //indegree of every recipe
        int n = recipes.size();
        for(int i=0; i<n; i++){
            for(auto ing: ingredients[i]){
                graph[ing].insert(recipes[i]);
            }
            indegree[recipes[i]]=ingredients[i].size();
        }
        queue<string> q;
        for(auto it : supplies) q.push(it);
        while(!q.empty()){
            string node= q.front();            
            q.pop();
            for(auto it : graph[node]){
                indegree[it]--;
                if(indegree[it]==0) {
                    q.push(it);
                }
            }
        }
        vector<string> ans;
        for(auto it : indegree){
            if(it.second==0) ans.push_back(it.first);
        }
        return ans;
    }
};