#ifndef USER_H
#define USER_H
#include <iostream>
#include<string>
class User//用户抽象类
{
    private:
        std::string username;
        std::string password;
    public:
        User(std::string t1="nullptr", std::string t2="nullptr"):username(t1), password(t2){};//构造函数
        std::string getUsername(){return username;}//获取用户名
        std::string getPassword(){return password;}//获取密码
        virtual std::string getUserType()=0;//获取用户类型(普通用户/管理员)
        void show_user()
        {
            std::cout<<"用户名："<<username<<"\t";
            std::cout<<"密码："<<password<<"\t";
            std::cout<<"用户类型："<<getUserType()<<std::endl;
        }
};
#endif