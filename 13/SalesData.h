//
// Created by desperado on 2018/7/11.
//

#ifndef CPRIMARY_SALESDATA_H
#define CPRIMARY_SALESDATA_H


#include <string>

class SalesData {

public:
    SalesData(const SalesData &salesData): ps(new std::string(*salesData.ps)),
        i(salesData.i){ //拷贝salesData内ps指针所指向的对象
    };

    SalesData &operator=(const SalesData &salesData) {
        auto p = new std::string(*salesData.ps);
        delete ps;
        ps = p;
        i = salesData.i;
        return *this;
    };

    ~SalesData() = default;

    explicit SalesData(const std::string &s = std::string()): ps(new std::string(s)),
            i(0){
    }


private:
    std::string *ps;
    int i;

};


#endif //CPRIMARY_SALESDATA_H
