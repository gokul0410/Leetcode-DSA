class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string result = "";
        //when sum is bigger than max integer offered in num digits
        if(sum>9*num) return result;
        for(int i=0;i<num;i++){
            int val = min(sum , 9);
            result+=to_string(val);
            sum-=val;
        }
        return result;
    }
};