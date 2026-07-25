class Solution {
public:
    int maxProduct(int n) {
        vector<int>digits;
        int copy = n;
        while(n!=0){
            int rem = n%10;
            digits.push_back(rem);
            n/=10;
        }
        int len = digits.size();
        int maxi1= *max_element(digits.begin(),digits.end());
        int maxi2= INT_MIN;
        bool found=false;
        for(int i=0;i<len;i++){
            if(digits[i]==maxi1 && !found){
                found =true;
                continue;
            }
            maxi2=max(maxi2,digits[i]);
        }
        return maxi1*maxi2;
    }
};