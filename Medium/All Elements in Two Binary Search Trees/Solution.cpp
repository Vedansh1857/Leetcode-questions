/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution{
public:
    void inorder(TreeNode* root,vector<int>& ans){
           if(root==NULL)
           return;

            inorder(root -> left,ans);
            ans.push_back(root -> val);
            inorder(root -> right,ans);
        
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        // vector<int> vec;
        inorder(root1,ans);
        inorder(root2,ans);
        // vec.push_back(ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
