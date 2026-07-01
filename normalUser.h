#ifndef NORMALUSER_H
#define NORMALUSER_H
#include"user.h"
class NormalUser:public User
{
    public:
        NormalUser(std::string t1="nullptr",std::string t2="nullptr"):User(t1,t2){};//构造函数
        std::string getUserType(){return "普通用户";};//获取用户类型(普通用户/管理员)
};
#endif