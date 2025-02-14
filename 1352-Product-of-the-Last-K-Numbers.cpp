class ProductOfNumbers {
    vector <int> pref;
public:

    ProductOfNumbers() {
        pref.push_back(1);
    }
    
    void add(int num) {
        if (!num){
            pref.clear();
            pref.push_back(1);
            return;
        }
        pref.push_back(num * pref.back());
    }
    
    int getProduct(int k) {
        int n = pref.size();
        if (k>n-1) return 0;
        return pref[n-1] / pref[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */