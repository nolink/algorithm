void merge(int* nums1, int m, int* nums2, int n) {
    int i=0;
    int j = 0;
    int k=0;
    
    if(m == 0){
        for(;i<n;i++){
            nums1[i]=nums2[i];
        }
        return;
    }
    if(n == 0){
        return;
    }
    
    int temp[m+n];
    for(;i<m+n;i++){
        
        if(j < m && k < n){
            if(nums1[j] < nums2[k]){
                temp[i] = nums1[j];
                j++;
            }else{
                temp[i] = nums2[k];
                k++;
            }
        }else if(j < m && k >= n){
            temp[i] = nums1[j];
            j++;
        }else{
            temp[i] = nums2[k];
            k++;
        }
    }
    
    i=0;
    for(;i<m+n;i++){
        nums1[i] = temp[i];
    }
    
}