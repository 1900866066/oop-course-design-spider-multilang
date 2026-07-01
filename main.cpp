#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

#include"data.h"
#include"login.h"
#include"user.h"
#include"menu.h"
#include"adminUser.h"
#include"normalUser.h"
#include"admin_client.h"
#include"normal_client.h"


int main()
{
    Data data;//初始化数据对象实例
    //登录模块
    login log(data,nullptr);//登录接口对象实例化
    User* user=log.login_user();//进行登录
    if(user->getUserType()=="管理员")//界面分流，登录用户为管理员则进入管理员后台否则进入爬虫界面
    {
        Admin_Client admin_client(user,data);//实例化管理员客户端对象
        admin_client.showAdmin();//管理员后台主要逻辑函数
    }
    else if(user->getUserType()=="普通用户")
    {
        Normal_Client  normal_client(user,data);//普通用户客户端对象
        Spider*spider=normal_client.showUser();//普通用户选择爬虫类型主要逻辑函数
        spider->showSpider();//多态，使用HUEU_OJ爬虫或者HNEU_News爬虫
    }
    return 0;
}