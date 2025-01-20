class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size() ;
        vector <int> rows(n),cols(m);
        map <int,pair<int,int>> mp;

        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                mp[mat[i][j]] = {i,j};
            }
        }

        for (int i=0 ; i<arr.size() ; i++){
            int r = mp[arr[i]].first;
            int c = mp[arr[i]].second;
            rows[r]++, cols[c]++;
            if (rows[r] == m || cols[c]== n){
                return i;
            }
        }
        return arr.size()-1;
    }
};