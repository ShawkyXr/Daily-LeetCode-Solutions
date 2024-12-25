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
    vector <vector<int>> vec;

    void dfs(TreeNode* root,int level){
        vec[level].push_back(root->val);
        if (root->left!=NULL) dfs(root->left,level+1);
        if (root->right!=NULL) dfs(root->right,level+1);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vec.assign(10000,vector<int>(0));
        if (root!=NULL) dfs (root,0);
        vector <int> ans;
        for (auto v : vec){
           if (v.size()) ans.push_back(*max_element(v.begin(),v.end()));
           else break;
        }
        return ans;
    }
};