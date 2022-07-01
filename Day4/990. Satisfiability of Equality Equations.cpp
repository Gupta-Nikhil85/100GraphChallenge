// Link to the problem :- https://leetcode.com/problems/satisfiability-of-equality-equations/
class Solution {
public:
    vector<int> parent;
    
    int find(int val){
        if(parent[val]==-1) parent[val]=val;
        if(val==parent[val]) return val;
        return parent[val]= find(parent[val]);
    }
    
    void unionn(char c1, char c2){
        int p1=find(c1-'a');
        int p2=find(c2-'a');
        parent[p1]=p2;
    }
    
    
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        for(int i=0; i<26; i++) parent[i]=-1;
        for(auto s : equations){
            char c1=s[0];
            char c2=s[3];
            if(s[1]=='=') unionn(c1,c2);
        }
        for(auto s :equations){
            char c1=s[0];
            char c2=s[3];
            if(s[1]=='!'){
                if(c1==c2) return false;
                if(find(c1-'a')==find(c2-'a')) return false;
            }
        }
        return true;
    }
};