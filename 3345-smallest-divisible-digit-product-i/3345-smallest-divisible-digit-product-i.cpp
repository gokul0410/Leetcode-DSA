class Solution {
public:
    int smallestNumber(int n, int t) {
        int result;
        while(true){
            int digits=1,cpy=n;
            while(cpy!=0){
                digits*=(cpy%10);
                cpy/=10;
            }
            if(digits%t==0){
                result=n; break;
            } 
            n++;
        }
        return result;
    }
};