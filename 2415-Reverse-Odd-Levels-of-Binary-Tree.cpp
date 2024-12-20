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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue <pair<TreeNode*,bool>> q;
        q.push({root,false});
        queue <TreeNode*> revQ;
        vector <int> values;
        while(!q.empty()){
            pair<TreeNode*,bool> top = q.front();
            q.pop();
            if (top.second){
                values.push_back(top.first->val);
                revQ.push(top.first);
            }else{
                while(!revQ.empty()){
                    revQ.front()->val = values.back();
                    values.pop_back();
                    revQ.pop();
                }
            }

            if (top.first->left != NULL) q.push({top.first->left,!top.second});
            if (top.first->right != NULL) q.push({top.first->right,!top.second});

        }
        
        while(!revQ.empty()){
            revQ.front()->val = values.back();
            values.pop_back();
            revQ.pop();
        }

        return root;
    }
};