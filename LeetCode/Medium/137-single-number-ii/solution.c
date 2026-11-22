int singleNumber(int* nums, int numsSize) {
    int uniq = 0;
    for(int i=0;i<32;++i){
        int count = 0;
        for(int j=0;j<numsSize;++j){
            if(((nums[j] >> i) & 1) == 1){
                count++;
            }
        }
        if(count % 3 == 1){
            uniq = uniq | (1U<<i);
        }
    }
    return uniq;
}
