#ifndef NORMAL_CLIENT_H
#define NORMAL_CLIENT_H

#include<iostream>
#include<string>
#include<vector>

#include"menu.h"
#include"data.h"
#include"user.h"
#include"normalUser.h"
#include"spider.h"
#include"HNEU_News.h"
#include"HNEU_OJ.h"

class Normal_Client:public Menu//用户客户端类
{
    private:
    User*curuser;
    Data data;
    public:
    Normal_Client():Menu(nullptr),curuser(nullptr){}//用户客户端类无参构造
    Normal_Client(User* user,Data&_data):Menu(user),curuser(user),data(_data){}//用户客户端类有参构造
    Spider* showUser()//返回一个爬虫抽象类指针用于爬虫的多态
    {
        int choice;
        while(1)
        {
            Menu::show_main_menu();
            std::cin>>choice;
            switch(choice)
            {
                case 1://选择HUEU-OJ爬虫
                {
                    std::cout<<"*选择成功*"<<std::endl;
                    std::cout<<"HNEU_OJ爬虫启动中......"<<std::endl;
                    system("pause");
                    system("cls");
                    std::cout<<"===================="<<std::endl;
                    std::cout<<"*HNEU_OJ爬虫启动成功*"<<std::endl;
                    std::cout<<"*欢迎使用HUEU-OJ爬虫*"<<std::endl;
                    std::cout<<"===================="<<std::endl;
                    return new HNEU_OJ(data,"HUEU_OJ爬虫",curuser);
                }
                break;
                case 2://选择HNEU-News爬虫
                {
                    std::cout<<"*选择成功*"<<std::endl;
                    std::cout<<"HNEU-News爬虫启动中......"<<std::endl;
                    system("pause");
                    system("cls");
                    std::cout<<"======================"<<std::endl;
                    std::cout<<"*HNEU-News爬虫启动成功*"<<std::endl;
                    std::cout<<"*欢迎使用HNEU-News爬虫*"<<std::endl;
                    std::cout<<"======================"<<std::endl;
                    return new HNEU_News(data,"HNEU_News爬虫",curuser);
                }
                break;
                case 3://开发中...
                {
                    std::cout<<"开发中，敬请期待..."<<std::endl;
                }
                break;
                case 4://退出系统
                {
                    std::cout<<"*退出系统成功*"<<std::endl;
                    std::cout<<"欢迎下次使用！"<<std::endl;
                    std::cout<<"bye~"<<std::endl;
                    exit(0);
                }
                break;
                default:
                {
                    std::cout<<"选择有误，请输入正确的选择（1-4）"<<std::endl;
                }
                break;
            }
            system("pause");
            system("cls");
        }
    }
};

#endif