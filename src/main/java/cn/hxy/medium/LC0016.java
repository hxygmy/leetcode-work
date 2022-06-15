package cn.hxy.medium;

import org.junit.Test;

import java.util.Arrays;

/**
 * 16. 最接近的三数之和
 *
 * 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
 *
 * 返回这三个数的和。
 *
 * 假定每组输入只存在恰好一个解。
 *
 *  
 *
 * 示例 1：
 *
 * 输入：nums = [-1,2,1,-4], target = 1
 * 输出：2
 * 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 * 示例 2：
 *
 * 输入：nums = [0,0,0], target = 1
 * 输出：0
 *  
 *
 * 提示：
 *
 * 3 <= nums.length <= 1000
 * -1000 <= nums[i] <= 1000
 * -104 <= target <= 104
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/3sum-closest
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 * @author Applewald
 * 2022/6/6 16:31
 */
public class LC0016 {
	public static void main(String[] args) {

	}

	public int threeSumClosest(int[] nums, int target) {
		Arrays.sort(nums);
		int sum = 9999999;
		for (int pivot = 0, begin = pivot + 1, end = nums.length - 1; pivot < nums.length - 1; pivot++) {
			while(begin < end){
				int s = nums[pivot] + nums[begin] + nums[end];
				if (s == target) {
					return s;
				}
				if (Math.abs(target - sum) > Math.abs(target - s)) {
					sum = s;
				}
				if (s < target) begin++;
				if (s > target) end--;
			}
			begin = pivot + 2;
			end = nums.length - 1;
		}
		return sum;
	}

	@Test
	public void test(){
		int[] a = new int[]{-3,-2,-5,3,-4};
		int target = -1;
		System.out.println(threeSumClosest(a, target));
	}
}
