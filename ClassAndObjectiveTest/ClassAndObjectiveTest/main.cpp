#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

// class A
// {
// public:
// 	A()
// 	{
// 		_a = 0;
// 		cout << "A()" << endl;
// 	}
// private:
// 	int _a;
// };

// class Date
// {
// public:
// 	// 1.无参构造函数
// 	Date()
// 	{
// 		_year = 2022;
// 		_month = 9;
// 		_day = 22;
// 	}
// 	// 2.带参构造函数
// 	Date(int year, int month, int day)
// 	{
// 		_year = year;
// 		_month = month;
// 		_day = day;
// 	}

// 	void print()
// 	{
// 		cout << _year << "-" << _month << "-" << _day << endl;
// 	}

// private:
// 	int _year;
// 	int _month;
// 	int _day;
// 	A _a;
// };

// int main()
// {
// 	Date d1; // 调用无参构造函数
// 	Date d2(2022, 9, 22); // 调用带参的构造函数
// 	// 注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
// 	// 以下代码的函数：声明了d3函数，该函数无参，返回一个日期类型的对象
// 	//Date d3();

// 	d1.print();
// 	d2.print();

// 	//Stack st;
// 	//st.Push(1);
// 	//cout << st.Top() << endl;

// 	return 0;
// }


typedef struct List
{
	struct List* next;
	int val;
}SL;

//SL* Buysl(int n, int m)
//{
//	SL* head = (SL*)malloc(sizeof(SL));
//	if (head == NULL)
//		return NULL;
//	head->next = NULL;
//	head->val = 1;
//	SL* tail = head;
//	for (int i = 2; i <= n; i++)
//	{
//		SL* node = (SL*)malloc(sizeof(SL));
//		if (node == NULL)
//			return NULL;
//		node->val = i;
//		node->next = NULL;
//		tail->next = node;
//		tail = node;
//	}
//	tail->next = head;
//	return head;
//}
//
//int ysf(SL* head, int n, int m)
//{
//	SL* cur = head;
//	SL* tail = head;
//	while (cur->next != cur)
//	{
//		int k = m;
//		while (k--)
//		{
//			tail = tail->next;
//		}
//		SL* p = cur->next;
//		cur->next = tail;
//		free(p);
//		p = NULL;
//		cur = tail;
//	}
//	return cur->val;
//}
//
//int main()
//{
//	int n, m;
//	scanf("%d%d", &n, &m);
//	SL* head = Buysl(n, m);
//	int ret = ysf(head, n, m);
//	printf("%d\n", ret);
//	return 0;
// }


// SL* Buysl(int n)
// {
// 	SL* head = (SL*)malloc(sizeof(SL));
// 	if (head == NULL)
// 		return NULL;
// 	head->next = NULL;
// 	head->val = 1;
// 	SL* tail = head;
// 	for (int i = 2; i <= n; i++)
// 	{
// 		SL* node = (SL*)malloc(sizeof(SL));
// 		if (node == NULL)
// 			return NULL;
// 		node->val = i;
// 		node->next = NULL;
// 		tail->next = node;
// 		tail = node;
// 	}
// 	return head;
// }

// int countlist(SL* head)
// {
// 	int count = 0;
// 	SL* cur = head;
// 	while (cur)
// 	{
// 		cur = cur->next;
// 		count++;
// 	}
// 	return count;
// }

// SL* removeNthFromEnd(SL* head, int n) {
// 	SL* cur = (SL*)malloc(sizeof(SL));
// 	cur->val = 0;
// 	cur->next = head;
// 	int count = countlist(head);
// 	if (count < n)
// 		return NULL;
// 	SL* p = cur;
// 	for (int i = 0; i < count - n; i++)
// 		p = p->next;
// 	p->next = p->next->next;

// 	SL* q = cur->next;

// 	return q;
// }
// int main()
// {
// 	int n, m;
// 	scanf("%d%d", &n, &m);
// 	SL* head = Buysl(n);
// 	SL* newnode = removeNthFromEnd(head, m);
// 	return 0;
// }


//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (_a == nullptr)
//			return;
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	//拷贝构造函数
//	Stack(const Stack& st)
//	{
//		_a = (int*)malloc(sizeof(int) * st._capacity);
//		if (_a == nullptr)
//			return;
//		_capacity = st._capacity;
//		_size = st._size;
//
//		for (int i = 0; i < st._size; i++)
//			_a[i] = st._a[i];
//
//	}
//
//	void Push(int data)
//	{
//		_a[_size++] = data;
//	}
//
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_capacity = 0;
//		_size = 0;
//	}
//	
//
//	private:
//		int* _a;
//		int _size;
//		int _capacity;
//	};
//
//int main()
//{
//	Stack s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	Stack s2(s1);
//
//	return 0;
//}
//


// class Date
// {
// public:
// 	Date(int year = 2022, int month = 8, int day = 19)
// 	{
// 		_year = year;
// 		_month = month;
// 		_day = day;
// 	}

// 	int GetMonthDay(int year, int month)
// 	{
// 		int monthday[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
// 		int day = monthday[month];
// 		if (month = 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
// 			return day + 1;
// 		else
// 			return day;
// 	}

