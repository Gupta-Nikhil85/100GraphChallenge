//Link to the problem :- https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n,0), outdegree(n,0);
        for(auto t : trust){
            outdegree[t[0]-1]++;
            indegree[t[1]-1]++;
        }
        int ans=-1;
        for(int i=0; i<n; i++){
            if(outdegree[i]==0 && indegree[i]==n-1){
                if(ans!=-1) return -1;
                else ans=i+1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n,0);
        for(auto t : trust){
            indegree[t[1]-1]++;
            indegree[t[0]-1]--;
        }
        for(int i=0; i<n; i++){
            if(indegree[i]==n-1) return i+1;
        }
        return -1;
    }
};