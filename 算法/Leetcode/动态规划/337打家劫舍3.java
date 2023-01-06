package 算法.Leetcode.dynamic;

import java.util.HashMap;

class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public int rob(TreeNode root) {
        HashMap<TreeNode, Integer> memo = new HashMap<>();
        return robInternal(root, memo);
    }
    public int robInternal(TreeNode root, HashMap<TreeNode, Integer> memo){
        if(root == null) return 0;
        if(memo.containsKey(root)) return memo.get(root);
        int money = root.val;
        if(root.left != null){
            money += robInternal(root.left.left, memo) + robInternal(root.left.right, memo);
        }
        if(root.right != null){
            money += robInternal(root.right.left, memo) + robInternal(root.right.right, memo);
        }
        int result = Math.max(money, robInternal(root.left, memo) + robInternal(root.right, memo));
        memo.put(root, result);
        return result;
    }
}

class Solution2{
    public int rob(TreeNode root){
        int[] result = robInternal(root);
        return Math.max(result[0], result[1]);
    }
    public int[] robInternal(TreeNode root){
        if(root == null) return new int[2];
        int[] result = new int[2]; //root节点对应的偷与不偷
        int[] left = robInternal(root.left);
        int[] right= robInternal(root.right);
        result[0] = Math.max(left[1], left[0]) + Math.max(right[1], right[0]);
        result[1] = left[0] + right[0] + root.val;
        return result;
    }
}
