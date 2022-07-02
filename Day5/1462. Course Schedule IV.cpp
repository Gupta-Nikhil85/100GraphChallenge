// Link to the problem :- https://leetcode.com/problems/course-schedule-iv/
// Using Topo SOrt.
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> indegree(n,0);
        vector<int> adj[n];
        for(auto course : prerequisites){
            adj[course[0]].push_back(course[1]);
            indegree[course[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n; i++){
            if(!indegree[i]) q.push(i);
        }
        unordered_set<int> s[n];
        while(!q.empty()){
            int node= q.front();
            q.pop();
            for(auto it : adj[node]){
                s[it].insert(node);
                for(auto i : s[node]){
                    s[it].insert(i);
                }
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }
        vector<bool> ans;
        for(auto q : queries){
            if(s[q[1]].find(q[0])!=s[q[1]].end()) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};

//Using Floyd Warshall

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> connect(n, vector<bool>(n,false));
        for(auto edge : prerequisites){
            connect[edge[0]][edge[1]]=true;
        }
        for(int i=0; i<n; i++) connect[i][i]=true;
        
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    connect[i][j]=connect[i][j] | (connect[i][k] && connect[k][j]);
                }
            }
        }
        vector<bool> ans;
        for(auto q : queries){
            ans.push_back(connect[q[0]][q[1]]);
        }
        return ans;       
    }
};