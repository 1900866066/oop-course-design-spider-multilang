#ifndef SPIDER_H
#define SPIDER_H

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>

#include"data.h"
#include"menu.h"
#include"user.h"
#include"adminUser.h"
#include"normalUser.h"


class Spider:public Menu//爬虫抽象类
{
    private:
    User* curuser;//当前操作用户
    Data data;//数据对象
    std::string SpiderType;//爬虫类型
    public:
    Spider():Menu(nullptr)
    {
        curuser=nullptr;
        SpiderType="NONE";
    }
    Spider(Data& _data,std::string Type,User*user=nullptr):Menu(user),data(_data),SpiderType(Type)
    {
        curuser=user;
    }
    virtual std::string getSpiderType()=0;//获取爬虫类型纯虚函数；
    virtual void showSpider()=0;//爬虫主要逻辑函数，与用户交互的接口
};
#endif