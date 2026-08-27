class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0) return {0};
        vector<int>result;
        result.push_back(0);
        for(int i=1;i<=n;i++){
            int ones =0;
            int val = i;
            while(val!=0){
                if(val&1){
                    ones++; val--;
                }
                val=val>>1;
            }
            result.push_back(ones);
        }
        return result ;
    }
};