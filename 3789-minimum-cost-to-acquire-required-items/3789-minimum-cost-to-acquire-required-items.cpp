class Solution {
using ll = long long int;
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll c1 = 1LL*cost1*need1, c2 = 1LL*cost2*need2;
        ll cb1 = (1LL*max(need1 , need2)*costBoth);
        ll cb2 = 1LL*(min(need1 , need2));
        if(cb2 == need1){
            cb2*= (1LL*costBoth);
            cb2+= (1LL*(need2 - need1) *cost2);
        }else{
            cb2*= (1LL*costBoth);
            cb2+= (1LL*(need1 - need2) *cost1);
        }
        return min({c1+c2 , cb1 , cb2});
    }
};