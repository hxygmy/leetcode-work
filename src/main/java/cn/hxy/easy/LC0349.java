package cn.hxy.easy;

import java.util.*;
import java.util.stream.Collectors;

/**
 * 349. 两个数组的交集
 *
 * 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
 *
 *  
 *
 * 示例 1：
 *
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 * 示例 2：
 *
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4]
 * 解释：[4,9] 也是可通过的
 *  
 *
 * 提示：
 *
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/intersection-of-two-arrays
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 * @author Applewald
 * 2022/7/14 15:49
 */
public class LC0349 {
	public static void main(String[] args) {

	}

	public int[] intersection(int[] nums1, int[] nums2) {
		ArrayList<Integer> res = new ArrayList<>();
		List<Integer> list1 = Arrays.stream(nums1).distinct().boxed().collect(Collectors.toList());
		Arrays.stream(nums2).distinct().forEach(
				(i) -> {
					if (list1.contains(i)) {
						res.add(i);
					}
				}
		);
		return res.stream().mapToInt(Integer::valueOf).toArray();
	}
}
