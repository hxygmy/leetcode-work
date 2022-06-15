package cn.hxy.hard;

/**
 * 4. 寻找两个正序数组的中位数
 * <a href="https://leetcode.cn/problems/median-of-two-sorted-arrays">题目链接</a>
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组nums1 和nums2。请你找出并返回这两个正序数组的 中位数 。
 *
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 * 示例 2：
 *
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 *
 *
 *
 *
 * 提示：
 *
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -106 <= nums1[i], nums2[i] <= 106
 *
 * @author 何晓宇
 * 2022/5/26 21:13
 */
public class LC0004 {
	public static void main(String[] args) {
		int[] a = {2,2,4,4};
		int[] b = {2,2,4,4};
		System.out.println(findMedianSortedArrays(a,b));
	}

	// 找到第K大的元素
	public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
		if (nums1.length == 0 && nums2.length == 0) return 0;
		if (nums1.length == 0 ) {
			if (nums2.length % 2 == 1){
				return nums2[nums2.length / 2];
			} else {
				return (nums2[nums2.length / 2 - 1] + nums2[nums2.length / 2]) / 2D;
			}
		}
		if (nums2.length == 0 ) {
			if (nums1.length % 2 == 1){
				return nums1[nums1.length / 2];
			} else {
				return (nums1[nums1.length / 2 - 1] + nums1[nums1.length / 2]) / 2D;
			}
		}

		double kth = getKth((nums1.length + nums2.length) / 2 + 1, nums1, nums2, 0, 0);
		if ((nums1.length + nums2.length) % 2 == 1) {
			return kth;
		} else {
			return (getKth((nums1.length + nums2.length) / 2, nums1, nums2, 0, 0) + kth) / 2;
		}
	}

	/**
	 * @param k 求两个数组第K大的元素
	 * @param nums1 第一个数组
	 * @param nums2 第二个数组
	 * @param flag1 第一个数组的偏移量，下标，非位序
	 * @param flag2 第二个数组的偏移量，下标，非位序
	 * @return 第k大元素的值
	 */
	private static double getKth(int k, int[] nums1, int[] nums2, int flag1, int flag2) {
		if (flag2 == nums2.length) return nums1[flag1 + k - 1];
		if (flag1 == nums1.length) return nums2[flag2 + k - 1];
		if (k == 1){
			return Math.min(nums1[flag1], nums2[flag2]);
		}
		if((k >> 1) + flag1 > nums1.length) {
			if (nums1[nums1.length - 1] > nums2[flag2 + (k >> 1) - 1]) {
				flag2 = flag2 + (k >> 1);
				k = k - (k >> 1);
				return getKth(k, nums1, nums2, flag1, flag2);
			} else {
				return nums2[k - nums1.length + flag1 + flag2 - 1];
			}
		}

		if ((k >> 1) + flag2 > nums2.length) {
			if (nums2[nums2.length - 1] > nums1[flag1 + (k >> 1) - 1]) {
				flag1 = flag1 + (k >> 1);
				k = k - (k >> 1);
				return getKth(k, nums1, nums2, flag1, flag2);
			} else {
				return nums1[k - nums2.length + flag2 + flag1 - 1];
			}
		}


		if (nums1[flag1 + (k >> 1) - 1] > nums2[flag2 + (k >> 1) - 1]) {
			flag2 = flag2 + (k >> 1);
		} else {
			flag1 = flag1 + (k >> 1);
		}
		k = k - (k >> 1);
		return getKth(k, nums1, nums2, flag1, flag2);
	}
}
