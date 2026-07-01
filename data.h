#ifndef DATA_H
#define DATA_H

#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<unordered_map>

#include"user.h"
#include"adminUser.h"
#include"normalUser.h"


class Data
{
    private:
        std::vector<User*> users;//用户信息
        std::unordered_map<std::string,int>mp;//哈希表快速查找用户信息，映射：用户名->下标
    public:
        Data()
        {
            std::ifstream in("users.txt");
            if(!in.is_open())
            {
                std::cout<<"用户信息文件（users.txt）打开失败"<<std::endl;
            }
            else
            {
                int cnt=0;
                std::string username;
                std::string password;
                std::string userType;
                while(in>>username>>password>>userType)
                {
                    mp[username]=cnt++;
                    if(userType=="管理员")
                    {
                        users.push_back(new AdminUser(username,password));
                    }
                    else if(userType=="普通用户")
                    {
                        users.push_back(new NormalUser(username,password));
                    }
                }
                std::cout<<"用户信息文件（users.txt）读取成功"<<std::endl;
                std::cout<<"共读取到"<<users.size()<<"条用户信息"<<std::endl;    
            }
        }//构造函数
        ~Data()
        {
            //释放用户信息数组users
            for(int i=0;i<users.size();i++)
            {
                if(users[i]) delete users[i];
            }
        }
        void addUser(std::string username,std::string password,std::string type)//添加用户
        {
            int idx=users.size();
            mp[username]=idx;
            if(type=="管理员")
            {
                users.push_back(new AdminUser(username,password));
            }
            else if(type=="普通用户") users.push_back(new NormalUser(username,password));
            saveUsers_file();//保存用户信息到文件
        }
        int getUser_size()//获取当前数据库用户数量
        {
            return users.size();
        }
        bool saveUsers_file()//保存用户信息到文件
        {
            if(users.size()==0) 
            {
                std::cout<<"保存失败，内存中无用户数据！"<<std::endl;
                return false;//内存中无用户数据
            }
            std::ofstream out("users.txt");
            if(!out.is_open())
            {
                std::cout<<"用户信息文件（users.txt）打开失败"<<std::endl;
                return false;
            }
            else
            {
                for(auto user:users)
                {
                    if(user)
                    out<<user->getUsername()<<" "<<user->getPassword()<<" "<<user->getUserType()<<std::endl;
                }
                std::cout<<"*用户信息保存成功*"<<std::endl;
                return true;
            }   
        }
        bool find_user(std::string username,std::string password)//查找用户数据
        {
            if(mp.count(username)&&mp[username]>=0)
            {
                int idx=mp[username];
                if(users[idx]->getPassword()==password) return true;
                else return false;
            }
            else return false;
        }
        User* getUser(std::string username)//返回用户指针
        {
            if(mp.count(username)&&mp[username]>=0)
            {
                return users[mp[username]];
            }
            else return nullptr;
        }
        User** getUser_idx(std::string username)//返回User二级指针用于修改一级指针的值
        {
            if(mp.count(username)&&mp[username]>=0) return &users[mp[username]];
            else return nullptr;
        }
        bool del_user(std::string username)//删除用户
        {
            User** user=getUser_idx(username);
            if(user)
            {
                mp[username]=-1;
                delete *user;
                *user=nullptr;
                saveUsers_file();
                return true;
            }
            else return false;
        }
        int show_all_user()//显示所有用户信息
        {
            int cnt=0;//统计用户数量
            for(auto user:users)
            {
                if(user)
                {
                    std::cout<<"#"<<++cnt<<"\t";
                    user->show_user();
                }
            }
            return cnt;
        }
};
#endif