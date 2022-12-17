class Solution {
    public int maxArea(int[] height) {
        int maxheight = height[0]; //水桶原理
        int dis = 0; //水平间的距离
        int ans = 0;
        int res = Integer.MIN_VALUE;
        for(int i = 0; i < height.length; ++i){
            maxheight = height[i];
            for(int j = i+1; j < height.length; ++j){
                maxheight = Math.min(maxheight, height[j]);
                dis = j-i;
                ans = dis * maxheight;
                res = Math.max(ans, res);
            }
        }
        return res;
    }
    
    public static void main(String[] args) {
        Solution s = new Solution();
        s.maxArea(new int[]{1,8,6,2,5,4,8,3,7});
    }
}