//
// Created by desperado on 2018/7/10.
//

#include "StrBlob.h"

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {

}

StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {

}

void StrBlob::check(StrBlob::size_type i, const string &msg) const {
    if (i >= size()) {
        throw out_of_range(msg);
    }
}

string &StrBlob::front() {
    check(0, "empty Strblob!");
    return data->front();
}

string &StrBlob::back() {
    check(0, "back on empty Strblob!");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob!");
    data->pop_back();
}
