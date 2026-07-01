#ifndef MENU_H
#define MENU_H
#include<iostream>
#include<string>


#include"user.h"
#include"adminUser.h"
#include"normalUser.h"

class Menu
{
    private:
        User* curUser;//当前用户
    public:
        Menu(User* user=nullptr):curUser(user){};//构造函数
        void setCurUser(User* user)//设置当前用户
        {
            curUser=user;
        }
        void show_main_menu()//展示主菜单
        {
            std::cout<<"====================主菜单====================================="<<std::endl;
            std::cout<<"1.爬虫1（HNEU-OJ爬虫）"<<std::endl;
            std::cout<<"爬虫简介1：爬取湖南工程学院OJ网站的各种信息包括（题目信息/用户信息）"<<std::endl;
            std::cout<<"2.爬虫2（HNEU-News爬虫）"<<std::endl;
            std::cout<<"爬虫简介2：爬取湖南工程学院新闻网站的新闻"<<std::endl;
            std::cout<<"3.开发中......."<<std::endl;
            std::cout<<"4.退出"<<std::endl;
            std::cout<<"==============================================================="<<std::endl;
            showCurUser();
            std::cout<<"请输入您的选择(1-4)：";
        }
        void show_admin_menu()//展示管理员菜单
        {
            std::cout<<"欢迎使用湖南工程学院爬虫信息管理系统"<<std::endl;
            std::cout<<"====================管理员菜单===================="<<std::endl;
            std::cout<<"1.添加用户"<<std::endl;
            std::cout<<"2.删除用户"<<std::endl;
            std::cout<<"3.修改用户权限"<<std::endl;
            std::cout<<"4.查询用户信息"<<std::endl;
            std::cout<<"5.显示所有用户信息"<<std::endl;
            std::cout<<"6.开发中..."<<std::endl;
            std::cout<<"7.退出"<<std::endl;
            std::cout<<"================================================="<<std::endl;
            showCurUser();
            std::cout<<"请输入您的选择(1-7)：";
        }
        void show_user_menu1()//展示用户菜单1
        {
            std::cout<<"====================HNEU-OJ爬虫===================="<<std::endl;
            std::cout<<"1.爬取题目信息"<<std::endl;
            std::cout<<"2.爬取用户信息"<<std::endl;
            std::cout<<"3.开发中..."<<std::endl;
            std::cout<<"4.退出"<<std::endl;
            std::cout<<"================================================"<<std::endl;
            std::cout<<"请输入您的选择(1-4)：";
        }
        void show_user_menu2()//展示用户菜单2
        {
            std::cout<<"====================HNEU-News爬虫===================="<<std::endl;
            std::cout<<"1.爬取新闻信息"<<std::endl;
            std::cout<<"2.开发中..."<<std::endl;
            std::cout<<"3.退出"<<std::endl;
            std::cout<<"================================================="<<std::endl;
            std::cout<<"请输入您的选择(1-3)：";
        }
        void show_login_menu()//展示登录菜单
        {
            std::cout<<"欢迎使用湖南工程学院爬虫信息管理系统"<<std::endl;
            std::cout<<"====================登录菜单===================="<<std::endl;
            std::cout<<"1.登录"<<std::endl;
            std::cout<<"2.注册"<<std::endl;
            std::cout<<"3.退出"<<std::endl;
            std::cout<<"==============================================="<<std::endl;
            std::cout<<"请输入您的选择(1-3)：";
        }
        void showCurUser()
        {
            std::cout<<"当前操作用户："<<curUser->getUsername()<<"\t"<<"当前用户权限："<<curUser->getUserType()<<std::endl;
        }
};



#endif