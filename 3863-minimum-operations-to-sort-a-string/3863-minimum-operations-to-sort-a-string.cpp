class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        string sorted = s;
        sort(sorted.begin(),sorted.end());
        if(s == sorted) return 0;
        if(n == 2) return -1;
        if(s[0] == sorted[0] || s[n-1] == sorted[n-1]) return 1;
        int c1 = count(s.begin(),s.end(),sorted[0]);
        int c2 = count(s.begin(),s.end(),sorted[n-1]);
        if(s[0]== sorted[n-1] && c2==1 && s[n-1] == sorted[0] && c1==1)
            return 3;
        return 2;
    }
};