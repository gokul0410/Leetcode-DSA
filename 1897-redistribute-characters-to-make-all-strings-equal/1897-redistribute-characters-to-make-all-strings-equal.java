class Solution {
    public boolean makeEqual(String[] words) {
        int n = words.length;
        int[] freq = new int[26];
        for(String it: words){
            int len = it.length();
            for(int i=0;i<len;i++){
                char ch = it.charAt(i);
                freq[ch-'a']++;
            }
        }
        for(int i=0;i<26;i++){
            if(freq[i]%n != 0) return false;
        }
        return true;
    }
}