#ifndef HNEU_OJ_H
#define HNEU_OJ_H
#include<iostream>
#include<string>
#include<cstdlib>

#include"spider.h"

class HNEU_OJ:public Spider//HNEU_OJ爬虫，用于爬取学校oj平台各种信息
{
    public:
    HNEU_OJ():Spider()//HNEU_OJ爬虫无参构造
    {

    }
    HNEU_OJ(Data _data,std::string Type,User*user=nullptr):Spider(_data,Type,user)//HNEU_OJ爬虫有参构造
    {

    }
    std::string getSpiderType(){return "HNEU_OJ爬虫";}//获取爬虫种类，重写抽象类纯虚函数
    void showSpider()
    {
        int choice;
        while(1)
        {
            Menu::show_user_menu1();
            std::cin>> choice;
            switch(choice)
            {
                case 1://爬取题目信息
                {
                    std::cout<<"----爬取题目信息----"<<std::endl;
                    int page;//爬取题目的页数
                    std::cout<<"请输入需要爬取题目信息的页数（1-23）："<<std::endl;
                    std::cin>>page;
                    if(page>=1&&page<=22)
                    {
                        std::string cmd="python ./QuestionSpider.py ";
                        cmd+=std::to_string(page);//调用python代码的控制台命令
                        FILE*p=popen(cmd.c_str(),"r");
                        if(!p) std::cout<<"管道打开失败！"<<std::endl;
                        else
                        {
                            std::cout<<"HNEU_OJ爬虫正在爬取题目信息.........."<<std::endl;
                            char buffer[1024];
                            while(fgets(buffer,1024,p))
                            {
                                std::cout<<buffer<<std::endl;
                            }
                            std::cout<<"爬取成功文件保存在湖南工程学院OJ题目.csv中"<<std::endl;
                        }
                    }
                    else
                    {
                        std::cout<<"请输入正确的页数！"<<std::endl;
                    }
                }
                break;
                case 2://爬取学生信息
                {
                    std::cout<<"----爬取学生信息----"<<std::endl;
                    std::string cmd="python ./StudentSpider.py ";
                    std::cout<<"请输入需要爬取学生信息的页数（1-80）："<<std::endl;
                    int page;
                    std::cin>>page;
                    if(page<1||page>80)
                    {
                        std::cout<<"请输入正确的页数！"<<std::endl;
                        break;
                    }
                    cmd+=std::to_string(page);//调用python代码的控制台命令
                    FILE*p=popen(cmd.c_str(),"r");
                    if(!p) std::cout<<"管道打开失败！"<<std::endl;
                    else
                    {
                        std::cout<<"HNEU_OJ爬虫正在爬取学生信息.........."<<std::endl;
                        char buffer[1024];
                        while(fgets(buffer,1024,p))
                        {
                            std::cout<<buffer<<std::endl;
                        }
                        std::cout<<"爬取成功文件保存在湖南工程学院OJ学生信息.csv中"<<std::endl;
                    }
                }
                break;
                case 3://开发中
                {
                    std::cout<<"开发中,敬请期待......"<<std::endl;
                }
                break;
                case 4://退出系统
                {
                    std::cout<<"*退出系统成功，欢迎下次使用*"<<std::endl;
                    std::cout<<"bye~"<<std::endl;
                    exit(0);
                }
                break;
                default:
                {
                    std::cout<<"请输入正确的选择"<<std::endl;
                }
                break;
            }
            system("pause");
            system("cls");
        }
    }
};

#endif