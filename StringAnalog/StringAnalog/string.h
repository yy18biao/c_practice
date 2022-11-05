#pragma once

#include<iostream>
#include <cassert>
#include<string>
using namespace std;

namespace myspace {
	class mystring {
	public:
		mystring(const char* str) {
			_size = strlen(str);
			_capacity = strlen(str);
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}

		///////////////////////////////////////////////////////////

		//��������һ�ַ�ʽ��ָ��
		typedef char* iterator;
		//��ȡbegin
		iterator begin() {
			return _str;
		}
		//��ȡend
		iterator end() {
			return _str + _size;
		}

		//////////////////////////////////////////////////////////////

		//c_str:���صȼ۵��ַ���
		const char* c_str() const{
			return _str;
		}

		//���س���
		size_t size() const {
			return _size;
		}

		//��������
		size_t capacity() const {
			return _capacity + 1;
		}

		//�ж��Ƿ�Ϊ��
		bool empty() const {
			return _size == 0;
		}

		//[]ʵ�ֿɶ���д �����÷���
		char& operator[](size_t pos) {
			assert(pos < _size);

			return _str[pos];
		}

		//ʵ������
		void reserve(size_t n) {
				char* str = new char[n + 1];
				strcpy(str, _str);
				delete[] _str;
				_str = str;

				_capacity = n;
		}

		//ʵ��push_back�����ַ�
		void push_buck(char ch) {
			if (_size == _capacity) {
				reserve(_capacity * 2);
			}

			_str[_size++] = ch;
			_str[_size] = '\0';
		}

		//ʵ�ֲ���һ���ַ���
		void append(const char* s) {
			if (_size + strlen(s) >= _capacity) {
				reserve(_capacity + strlen(s) + 1);
			}

			while (*s != '\0') {
				_str[_size++] = *s;
				s++;
			}

			_str[_size] = '\0';
		}

		//ʵ��+=
		mystring& operator+=(char ch) {
			push_buck(ch);

			return *this;
		}

		mystring& operator+=(const char* str)
		{
			append(str);

			return *this;
		}

		//ʵ���������
		void clear() {
			for (int i = 0; i < _size; i++) {
				_str[i] = '\0';
			}

			_size = 0;
		}

		//ʵ�ֵ����ַ�����С
		void resize(size_t n, char c = '\0') {
			if (n < _size) {
				_str[n + 1] = '\0';
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

		//-----ʵ�ֽ�������������
		void swap(mystring& s) {
			int i = strlen(s.c_str());

			s.reserve(i + _size);
			reserve(i + _size);

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

		// ����c��string�е�һ�γ��ֵ�λ��
		size_t find(char c, size_t pos = 0) const {
			assert(pos < _size);

			for (int i = pos; i < _size; i++) {
				if (_str[i] == c)
					return i;
			}
			return -1;
		}

		// �����Ӵ�s��string�е�һ�γ��ֵ�λ��
		size_t find(const char* s, size_t pos = 0) const {
			int i = strlen(s);
			mystring str = "";
			str.reserve(i);

			for (int j = 0; j < _size; j++) {
				for (int k = j; k < i + j; k++) {
					str.push_buck(_str[k]);
				}
				if (str == s)
					return j;
				str.clear();
			}

			return -1;
		}

		// ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��
		mystring& insert(size_t pos, char c) {
			assert(pos < _size);

			if (_size >= _capacity)
				reserve(_capacity * 2);

			for (int i = _size; i > pos; i--) {
				_str[i] = _str[i - 1];
			}
			_str[pos] = c;
			_str[++_size] = '\0';

			return *this;
		}

		mystring& insert(size_t pos, const char* str) {
			assert(pos < _size);

			if (_size + strlen(str) >= _capacity)
				reserve(_size + strlen(str));

			for (int i = _size - 1; i >= pos; i--) {
				_str[i + strlen(str)] = _str[i];
			}

			for (int i = 0; i < strlen(str); i++) {
				_str[pos++] = str[i];
			}

			_size += strlen(str);
			_str[_size] = '\0';

			return *this;
		}

		// ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
		mystring& erase(size_t pos, size_t len) {
			assert(pos < _size);

			if (len > _size - pos) {
				for (int i = pos; i < _size; i++)
					_str[i] = '\0';
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

	//���Ժ���
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
		//��Χfor�ĵײ���ǵ�������д�õ������Ϳ����÷�Χfor��
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
}