 void sort012(int a[], int n)
   {
        int count0 =0 , count1 =0 ,count2 =0;
        for(int i =0;i<n;i++){
            if(a[i]==0){
                count0 += 1;
            }else if(a[i]==1){
                count1 += 1;
            }else{
                count2 += 1;
            }
        }
        //cout<<count0<<count1<<count2<<endl;
        for(int i =0;i<count0;i++){
            a[i] = 0;
        }
        for(int i = count0;i<(count0 + count1);i++){
            a[i] = 1;
        }
        for(int i =count0 + count1 ;i<n;i++){
            a[i] = 2;
        }
    }