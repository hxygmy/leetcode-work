package cn.liangsh.greed;

/**
 * @author Liangsh
 * @description 单调递增数字
 * @date 2022/9/1 9:05
 */
public class LC738_MonotoneIncreasingDigits {

    public static void main(String[] args) {

        System.out.println(new LC738_MonotoneIncreasingDigits().monotoneIncreasingDigits(10));
    }

    public int monotoneIncreasingDigits(int n) {
        // 转为字符串后做位数处理
        String[] nums = (n + "").split("");

        // 记录需要变9的索引
        int index = nums.length;
        for (int i = nums.length - 1; i > 0; i--) {
            // 比较前一位是否大于后一位，若大于后一位，则将其 -1 并将后一位置为9
            if (Integer.parseInt(nums[i - 1]) > Integer.parseInt(nums[i])) {
                index = i;
                nums[i - 1] = Integer.parseInt(nums[i - 1]) - 1 + "";
            }
        }

        for (int i = index; i < nums.length; i++) {
            nums[i] = 9 + "";
        }

        return Integer.parseInt(String.join("", nums));
    }
}
