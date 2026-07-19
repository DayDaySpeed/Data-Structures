#include "CurrentDemo.h"
#if DEMO == KMP

#include <iostream>
#include <vector>
#include <string>


using namespace std;

//求next数组
vector<int> getNext(const string& pattern) {
	int m = pattern.length();
	vector<int> next(m, 0);
	int j = 0;
	for (int i = 1; i < m; ++i) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = next[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			++j;
		}
		next[i] = j;
	}
	return next;
}


//KMP算法实现
int kmp(const string& text, const string& pattern) {
	int n = text.length();
	int m = pattern.length();
	vector<int> next = getNext(pattern);
	int j = 0;
	for (int i = 0; i < n; ++i) {
		while (j > 0 && text[i] != pattern[j]) {
			j = next[j - 1];
		}
		if (text[i] == pattern[j]) {
			++j;
		}
		if (j == m) {
			return i - m + 1; //匹配成功，返回匹配位置
		}
	}
	return -1; //匹配失败
}


int main() {
	string text = "ababcabcabababd";
	string pattern = "ababd";
	int index = kmp(text, pattern);
	if (index != -1) {
		cout << "Pattern found at index: " << index << endl;
	}
	else {
		cout << "Pattern not found" << endl;
	}
	return 0;

}













#endif