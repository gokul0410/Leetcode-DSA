class Solution {
#define ll long long
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        else if(n<1e6) return n-999;

        long long comma = (1e6-1000);

        if(n<1e9) {
            ll val = n-1e6+1;
            return comma+(val*2);
        }
        comma+= (2e9-2e6);
        if (n<1e12){
            ll val = n-1e9+1;
            return comma+(3*val);
        }
        comma+=(3e12-3e9);
        if(n<1e15){
            ll val = n-1e12+1;
            return comma+(val*4);
        }
        comma+=(4e15-4e12);
        return comma+5;
    }
};