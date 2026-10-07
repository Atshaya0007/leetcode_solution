/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize=2;
    int* res=(int*)malloc(2* sizeof(int));
    res[0]=-1;
    res[1]=-1;
    
    
    int left=0;
    int right=numsSize-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]>=target){
            right=mid-1;
        }else{
            left = mid+1;
        }
    }
    if(left<numsSize && nums[left]==target){
        res[0]=left;
    }else{
        return res;
    }
    left=0;
    right=numsSize-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]<=target){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    res[1]=right;
    return res;
}
