package cn.hxy.medium;

import org.junit.Test;

/**
 * 209. 长度最小的子数组
 *
 * 给定一个含有n个正整数的数组和一个正整数 target 。
 *
 * 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组[numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 *
 * 
 *
 * 示例 1：
 *
 * 输入：target = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组[4,3]是该条件下的长度最小的子数组。
 * 示例 2：
 *
 * 输入：target = 4, nums = [1,4,4]
 * 输出：1
 * 示例 3：
 *
 * 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
 * 输出：0
 * 
 *
 * 提示：
 *
 * 1 <= target <= 109
 * 1 <= nums.length <= 105
 * 1 <= nums[i] <= 105
 * 
 *
 * 进阶：
 *
 * 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/minimum-size-subarray-sum
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 * @author Applewald
 * 2022/6/9 10:03
 */
public class LC0209 {
	public static void main(String[] args) {

	}

	public int minSubArrayLen(int target, int[] nums) {
		int begin = 0;
		int end = 0;
		int sum = 0;
		int res = Integer.MAX_VALUE;
		while (begin < nums.length){
			while(sum < target && end < nums.length){
				sum += nums[end];
				end++;
			}
			if(sum >= target && res > (end - begin)) {
				res = end - begin;
			}
			sum -= nums[begin];
			begin++;
		}
		return res == Integer.MAX_VALUE ? 0 : res;
	}

	@Test
	public void test(){
		int[] a = new int[]{2,3,1,2,4,3};
		System.out.println(minSubArrayLen(7, a));
	}

	/*
	 * 执行用时：
	 * 1 ms
	 * , 在所有 Java 提交中击败了
	 * 99.98%
	 * 的用户
	 * 内存消耗：
	 * 41.2 MB
	 * , 在所有 Java 提交中击败了
	 * 58.84%
	 * 的用户
	 */
}
