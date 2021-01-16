#include <iostream>
using namespace std;
#include <string>

template<class T>
class MyArray 
{
public:
	// 有参构造函数
	MyArray(int capacity)
	{
		cout << "有参构造函数调用" << endl;
		this->m_Capacity = capacity; // 数组容量传入
		this->m_Size = 0; // 初始数组大小为0
		this->pAddress = new T[this->m_Capacity]; // 堆区数据，按照容量开辟空间
	}

	// 拷贝构造
	MyArray(const MyArray& arr)
	{
		cout << "拷贝构造函数调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		// this->pAddress = arr.pAddress; 不可，由于是堆区数据，会导致浅拷贝出错
		// 深拷贝
		this->pAddress = new T[arr.m_Capacity];
		// 将arr中的数据都拷贝过来
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	// 重载赋值运算符，注意深拷贝问题
	MyArray& operator=(const MyArray& arr)
	{
		cout << "operator=的调用" << endl;
		// 先判断原来堆区是否有数据，如果有就先释放
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		// 深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		// 返回自身
		return *this;
	}

	// 尾插法
	void Push_Back(const T& val)
	{
		// 判断容量是否等于大小
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val; // 在数组末尾插入数据
		this->m_Size++; // 更新数组大小
	}

	// 尾删法
	void Pop_Back()
	{
		// 让用户访问不到最后一个元素，即为逻辑尾删
		// 判断容器中是否没有数据了
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--; // 逻辑尾删
	}

	// 通过下标访问数组元素,重载[]运算符,返回T&是为了实现a[100] = 10，
	// 函数调用还想作为左值存在，把其自身返回
	T& operator[](int index)
	{
		return this->pAddress[index];
	}
	
	// 返回数组大小
	int getSize()
	{
		return this->m_Size;
	}
	// 返回数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}
	// 析构函数
	~MyArray()
	{
		cout << "析构函数调用" << endl;
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress; // 清空数组
			this->pAddress = NULL; // 置空，防止野指针
		}
	}

private:
	T* pAddress; // 指针指向堆区开辟的真实数组
	int m_Capacity; // 数组容量
	int m_Size; // 数组大小
};

void printArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++) // 测试getSize
	{
		cout << arr[i] << endl;
	}
}

// 测试自定义数据类型
class Person
{
public:
	Person() {}; // 默认构造，变成空实现，这个必须得写，否则报错，原因是new T[arr.m_Capacity];
	// 等价于new Person[arr.m_Capacity];开辟堆区空间时会自动调用默认无参构造（因为new时没有传参）
	// 所以这里写，如果不写，就没有无参构造了（由于写了有参，编译器不会给默认的无惨构造了）
	//	• 调用规则："如果用户定义有参构造函数，c++不再提供默认无参构造，但会提供默认拷贝构造"
	Person(string name, int age) // 有参构造
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "name" << arr[i].m_Name << " age" << arr[i].m_Age;
	};
}

void test01()
{
	MyArray <int>arr1(5); // 测试构造
	MyArray <int>arr2(arr1); // 测试拷贝构造
	MyArray <int>arr3(100); 
	arr3 = arr1; // 测试赋值运算符重载情况
	MyArray <int>arr4(10);
	for (int i = 0; i < 10; i++)
	{
		arr4.Push_Back(i);
	};
	printArray(arr4); // 测试尾插法
	cout << "容量" << arr4.getCapacity() << " 大小" << arr4.getSize() << endl;

	for (int i = 0; i < 5; i++)
	{
		arr4.Pop_Back();
	};
	printArray(arr4); //  测试尾删法
	cout << "容量" << arr4.getCapacity() << " 大小" << arr4.getSize() << endl;
	
	// 测试自定义数据类型
	MyArray<Person> arr5(3);
	Person p1("s1", 100);
	Person p2("s2", 90);
	Person p3("s3", 70);
	arr5.Push_Back(p1);
	arr5.Push_Back(p2);
	arr5.Push_Back(p3);
	cout << "容量" << arr5.getCapacity() << " 大小" << arr5.getSize() << endl;
	printPersonArray(arr5);
}


int main()
{
	test01();
	system("pause");//按任意键继续

	return 0;//退出

}