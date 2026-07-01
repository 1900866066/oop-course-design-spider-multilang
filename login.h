#ifndef LOGIN_H
#define LOGIN_H

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>

#include"menu.h"
#include"user.h"
#include"adminUser.h"
#include"normalUser.h"
#include"data.h"

class login:public Menu
{
    private:
        User* curUser;//当前用户
        Data data;//数据对象
        public:
        login():Menu(nullptr)//登录类无参构造
        {
            curUser=nullptr;
        }
        login(Data&_data,User* user=nullptr):Menu(user),data(_data){}//构造函数
        User* login_user()
        {
            int choice;//用户选择
            while(1)
            {
                Menu::show_login_menu();//展示登录菜单
                std::cin>>choice;
                std::string username,password;
                bool login_success=false;//登录成功信号
                switch(choice)
                {
                    case 1:
                    {
                        std::cout<<"请输入用户名："<<std::endl;
                        std::cin>>username;
                        std::cout<<"请输入密码："<<std::endl;
                        std::cin>>password;
                        if(data.find_user(username,password))
                        {
                            login_success=true;
                        }
                        else
                        {
                            std::cout<<"用户名或密码错误请重试"<<std::endl;
                        }
                    }
                    break;
                    case 2:
                    {
                        std::cout<<"请输入用户名："<<std::endl;
                        std::cin>>username;
                        std::cout<<"请输入密码："<<std::endl;
                        std::cin>>password;
                        std::string temp;
                        std::cout<<"请再次输入密码："<<std::endl;
                        std::cin>>temp;
                        if(temp!=password)
                        {
                            std::cout<<"两次密码不统一请检查后重试"<<std::endl;
                        }
                        else
                        {
                            data.addUser(username,password,"普通用户");
                            std::cout<<"注册成功！"<<std::endl;
                            std::cout<<"请重新登录"<<std::endl;
                            std::cout<<"当前用户数量"<<data.getUser_size()<<std::endl;
                        }
                    }
                    break;
                    case 3:
                    {
                        std::cout<<"退出系统成功，欢迎下次使用！"<<std::endl;
                        std::cout<<"bye~~"<<std::endl;
                        exit(0);
                    }
                    break;
                    default:
                    {
                        std::cout<<"请正确输入您的选择(1-3)"<<std::endl;
                    }
                    break;
 
                }
                if(login_success)
                {
                    std::cout<<"*登录成功*"<<std::endl;
                    curUser= data.getUser(username);
                    std::cout<<"欢迎用户：（"<<curUser->getUsername()<<"）使用本系统\t"<<"当前用户权限:"
                    <<curUser->getUserType()<<std::endl;
                    std::cout<<"正在进入系统........"<<std::endl;
                    system("pause");
                    system("cls");
                    return curUser;
                }
                system("pause");
                system("cls");
            }
            return nullptr;
        }
};

#endif