//
// Created by desperado on 2018/7/10.
//

#include "MemoryTest.h"

#include <memory.h>
#include <string>
#include <memory>
#include <list>

using namespace std;


int main() {
    shared_ptr<string> p1;
    shared_ptr<list<int>> p2;

    make_shared<int>(args); //返回一个shared_ptr， 指向一个动态分配的类型对象， 使用args进行初始化
    int *pInt = new int(3);
    shared_ptr<int> p(pInt); //p是shared_ptr的拷贝，此操作会递增pInt的计数器， pInt中的指针必须是能转换为T*
    p = p1; //此操作会递减p的引用计数， 增加p1的引用计数

    unique_ptr<string> u1; //空的up， 可以指向string对象， u1会使用delete来释放它的指针
    unique_ptr<string, decltype(main)*> u2; //u2会使用main函数作为它的删除器
    u2.release(); //放弃u2对指针的控制权， 返回对应的指针， 并将u2置空
    u2.reset(); //释放u指向的对象
    u2.reset(new string()); //如果传入的是内置指针， 将u2指向改对象， 否则将u2置空

}
