package cn.liangsh.greed;

import java.util.Arrays;

/**
 * @author Liangsh
 * @description
 * @date 2022/7/27 9:19
 */
public class LC455_FindContentChildren {
    public static void main(String[] args) {
        int[] g = {1, 2, 3};
        int[] s = {};

        new LC455_FindContentChildren().findContentChildren(g, s);
    }

    public int findContentChildren(int[] g, int[] s) {
        // 排序
        Arrays.sort(g);
        Arrays.sort(s);
        int count = 0;
        int index = s.length - 1;
        // 使最大的饼干刚好满足胃口大的小孩
        for (int i = g.length - 1; i >= 0; i--) {
            if (index >= 0 && s[index] >= g[i]) {
                count++;
                index--;
            }
        }

        return count;
    }
}
