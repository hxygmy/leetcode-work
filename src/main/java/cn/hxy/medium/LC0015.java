package cn.hxy.medium;

import java.util.*;

/**
 * 15. 三数之和
 *
 * 给你一个包含 n 个整数的数组nums，判断nums中是否存在三个元素 a，b，c ，使得a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
 *
 * 注意：答案中不可以包含重复的三元组。
 *
 * 
 *
 * 示例 1：
 *
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 示例 2：
 *
 * 输入：nums = []
 * 输出：[]
 * 示例 3：
 *
 * 输入：nums = [0]
 * 输出：[]
 * 
 *
 * 提示：
 *
 * 0 <= nums.length <= 3000
 * -105 <= nums[i] <= 105
 *
 * 来源：力扣（LeetCode）
 * 链接：<a href="https://leetcode.cn/problems/3sum">链接</a>
 *
 * @author 何晓宇
 * 2022/6/5 23:10
 */
public class LC0015 {

	public static void main(String[] args) {

	}

	/**
	 * 思路：分开正负到两个数组里，
	 * 然后就变成了在正数数组里寻找两数之和的问题 <a href="https://leetcode.cn/problems/two-sum">两数之和问题链接</a>
	 * @param nums 	待寻找数组
	 * @return		返回可能的所有结果
	 */
	public List<List<Integer>> threeSum(int[] nums) {
		Arrays.sort(nums);
		List<List<Integer>> result = new ArrayList<>();
		for (int i = 0; i < nums.length - 1; i++) {
			result.addAll(twoSum(nums, -nums[i], i + 1));
			while (i < nums.length - 1 && nums[i] == nums[i + 1]) i++;
		}
		return new ArrayList<>(result);
	}

	private List<List<Integer>> twoSum(int[] nums, int target, int begin) {
		Set<Integer> list = new HashSet<>();
		Set<List<Integer>> result = new HashSet<>();
		for (int i = begin; i < nums.length; i++) {
			if (list.contains(target - nums[i])) {
				result.add(Arrays.asList(-target, target - nums[i], nums[i]));
				list.add(nums[i]);
			} else {
				list.add(nums[i]);
			}
		}
		return new ArrayList<>(result);
	}
}
