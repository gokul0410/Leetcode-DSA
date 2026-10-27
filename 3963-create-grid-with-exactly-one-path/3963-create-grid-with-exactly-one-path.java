class Solution {
    public String[] createGrid(int m, int n) {
        String[] grid = new String[m];
        for(int i=0;i<m;i++){
            String temp = "";
            for(int j =0;j<n;j++){
                if(j == 0 || i == m-1)
                    temp+= '.';
                else temp+= '#';
            }
            grid[i] = temp;
        }
        return grid;
    }
}