class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        int mod = grid[0][0]%x;
        vector <int> arr;
        for (auto &r : grid){
            for (auto &i : r){
                arr.push_back(i);
                if (i%x != mod) return -1;
            }
        }

        sort(arr.begin(),arr.end());
        int target = arr[arr.size()/2];

        int cost = 0;

        for (auto &i : arr){
            cost+= abs(target-i)/x;
        }

        return cost;
    }
};