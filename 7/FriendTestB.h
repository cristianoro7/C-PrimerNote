//
// Created by desperado on 18-7-8.
//

#ifndef CPRIMARY_FRIENDTESTB_H
#define CPRIMARY_FRIENDTESTB_H

class FriendTestB {

private:
    int a;

public:
    FriendTestB(int a): a(a){}
    friend class FriendTest;

};


#endif //CPRIMARY_FRIENDTESTB_H
