class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        
        int i=0,j=0;
        for (; i<str1.size() ;i++){
            if (str1[i]=='z'){
                if (str2[j]=='z' || str2[j]=='a') {
                    j++;
                    if (j==str2.size()) return true;
                }
            }else{
                if (str1[i]==str2[j] || str1[i]+1==str2[j]){
                    j++;
                    if (j==str2.size()) return true;
                }
            }
        }
        return false;
        
    }
};