#include<iostream>
#include"normal_client.h"
using namespace std;
int main()
{
    Data data;//数据类对象实例化
    User*user=new NormalUser("yww","password");//创建一个临时的操作用户
    Normal_Client normal_client(user,data);//用户客户端接口实例化
    normal_client.showUser();//调用用户交互接口方法
    return 0;
}