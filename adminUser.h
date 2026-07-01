#ifndef ADMINUSER_H
#define ADMINUSER_H

#include"user.h"
class AdminUser:public User
{
    public:
        AdminUser(std::string t1="nullptr",std::string t2="nullptr"):User(t1,t2){};//构造函数
        std::string getUserType(){return "管理员";};//获取用户类型(普通用户/管理员)
};



#endif