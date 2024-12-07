class Solution {
    bool good(vector<int> &vec, int goal,int mx){
        int op=0;
        for (int i=vec.size()-1 ; i>=0 ;i--){
            if (vec[i] > goal){
                op+= (vec[i]/goal);
                if (vec[i]%goal==0) op--;
            }
        }
        return op <= mx;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1,r= *max_element(nums.begin(),nums.end()),ans=r;
        while(l<=r){
            int md = (l+r)/2;
            if (good(nums,md,maxOperations)){
                r = md-1;
                ans = md;
            }else{
                l = md+1;
            }
        }
        return ans;
    }
};