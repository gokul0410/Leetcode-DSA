class Solution {
int MOD = 1e9 + 7;
using ll = long long int;
public:
    int countGoodNumbers(long long n) {
        ll odd = n/2 , even = (n+1)/2;
        auto power = [this](ll x , ll n) -> ll{
            ll result = 1;
        while(n!=0){
            if(n&1){
                result = (result*x)%MOD;
                n--;
            }else{
                x = (x*x)%MOD;
                n/=2;
            }
        }
        int val = result%MOD;
        return val;
        };
        ll result = (1LL*power(5,even)*power(4,odd))%MOD;
        return result;
    }
};