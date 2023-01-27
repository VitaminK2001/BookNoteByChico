#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n-1, ans = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for(int i = 0; i < n; ++i) {
                cnt += nums[i] <= mid;
            }
            if(cnt <= mid) {
                l = mid + 1;
            }else {
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }

    // 可以采用指针的做法
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = nums[nums[fast]];
        // 因为数组中有一个重复元素，所以有环，快慢指针一定会相遇
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]]; // 快指针走两步
        }
        // 从头开始的指针和从相遇点开始的指针 每次都走一步 相遇点就是入口点
        int pre1 = 0;
        int pre2 = slow;
        while(pre1 != pre2) {
            pre1 = nums[pre1];
            pre2 = nums[pre2];
        }
        return pre1;
    }
    // slow和fast会在环中相遇，先假设一些量：起点到环的入口长度为m，环的周长为c，在fast和slow相遇时slow走了n步。
    // 则fast走了2n步，fast比slow多走了n步，而这n步全用在了在环里循环（n%c==0）。
    // 当fast和last相遇之后，我们设置第三个指针finder，它从起点开始和slow(在fast和slow相遇处)同步前进，
    // 当finder和slow相遇时，就是在环的入口处相遇，也就是重复的那个数字相遇。

    // 为什么 finder 和 slow 相遇在入口
    // fast 和 slow 相遇时，slow 在环中行进的距离是n-m，其中 n%c==0。
    // 这时我们再让 slow 前进 m 步——也就是在环中走了 n 步了。
    // 而 n%c==0 即 slow 在环里面走的距离是环的周长的整数倍，就回到了环的入口了，而入口就是重复的数字。
    // 我们不知道起点到入口的长度m，所以弄个 finder 和 slow 一起走，他们必定会在入口处相遇。

    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int left = 1;
        int right = len - 1;
        while(left < right) {
            int mid = (left + right) >> 1;
            int count = 0;
            for(int num : nums) {
                if(num <= mid) {
                    count++;
                }
            }
            if(count > mid) {
                right = mid;
            }else {
                left = mid + 1;
            }
        }
        return left;
    }
};