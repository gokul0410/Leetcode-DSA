class Solution {
    public boolean canAliceWin(int n) {
        int ptr = 10;
        int cnt = 0;
        while(n>=ptr){
            n-=ptr;
            ptr--;
            cnt++;
        }
        return (cnt%2!=0);
    }
}