class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int Odd=0, Even=0;
        for(int i=1 ; i<=2*n ; i++){
            if(i%2==0) Even+=i;
            else Odd+=i;
        }
        return gcd(Odd , Even);
    }
};