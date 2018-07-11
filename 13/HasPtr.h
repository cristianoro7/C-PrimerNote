//
// Created by desperado on 2018/7/11.
//

#ifndef CPRIMARY_HASPTR_H
#define CPRIMARY_HASPTR_H


#include <string>

class HasPtr {

private:
    std::string *ps;
    int i;
    std::size_t *use; //记录有多少个对象共享*ps成员

public:
    explicit HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0), use(new std::size_t(1)) {}

    HasPtr(const HasPtr &p): ps(p.ps), i(p.i), use(p.use) {
        ++*use;
    }

    HasPtr&operator=(const HasPtr& p) {
        ++*p.use; //递增右侧运算对象的引用
        if (--*use == 0) {
            delete ps;
            delete use;
        }
        ps = p.ps;
        i = p.i;
        use = p.use;
        return *this;
    }

    ~HasPtr() {
        if (--*use == 0) {
            delete ps;
            delete use;
        }
    }
};

#endif //CPRIMARY_HASPTR_H
