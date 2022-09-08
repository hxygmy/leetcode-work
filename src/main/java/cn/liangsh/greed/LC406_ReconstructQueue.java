package cn.liangsh.greed;

import java.util.Arrays;
import java.util.LinkedList;

/**
 * @author Liangsh
 * @description 根据身高重建队列
 * @date 2022/8/22 9:04
 */
public class LC406_ReconstructQueue {

    public int[][] reconstructQueue(int[][] people) {
        // 根据身高最高的人的ki来选择插入
        Arrays.sort(people, (a,b) -> {
            // 根据hi从大到小排序，相等则ki较小的排在前面
            if (a[0] == b[0]) return a[1] - b[1];
            return b[0] - a[0];
        });

        LinkedList<int[]> queue = new LinkedList<>();

        for (int[] person : people) {
            // 根据排序后的ki选择插入位置
            queue.add(person[1], person);
        }

        return queue.toArray(new int[people.length][]);
    }
}
