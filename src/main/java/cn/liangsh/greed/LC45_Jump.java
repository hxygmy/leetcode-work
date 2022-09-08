package cn.liangsh.greed;

/**
 * @author Liangsh
 * @description 跳跃游戏II
 * @date 2022/8/10 10:07
 */
public class LC45_Jump {

    public int jump(int[] nums) {
        if (nums.length == 1) {
            return 0;
        }

        // 记录当前范围，下一步范围以及结果
        int current = 0;
        int next = 0;
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            // 下一步的最远范围
            next = Math.max(next, nums[i] + i);

            // 若当前等于最大范围,则走下一步
            if (current == i) {
                // 若当前不等于最终范围则继续
                if (current != nums.length - 1) {
                    // 当前为最远距离下标
                    result++;
                    current = next;
                    if (next >= nums.length) {
                        break;
                    }
                } else {
                    break;
                }
            }
        }

        return result;
    }
}
