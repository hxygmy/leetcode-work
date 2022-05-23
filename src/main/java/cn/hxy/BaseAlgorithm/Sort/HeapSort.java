package cn.hxy.BaseAlgorithm.Sort;


import java.util.Arrays;

/**
 * 堆排序
 *
 * 经典排序算法之一
 * 是一个乍一看很麻烦，看懂后思路相当简单明了的算法
 *
 * 什么是堆：数组以层序遍历的方式构建成一棵完全二叉树，即为堆
 *
 * 数组转堆数据结构如下：数字为数组下标
 * 					[0]
 *			[1]				[2]
 *		[3]		[4]		[5]		[6]
 *	[7]		[8]	   ......
 *
 *
 * 时间复杂度O(nlog(n))
 * 空间复杂度O(1)
 * 不稳定算法
 *
 * @author 何晓宇
 * 2022/5/23 18:05
 */
public class HeapSort {

	public static void main(String[] args) {
		int[] a = {1,3,4,5,2,95,6,888,112,412,543};
		heapSort(a, a.length - 1);
		System.out.println(Arrays.toString(a));
	}

	/**
	 * 堆排序算法
	 *
	 * 1. 先把数组建立成大根堆
	 * 		大根堆：根节点是整个数组中的最大值
	 *
	 * 2. 把根节点与最后一个叶子节点交换位置，即可把最大值放在最后
	 * 3. 去掉最后一个叶子节点，对之前的数组递归地进行堆排序即可完成排序
	 *
	 * @param array 	待排数组
	 * @param n			数组下标最大值
	 */
	public static void heapSort(int[] array, int n) {
		// 建立大根堆
		buildMaxHeap(array, n);

		for (int i = n; i > 0; i--) {
			// 交换
			int tmp = array[0];
			array[0] = array[i];
			array[i] = tmp;

			headAdjust(array, 0, i - 1);

		}
	}

	/**
	 * 建立大根堆
	 * 指把任意数组先建立成大根堆，以方便后续操作
	 *
	 * 1. 取数组中最后一个父节点，即 (int)Math.ceil(n / 2d) - 1，画图可以轻易验证
	 * 2. 该元素之前的全是父节点，故向前遍历所有父节点，调整子树，即可使堆成为大根堆
	 *
	 * @param array		待排数组
	 * @param n			数组下标最大值
	 */
	private static void buildMaxHeap(int[] array, int n) {
		for(int i = (int)Math.ceil(n / 2d) - 1; i >= 0; i--){
			headAdjust(array, i, n);
		}
	}

	/**
	 * 以i为根，对子树进行调整，使array[i]为数组中的最大值
	 *
	 * ！！！[i]必须是父节点，不可以是叶子节点
	 *
	 * 1. 首先看左子树，若左孩子的值小于右孩子，则直接看右子树
	 * 2. 如果孩子节点大于父节点，就把孩子节点的值赋给父节点，再以该孩子节点为父节点，对该子树进行调整
	 *
	 * @param array		待排数组
	 * @param i			根的数组下标
	 * @param n			数组长度
	 */
	private static void headAdjust(int[] array, int i, int n) {
		int guard = array[i];
		//此处打印数组可以方便查看调用过程 System.out.println(Arrays.toString(array));
		for (int j = 2 * i + 1; j <= n; j = j * 2 + 1) {
			if (j < n && array[j] < array[j + 1]) {
				j++;
			}
			if (guard < array[j]) {
				array[i] = array[j];
				i = j;
			} else {
				break;
			}
		}
		array[i] = guard;
		//此处打印数组可以方便查看调用过程 System.out.println(Arrays.toString(array));
	}

}
