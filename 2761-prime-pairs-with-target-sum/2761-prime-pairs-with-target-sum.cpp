class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool>prime(n+1,true);
        //sieve of erathoshtenses
        prime[0] = false ; prime[1] = false;
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                //making the prime factors has not prime
                for(int j=i*i;j<=n;j+=i)
                    prime[j] = false;
            }
        }
        set<vector<int>>st;
        for(int i=2;i<=n/2;i++){
            if(prime[i] && prime[n-i]){
                st.insert({i,n-i});
            }
        } 
        vector<vector<int>>result(st.begin(),st.end());
        return result;
    }
};