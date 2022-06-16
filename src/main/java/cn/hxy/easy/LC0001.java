package cn.hxy.easy;

import org.junit.Test;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * 1. 两数之和
 * 给定一个整数数组 nums和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那两个整数，并返回它们的数组下标。
 *
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 *
 * 你可以按任意顺序返回答案。
 *
 *
 * 示例 1：
 *
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[0,1]
 * 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
 * 示例 2：
 *
 * 输入：nums = [3,2,4], target = 6
 * 输出：[1,2]
 * 示例 3：
 *
 * 输入：nums = [3,3], target = 6
 * 输出：[0,1]
 * 
 *
 * 提示：
 *
 * 2 <= nums.length <= 104
 * -109 <= nums[i] <= 109
 * -109 <= target <= 109
 * 只会存在一个有效答案
 * 进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？
 *
 * <a href="https://leetcode.cn/problems/two-sum">链接</a>
 *
 * @author 何晓宇
 * 2022/5/24 16:20
 */
public class LC0001 {

	/**
	 * 两数之和
	 * 1. HashMap维护一个<数组元素, 数组下标>的键值对
	 * 2. 遍历数组，在HashMap中寻找(target - nums[i])，若存在即为答案，若不存在则把<nums[i], i>压入HashMap，继续遍历
	 *
	 * 时间复杂度O(n)
	 *
	 * @param nums		数组
	 * @param target	两数之和
	 * @return			相加得到target的两个数字的数组下标
	 */
	public int[] twoSum(int[] nums, int target) {
		Map<Integer, Integer> map = new HashMap<>();
		int[] result = new int[0];
		for(int i = 0 ; i < nums.length; i++){
			if (map.get(target - nums[i]) == null) {
				map.put(nums[i], i);
			} else {
				result = new int[]{map.get(target - nums[i]), i};
				break;
			}
		}
		return result;
	}


	@Test
	public void test(){
		int[] nums = new int[]{2,7,11,15};
		System.out.println(Arrays.toString(twoSum(nums, 9)));
	}

	/*
	 * 执行用时：
	 * 1 ms
	 * , 在所有 Java 提交中击败了
	 * 99.33%
	 * 的用户
	 * 内存消耗：
	 * 41.3 MB
	 * , 在所有 Java 提交中击败了
	 * 74.09%
	 * 的用户
	 * 通过测试用例：
	 * 57 / 57
	 */
}
