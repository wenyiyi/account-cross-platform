
#include <string>

#include "../conf/server_conf.h"

#include "source/cpp/manager/db/db_base.h"

// #include "source/libs/sqlite3/sqlite3.h"
#include "source/cpp/account/model/user_account.h"
#include "source/cpp/account/model/user_session.h"

using namespace std;
using namespace my_model;

namespace manager{

	class Database{
	public:
		Database();

		/*
		主要功能：
		初始化数据库

		入口参数
       	conf： 			配置文件
		*/
		void connect(ServerConfig conf);

		/*
		主要功能：
		判断用户是否存在

		入口参数
       	account： 		用户账号(手机号)
 
       	出口参数：
       	bool： 			true表示存在；false表示不存在
		*/
		bool isUserExist(string account);

		/*
		主要功能：
		新增用户账号

		入口参数
       	account： 		用户账号(手机号)
       	password： 		密码(加密后)
 
       	出口参数：
       	bool： 			true表示成功；false表示失败
		*/
		bool addUserAccount(string account, string password);

		/*
		主要功能：
		获取用户账号信息

		入口参数
       	account： 		用户账号(手机号)
 
       	出口参数：
       	UserAccount：	用户账号信息
		*/
		UserAccount queryUserAccountByAccount(string account);
	
		/*
		主要功能：
		获取数据库操作类

       	出口参数：
       	Database ： 	数据库操作类（静态单例）
		*/
		static Database* getDatabase();

	private:

		//数据库操作类（静态单例）
		static Database* database; 

		//数据库基础操作类
		DBBase* db_base = new DBBase();

		//用户账号数据库表名
		string TABLE_USER_ACCOUNT = "user_account";
	
		//变量，标记是否已经初始化
		bool isHadInit = false;

		/*
		主要功能：
		新增数据到数据库

		入口参数
       	tabls_name： 	数据库表名
		v_key： 		插入数据的键数据
		v_value： 		插入数据的值数据

       	出口参数：
       	bool ： 		true表示成功；false表示失败
		*/
		bool insertDbAccount(string tabls_name, std::vector<string> v_key, std::vector<string> v_value);

		/*
		主要功能：
		更新数据到数据库

		入口参数
       	tabls_name： 	数据库表名
		v_key： 		插入数据的键数组
		v_value： 		插入数据的值数组
		where_key： 	执行sql条件的键数组
		where_value： 	执行sql条件的值数组

       	出口参数：
       	bool ： 		true表示成功；false表示失败
		*/
		bool updateDbAccount(string tabls_name, std::vector<string> v_key, std::vector<string> v_value, std::vector<string> where_key, std::vector<string> where_value);

		/*
		主要功能：
		新增数据到数据库

		入口参数
       	tabls_name： 	数据库表名
		*/
		void checkAndCreateTable(string tabls_name);

	};
}