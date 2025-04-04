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
    vector <vector <int>> adj;

    vector <int> parent;
    vector <int> depth;
    TreeNode *ans;
    int leftleaf = -1, rightleaf = -1, maxdep = 0,lstdeb = -1;
    int lca = -1;
    
    void buildadj (TreeNode * root, int dep){
        maxdep = max(dep,maxdep);
        depth[root->val] = dep;
        if (root->left != NULL){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            parent[root->left->val] = root->val;
            buildadj(root->left,dep+1);
        }
        if (root->right != NULL){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            parent[root->right->val] = root->val;
            buildadj(root->right,dep+1);

        }

        if (root->left == NULL && root->right==NULL && depth[root->val] == maxdep){
            if (maxdep > lstdeb){
                leftleaf = root->val;
                lstdeb = maxdep;
            }
            rightleaf = root->val;
        }
    }
    

    void findlca(TreeNode *root){
        if (root->val == lca){
            ans = root;
            return;
        }

        if (root->left != NULL){
            findlca(root->left);
        }

        if (root->right != NULL){
            findlca(root->right);
        }

    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        adj.assign(1005,vector <int> ());
        parent.assign(1005,-1);
        depth.assign(1005,-1);
        buildadj(root,0);
        
        // cout << leftleaf << " " << rightleaf;
        while (leftleaf != rightleaf){
            leftleaf = parent[leftleaf];
            rightleaf = parent[rightleaf];
        }

        lca = leftleaf;

        findlca(root);
        
        return ans;
    }
};