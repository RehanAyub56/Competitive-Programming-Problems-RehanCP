class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>a;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a.push_back(grid[i][j]);
            }
        }

        sort(a.begin(),a.end());
        n=a.size();
        int mid=a[n/2];
        long long int ans=0;
        for(int i=0;i<n;i++){
            int y=abs(mid-a[i]);
            if(y%x==0){
                ans+=(y/x);
            }
            else{
                return -1;  
            }
        }

        return  ans;
    }
};