#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
   int maxSubarraySum(vector<int> arr, int n){     
        int max_sum = INT_MIN;
        int until = 0;
        for(int i =0;i<n;i++){
            until += arr[i];
            if(until>max_sum)
                max_sum = until;
            if(until<0)
                until = 0;
        }
        return max_sum;    
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {     
       int max_subarray_sum  = INT_MIN;
       for(int i =0;i<R;i++){
            vector<int> newrow(C);
            for(int j = i;j<R;j++){
                for(int col = 0 ;col<C;col++){
                    newrow[col] += M[j][col];
                }
                max_subarray_sum = max(max_subarray_sum,maxSubarraySum(newrow,C));
            }
       }
       return max_subarray_sum;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  