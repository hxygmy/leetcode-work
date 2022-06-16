package cn.hxy.easy;

/**
 * 977. 有序数组的平方
 *
 * 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 *
 * 
 *
 * 示例 1：
 *
 * 输入：nums = [-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 * 解释：平方后，数组变为 [16,1,0,9,100]
 * 排序后，数组变为 [0,1,9,16,100]
 * 示例 2：
 *
 * 输入：nums = [-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
 * 
 *
 * 提示：
 *
 * 1 <= nums.length <= 104
 * -104 <= nums[i] <= 104
 * nums 已按 非递减顺序 排序
 * 
 *
 * 进阶：
 *
 * 请你设计时间复杂度为 O(n) 的算法解决本问题
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/squares-of-a-sorted-array
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 * @author Applewald
 * 2022/6/8 0:22
 */
public class LC0977 {
	public static void main(String[] args) {

	}

	/**
	 * 用前后两个指针即可一次遍历完成
	 * @param nums	待排数组
	 * @return		排序后数组
	 */
	public int[] sortedSquares(int[] nums) {
		int begin = 0;
		int end = nums.length - 1;
		int i = nums.length - 1;

		int[] res = new int[nums.length];

		while (begin <= end) {
			if (nums[begin] >= 0){
				while (end >= begin) {
					res[i] = nums[end] * nums[end];
					i--;
					end--;
				}
			} else {
				if (- nums[begin] > nums[end]) {
					res[i] = nums[begin] * nums[begin];
					begin++;
				} else {
					res[i] = nums[end] * nums[end];
					end--;
				}
				i--;
			}

		}
		return res;

	}

	/*
	 * 执行用时：
	 * 1 ms
	 * , 在所有 Java 提交中击败了
	 * 100.00%
	 * 的用户
	 * 内存消耗：
	 * 43.2 MB
	 * , 在所有 Java 提交中击败了
	 * 30.67%
	 * 的用户
	 * 通过测试用例：
	 * 137 / 137
	 */
}
