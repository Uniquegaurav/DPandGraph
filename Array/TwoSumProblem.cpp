// Given a sorted array A (sorted in ascending order), having N integers, 
// find if there exists any pair of elements (A[i], A[j]) such that their sum is equal to X.

bool isPairSum(int arr[], int N, int X){
    int i =0; // represents first pointer
    int j = N-1;  // represents second pointer
    while(i<j){
        if(arr[i]+arr[j]==X){        // If we find a pair
            return true;
        }else if(arr[i]+arr[j]<X){  // If sum of elements at current pointers is less,
            i += 1;                      // we move towards higher values by doing i++
        }else{
            j -= 1;              // If sum of elements at current pointers is more, we move towards
                                      // lower values by doing j--
        }
    }
    return false;
}
