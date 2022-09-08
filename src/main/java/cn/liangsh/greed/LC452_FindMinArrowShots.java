package cn.liangsh.greed;

import java.util.Arrays;
import java.util.Comparator;

/**
 * @author Liangsh
 * @description 气球最小右边界
 * @date 2022/8/23 8:57
 */
public class LC452_FindMinArrowShots {

    public int findMinArrowShots(int[][] points) {
        if (points.length <= 0) {
            return 0;
        }

        Arrays.sort(points, Comparator.comparingInt(a -> a[0]));

        // 最小数为1
        int result = 1;

        for (int i = 1; i < points.length; i++) {
            if (points[i][0] > points[i - 1][1]) {
                // 前一个气球的右边界小于后一个的左边界
                result++;
            }else {
                // 更新最小右边界
                points[i][1] = Math.min(points[i][1], points[i - 1][1]);
            }
        }

        return result;
    }
}
