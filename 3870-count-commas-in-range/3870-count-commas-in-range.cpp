class Solution {
public:
    int countCommas(int n) {
        if(n<1000) return 0;
        int comma = 0;
        for(int i=1000;i<=n;i++){
            int div = 1000, num= i;
            while(num>100){
                num/=div;
                if(div == 1000) div = 100;
                comma++;
            }
        }
        return comma;
    }
};