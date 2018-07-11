//
// Created by desperado on 2018/7/10
//
/**
 * StrBlob伴随指针类， 熟悉weak_ptr的用法
 */
#ifndef CPRIMARY_STRBLOBPTR_H
#define CPRIMARY_STRBLOBPTR_H


#include <cstddef>
#include <memory>
#include <vector>
#include "StrBlob.h"

class StrBlobPtr {

private:
    std::size_t curr; //数组中当前的位置
    std::weak_ptr<std::vector<std::string>> weakPtr;
    std::shared_ptr<std::vector<std::string>> check(std::size_t index, const std::string &msg) const;

public:
    StrBlobPtr(): curr(0) {};

    StrBlobPtr(StrBlob &a, size_t sz = 0): weakPtr(a.data), curr(sz) {}

    std::string& deref() const;

    StrBlobPtr& incr();
};


#endif //CPRIMARY_STRBLOBPTR_H
