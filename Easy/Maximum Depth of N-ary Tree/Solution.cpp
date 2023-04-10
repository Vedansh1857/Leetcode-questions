/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int solveRec(Node* curr_node){
        if(!curr_node) return 0;
        int a = 0;
        for(auto ans : curr_node->children) a = max(a,solveRec(ans)+1);
        return a;
    }
    int maxDepth(Node* root){
        if(root==NULL) return 0;
        return solveRec(root)+1;
    }
};
