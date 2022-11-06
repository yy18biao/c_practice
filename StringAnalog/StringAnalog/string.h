#pragma once

#include<iostream>
#include <cassert>
using namespace std;

namespace myspace {
	class mystring {
	public:
		mystring(const char* str = "") {
			//如果传过来的是一个空串，那strlen就会是0
			//不过要考虑'\0'，所以开辟的空间要+1
			//构造完之后有效长度就得等于strlen的长度
			_size = strlen(str);
			_capacity = strlen(str);
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}

		mystring(const mystring& s) {
			_str = new char[s._capacity + 1];
			_capacity = s._capacity;
			_size = s._size;

			strcpy(_str, s._str);
		}

		mystring& operator=(const mystring& s) {
			//判断两个是否是同一个地址值
			if (this != &s) {
				//利用一个临时的变量先存储
				char* str = new char[s._capacity + 1];
				strcpy(str, s._str);

				//注意如果不先把之前的空间释放可能会浪费空间
				delete[] _str;
				//将临时的变量赋值
				_str = str;

				//这两个成员变量每一次都要记得随时更新
				_size = s._size;
				_capacity = s._capacity;
			}

			return *this;
		}

		~mystring() {
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		///////////////////////////////////////////////////////////

		//迭代器第一种方式，指针
		typedef char* iterator;
		//获取begin
		iterator begin() const {
			return _str;
		}
		//获取end
		iterator end() const {
			//尾元素就只需要加上有效元素个数就行了
			return _str + _size;
		}

		//////////////////////////////////////////////////////////////

		//c_str:返回C形式的字符串
		const char* c_str() const{
			return _str;
		}

		//返回长度
		size_t size() const {
			return _size;
		}

		//返回容量
		size_t capacity() const {
			//因为总容量是包括'\0'的所以要加1
			return _capacity + 1;
		}

		//判断是否为空
		bool empty() const {
			return _size == 0;
		}

		//[]实现可读可写 用引用返回
		char& operator[](size_t pos) {
			assert(pos < _size);

			return _str[pos];
		}

		char& operator[](size_t pos) const {
			assert(pos < _size);

			return _str[pos];
		}

		//实现扩容
		void reserve(size_t n) {
			//开辟新空间
			char* str = new char[n + 1];
			strcpy(str, _str);
			//释放原有空间
			delete[] _str;
			_str = str;

			//注意容量记得改变
			_capacity = n;
		}

		//实现push_back插入字符
		void push_buck(char ch) {
			//判断是否需要扩容
			if (_size == _capacity) {
				int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity * 2);
			}

			_str[_size++] = ch;
			//记住要补上'\0'
			_str[_size] = '\0';
		}

		//实现插入一个字符串
		void append(const char* s) {
			//判断是否需要扩容
			if (_size + strlen(s) > _capacity) {
				reserve(_capacity + strlen(s));
			}

			//可以选择一个字符的放
			/*while (*s != '\0') {
				_str[_size++] = *s;
				s++;
			}

			_str[_size] = '\0';*/

			//也可以选择库函数直接拷贝
			strcpy(_str + _size, s);
			_size += strlen(s);
		}

		//实现+=
		mystring& operator+=(char ch) {
			push_buck(ch);

			return *this;
		}

		mystring& operator+=(const char* str){
			append(str);

			return *this;
		}

		mystring& operator+=(const mystring& s) {
			append(s.c_str());

			return *this;
		}

		//实现清空内容
		void clear() {
			/*for (int i = 0; i < _size; i++) {
				_str[i] = '\0';
			}*/

			_str[0] = '\0';

			_size = 0;
		}

		//实现调整字符串大小
		void resize(size_t n, char c = '\0') {
			if (n < _size) {
				_str[n + 1] = '\0';
				_size = n;
			}

			else {
				if (_capacity < n) {
					reserve(n);
				}

				while (_size != n) {
					_str[_size++] = c;
				}
				_str[_size] = '\0';
			}

		}

		//-----实现交换容器的内容
		void swap(mystring& s) {
			//确保两个容器的容量都能装得下
			if(_size>s.size())
				s.reserve(_size);
			else
				reserve(s.size());

			mystring tmp = *this;
			*this = s;
			s = tmp;
		}

		bool operator<(const mystring& s) {
			if (strcmp(this->c_str(), s.c_str()) < 0)
				return true;
			else
				return false;
		}

		bool operator<=(const mystring& s) {
			if (strcmp(this->c_str(), s.c_str()) <= 0)
				return true;
			else
				return false;
		}

		bool operator>(const mystring& s) {
			if (strcmp(this->c_str(), s.c_str()) > 0)
				return true;
			else
				return false;
		}

		bool operator>=(const mystring& s) {
			if (strcmp(this->c_str(), s.c_str()) >= 0)
				return true;
			else
				return false;
		}

