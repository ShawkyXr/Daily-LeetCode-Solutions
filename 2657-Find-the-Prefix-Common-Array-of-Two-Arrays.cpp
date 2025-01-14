class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int a[51]{},b[51]{};
        vector <int> c(n);

        for (int i=0 ; i<n ;i++){
            if (A[i]==B[i]){
                c[i]++;
            }else{
                if (a[B[i]]){
                    c[i]++;
                }
                if (b[A[i]]){
                    c[i]++;
                }
            }

            if (i!=0){
                    c[i] += c[i-1];
            }

            a[A[i]]++,b[B[i]]++;
        }

        return c;
    }
};