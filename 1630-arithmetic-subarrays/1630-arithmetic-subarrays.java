class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        int q = l.length;
        List<Boolean> result = new ArrayList<>();
        for(int i=0;i<q;i++){
            int left = l[i],right = r[i];
            int[] slice = Arrays.copyOfRange(nums, left , right+1);
            if(slice.length<2){
                result.add(false);
            }else{
                Arrays.sort(slice); //rearranging to form 
                int diff = slice[1] - slice[0];
                Boolean found = true;
                for(int j=2;j<slice.length;j++){
                    if(slice[j] - slice[j-1]!= diff) found = false;
                }
                if(found) result.add(true);
                else result.add(false);
            }
        }
        return result;
    }
}