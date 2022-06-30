// Link to the problem :-https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:
    vector<int> parent;
    
    int findPar(int i){
        return i==parent[i] ? i : parent[i]=findPar(parent[i]);
    }
    
    void unionn(int i, int j){
        int p1=findPar(i);
        int p2=findPar(j);
        parent[p1]=p2;
    }
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1>connections.size()) return -1;
        parent.resize(n);    
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
        for(auto c : connections){
            unionn(c[0],c[1]);
        }
        unordered_set<int> s;
        for(int i=0; i<n; i++){
            s.insert(findPar(i));
        }
        return (int) s.size()-1;
    }
};