package cn.hxy.easy;

import org.junit.Test;

/**
 * 704. 二分查找
 *
 * 给定一个n个元素有序的（升序）整型数组nums 和一个目标值target ，写一个函数搜索nums中的 target，如果目标值存在返回下标，否则返回 -1。
 *
 *
 * 示例 1:
 *
 * 输入: nums = [-1,0,3,5,9,12], target = 9
 * 输出: 4
 * 解释: 9 出现在 nums 中并且下标为 4
 * 示例2:
 *
 * 输入: nums = [-1,0,3,5,9,12], target = 2
 * 输出: -1
 * 解释: 2 不存在 nums 中因此返回 -1
 * 
 *
 * 提示：
 *
 * 你可以假设 nums中的所有元素是不重复的。
 * n将在[1, 10000]之间。
 * nums的每个元素都将在[-9999, 9999]之间。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/binary-search
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 * @author Applewald
 * 2022/6/15 10:24
 */
public class LC0704 {

	public static void main(String[] args) {

	}

	public int search(int[] nums, int target) {
		int res = -1;

		int begin = 0, end = nums.length - 1;
		while(begin <= end) {
			if (nums[(begin + end) / 2] == target) {
				res = (begin + end) / 2;
				break;
			} else if (nums[(begin + end) / 2] > target) {
				end = (begin + end) / 2 - 1;
			} else {
				begin = (begin + end) / 2 + 1;
			}
		}

		return res;
	}

	@Test
	public void test(){
		int[] a = new int[]{-1,0,3,5,9,12};
		System.out.println(search(a, 9));
	}
}
