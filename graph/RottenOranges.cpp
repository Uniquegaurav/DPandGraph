#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges.
    bool canrotten(vector<vector<int>>& grid ,int i ,int j,int n,int m){
        return (i>=0&&i<n&&j>=0&&j<m&&grid[i][j]==1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int timer = -1;
        queue<pair<int,int>> q;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j] = 3;
                }
            }
        }
        while(!q.empty()){
            int count  = q.size();
            while(count--){
                auto index = q.front();
                q.pop();
                int i = index.first , j= index.second;
                if(canrotten(grid,i,j+1,n,m)){
                    q.push({i,j+1});
                    grid[i][j+1] =3;
                }
                if(canrotten(grid,i+1,j,n,m)){
                    q.push({i+1,j});
                    grid[i+1][j] =3;
                }
                if(canrotten(grid,i,j-1,n,m)){
                    q.push({i,j-1});
                    grid[i][j-1] =3;
                }
                if(canrotten(grid,i-1,j,n,m)){
                    q.push({i-1,j});
                    grid[i-1][j] =3;
                }
            }
            timer += 1;
        }
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return timer;
    }
};