// 	Date(const Date& d)
// 	{
// 		_year = d._year;
// 		_month = d._month;
// 		_day = d._day;
// 	}

// 	void print()
// 	{
// 		cout << _year << "-" << _month << "-" << _day << endl;
// 	}

// 	Date& operator+=(int day)
// 	{
// 		_day += day;
// 		while (_day > GetMonthDay(_year, _month))
// 		{
// 			_day -= GetMonthDay(_year, _month);
// 			_month++;
// 		}
// 		if (_month > 12)
// 		{
// 			_year++;
// 			_month -= 12;
// 		}

// 		return *this;
// 	}

// 	//+-不会改变其原来的值，所以使用传值返回
// 	Date operator+(int day)
// 	{
// 		Date tmp;
// 		tmp += day;

// 		return tmp;
// 	}

// 	Date& operator-=(int day)
// 	{
// 		_day -= day;
// 		while (_day <= 0)
// 		{
// 			if (_day < 0 && _month == 1)
// 			{
// 				_year--;
// 				_month = 12;
// 			}
// 			else
// 				_month--;
// 			_day += GetMonthDay(_year, _month);
// 		}
// 		return *this;
// 	}

// 	Date operator-(int day)
// 	{
// 		Date tmp;
// 		tmp -= day;

// 		return tmp;
// 	}

// 	bool operator==(const Date& d)
// 	{
// 		return (_year == d._year) && (_month == d._month) && (_day == d._day);
// 	}

// 	bool operator>(const Date& d)
// 	{
// 		if (_year > d._year)
// 			return true;
// 		else if (_year == d._year && _month > d._month)
// 			return true;
// 		else if (_year == d._year && _month == d._month && _day > d._day)
// 			return true;
// 		else
// 			return false;
// 	}

// 	bool operator>=(const Date& d)
// 	{
// 		return (*this == d) || (*this > d);
// 	}

// 	bool operator < (const Date& d)
// 	{
// 		if (_year < d._year)
// 			return true;
// 		else if (_year == d._year && _month < d._month)
// 			return true;
// 		else if (_year == d._year && _month == d._month && _day < d._day)
// 			return true;
// 		else
// 			return false;
// 	}

// 	bool operator<=(const Date& d)
// 	{
// 		return (*this == d) || (*this < d);
// 	}

// 	bool operator != (const Date& d)
// 	{
// 		if (*this == d)
// 			return false;
// 		else
// 			return true;
// 	}

// 	~Date()
// 	{
// 		_year = _month = _day = 0;
// 	}

// private:
// 	int _year; // 年
// 	int _month; // 月
// 	int _day; // 日
// };

// int main()
// {
// 	Date d1(2022, 9, 22);
// 	Date d2;
// 	Date d3(d1);
// 	d1.print();
// 	d2.print();
// 	cout << "是否相等：" << (d1 == d2) << endl;
// 	cout << "d1是否大于d2：" << (d1 > d2) << endl;
// 	cout << "d1是否大于等于d2：" << (d1 >= d2) << endl;
// 	cout << "d1是否小于d2：" << (d1 < d2) << endl;
// 	cout << "d1是否小于等于d2：" << (d1 <= d2) << endl;
// 	cout << "d1是否不等于d2：" << (d1 != d2) << endl;
// 	d1 -= 10;
// 	d1.print();
// 	d1 -= 12;
// 	d1.print();
// 	d1 += 10;
// 	d1.print();

// 	return 0;
// }



// typedef int QueueDate;
// class Queue {
// public:
// 	Queue(QueueDate capacity =4)
// 	{
// 		_a = (QueueDate*)malloc(sizeof(QueueDate) * capacity);
// 		if (_a == nullptr)
// 		{
// 			perror("malloc fail");
// 			return;
// 		}
// 		_capacity = capacity;
// 		_size = 0;
// 	}

// 	void push(QueueDate x)
// 	{
// 		if (_size == _capacity)
// 		{
// 			_capacity *= 2;
// 			QueueDate* a = (QueueDate*)realloc(_a,sizeof(QueueDate) * _capacity);
// 			if (a == nullptr)
// 			{
// 				perror("realloc fail");
// 				return;
// 			}
// 			_a = a;
// 		}
// 		_a[_size++] = x;
// 	}

// 	int Top()
// 	{
// 		return _a[0];
// 	}

// 	void Pop()
// 	{
// 		int i = 0;
// 		for (i = 1; i < _size; i++)
// 			_a[i - 1] = _a[i];
// 		_size--;
// 	}

// 	bool Empty()
// 	{
// 		return _size == 0;
// 	}

// 	~Queue()
// 	{
// 		free(_a);
// 		_a = nullptr;
// 		_size = _capacity = 0;
// 	}

// private:
// 	QueueDate* _a;
// 	QueueDate _size;
// 	QueueDate _capacity;
// };

// int main()
// {
// 	Queue qu;
// 	qu.push(1);
// 	qu.push(2);
// 	qu.push(3);
// 	qu.push(4);
// 	qu.push(5);
// 	qu.push(6);
// 	for (int i = 0; i < 6; i++)
// 	{
// 		cout << qu.Top() << "->"; 
// 		qu.Pop();
// 	}
// 	return 0;
// }



