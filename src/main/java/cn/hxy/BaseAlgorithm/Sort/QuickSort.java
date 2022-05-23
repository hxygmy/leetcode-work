package cn.hxy.BaseAlgorithm.Sort;

import java.util.Arrays;

/**
 * 快速排序Java版
 *
 * 神迹算法之一，个人最喜欢的排序算法
 *
 * 时间复杂度O(nlog(n))
 * 空间复杂度O(log(n))
 * 非稳定算法
 *
 * 进阶：通过对快速排序时间复杂度进行分析，快速排序将存在改进方案
 * 		1. 主要思路为得到尽可能高效的递归二叉树
 * 			此思路为改进枢纽元素的选取方案，是一个数学上的概率问题
 * 		2. 改为非递归
 * 		3. 当数组过小时采用别的方案
 *
 * @author 何晓宇
 * 2022/5/23 13:17
 */
public class QuickSort {

	public static void main(String[] args) {
		int[] a = {1,3,4,5,2,1,6,888,112,412,543};
		quickSort(a, 0, a.length - 1);
		System.out.println(Arrays.toString(a));
	}

	/**
	 * 快速排序算法
	 * 1. 确定一个元素的位置，获取其数组下标
	 * 2. 对左右子数组分别进行快速排序，当子数组大小为0时即排序完成
	 *
	 * 当递归树为完全二叉树时，时间复杂度最小
	 *
	 * @param array 待排数组
	 * @param low 低位指针
	 * @param high 高位指针
	 */
	public static void quickSort(int[] array, int low, int high) {
		if (low < high) {
			// 对元素进行划分，左边小于枢纽元素，右边大于枢纽元素，返回枢纽元素所在数组下标
			int pos = partition(array, low, high);
			// 子数组递归调用
			quickSort(array, low, pos - 1);
			quickSort(array, pos + 1, high);
		}
	}

	/**
	 * 目的：把给定数组中的其中一个元素放在正确的位置，并返回该元素的数组下标
	 *
	 * 该方法为快速排序的核心
	 *
	 * 1. 找到一个枢纽元素，随便找就可以，这里取第一个元素
	 * 2. 以high为指针向前遍历
	 * 		2.1 当指向的元素大于等于枢纽元素时，不做任何操作，继续遍历
	 * 		2.2 当指向的元素小于枢纽元素时，直接赋值给low指向的元素
	 * 			此时high和low都指向一个小于枢纽元素的元素
	 * 3. 以low为指针向后遍历
	 * 		3.1 当指向的元素小于等于枢纽元素时，不做任何操作，继续遍历
	 * 		3.2 当指向的元素大于枢纽元素时，直接赋值给high指向的元素
	 * 			此时high和low都指向一个大于枢纽元素的元素
	 * 4. 重复步骤2和3，直到low和high指向同一位置，即low == high，该位置即枢纽元素应该在的位置
	 *
	 *
	 * 思考：关于枢纽元素如何选取的问题
	 * 		在严蔚敏老师的算法中，使用了以第一个元素为枢纽元素
	 * 		实际上枢纽元素可以任意选取，对时间复杂度并非没有影响
	 * 		O(nlog(n))的时间复杂度为平均时间复杂度
	 *
	 *
	 * @param array 待排序的数组
	 * @param low 指向低位的指针
	 * @param high 指向高位的指针
	 * @return 返回枢纽元素所在位置的数组下标
	 */
	public static int partition(int[] array, int low, int high) {
		// 取第一个元素作为枢纽元素
		int pivot = array[low];
		while (low < high) {
			while (low < high && array[high] >= pivot) {
				high--;
			}
			array[low] = array[high];
			while (low < high && array[low] <= pivot) {
				low++;
			}
			array[high] = array[low];
		}
		array[low] = pivot;
		return low;
	}

}
