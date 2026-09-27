class NumMatrix {
public:
   vector<vector<int>>a;
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            vector<int>v;
            for(int j=0;j<matrix[i].size();j++){
                v.push_back(matrix[i][j]);
            }
            a.push_back(v);
        }
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size();j++){
                int x=i-1,y=j-1;
                if(x>=0){
                    a[i][j]+=a[x][j];
                }
                if(y>=0){
                    a[i][j]+=a[i][y];
                }
                if(x>=0 && y>=0)a[i][j]-=a[x][y];
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int col=col1-1,row=row1-1;
        int sum=a[row2][col2];

        if(col>=0) sum-=a[row2][col];   
        if(row>=0) sum-=a[row][col2];

        int dr=row1-1,dc=col1-1;
        if(dr>=0 && dc>=0) sum+=a[dr][dc];
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */