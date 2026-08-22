class Solution {
public:
    bool checkDivisibility(int n) {
        int Sum=0, Prod=1;
        int cpy = n;
        while(cpy!=0){
            Sum+=(cpy%10); Prod*=(cpy%10);
            cpy/=10; 
        }
        return (n%(Sum+Prod) == 0) ;
    }
};