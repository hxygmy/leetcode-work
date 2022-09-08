package cn.liangsh.greed;

import java.util.Arrays;
import java.util.Comparator;

/**
 * @author Liangsh
 * @description 无重叠区间
 * @date 2022/8/23 9:13
 */
public class LC435_EraseOverLapIntervals {

    public static void main(String[] args) {
        int[][] intervals = {{1,2}, {2,3}, {3,4}, {1,3}};

        System.out.println(new LC435_EraseOverLapIntervals().eraseOverlapIntervals(intervals));
    }

    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals.length == 0) {
            return 0;
        }

        Arrays.sort(intervals, Comparator.comparingInt(a -> a[1]));

        int count = 1;
        // 记录右区间分割
        int edge = intervals[0][1];
        for (int i = 1; i < intervals.length; i++) {
            // 右区间边界小于左边界，无重叠
            if (edge <= intervals[i][0]) {
                count++;
                edge = intervals[i][1];
            }
        }

        return intervals.length - count;
    }
}
