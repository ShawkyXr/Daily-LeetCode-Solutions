class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n= blocks.size();
        int w=0,op=k;
        for (int i=0 ; i<k ; i++){
            if (blocks[i]=='W') w++;
        }
        op = min(op,w);
        int l=1,r=k;
        while(r<n){
            if (blocks[l-1] =='W') w--;
            if (blocks[r]=='W') w++;
            op = min(op,w);
            l++,r++;
        }

        return op;
    }
};