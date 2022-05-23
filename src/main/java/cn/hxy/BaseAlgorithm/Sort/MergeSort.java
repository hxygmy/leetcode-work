package cn.hxy.BaseAlgorithm.Sort;

import java.util.Arrays;

/**
 * 归并排序
 *
 * 经典排序算法之一
 *
 * 时间复杂度O(nlog(n))
 * 空间复杂度O(n)
 * 稳定算法
 *
 * @author 何晓宇
 * 2022/5/23 17:24
 */
public class MergeSort {
	public static void main(String[] args) {
		int[] a = {1,3,4,5,2,1,6,888,112,412,543};
		mergeSort(a, 0, a.length - 1);
		System.out.println(Arrays.toString(a));
	}

	/**
	 * 归并排序算法
	 *
	 * 1. 取数组下标中间，把待排数组分成两个区
	 * 2. 递归调用归并排序算法本身，把左右子数组进行归并排序
	 * 3. 当函数调用栈到极限时，不满足low < high 即递归结束
	 * 4. 归并
	 * 		4.1 归并本身是使数组基本有序，非严格有序
	 * 		4.2 当待排数组的长度足够短，即实现严格有序
	 *
	 * @param array 	待排数组
	 * @param low 		开始的位置
	 * @param high 		结束的位置
	 */
	public static void mergeSort(int[] array, int low, int high){
		if(low < high){
			int mid = (low + high) / 2;
			// 开始递归
			mergeSort(array, low, mid);
			mergeSort(array, mid + 1, high);
			merge(array, low, mid, high);
		}
	}

	/**
	 * 归并排序算法的核心方法
	 *
	 * 1. 缓存一个同样的数组b
	 * 2. 定义三个指针
	 * 		i、j 分别用于遍历数组b的两个分区，是指向数组b的指针；k用于遍历数组a
	 * 		i 指向 low
	 * 		j 指向 mid + 1，即第二个分区的首位元素
	 * 		k 指向 low，从小到大对数组a进行依次遍历
	 * 3. b[i] 和 b[j] 中较小的写入到 a[k]，并后移对应的指针
	 * 		此处临界点问题： 当b[i] = b[j]时，应优先写入b[i]，这样可以保证算法的稳定性
	 * 4. 若数组b中的其中一个分区遍历完了，另一个还没有遍历完，则把整下的元素直接插入到数组a剩下的位置
	 *
	 * @param a 		待排序数组
	 * @param low 		指向分区后第一个区的首位的指针
	 * @param mid 		指向分区后第一个区最后一位的指针
	 * @param high 		指向分区后第二个区最后一位的指针
	 */
	private static void merge(int[] a, int low, int mid, int high) {
		int[] b = a.clone();
		int i, j, k;

		for(i = low, j = mid +1, k = i; i <= mid && j <= high; k++){
			if(b[i] <= b[j]){
				a[k] = b[i++];
			} else {
				a[k] = b[j++];
			}
		}
		while(i <= mid){
			a[k++] = b[i++];
		}
		while(j <= high){
			a[k++] = b[j++];
		}
	}

}
