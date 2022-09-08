package cn.liangsh.greed;

/**
 * @author Liangsh
 * @description 跳跃游戏
 * @date 2022/8/10 8:56
 */
public class LC55_CanJump {

    public boolean canJump(int[] nums) {
        if (nums.length == 1) {
            return true;
        }

        int cover = 0;

        // cover覆盖范围
        for (int i = 0; i <= cover; i++) {
            cover = Math.max(cover, nums[i] + i);
            if (cover >= nums.length - 1) {
                return true;
            }
        }

        return false;
    }
}
