//
// Created by desperado on 2018/7/10.
//

#ifndef CPRIMARY_STRBLOB_H
#define CPRIMARY_STRBLOB_H

#include <memory>
#include <vector>

using namespace std;

class StrBlob {

public:
    using size_type = vector<string>::size_type;
    StrBlob();

    StrBlob(initializer_list<string> il);

    size_type size() const {
        return data->size();
    }

    bool empty() const {
        return data->empty();
    }

    void push_back(const string &s) {
        data->push_back(s);
    }

    void pop_back();

    string &front();
    string &back();

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const ;

};


#endif //CPRIMARY_STRBLOB_H
