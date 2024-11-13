class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // store best answer for each item in map
        sort(items.begin(),items.end());
        int maxval = 0;
        for (int i=0 ; i < items.size() ; i++){
            maxval = max(maxval,items[i][1]);
            items[i][1] = maxval;
        }

        vector <int> ans;
        // answer for quieres
        for (int i=0 ; i<queries.size() ; i++){
            int cost = queries[i];
            int l=0,r=items.size()-1,res=0;
            while(l<=r){
                int md = (l+r)/2;
                if (items[md][0]<=cost){
                    res = items[md][1];
                    l=md+1;
                }else{
                    r = md-1;
                }
            }
            ans.push_back(res);
        }

        return ans;
    }
};