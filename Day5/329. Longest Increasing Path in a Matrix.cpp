// Link to the problem :- https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
class Solution {
public:
    int dx[4]= {1,-1,0,0};
    int dy[4]= {0,0,-1,1};
    int f(int i, int j, int n, int m, vector<vector<int>>& arr, vector<vector<int>> &dp){
        if(i<0 || j<0 || i>=n || j>=m){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=1;
        for(int k=0; k<4; k++){
            int x=i+dx[k], y= j+dy[k];
            if(x>=0 && y>=0 && x<n && y<m && arr[x][y] > arr[i][j]){
                dp[i][j]=max(1+f(x,y,n,m,arr,dp),dp[i][j]);
            }
        }
        return dp[i][j];       
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=1;
        for(int i=0; i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,f(i,j,n,m,matrix,dp));
            }
        }
        return ans;
    }
};