class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        vector <int> valid(n);

        for (int i=0 ; i<n ; i++){
            if (i==0){
                if (colors[i]!=colors[i+1] && colors[i]!=colors[n-1]) 
                    valid[i] = 1;
            }else if (i==n-1){
                if (colors[i]!=colors[i-1] && colors[i]!=colors[0]) 
                    valid[i] = 1;
            }else{
                if (colors[i]!=colors[i+1] && colors[i]!=colors[i-1]) 
                    valid[i] = 1;
            }
        }

        for (int i=1 ; i<n ; i++) valid[i]+=valid[i-1];

        int ans = 0;
        for (int i=0 ; i<n ;i++){
            int start = i , end = i+k-1;
            int cnt = 0;
            if (end >= n){
                int rem = end-n;
                if (start + 1 == n){
                    cnt = valid[rem-1];
                }else{
                    if (rem==0){
                        cnt= valid[n-1]-valid[start];
                    }else{
                        cnt= valid[n-1]-valid[start];
                        cnt+= valid[rem-1];
                    }
                }
            }else{
                cnt = valid[end-1]-valid[start];
            }
            if (cnt == k-2) ans++;
        }

        return ans;
    }
};