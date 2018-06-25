/*157. Read N Characters Given Read4
The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is 
only 3 characters left in the file.
By using the read4 API, implement the function int read(char *buf, int n) that reads n characters 
from the file.

Example 1:
Input: buf = "abc", n = 4
Output: "abc"
Explanation: The actual number of characters read is 3, which is "abc".

Example 2:
Input: buf = "abcde", n = 5 
Output: "abcde"
*/

/*这道题给了我们一个Read4函数，每次可以从一个文件中最多读出4个字符，如果文件中的字符不足4个字符时，返回准确的
当前剩余的字符数。现在让我们实现一个最多能读取n个字符的函数。这题思路是我们每4个读一次，然后把读出的结果判断一下，
如果为0的话，说明此时的buf已经被读完，跳出循环，直接返回res和n之中的较小值。否则一直读入，直到读完n个字符，循环
结束，最后再返回res和n之中的较小值*/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int res = 0;
        for (int i = 0; i <= n / 4; ++i) {
            int len = read4(buf + res);
            if (len == 0) break;
            res += len;
        }
        return min(res, n);
    }
};