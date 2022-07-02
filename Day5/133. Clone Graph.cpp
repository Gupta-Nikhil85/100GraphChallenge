// Link to the problem :- https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return node;
        
        unordered_map<Node*, Node*> m;
        m[node]= new Node();
        m[node]->val=node->val;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* cur= q.front();
            q.pop();
            for(auto it : cur->neighbors){
                if(m.find(it)==m.end()){
                    m[it]= new Node();
                    m[it]->val=it->val;
                    q.push(it);
                }
                m[cur]->neighbors.push_back(m[it]);
            }
        }
        return m[node];
    }
};