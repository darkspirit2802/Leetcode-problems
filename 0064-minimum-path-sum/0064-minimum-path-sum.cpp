class Solution {
public:
    int m , n;
    int solve(int i , int j , vector<vector<int>>& grid,int m , int n,vector<vector<int>> &t){
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }

        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(i==m-1){
            return t[i][j] = grid[i][j] + solve(i,j+1,grid,m,n,t); 
        }else if(j==n-1){
            return t[i][j] = grid[i][j] + solve(i+1,j,grid,m,n,t);
        }else{
            return t[i][j] = grid[i][j] + min(solve(i,j+1,grid,m,n,t),solve(i+1,j,grid,m,n,t));
        }
        
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>>t(m+1,vector<int>(n+1,-1));
        
        return solve(0,0,grid,m,n,t);    
    }   
};  