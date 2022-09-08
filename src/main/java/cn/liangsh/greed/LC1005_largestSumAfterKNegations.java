package cn.liangsh.greed;


import java.util.stream.IntStream;

/**
 * @author Liangsh
 * @description K次取反后最大化的数组和
 * @date 2022/8/12 8:56
 */
public class LC1005_largestSumAfterKNegations {

    public int largestSumAfterKNegations(int[] nums, int k) {
        // 根据绝对值大小从大到小对数组排序
        int[] sort = IntStream.of(nums)
                .boxed()
                // 从大到小排序
                .sorted(((o1, o2) -> Math.abs(o2) - Math.abs(o1)))
                .mapToInt(Integer::intValue)
                .toArray();

        for (int i = 0; i < sort.length; i++) {
            // 遍历数组遇到负数则将其取反
            if (k > 0 && sort[i] < 0) {
                sort[i] = sort[i] * -1;
                k--;
            }
        }

        if (k % 2 == 1) {
            // 剩余k次连续反转最小的数
            sort[sort.length - 1] *= -1;
        }

        int result = 0;
        for (int i : sort) {
            result += i;
        }

        return result;
    }
}
