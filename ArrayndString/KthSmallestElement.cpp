class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
     void insert(int arr[],int n) {
        for(int i =1;i<n;i++){
            
                int childIndex = i;
                while (childIndex > 0) {
                int parentIndex = (childIndex - 1) / 2;

                if (arr[childIndex] < arr[parentIndex]) {
                    int temp = arr[childIndex];
                    arr[childIndex] = arr[parentIndex];
                    arr[parentIndex] = temp;
                } else {
                    break;
                }

                childIndex = parentIndex;
                }
        }
       
   }

   void removeMin(int arr[],int n,int k,int & ans) {
      
       int size = n;
       int v = k;
       while(v--){
       int temp = arr[0];
       arr[0] = arr[size-1];
       arr[size-1] = temp;
       size -= 1;
       int parentIndex = 0;
       int leftChildIndex = 2*parentIndex + 1;
       int rightChildIndex  = 2*parentIndex  + 2;
       while(leftChildIndex<size){
           int minIndex = parentIndex;
           if(arr[leftChildIndex]<arr[minIndex]){
               minIndex = leftChildIndex;
           }
           if(rightChildIndex<size&&arr[rightChildIndex]<arr[minIndex]){
               minIndex = rightChildIndex;
           }
           if(minIndex==parentIndex){
               break;
           }
           int temp = arr[minIndex];
           arr[minIndex] = arr[parentIndex];
           arr[parentIndex] = temp;
           
           parentIndex = minIndex;
           leftChildIndex = 2*parentIndex + 1;
           rightChildIndex = 2*parentIndex + 2;
        }
     }
     ans = arr[n-k];
   }
    int kthSmallest(int arr[], int l, int r, int k) {
        int n = r+1;
        insert(arr,n);
        int ans = -1;
        removeMin(arr,n,k,ans);
        return ans;
    }
};