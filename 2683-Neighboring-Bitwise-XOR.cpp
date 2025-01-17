class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int lst = 0;
        for (int i=0 ; i<derived.size()-1 ; i++){
            if (derived[i]){
                lst^=1;
            }
        }
        return ((lst^0) == derived.back());
    }
};