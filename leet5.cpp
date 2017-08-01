#include<iostream>
#include <iomanip>
#include<string>
using namespace std;
class Solution {
public:

	string longestPalindrome(string s) {

		int sLen = s.size();
		if (sLen <= 1)return s;

		int i = 0, j = 0;
		int rMax = 0, lMax = 0;
		int r = 0, l = 0;

		while (i<sLen - 1) {
			j = i + 1;
			while (s[j] == s[j + 1]) {
				j++;
			}
			int iNext = j;
			for (; j <iNext + 2 && j < sLen; j++) {
				l = i;
				r = j;
				while (l >= 0 && r<sLen) {
					if (s[l] == s[r]) {
						if (l == 0 || r == sLen - 1)break;
						l--; r++;
					}
					else {
						l++; 
						if(r>iNext)r--;
						break;
					}
				}
				if ((r - l)>(rMax - lMax)) {
					lMax = l;
					rMax = r;
				}
			}
			i = iNext;
		}

		string subStr = s.substr(lMax, rMax - lMax + 1);
		return subStr;
	}
};
