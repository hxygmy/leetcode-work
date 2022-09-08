package cn.liangsh.greed;

/**
 * @author Liangsh
 * @description 摆动序列
 * @date 2022/8/9 8:46
 */
public class LC376_wiggleMaxLength {

    public int wiggleMaxLength(int[] nums) {
        if (nums.length <= 1) {
            return nums.length;
        }

        // 当前差值和前一对数的差值
        int curDiff = 0;
        int preDiff = 0;

        // 波峰个数，默认计算最右边为一个波峰
        int result = 1;
        for (int i = 1; i < nums.length; i++) {
            curDiff = nums[i] - nums[i - 1];

            if ((curDiff < 0 && preDiff >= 0) || (curDiff > 0 && preDiff <= 0)) {
                result++;
                preDiff = curDiff;
            }
        }

        return result;
    }
}
