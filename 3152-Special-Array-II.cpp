class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector <bool> ans;
        vector <int> invalid;

        for (int i=1 ; i< nums.size() ; i++){
            if (nums[i]%2==nums[i-1]%2){
                invalid.push_back(i-1);
            }
        }

        for (int i=0; i<queries.size() ; i++){
            int lx = queries[i][0],rx = queries[i][1];
            
            int l=0,r=invalid.size()-1;
            int goal = -1;
            while(l<=r){
                int md = (l+r)/2;
                if (invalid[md]>=lx){
                    r=md-1;
                    goal = invalid[md];
                }else{
                    l=md+1;
                }
            }

            if (~goal){
                ans.push_back(goal+1 > rx);
            }else{
                ans.push_back(true);
            }
        }

        return ans;
    }
};