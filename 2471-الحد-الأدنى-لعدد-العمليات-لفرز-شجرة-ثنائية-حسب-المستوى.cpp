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
    void swap(vector<int>& arr, int i, int j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
public:
    int minimumOperations(TreeNode* root) {
        queue <pair<TreeNode*,int>> q;
        vector <int> v;

        int ans = 0;

        int level = 0;
        q.push({root,level});

        while(!q.empty()){
            pair <TreeNode*,int> u = q.front();
            int cnt =0;
            q.pop();
            if (u.second != level){
                map <int,int> mp;
                for (int i=0 ; i<v.size() ; i++){
                    mp[v[i]] = i ;
                }
                vector<int> sorted = v;
                sort(sorted.begin(),sorted.end());
                
                for (int i=0 ; i<v.size() ; i++){
                    if (v[i]!=sorted[i]){
                        ans++;
                        int n = v[i];
                        swap (v,i,mp[sorted[i]]);
                        mp[n] = mp[sorted[i]];
                        mp[sorted[i]] = i;
                    }

                }
                v.clear();
                level++;
            }
            v.push_back(u.first->val);
            if (u.first->left != NULL) q.push({u.first->left,u.second+1});
            if (u.first->right != NULL) q.push({u.first->right,u.second+1});
        }
            // check for leafs
            map <int,int> mp;
                for (int i=0 ; i<v.size() ; i++){
                    mp[v[i]] = i ;
                }
                vector<int> sorted = v;
                sort(sorted.begin(),sorted.end());
                for (int i=0 ; i<v.size() ; i++){
                    if (v[i]!=sorted[i]){
                        ans++;
                        int n = v[i];
                        swap (v,i,mp[sorted[i]]);
                        mp[n] = mp[sorted[i]];
                        mp[sorted[i]] = i;
                    }

                }
       
        return ans;
    }
};