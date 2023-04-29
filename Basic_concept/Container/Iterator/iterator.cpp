#include <iostream>
#include <vector>
/*
 * 迭代器练习1：
 * 1. 创建一个int类型的vector
 * 2. 使用迭代器输出第一个和最后一个元素的和、第二个和倒数第二个元素的和、第三个....
 *
 * 迭代器练习2：
 * 二分搜索
*/

void exercise1(const std::vector<int> &v) {
    if (v.begin() == v.end())  //如果vector容器为空 此时v.begin()和v.end()均为尾后迭代器
    {
        std::cout << "empty container" <<std::endl;
        return ;
    }
    //计算vector中元素两两相邻的和
    std::cout << "sum of adjacent elements" << std::endl;
    for (auto i = v.begin(); i != (v.end()-1); ++i)
    {
        auto j = i+1;
        std::cout << *i + *j << " ";
    }
    std::cout << std::endl;

    //计算vector首尾元素之和
    std::cout << "sum of head and tail elements" << std::endl;
    auto x = v.cbegin();  //只读时使用常量迭代器
    auto y = v.cend() - 1;

    for (int i = 0; i < v.size()/2; i++)
    {
        std::cout << (*x + *y) << " ";
        ++x;
        --y;
    }
    if (v.size() % 2 != 0)
        std::cout << (*x + *y);
    std::cout << std::endl;

}

void exercise2(const std::vector<int> v, const int &find){
    auto start = v.begin();
    auto end = v.end();
    auto mid = start + (end - start) / 2;
    while(mid != end)
    {
        if(*mid == find)
        {
            std::cout << "Find subscript:" << mid - v.begin() << std::endl;
            return;
        }
        if(*mid > find)
            end = mid;
        if(*mid < find)
            start = mid + 1;

        mid = start + (end - start) / 2;
    }
    std::cout << "Not found" << std::endl;
}

int main() {
    /*******练习1********/
    std::vector<int> v{0, 1, 2, 3, 4, 5, 6};
    exercise1(v);

    /*******练习2********/
    std::vector<int> v1{0,1,2,3,4,5,6,7,8,9};
    const int find = 5;
    exercise2(v1, find);
    return 0;
}
