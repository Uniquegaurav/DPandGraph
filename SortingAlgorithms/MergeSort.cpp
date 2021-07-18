void Merge(int input[],int left ,int mid ,int right){
    int temp[right -left+1];
    int i = left;
    int j = mid+1;
    int k =0;
    while(i<=mid&&j<=right){
     	if(input[i]<input[j]){
            temp[k++] = input[i++];
        }else{
            temp[k++] = input[j++];
        }
    }
    while(i<=mid){
        temp[k++] = input[i++];
    }
    while(j<=right){
        temp[k++] = input[j++];
    }
    for(int i = left, k=0;i<=right;i++,k++){
        input[i]=temp[k];
    } 
}

void MergeSort(int input[] ,int left ,int right ){
    if(left>=right){
        return;
    }
    int mid = (left+right)/2;
    MergeSort(input,left,mid);
    MergeSort(input,mid+1,right);
    Merge(input,left,mid,right);
}

void mergeSort(int input[], int size){
	// Write your code here
        int left = 0;
    	int right  = size -1;
    	MergeSort(input,left,right);
}
