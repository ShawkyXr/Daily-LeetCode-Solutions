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
class Solution {
public:
    TreeNode* constructTree(int& preidx, int & postidx, vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[preidx]);
        preidx++;

        if (root->val != postorder[postidx]) 
            root-> left = constructTree(preidx, postidx, preorder, postorder);

        if (root->val != postorder[postidx]) 
            root-> right = constructTree(preidx, postidx, preorder, postorder);
        
        postidx++;

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int pri = 0, poi = 0;
        return constructTree(pri, poi, preorder, postorder);
    }
};