package cn.hxy.medium;

import org.junit.Test;

import java.util.Arrays;

/**
 * 59. 螺旋矩阵 II
 *
 * 给你一个正整数n ，生成一个包含 1 到n2所有元素，且元素按顺时针顺序螺旋排列的n x n 正方形矩阵 matrix 。
 *
 * 
 *
 * 示例 1：
 *
 *
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 * 示例 2：
 *
 * 输入：n = 1
 * 输出：[[1]]
 * 
 *
 * 提示：
 *
 * 1 <= n <= 20
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/spiral-matrix-ii
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 * @author Applewald
 * 2022/6/10 15:47
 */
public class LC0059 {
	public static void main(String[] args) {

	}

	/**
	 * 纯代码题
	 * @param n		生成1-n^2的所有元素
	 * @return		返回二维数组
	 */
	public int[][] generateMatrix(int n) {
		int[][] res = new int[n][n];
		int target = 1;
		int side = n / 2;
		for (int i = 0; i <= side; i++) {
			target = setAngle(i, n, res, target);
			n = n - 2;
		}
		return res;
	}

	public int setAngle(int s, int n, int[][] res, int target){
		if (n == 1) {
			res[s][s] = target;
		}

		for (int i = s; i < n + s; i++) {
			res[s][i] = target;
			target++;
		}
		for (int i = s + 1; i < n + s; i++) {
			res[i][s + n - 1] = target;
			target++;
		}
		for (int i = n + s - 2; i >= s; i--) {
			res[n + s - 1][i] = target;
			target++;
		}
		for (int i = n + s - 2; i > s; i--) {
			res[i][s] = target;
			target++;
		}
		return target;
	}

	@Test
	public void test(){
		System.out.println(Arrays.deepToString(generateMatrix(3)));
	}

}
