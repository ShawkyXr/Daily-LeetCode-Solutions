class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        // Matching string
        int idx=1;
        for (int i=0 ; i<sentence.size() ;i++){
            if (sentence[i]==' '){
                idx++;
                continue;
            }
            if(i==0 || sentence[i-1]==' '){
                int j=i;
                int start = 0;
                while(j<sentence.size() && start<searchWord.size() && sentence[j]==searchWord[start]){
                    j++,start++;
                }
                if (start==searchWord.size()) return idx;
            }
        }
        return -1;
    }
};