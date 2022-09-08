package cn.liangsh.greed;

import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;

/**
 * @author Liangsh
 * @description 合并区间
 * @date 2022/8/31 9:18
 */
public class LC56_Merge {

    public int[][] merge(int[][] intervals) {
        List<int[]> res = new LinkedList<>();
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));

        int start = intervals[0][0];
        for (int i = 1; i < intervals.length; i++) {

            // 当前的左区间大于前一位的右区间，不能合并
            if (intervals[i][0] > intervals[i - 1][1]) {
                res.add(new int[]{start, intervals[i - 1][1]});
                start = intervals[i][0];
            } else {
                // 更新当前右区间
                intervals[i][1] = Math.max(intervals[i - 1][1], intervals[i][i]);
            }
        }
        // 若最后一个区间是独立的，添加最后一个区间
        res.add(new int[]{start, intervals[intervals.length - 1][1]});

        return res.toArray(new int[res.size()][]);
    }
}
