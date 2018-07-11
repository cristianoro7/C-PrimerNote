//
// Created by desperado on 2018/7/10.
//

#include "MemoryTest.h"

#include <memory.h>
#include <string>
#include <memory>
#include <list>
#include <vector>

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

    allocator<string> a; //定义了一个名为a的allocator对象， 他可以为string对象分配内存
    string *sp = a.allocate(10); //分配10个string对象的内存
    a.deallocate(sp, 10); //释放从sp指针中地址开始的内存， 这块内存保存了10个对象 sp必须是先前allocate方法返回的指针。在调用deallocate之前， 必须调用对象的destroy
    a.construct(sp, "s"); //在sp指向的内存中构造一个对象
    a.destroy(sp); //执行对象的析构函数

    vector<int> v;
    auto ap = a.allocate(v.size() * 2);
    auto aq = uninitialized_copy(v.begin(), v.end(), ap); //返回的地址是最后一个指针
    uninitialized_fill_n(aq, v.size(), 42);

}
