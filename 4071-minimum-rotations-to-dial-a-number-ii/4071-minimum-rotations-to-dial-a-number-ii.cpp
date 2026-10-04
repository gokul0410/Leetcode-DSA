class Solution {
public:
    int minRotations(int n, string s) {
        auto dist =[](char ch1 , char ch2)->int{
            int val1= ch1-'0', val2 = ch2-'0';
            return min(abs(val1-val2), 10-abs(val1-val2));
        };
        if(n == 1) return dist('0',s[0]);
        int total = dist('0',s[0]);
        for(int i=0;i<n-1;i++){
            total+=dist(s[i],s[i+1]);
        }
        int mini = total;
        //cout<<mini<<" ";
        //when k= 0 
        mini = min(mini , total-dist('0',s[0])+dist('0',s[n-1]));
        for(int k=1;k<n;k++){
            int temp = total - dist(s[k-1],s[k])+dist(s[k-1],s[n-1]);
            mini = min(mini , temp);
        }
        return mini;
    }
};