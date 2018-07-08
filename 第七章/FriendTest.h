//
// Created by desperado on 18-7-8.
//

#ifndef CPRIMARY_FRIENDTEST_H
#define CPRIMARY_FRIENDTEST_H

#include "FriendTestB.h"

class FriendTest {

private:
    int b;

public:
    FriendTest(int b): b(b) {}

    friend int getFriendTest_b(FriendTest &friendTest); //普通函数友元
    int getFriendTestB_a(FriendTestB &friendTestB) {
        return friendTestB.a;
    }
};

#endif //CPRIMARY_FRIENDTEST_H


int getFriendTest_b(FriendTest &friendTest) {
    return friendTest.b;
}