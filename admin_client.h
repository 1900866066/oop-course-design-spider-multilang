#ifndef ADMIN_CLIENT_H
#define ADMIN_CLIENT_H


#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

#include"menu.h"
#include"user.h"
#include"data.h"
#include"adminUser.h"
#include"normalUser.h"



class Admin_Client:public Menu//管理员后台类,继承自菜单类
{
    private:
    Data data;//数据类成员-用于管理数据
    User*curUser;//当前操作用户
    public:
    Admin_Client():Menu(nullptr)//无参构造
    {
        curUser=nullptr;
    }
    Admin_Client(User*curUser,Data &data):Menu(curUser),curUser(curUser),data(data)
    {

    }//管理员后台构造函数
    void showAdmin()//管理员后台主要逻辑函数，用于展示用户交互界面；
    {
        int choice;
        while(1)
        {
            Menu::show_admin_menu();//展示管理员菜单
            std::cin>>choice;
            std::string username,password;//用户名，密码
            switch(choice)
            {
                case 1://添加用户
                {
                    std::cout<<"----添加用户----"<<std::endl;
                    std::cout<<"请输入添加用户名："<<std::endl;
                    std::cin>>username;
                    std::cout<<"请输入用户密码："<<std::endl;
                    std::cin>>password;
                    std::cout<<"请选择用户权限（1.普通用户/2.管理员）："<<std::endl;
                    int type=1;
                    std::cin>>type;
                    if(type!=1&&type!=2)
                    {
                        std::cout<<"请输入确的用户权限！"<<std::endl;
                        break;
                    }
                    std::string userType=type==1? "普通用户":"管理员";
                    data.addUser(username,password,userType);
                    std::cout<<"*用户添加成功*"<<std::endl;
                    std::cout<<"用户名："<<username<<"\t"<<"密码："<<password<<std::endl;
                }
                break;
                case 2://删除用户
                {
                    std::cout<<"----删除用户----"<<std::endl;
                    std::string username;
                    std::cout<<"请输入要删除的用户名："<<std::endl;
                    std::cin>>username;
                    if(data.del_user(username))
                    {
                        std::cout<<"*删除成功*"<<std::endl;
                    }
                    else
                    {
                        std::cout<<"删除失败，请确认用户名是否正确"<<std::endl;
                    }
                }
                break;
                case 3://修改用户权限
                {
                    std::cout<<"----修改用户权限----"<<std::endl;
                    std::string username;
                    std::cout<<"请输入用户名："<<std::endl;
                    std::cin>>username;
                    if(username==curUser->getUsername())
                    {
                        std::cout<<"禁止修改当前用户权限"<<std::endl;
                        break;
                    }
                    User** user=data.getUser_idx(username);
                    if(user)
                    {
                        std::cout<<"--正在修改用户--"<<std::endl;
                        (*user)->show_user();
                        std::cout<<"---------------"<<std::endl;
                        std::cout<<"请选择用户权限（1.普通用户/2.管理员）："<<std::endl;
                        int type=1;
                        std::cin>>type;
                        std::string password=(*user)->getPassword();
                        if(*user) delete *user;
                        if(type==1)
                        {
                            *user=new NormalUser(username,password);
                        }
                        else if(type==2) *user=new AdminUser(username,password);
                        else
                        {
                            std::cout<<"修改失败，请选择正确用户权限"<<std::endl;
                            break;
                        }
                        std::cout<<"*修改成功*"<<std::endl;
                        data.saveUsers_file();//保存用户信息；
                    }
                    else
                    {
                        std::cout<<"查询失败，不存在用户名："<<username<<std::endl;
                    }
                }
                break;
                case 4://查询用户信息
                {
                    std::cout<<"----查询用户信息----"<<std::endl;
                    std::string username;
                    std::cout<<"请输入查询的用户名："<<std::endl;
                    std::cin>>username;
                    User*user=data.getUser(username);
                    if(user)
                    {
                        std::cout<<"*查询成功*"<<std::endl;
                        std::cout<<"用户信息如下："<<std::endl;
                        user->show_user();
                    }
                    else 
                    {
                        std::cout<<"查询失败，不存在用户名："<<username<<std::endl;
                    }

                }
                break;
                case 5://显示所有用户信息
                {
                    std::cout<<"----显示所有用户信息----"<<std::endl;
                    int cnt=data.show_all_user();
                    std::cout<<"*显示成功*"<<std::endl;
                    std::cout<<"数据库中共（"<<cnt<<"）位用户"<<std::endl;
                }
                break;
                case 6://开发中
                    std::cout<<"开发中，敬请期待..."<<std::endl;
                break;
                case 7://退出系统
                {
                    std::cout<<"退出系统成功，欢迎下次使用！"<<std::endl;
                    std::cout<<"bye~~"<<std::endl;
                    exit(0);
                }
                break;
                default://选择错误
                    std::cout<<"请正确输入您的选择(1-7)"<<std::endl;
                break;
            }
            system("pause");
            system("cls");

        }
    }

};


#endif
