class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if ((locked[0]=='1' && s[0]==')') || (locked[n-1]=='1' && s[n-1]=='(') || n&1){
            return false;
        }
        stack <int> x;
        stack <int> st;
        for (int i=0 ; i<n ; i++){
            if (locked[i]=='0'){
                x.push(i);
            }else{
                if (s[i]=='(') {
                    st.push(i);
                }else{
                    if (!st.empty()){
                        st.pop();
                    }else {
                        if (x.empty()){
                            return false;
                        }else{
                            x.pop();
                        }
                    }
                }
                
            }
        }
        while(!st.empty() && !x.empty() && st.top() < x.top()){
            st.pop();
            x.pop();
        }
        return st.empty();
    }
};