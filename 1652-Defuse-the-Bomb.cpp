class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n= code.size();
        vector <int> ans(n);
        if (!k) return ans;

        for (int i=0 ;i<n ;i++){
            if (k>0){
                int x = i+1;
                for (int j=0 ;j<k ;j++){
                    if (x==n) x=0;
                    ans[i]+= code[x++];
                }
            }else{
                int x = i-1;
                for (int j=0 ;j<abs(k) ;j++){
                    if (x==-1) x=n-1;
                    ans[i]+= code[x--];
                }
            }
        }
        return ans;
    }
};