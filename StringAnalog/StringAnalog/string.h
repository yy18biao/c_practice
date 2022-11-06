#pragma once

#include<iostream>
#include <cassert>
using namespace std;

namespace myspace {
	class mystring {
	public:
		mystring(const char* str = "") {
			//�������������һ���մ�����strlen�ͻ���0
			//����Ҫ����'\0'�����Կ��ٵĿռ�Ҫ+1
			//������֮����Ч���Ⱦ͵õ���strlen�ĳ���
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
			//�ж������Ƿ���ͬһ����ֵַ
			if (this != &s) {
				//����һ����ʱ�ı����ȴ洢
				char* str = new char[s._capacity + 1];
				strcpy(str, s._str);

				//ע��������Ȱ�֮ǰ�Ŀռ��ͷſ��ܻ��˷ѿռ�
				delete[] _str;
				//����ʱ�ı�����ֵ
				_str = str;

				//��������Ա����ÿһ�ζ�Ҫ�ǵ���ʱ����
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

		//��������һ�ַ�ʽ��ָ��
		typedef char* iterator;
		//��ȡbegin
		iterator begin() const {
			return _str;
		}
		//��ȡend
		iterator end() const {
			//βԪ�ؾ�ֻ��Ҫ������ЧԪ�ظ���������
			return _str + _size;
		}

		//////////////////////////////////////////////////////////////

		//c_str:����C��ʽ���ַ���
		const char* c_str() const{
			return _str;
		}

		//���س���
		size_t size() const {
			return _size;
		}

		//��������
		size_t capacity() const {
			//��Ϊ�������ǰ���'\0'������Ҫ��1
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

		char& operator[](size_t pos) const {
			assert(pos < _size);

			return _str[pos];
		}

		//ʵ������
		void reserve(size_t n) {
			//�����¿ռ�
			char* str = new char[n + 1];
			strcpy(str, _str);
			//�ͷ�ԭ�пռ�
			delete[] _str;
			_str = str;

			//ע�������ǵøı�
			_capacity = n;
		}

		//ʵ��push_back�����ַ�
		void push_buck(char ch) {
			//�ж��Ƿ���Ҫ����
			if (_size == _capacity) {
				int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity * 2);
			}

			_str[_size++] = ch;
			//��סҪ����'\0'
			_str[_size] = '\0';
		}

		//ʵ�ֲ���һ���ַ���
		void append(const char* s) {
			//�ж��Ƿ���Ҫ����
			if (_size + strlen(s) > _capacity) {
				reserve(_capacity + strlen(s));
			}

			//����ѡ��һ���ַ��ķ�
			/*while (*s != '\0') {
				_str[_size++] = *s;
				s++;
			}

			_str[_size] = '\0';*/

			//Ҳ����ѡ��⺯��ֱ�ӿ���
			strcpy(_str + _size, s);
			_size += strlen(s);
		}

		//ʵ��+=
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

		//ʵ���������
		void clear() {
			/*for (int i = 0; i < _size; i++) {
				_str[i] = '\0';
			}*/

			_str[0] = '\0';

			_size = 0;
		}

		//ʵ�ֵ����ַ�����С
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

		//-----ʵ�ֽ�������������
		void swap(mystring& s) {
			//ȷ��������������������װ����
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

		// ����c��string�е�һ�γ��ֵ�λ��
		size_t find(char c, size_t pos = 0) const {
			assert(pos < _size);

			for (int i = pos; i < _size; i++) {
				if (_str[i] == c)
					return i;
			}

			return string::npos;
		}

		// �����Ӵ�s��string�е�һ�γ��ֵ�λ��
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

		// ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��
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

		// ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
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