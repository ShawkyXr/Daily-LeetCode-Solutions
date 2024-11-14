class Solution {
    bool good(int n,vector<int>& vec,int x){
        int stores = 0;
        for (int i=0 ; i<vec.size() ;i++){
            stores+=(int)ceil(vec[i]/double(x));
        }
        return stores<=n;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        // Binary Search for answer
        int l=1,r =100005, ans=0; 
        while(l<=r){
            int md = (l+r)/2;
            if (good(n,quantities,md)){
                r=md-1;
                ans = md;
            }else{
                l=md+1;
            }
        }
        return ans;
    }
};