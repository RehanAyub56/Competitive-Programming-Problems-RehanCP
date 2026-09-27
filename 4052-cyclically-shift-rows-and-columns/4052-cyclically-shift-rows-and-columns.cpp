class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {

        
        for(int i=0;i<n;i++){

            int rot=rowShift[i];
            while(rot){
             for(int j=0;j<n-1;j++){
                swap(grid[i][j],grid[i][j+1]);
             }  
                rot--;
            }
        }

        for(int i=0;i<n;i++){
            int rot=colShift[i];
            while(rot){
             for(int j=0;j<n-1;j++){
                swap(grid[j][i],grid[j+1][i]);
             }  
                rot--;
            }
        }

        return grid;
    }
};