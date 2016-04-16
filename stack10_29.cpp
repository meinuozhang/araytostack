////判断元素出栈入栈的合法性
////入栈顺序为1，2，3，4  出栈顺序可以随意给出
////在这里可以考虑用指针来操作比较最后得出结果
//#include <iostream>
//using namespace std;
//template <typename T>
//class Stack
//{
//public:
//	Stack()
//		:_array(new T(1))
//		, _topindex(-1)//初始化栈顶元素下标为-1
//		, _capacity(0)//栈容量
//	{}
//	~Stack()
//	{
//		if (_array)
//		{
//			
//			delete[] _array;
//			cout << "调用了析构函数" << endl;
//			_topindex = -1;
//		}
//	}
//	void Push(const T & x)
// 	{
//		if (_topindex + 1 == _capacity)
//		{
//			_capacity = _capacity * 2 + 3;
//			T *tmp = new T[_capacity];
//			memcpy(tmp, _array, sizeof(T)* (_topindex + 1));
//			delete[] _array;
//			_array = tmp;
//		}
//		_array[++_topindex] = x;
//	}
//	void  Pop()
//	{
//		if (_topindex > -1)
//		{
//			cout << _array[_topindex] << endl;
//			--_topindex;
//		}
//
//	}
//	bool empty()
//	{
//		if (_topindex == -1)
//			return true;
//		else
//			return false;
//	}
//	T gettopdata()
//	{
//		if (!empty())
//		{
//			return _array[_topindex];
//		}
//		return NULL;
//	}
//	//dst为空时，s1中元素压栈，dst指针后移，取栈顶元素跟src中元素比较，相等出栈，反之dst继续入栈
//	bool IsLegal(const char *dst, const char *src)//判断出栈顺序是否是合法的
//	{
//		Stack<char> s1;
//		
//		while (*dst&&*src)
//		{
//			if (s1.empty())
//			{
//				s1.Push(*dst);
//     			++dst;
//			}
//			char ret;
//			if( (ret=s1.gettopdata()) != *src)
//			{
//				s1.Push(*dst);
//				++dst;
//			}
//			while (ret = s1.gettopdata()==*src && *src)
//			{
//				s1.Pop();
//				++src;
//			}
//		}
//		return s1.empty() ? true : false;
//	}
//private:
//	T *_array;
//	int _topindex;
//	int _capacity;
//};
//void Test()
//{
//	char dst[] = { "1234" };
//	char src[] = { "4321" };
//	char p[] = { "4123" };
//	Stack<char> s1;
//	cout<<(s1.IsLegal(dst, src)? "Yes" : "No")<<endl;
//	cout << (s1.IsLegal(dst, p) ? "Yes" : "No")<<endl;
//}
//int main()
//{
//
//	Test();
//	getchar();
//	return 0;
//}
////在这里，我们直接调用<stack>库里面的函数
//#include<iostream>
//#include<stack>
//using namespace std;
//template <typename T>
//class Stack
//{
//public:
//	void Push(const T& x)
//	{
//		if (DataStack.empty()&& MinStack.empty())
//		{
//          DataStack.push(x);
//		   MinStack.push(x);
//		}
//		else
//		{
//			DataStack.push(x);
//			if (x >= MinStack.top())
//			{
//				MinStack.push(MinStack.top());
//			}
//			else
//			{
//				MinStack.push(x);
//			}
//		}
//	}
//	void Pop()
//	{
//		DataStack.pop();
//	}
//	T Mindata()
//	{ 
//		if (!MinStack.empty())
//		{
//			T ret;
//			ret = MinStack.top();
//			return ret;
//		}
//	}
//	
//private:
//	stack<T> DataStack;
//	stack<T> MinStack;
//};
//void  Test()
//{
//	Stack<int> s1;
//	s1.Push(9);
//	s1.Push(2);
//	s1.Push(5);
//	s1.Push(3);
//	int mindata=s1.Mindata();
//	cout << "栈中最小元素为:" << mindata << endl;
//	/*s1.Pop();
//	s1.Pop();
//	s1.Pop();*/
//}
//int main()
//{
//	Test();
//	getchar();
//	return 0;
//}
//用一个数组实现两个栈，在这里我们共用一个_topindex
#include<iostream>
using  namespace std;
#define Dafault_Capacity 30
template <typename T>
class ArraytoStack
{
public:
	ArraytoStack()
		:_array(new T[1])
		,_topindex(-1)
		,_capacity(Dafault_Capacity)
	{}
	void Push(const T& x,size_t topindex)
	{  
		_topindex = topindex;
		if (_topindex + 1 == _capacity)
		{
			_capacity = _capacity * 2 + 3;
			T *tmp = new T[_capacity];
			memcpy(tmp, _array, sizeof(T)*(_topindex + 1));
			delete[]_array;
			_array = tmp;
		}
		if (_topindex % 2 == 0)
		{
			_array[_topindex] = x;
			
		}
		else
		{
			_array[_topindex]=x;
	
		}

	}
	void Pop()
	{
		if (_array)
		{
			cout << _array[_topindex] << endl;
			--_topindex;
		}
	}
	T Gettopdata()
	{ 
		
		if (!Empty())
		{
			if (_topindex % 2 == 0)
			{
				cout << "左栈栈顶元素为：" << _array[_topindex] << endl;
				return  _array[_topindex];
			}
			else
			{
				cout << "右栈栈顶元素为：" << _array[_topindex] << endl;
				return _array[_topindex];
			}
		}

	}
	bool Empty()
	{
		if (_topindex == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	T * _array;
	size_t _topindex;
	size_t _capacity;
};
void Test()
{
	ArraytoStack<int> s1;
	ArraytoStack<int> s2;
	s1.Push(1, 0);
	s2.Push(2, 1);
	s1.Push(3, 2);
	s2.Push(4, 3);
	/*s1.Push(5, 4);

	s1.Pop();
	s1.Pop();
	s1.Pop();
	s1.Pop();*/
	int ret = s1.Gettopdata();
	cout << "左栈栈顶元素为：" << ret << endl;

}
int main()
{
	Test();
	getchar();
	return 0;
}














