class Solution {
    bool ispresuf(string s1, string s2){
        if (s1.size() > s2.size()) return false;
        int i=0;
        while(i<s1.size() && s1[i]==s2[i]) i++;
        if (i!=s1.size()) return false;
        i = s1.size()-1;
        int j= s2.size()-1;
        while(i>=0 && s1[i]==s2[j]) i--,j--;
        if (i>=0) return false;
        return true; 
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans=0;
        for (int i=0 ; i<n ; i++){
            for (int j=i+1 ; j<n ; j++){
                if (ispresuf(words[i],words[j])) ans++;
            }
        }
        return ans;
    }
};