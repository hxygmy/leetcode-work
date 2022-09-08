package cn.liangsh.greed;

import java.util.LinkedList;
import java.util.List;

/**
 * @author Liangsh
 * @description 划分区间
 * @date 2022/8/29 9:16
 */
public class LC763_PartitionLabels {

    public List<Integer> partitionLabels(String s) {
        List<Integer> list = new LinkedList<>();
        // 记录26个字母位置
        int[] edge = new int[26];
        char[] chars = s.toCharArray();
        for (int i = 0; i < s.length(); i++) {
            // 记录每个字符最后的位置
            edge[chars[i] - 'a'] = i;
        }

        int left = 0;
        int right = -1;

        for (int i = 0; i < s.length(); i++) {
            right = Math.max(right, edge[chars[i] - 'a']);

            if (right == i) {
                list.add(i - left);
                left = i;
            }
        }

        return list;
    }
}
