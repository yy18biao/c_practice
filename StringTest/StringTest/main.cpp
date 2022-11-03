#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void Test1() {
	string s1("hello");
	cout << s1 << endl;

	//正向迭代器遍历
	string::iterator sit = s1.begin();
	//auto sit = s1.begin();
	while (sit != s1.end()) {
		cout << *sit;
		sit++;
	}
	cout << endl;

	//反向迭代器遍历
	string::reverse_iterator it = s1.rbegin();
	//auto it = s1.rbegin();
	while (it != s1.rend()) {
		cout << *it;
		it++;
	}
	cout << endl;
}

void Test2() {
	string s("hello world");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	s.clear();
	cout << s << endl;
	cout << s.capacity() << endl;
	s = "hello world";
	cout << s.empty() << endl;

	string s1;
	s1.reserve(10);
	cout << s1.capacity() << endl;

	s1.push_back('a');
	cout << s1 << endl;
}

void Test3() {
	string s("hello world");
	s.resize(10);
	cout << s << endl;
	s.resize(12, 'd');
	cout << s << endl;
	s.resize(20, 'a');
	cout << s << endl;
}

void Test4() {
	string s("hello world");
	s.append("xxxx");
	cout << s << endl;

	string s2 = ("!!!!!");
	s.append(s2);
	cout << s << endl;

}

class Solution {
public:
	string reverseStr(string s, int k) {
		int n = s.size();
		for (int i = 0; i < n; i += 2 * k) {
			reverse(s.begin() + i, s.begin() + min(i + k, n));
		}
		return s;
	}

	int StrToInt(string str) {
		bool flag = false;
		int sum = 0;
		if (str[0] == '-')
			flag = true;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' ')
				continue;
			if ((str[i] == '+' || str[i] == '-'))
				i++;
			if (isdigit(str[i]) == 0)
				return 0;
			sum = sum * 10 + (str[i] - '0');
		}
		if (flag)
			sum *= -1;
		return sum;
	}

	string addStrings(string num1, string num2) {
		int c = 0;
		int s1 = num1.size() - 1;
		int s2 = num2.size() - 1;
		string str = "";
		while (s1 >= 0 || s2 >= 0 || c != 0) {
			int i1 = s1 >= 0 ? num1[s1] - '0' : 0;
			int i2 = s2 >= 0 ? num2[s2] - '0' : 0;
			int count = i1 + i2;
			if (c == 1)
				count++;
			if (count > 9)
				c = 1;
			else
				c = 0;
			count %= 10;
			char sc = count + '0';
			str.push_back(sc);
			s1--;
			s2--;
		}

		std::reverse(str.begin(), str.end());

		return str;
	}

	string reverseWords(string s) {
		int i = 0;
		while (i < s.size()) {
			int left = i;
			while (i < s.size() && s[i] != ' ')
				i++;
			int right = i - 1;
			while (left <= right) {
				swap(s[left++], s[right--]);
			}
			while (i < s.size() && s[i] == ' ')
				i++;
		}
		return s;
	}

};

//void Test5() {
//
//
//}
//
//int main() {
//	//Test1();
//	//Test2();
//	//Test3();
//	//Test4();
//
//	/*string s("abcdefg");
//	Solution s1;
//	string str = s1.reverseStr(s, 2);
//	cout << str << endl;*/
//
//	/*string s("+1234567");
//	Solution s1;
//	int str = s1.StrToInt(s);*/
//
//	/*string s1("1");
//	string s2("9");
//	Solution s;
//	string str = s.addStrings(s1, s2);*/
//
//	/*string s("hello world ok");
//	Solution s1;
//	s = s1.reverseWords(s);*/
//
//
//
//	return 0;
//}


/////////////////////////////////////////////////////////////////

//string的模拟实现
