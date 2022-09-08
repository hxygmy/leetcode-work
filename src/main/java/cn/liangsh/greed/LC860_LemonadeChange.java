package cn.liangsh.greed;

/**
 * @author Liangsh
 * @description 柠檬水找零
 * @date 2022/8/15 9:13
 */
public class LC860_LemonadeChange {

    public boolean lemonadeChange(int[] bills) {
        int five = 0;
        int ten = 0;

        for (int bill : bills) {
            // 5元直接收
            if (bill == 5) {
                five++;
            }

            // 10元用5找
            if (bill == 10) {
                if (five > 0) {
                    ten++;
                    five--;
                }else {
                    return false;
                }
            }

            // 20元做判断
            if (bill == 20) {
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }else if (five >= 3) {
                    five -= 3;
                }else{
                    return false;
                }
            }
        }

        return true;
    }
}
