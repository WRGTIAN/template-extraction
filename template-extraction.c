#include <iostream>
using namespace std;
#include <string>
struct _TureType
{
	bool get()
	{
		return true;
	}
};
struct _FalseType
{
	bool get()
	{
		return false;
	}
};


//类型萃取
template<typename T>
struct TypeTraits      
{
	typedef _FalseType _IsPodType;
};
//特化TypeTraits进行类型判断(由于内置类型已经确定，而自定义类型不确定，因此经常特化内置类型)
template<>
struct TypeTraits<int>
{
	typedef _TureType _IsPodType;
}; 
template<>
struct TypeTraits<unsigned int>
{
	typedef _TureType _IsPodType;
};
template<>
struct TypeTraits<double>
{
	typedef _TureType _IsPodType;
};
template<>
struct TypeTraits<float>
{
	typedef _TureType _IsPodType;
};
template<>
struct TypeTraits<char>
{
	typedef _TureType _IsPodType;
};
template<>
struct TypeTraits<unsigned char>
{
	typedef _TureType _IsPodType;
};
template<>
struct TypeTraits<short>
{
	typedef _TureType _IsPodType;
};
template<>
struct TypeTraits<long>
{
	typedef _TureType _IsPodType;
};
template<>
struct TypeTraits<long long>
{
	typedef _TureType _IsPodType;
};
/*根据需要继续特化.................*/



template<typename T>
T* _Copy(T* dest, T* src, size_t n, _TureType)
{
		memcpy(dest, src, sizeof(T)*n);
		return dest;
}
template<typename T>
T* _Copy(T* dest, T* src, size_t n, _FalseType)
{
	for (size_t i = 0; i < n; i++)
	{
		dest[i] = src[i];       //相当与调用string的赋值运算符重载
	}
	return dest;
}
template<typename T>
T* _Copy(T*dest, T* src, size_t n)
{
	return _Copy(dest, src, n, TypeTraits<T>::_IsPodType());
}
//测试普通类型
void test1()
{
	int a[10] = { 2, 2, 3, 4, 5, 6, 7, 8, 8 };
	int b[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	_Copy(a, b, 5);
}
//特化自定义类型
void test2()
{
	string a[5] = { "abc", "def", "ghi", "123", "456" };
	string b[4] = {"111111111111111111111111111111111111111", "222222", "333333", "44444444"};
	_Copy(a, b, 3);
}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}