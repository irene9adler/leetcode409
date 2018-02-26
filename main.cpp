/*Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.*/

/*思路：
当字符串中字符出现次数为偶数时，必然可以加入最长回文子串
当字符串中字符出现次数为奇数时，分情况讨论：
如果出现次数为大于1的奇数n，则可以加入n-1个对应字符到最长回文子串
最终的最长回文子串，最中间还可以加入一个单一字符*/

class Solution {
public:
    int longestPalindrome(string s) {
        vector <int> vec(52,0);
        int i;
        int flag = 0;//判断有没有奇数长的串
        for(i = 0;i < s.size();i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z')
              vec[s[i] - 'a']++;
            else if(s[i] >= 'A' && s[i] <= 'Z')

              vec[s[i] - 'A' + 26]++;

        }

        int res = 0;
        int max_odd = 0;
        for(i = 0;i < 52;i++)
        {
            if(vec[i] % 2 == 0)
               res += vec[i];
             else
             {
                 flag = 1;
                 //if(vec[i] > max_odd)
                 res += vec[i] - 1;
             }
        }
        //res += max_odd;
        if(flag == 1) res += 1;
        return res;
    }
};
