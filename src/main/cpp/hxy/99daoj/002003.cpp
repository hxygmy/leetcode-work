/*
 * Created by hexiaoyu 
 * on 2023/3/24 21:56
 * FJ的字符串
 * Description
 *
 * FJ在沙盘上写了这样一些字符串：　　A1 = “A”　　A2 = “ABA”　　A3 = “ABACABA”　　A4 = “ABACABADABACABA”　　… …　　你能找出其中的规律并写所有的数列AN吗？
 *
 *
 * Input
 * 仅有一个数：N ≤ 26。
 *
 *
 * Output
 * 请输出相应的字符串AN，以一个换行符结束。输出中不得含有多余的空格或换行、回车符。
 *
 *
 * Sample Input 1
 *
 * 3
 * Sample Output 1
 *
 * ABACABA
 */
#include "iostream"
#include "string"

using namespace std;

int main(){
    int n;
    cin >> n;
    string traversal(int n);
    cout << traversal(n) << endl;
    return 0;
}

// 1. 参数返回
string traversal(int n) {
    // 2. 出口
    if (n == 0) return "";
    if (n == 1) return "A";

    // 3. 单层逻辑
    string pre = traversal(n - 1);
    string tmp = pre;
    pre.push_back('A' + n - 1);
    pre.append(tmp);
    return pre;
}