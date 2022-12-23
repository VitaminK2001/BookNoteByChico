package 算法.Leetcode.binary_search;
// https://www.geekxh.com/1.99.%E5%85%B6%E4%BB%96%E8%A1%A5%E5%85%85%E9%A2%98%E7%9B%AE/21.html#_03%E3%80%81%E8%AF%81%E6%98%8E%E8%BF%87%E7%A8%8B
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len1 = nums1.length;
        int len2 = nums2.length;
        int total = len1 + len2;
        //如果是偶数,通过left 和 right 找到靠前和靠后的两个数
        //如果是奇数,left 和 right是同一个数
        int left = (total+1)/2;  
        int right = (total+2)/2;
        return (find(nums1, nums2, left, 0, 0) + find(nums1, nums2, right, 0, 0))/2.0;
    }
    //找到两个数组中第k小的元素
    public int find(int[] num1, int[] num2, int k, int i, int j){
        if(i >= num1.length){
            // 如果已经超过数组长度
            return num2[j+k-1]; //选取另一个数组的第k个元素
        }
        if(j >= num2.length){
            // 如果已经超过数组长度
            return num1[i+k-1]; //选取另一个数组的第k个元素
        }
        if(k == 1){
            // 如果已经不需要删数字
            return Math.min(num1[i], num2[j]);
        }
        int mid1 = (i + k/2 - 1) < num1.length ? num1[i + k/2 -1] : Integer.MAX_VALUE;
        int mid2 = (j + k/2 - 1) < num2.length ? num2[j + k/2 -1] : Integer.MAX_VALUE;
        if(mid1 < mid2){
            return find(num1, num2, k-k/2, i+k/2, j); //模拟删除掉的前k-1个元素
        }else {
            return find(num1, num2, k-k/2, i, j+k/2);
        }
    }
}