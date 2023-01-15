package 算法杂思.滑动窗口.三数之和;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution{
    // 基础的枚举方法
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        for(int i = 0; i < nums.length; ++i){
            int l = i+1;
            int r = nums.length-1;
            if(nums[i] > 0) break;
            if(i == 0 || nums[i-1] != nums[i]){ //首先判断是否已经跳过重复的数字
                while(l < r){
                    int target = 0-nums[i];
                    if(nums[l] + nums[r] == target){
                        res.add(Arrays.asList(nums[i], nums[l], nums[r]));
                        // 跳过重复的
                        while(l < r && nums[l] == nums[l+1]) ++l;
                        while(l < r && nums[r] == nums[r-1]) --r;
                        ++l;
                        --r;
                    }else if(nums[l] + nums[r] < target){
                        ++l;
                    }else {
                        --r;
                    }
                }
            }
        }
        return res;
    }
}
