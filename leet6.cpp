class Solution {
public:
	string convert(string s, int numRows) {
		int nLenOfS = s.size();
		int nStep = numRows - 1;

		if (nStep == 0) {
			return s;
		}

		list<char>* lZig = new list<char>[numRows];

		for (int i = 0; i<nLenOfS; i++) {
			int j = i / nStep;
			int k = i % nStep;
			if (j % 2) {
				lZig[nStep - k].push_back(s[i]);
			}
			else {
				lZig[k].push_back(s[i]);
			}
		}

		string res = "";
		for (int i = 0; i<numRows; i++) {
			list<char>::iterator itr = lZig[i].begin();
			while (itr != lZig[i].end()) {
				res += (*itr);
				itr++;
			}
		}
		return res;
	}
};
