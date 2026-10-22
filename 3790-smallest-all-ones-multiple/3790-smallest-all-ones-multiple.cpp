class Solution {
public:
    int minAllOneMultiple(int k) {
        if(!(k&1)) return -1;
        if(k == 5) return -1;
        int val = 0; int dig = 0;
        for(int i=1;i<=k;i++){
            val =(val*10+1)%k; dig++;
            if(val == 0) return dig; 
        }
        return -1;
    }
};