package cn.hxy.medium;

/**
 * 11. 盛最多水的容器
 *
 * 给定一个长度为 n 的整数数组height。有n条垂线，第 i 条线的两个端点是(i, 0)和(i, height[i])。
 *
 * 找出其中的两条线，使得它们与x轴共同构成的容器可以容纳最多的水。
 *
 * 返回容器可以储存的最大水量。
 *
 * 说明：你不能倾斜容器。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：[1,8,6,2,5,4,8,3,7]
 * 输出：49 
 * 解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为49。
 * 示例 2：
 *
 * 输入：height = [1,1]
 * 输出：1
 *
 *
 * 提示：
 *
 * n == height.length
 * 2 <= n <= 105
 * 0 <= height[i] <= 104
 *
 * 来源：力扣（LeetCode）
 * 链接：<a href="https://leetcode.cn/problems/container-with-most-water">链接</a>
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * @author 何晓宇
 * 2022/6/1 10:01
 */
public class LC0011 {
	public static void main(String[] args) {

	}

	/**
	 * 思路：
	 * 1. result = 数组下标之差 * 二者之间较小的数
	 * 2. 如果数组长度为0或1，直接返回0
	 * 3. 使用两个指针从数组两端开始遍历，每次取对应数组中元素较小的指针进行移动
	 * 		数组中元素较小的位置，不可能再做为更大容量的边界了
	 * 		若移动的是较大的位置，则容积必然比之前小，因为底减少了1
	 * @param height	给定数组
	 * @return			能容纳最多的水量
	 */
	public int maxArea(int[] height) {
		if (height.length < 2) {
			return 0;
		}
		int contain = 0;
		int i = 0, j = height.length - 1;
		while (i < j) {
			if (height[i] > height[j]) {
				contain = Math.max(height[j] * (j - i), contain);
				j--;
			} else {
				contain = Math.max(height[i] * (j - i), contain);
				i++;
			}
		}
		return contain;
	}

	/*
	 * 执行用时：
	 * 3 ms
	 * , 在所有 Java 提交中击败了
	 * 93.17%
	 * 的用户
	 * 内存消耗：
	 * 51.3 MB
	 * , 在所有 Java 提交中击败了
	 * 64.64%
	 * 的用户
	 * 通过测试用例：
	 * 60 / 60
	 */
}
