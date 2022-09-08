package cn.liangsh.greed;

/**
 * @author Liangsh
 * @description 最大子数组和
 * @date 2022/8/9 9:02
 */
public class LC53_MaxSubArray {

    public int maxSubArray(int[] nums) {

        int result = Integer.MIN_VALUE;
        int count = 0;

        for (int i = 0; i < nums.length; i++) {
            count += nums[i];

            if (count > result) {
                result = count;
            }
            // 若累计和为负数，立刻放弃！
            if (count < 0) {
                count = 0;
            }

        }

        return result;
    }
}
