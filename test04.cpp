#include<iostream>
#include"HNEU_OJ.h"
using namespace std;
int main()
{
    Data data;
    User*user=new NormalUser("yww","1234");
    HNEU_OJ OjSpider(data,"HUEU_OJ爬虫",user);//实例化一个HNEU_OJ爬虫内部通过控制台命令调用python实现数据爬取
    OjSpider.showSpider();//用户交互接口
    return 0;
}