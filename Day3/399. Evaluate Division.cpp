// Link to the problem :- https://leetcode.com/problems/evaluate-division/

class Solution {
public:
    bool dfs(unordered_set<string> &vis, unordered_map<string,vector<pair<string,double>>>&m, string src, string dest, double &temp){
        
        if(src==dest) return true;       
        vis.insert(src);
        
        for(auto p : m[src]){
            if(vis.find(p.first)==vis.end()){
                if(dfs(vis,m,p.first,dest,temp)){
                    temp*=p.second;
                    return true;
                }
            }
        }
        return false;       
    }
    
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> m;
        int n=equations.size();
        for(int i=0; i<n; i++){
            m[equations[i][0]].push_back(make_pair(equations[i][1],values[i]));
            m[equations[i][1]].push_back(make_pair(equations[i][0],1/values[i]));
        }
        vector<double> ans;
        for(auto q : queries){
            if(m.find(q[0])==m.end() || m.find(q[1])==m.end()){
                ans.push_back((double) -1);
            }else{
                double temp=1;
                unordered_set<string> vis;
                if(dfs(vis,m,q[0],q[1],temp))ans.push_back(temp);
                else ans.push_back((double) -1);
            }
        }
        return ans;
    }
};