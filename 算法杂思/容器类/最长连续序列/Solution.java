package 容器类.最长连续序列;

import java.util.HashSet;
import java.util.Set;

class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for(int num : nums) {
            set.add(num);
        }
        int res = 0;
        for(int num : nums) {
            if(!set.contains(num-1)) {
                int cur = num;
                int path = 1;
                while(set.contains(cur+1)) {
                    cur += 1;
                    path += 1;
                }
                res = Math.max(res, path);
            }
        } 
        return res;
    }
}