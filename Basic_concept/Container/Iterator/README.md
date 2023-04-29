## 迭代器

>通过迭代器访问容器的对象

### 1.迭代器的使用

使用容器的`begin()`和`end()`方法返回指向容器对象的迭代器

> `begin()`返回指向第一个元素的迭代器

> `end()`返回指向最后一个元素**下一个位置**的迭代器（尾后迭代器）


> 如果迭代器为空，`begin()`和`end()`均为尾后迭代器

`*iter`将返回iter指向元素的引用，可以使用`(*iter).mem`或者`iter->mem`来访问指向对象的成员

	#include<vector>
	#include<iostream>

	std::vector<int> v{0,1,2,3,4,5,6};
	for(auto iter = v.begin() ; iter != v.end() ; ++iter)
	{
		std::cout << *iter << std::endl;
	}



使用容器的`cbegin()`和`cend()`方法返回cosnt类型迭代器

> 但凡在循环体中使用了迭代器，均不要向容器中添加新的元素

练习1：迭代器的基本使用

### 2.迭代器的运算

> 迭代器加上或减去一个整数n仍为一个迭代器，返回新迭代器指向的位置为原来指向位置向前或向后移动n个元素

>两个迭代器可以使用关系运算符进行比较位置前后关系

> 两个迭代器相减返回 **long long** 类型的整数

	auto iter = iter2 - n;
	bool a = (iter2 >= iter1);
	long long b = iter2 - iter1;

练习2：使用迭代器实现二分搜索





