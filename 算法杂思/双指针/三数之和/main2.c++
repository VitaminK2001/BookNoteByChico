#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// https://leetcode.cn/problems/3sum/
// 答案中不能包含重复的三元组
// 假如有一个三元组 {-1 -1 2} 但是数组中存在两个相同的2
// 则算到后面一个2的时候可能会出现相同的情况
// 所以答案中不能包含重复的三元组的意思就是，计算到数组中相同元素的值时跳过
// 因为三元组的顺序和输出的顺序都不重要，所以对数组进行排序，如果当前的数组和之前相同则跳过
// 而且每次找三个元素都从当前的位置往后找
// 因为需要判断当前的元素是否可能在一个三元组中
// 如果不可能或者可能这个元素都只能出现一次
// 如果允许找左边的数则一定会出现重复的情况
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.size() < 3) return res;
        // 从小到大排序
        bubble_sort(nums);
        for(int n : nums){
            cout << n << " " << endl;
        }
        for(int i = 0; i < nums.size(); ++i){
            // 如果当前的数大于0 则返回res
            if(nums[i] > 0) return res;
            // 如果当前的数和前面一个数相同则要去重
            // 注意不一定相同的只有一个所以是while
            while(i > 0 && i < nums.size() && nums[i] == nums[i-1]) i++;

            // 需要找到两个数 和nums[i]相加等于0
            int l = i+1, r = nums.size()-1;
            int sum = 0;
            while(l < r){
                sum = nums[i] + nums[l] + nums[r];
                // 如果等于0
                if(sum == 0) {
                    vector<int> path;
                    path.push_back(nums[i]);
                    path.push_back(nums[l]);
                    path.push_back(nums[r]);
                    res.push_back(path);
                    while(l < r && nums[l] == nums[l+1]){
                        ++l;
                    }
                    // 就算没有上面相同的情况也需要移动l
                    ++l;
                    while(l < r && nums[r] == nums[r-1]){
                        --r;
                    }
                    // r同理
                    --r;
                }else if(sum < 0) {
                    l++;
                }else if(sum > 0){
                    r--;
                }
            }
        }
        return res;
    }
    void static bubble_sort(vector<int>& nums){
        int sz = nums.size();
        int cnt = 0; // 已经排好的个数
        int pos = 0; // 记录最小数的位置
        int tmp = 0; // 做交换用
        while(cnt < sz-1){
            int key = nums[cnt];
            pos = cnt;
            for(int i = cnt+1; i < sz; ++i){
                if(nums[i] < key){
                    // 一定要体现最小，所以需要改变key的值
                    key = nums[i];
                    pos = i;
                }
            }
            // 找到最小的一个数后
            tmp = key;
            nums[cnt] = nums[pos];
            nums[pos] = tmp;
            cnt++;
        }
    }
};

int main(){
     int a[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<int> c(a, a+15);
    vector<int>& b = c;
    Solution s;
    s.threeSum(b);
}   

