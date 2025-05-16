class Solution {
public:
    vector <vector <int>> dp;
    int takeorleave(int i,int lst, vector<string>& words, vector<int>& groups){
        if (i==words.size()) return 0;
        int take = 0,leave = 0;;
        int &ret = dp[i][lst];
        if (~ret) return ret; 
        if (lst==words.size()){
            take += takeorleave(i+1,i,words,groups)+1;
        }else{
            if (groups[i]!=groups[lst]){
                int cnt = 0, p=0;
                if (words[i].size() == words[lst].size()){
                    while(p<words[i].size()){
                        if (words[i][p]!=words[lst][p]) cnt++;
                        p++;
                    }
                    if (cnt==1) take += takeorleave(i+1,i,words,groups)+1;
                }
            }
        }
        leave += takeorleave(i+1,lst,words,groups);

        return ret = max(take,leave);
    }

    vector <string> ans ;

    void build(int i,int lst, vector<string>& words, vector<int>& groups){
        if (i==words.size()) return ;

        int take = -1, leave = 0;

        if (lst == words.size()){
            take = dp[i+1][i]+1;
        }else{
              if (groups[i]!=groups[lst]){
                int cnt = 0, p=0;
                if (words[i].size() == words[lst].size()){
                    while(p<words[i].size()){
                        if (words[i][p]!=words[lst][p]) cnt++;
                        p++;
                    }
                    if (cnt==1) take = dp[i+1][i]+1;
                }
            }
        }
         leave = dp[i+1][lst];

        if (take > leave){
            ans.push_back(words[i]);
            build(i+1,i,words,groups);
        }else{
            build(i+1,lst,words,groups);
        }

    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        dp.assign(words.size()+2,vector <int> (words.size()+2,-1));
        takeorleave(0, words.size(), words, groups);
        build(0,words.size(),words,groups);
        return ans;
    }
};