class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        int n = nums.length;
        int maxi = Arrays.stream(nums).max().getAsInt();
        int mini = Arrays.stream(nums).min().getAsInt();
        int range = maxi - mini + 1;
        int [] freq = new int[range];
        for(int i=0;i<n;i++) freq[i]=0;
        for(int i=0 ;i<n ;i++){
            freq[nums[i]-mini]++;
        }
        List<Integer> result = new ArrayList<>();
        for(int i=0;i<range;i++){
            if(freq[i]==0){
                result.add(i+mini);
            }
        }
        return result;
    }
}