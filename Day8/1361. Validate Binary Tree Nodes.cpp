// Link to the problem :- https://leetcode.com/problems/validate-binary-tree-nodes/
class Solution {
public:
    vector<int> parent;
    
    int find(int val){
        if(parent[val]==-1) parent[val]=val;
        if(parent[val]==val) return val;
        return parent[val]= find(parent[val]);
    }
    
    void unionn(int i, int j){
        int p1= find(i);
        int p2= find(j);
        parent[p1]=p2;
    }
    
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n,0), outdegree(n,0);
        int edge=0;
        parent.resize(n,-1);
        for(int i=0; i<n; i++){
            if(leftChild[i]!=-1){
                edge++;
                unionn(i, leftChild[i]);
                indegree[leftChild[i]]++;
                outdegree[i]++;
            }
            if(rightChild[i]!=-1){
                edge++;
                unionn(i, rightChild[i]);
                indegree[rightChild[i]]++;
                outdegree[i]++;
            }
        }
        if(edge!=n-1) return false;
        int zeroIn=0;
        int par=find(0);
        for(int i=0; i<n; i++){
            if(indegree[i]==0) zeroIn++;
            if(outdegree[i]>2 || par!=find(i) || indegree[i]>1 || zeroIn>1) return false;
        }
        return zeroIn==1;
    }
};