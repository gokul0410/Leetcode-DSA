class Solution {
public:
    bool canAliceWin(int n) {
        int val =10,i=1;
        while(val<=n){
            n= n-val;
            val--;
            i++;
        }
        if(i%2==0) return true;
        return false;
    }
};