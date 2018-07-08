#include <iostream>
#include <cstring>
#include "第七章/FriendTest.h"

int main() {

    FriendTest friendTest(3);
    std::cout << getFriendTest_b(friendTest);

    FriendTestB friendTestB(5);
    std::cout << friendTest.getFriendTestB_a(friendTestB);
    return 0;
}