// Link to the problem :- https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
class Solution {
public:
    unordered_map<int,int> parent;
    int island=0;
    
    int findParent(int x){
        if(!parent.count(x)){
            parent[x]=x;
            island++;
        }
        if(parent[x]!=x) return findParent(parent[x]);
        return x;        
    }
    
    void unionn(int x, int y){
        int p1=findParent(x),p2=findParent(y);
        if(p1!=p2){
            parent[p1]=p2;
            island--;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        for(auto s : stones){
            unionn(s[0], 10000+ s[1]);
        }
        return stones.size()-island;
    }
};