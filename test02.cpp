#include<iostream>
#include<vector>

#include"admin_client.h"

int main()
{
    Data data;
    User*user=new AdminUser("yww","123987");//临时生成一个管理员权限的操作用户对象
    Admin_Client admin_client(user,data);//实例化管理员后台客户端对象
    admin_client.showAdmin();//调用用户交互接口
    return 0;
}