		bool operator==(const mystring& s) {
			if (strcmp(this->c_str(), s.c_str()) == 0)
				return true;
			else
				return false;
		}

		bool operator!=(const mystring& s) {
			if (strcmp(this->c_str(), s.c_str()) != 0)
				return true;
			else
				return false;
		}

		// 返回c在string中第一次出现的位置
		size_t find(char c, size_t pos = 0) const {
			assert(pos < _size);

			for (int i = pos; i < _size; i++) {
				if (_str[i] == c)
					return i;
			}

			return string::npos;
		}

		// 返回子串s在string中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const {
			assert(pos < _size);

			/*int i = strlen(s);
			mystring str = "";
			str.reserve(i);

			for (int j = 0; j < _size; j++) {
				for (int k = j; k < i + j; k++) {
					str.push_buck(_str[k]);
				}
				if (str == s)
					return j;
				str.clear();
			}*/

			const char* p = strstr(_str + pos, s);
			if (p != nullptr)
				return p - _str;

			return string::npos;
		}

		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		mystring& insert(size_t pos, char c) {
			assert(pos <= _size);

			if (_size >= _capacity) {
				int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			for (size_t i = _size; i > pos; i--) {
				_str[i] = _str[i - 1];
			}
			_str[pos] = c;
			_str[++_size] = '\0';

			return *this;
		}

		mystring& insert(size_t pos, const char* str) {
			assert(pos < _size);

			if (_size + strlen(str) > _capacity)
				reserve(_size + strlen(str));

			for (int i = _size; i > pos - 1; i--) {
				_str[i + strlen(str)] = _str[i];
			}

			strncpy(_str + pos, str, strlen(str));
			_size += strlen(str);

			return *this;
		}

		// 删除pos位置上的元素，并返回该元素的下一个位置
		mystring& erase(size_t pos, size_t len = string::npos) {
			assert(pos < _size);

			if (len > _size - pos || len == string::npos) {
				for (int i = pos; i < _size; i++)
					_str[i] = '\0';
				_size = pos;
			}

			else {
				for (int i = pos + len - 1; i < _size; i++) {
					_str[i - len] = _str[i];
				}

				_size -= len;
				_str[_size] = '\0';
			}
			
			return *this;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

	ostream& operator<<(ostream& out, const mystring& s) {
		for (int i = 0; i < s.size(); i++)
			out << s[i];

		return out;
	}

	istream& operator>>(istream& in, mystring& s) {
		s.clear();

		char butt[128] = { '\0' };
		size_t i = 0;
		char c = in.get();

		while (c != ' ' && c != '\n') {
			if (i == 127) {
				s += butt;
				i = 0;
			}

			butt[i++] = c;
			c = in.get();
		}

		if (i > 0) {
			butt[i] = '\0';
			s += butt;
		}

		return in;
	}

	//测试函数
	void Test1() {
		mystring s1 = "hello world";
		const char* c = s1.c_str();
		std::cout << c << std::endl;
		for (int i = 0; i < s1.size(); i++) {
			s1[i]++;
		}
		std::cout << c << std::endl;

		mystring::iterator it1 = s1.begin();
		while (it1 != s1.end()) {
			(*it1)--;
			it1++;
		}
		std::cout << c << std::endl;
		//范围for的底层就是迭代器，写好迭代器就可以用范围for了
		for (auto ch : s1) {
			std::cout << ch;
		}
		cout << endl;
	}

	void Test2() {
		mystring s1 = "hello world";
		s1.push_buck('!');
		s1.push_buck('!');
		s1.push_buck('!');
		const char* c = s1.c_str();
		cout << c << endl;
		s1.append("hjb");
		cout << c << endl;
		s1 += 'a';
		cout << c << endl;
		s1 += "bjh";
		cout << c << endl;
		/*s1.clear();
		cout << c << endl;*/
		s1.resize(25,'a');
		mystring s2 = "abc";
		s2.swap(s1);

		if (s1 != s2)
			cout << 1 << endl;
		else
			cout << 0 << endl;

		cout << s1.find('w') << endl;

		mystring s3 = "world";
		cout << s2.find(s3.c_str()) << endl;

		s1.insert(2, 'k');
		cout << s1.c_str() << endl;

		s2 = "hello world";
		s2.insert(5, "hjb");
		cout << s2.c_str() << endl;

		mystring s4 = "hello world";
		s4.erase(5, 3);
		cout << s4.c_str() << endl;
	}

	void Test3() {
		mystring s1 = "hello world";
		s1.insert(5, "sad");
		cout << s1 << endl;
		cin >> s1;
		cout << s1 << endl;
		cout << s1.size();
	}

	void bugTest() {
		mystring s1("hello world");
		mystring s2("!!!!");
		s1 += s2;
		s1.insert(0, 'a');
		cout << s1 << endl;

		cout << s1.find('h') << endl;
	}
}