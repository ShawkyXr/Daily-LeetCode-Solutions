class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map <string,int> freq,eq;
        int same = 0, rev = 0;
        string mxs = "";
        for (auto &word : words){
            freq[word]++;
            if (word[0]==word[1]) eq[word]++;
            else{
                reverse(word.begin(),word.end());
                if (freq[word] > 0){
                    rev++;
                    freq[word]--;
                    reverse(word.begin(),word.end());
                    freq[word]--;
                }
                continue;
            }
            if (eq[word] > same){
                same = eq[word];
                mxs = word;
            }
        }
        bool haveodd = 0,sameodd = 0;
        if (same&1) sameodd=1;
        
        for (auto e :eq){
            if (e.first != mxs && e.second > 1){
                same+=e.second;
                if (e.second&1) same--;
            }
            if (!sameodd && e.second &1) haveodd = 1;
        }

        if (haveodd) same++;

        return (rev*4) + (same*2);
    }
};