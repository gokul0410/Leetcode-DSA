class Solution {
    public static int GCD(int a , int b){
        while(b!= 0){
            int temp = b;
            b = a%b;
            a = temp; 
        }
        return Math.abs(a); //positive value
    }
    public static int LCM(int a , int b){
        if(a==0 || b ==0) return 0;
        return Math.abs((a/GCD(a,b))*b);
    }
    public int maxLength(int[] nums) {  
        int n = nums.length;
        int maxi = Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            int curr = 1 , lcm = 1 , gcd =0;
            for(int j=i;j<n;j++){
                curr*= nums[j];
                lcm = LCM(lcm , nums[j]);
                gcd = GCD(gcd , nums[j]);
                if(curr == (lcm*gcd)) maxi = Math.max(maxi , j-i+1);
            }
        }
        return maxi;
    }
}