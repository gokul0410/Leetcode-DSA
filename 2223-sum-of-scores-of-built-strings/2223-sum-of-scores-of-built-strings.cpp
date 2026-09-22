class Solution {
public:
    long long sumScores(string s) {
        int n = s.length();
        //Z - function 
        vector<int>z(n,0);
        z[0] = n; int l= 0 , r=0;
        for(int i=1;i<n;i++){
            // we can reuse prefix 
            if(i<=r){
                z[i] = min(r-i+1,z[i-l]);
            }
            //checking prefix score
            while(i+z[i]<n && s[i+z[i]]==s[z[i]])
                z[i]++;
            // moving left and right  
            if(i+z[i]-1 > r ){
                l= i;
                r = i+z[i]-1;
            }
        }
        long long result = 0;
        for(int i=0;i<n;i++)
            result+=1LL*z[i];
        return result;
    }
};