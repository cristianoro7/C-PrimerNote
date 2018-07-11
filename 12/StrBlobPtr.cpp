//
// Created by desperado on 2018/7/10.
//

#include "StrBlobPtr.h"

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t index, const std::string &msg) const {
    auto p = weakPtr.lock();
    if (!p) {
        throw std::runtime_error("unbound StrBlobPtr!");
    }
    if (index > p->size()) {
        throw std::out_of_range(msg);
    }
    return p;
}

std::string &StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr() {
    check(curr, "end!");
    ++curr;
    return *this;
}
