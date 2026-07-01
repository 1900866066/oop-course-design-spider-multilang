#ifndef HNEU_NEWS_H
#define HNEU_NEWS_H

#include<iostream>
#include<vector>
#include<string>

#include"spider.h"

class HNEU_News:public Spider
{
    public:
    HNEU_News():Spider()
    {

    }//HNEU_News爬虫无参构造
    HNEU_News(Data &_data,std::string Type,User* user):Spider(_data,Type,user)
    {

    }//HNEU_News爬虫有参构造
    std::string getSpiderType(){return "HNEU_News爬虫";}//获取爬虫种类
    void showSpider()
    {
        int choice;
        while(1)
        {
            Menu::show_user_menu2();
            std::cin>>choice;
            switch(choice)
            {
                case 1://爬取新闻信息
                {
                    std::cout<<"----爬取新闻信息----"<<std::endl;
                    std::string cmd="python ./NewsSpider.py";//通过命令行调用python爬虫脚本
                    FILE*p=popen(cmd.c_str(),"r");
                    if(!p)
                    {
                        std::cout<<"管道打开失败！"<<std::endl;
                    }
                    else
                    {
                        std::cout<<"HNEU_News爬虫正在爬取新闻信息.........."<<std::endl;
                        //显示python爬虫脚本的输出信息
                        char buffer[1024];
                        while(fgets(buffer,1024,p))
                        {
                            std::cout<<buffer<<std::endl;
                        }
                        std::cout<<"爬取成功，文件保存在湖南工程学院新闻.csv中"<<std::endl;
                    }
                }
                break;
                case 2://开发中
                {
                    std::cout<<"开发中，敬请期待！"<<std::endl;
                }
                break;
                case 3://退出
                {
                    std::cout<<"欢迎下次使用湖南工程学院爬虫信息管理系统"<<std::endl;
                    std::cout<<"*系统退出中......*"<<std::endl;
                    std::cout<<"*系统退出成功*"<<std::endl;
                    std::cout<<"bye~"<<std::endl;
                    exit(0);
                }
                break;
                default://选择错误
                {
                    std::cout<<"输入有误，请重新输入！"<<std::endl;
                }
                break;

            }
            system("pause");
            system("cls");

        }
    }
};


#endif