class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        int start = 100 , end = 999;
        int result = 0;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                for(int k=0;k<n ;k++){
                    if(i==k || j==k) continue;
                    int val = ((digits[i]*10)+digits[j])*10+digits[k];
                    if((val>=start && val<=end) && !st.count(val)){
                        if(!(val&1)) result++;
                        st.insert(val);   
                    }
                }
            }
        }
        return result;
    }
};