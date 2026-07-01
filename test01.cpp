#include<iostream>
#include"login.h"
#include"user.h"
#include"data.h"

using namespace std;
int main(int argc,char*argv[])
{
    Data data;
    login log(data,nullptr);
    User *user=log.login_user();
    if(user) delete user,user=nullptr;
    return 0;
}