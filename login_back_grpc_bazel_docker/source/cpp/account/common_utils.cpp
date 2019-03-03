//
// Created by melon on 2019/2/28.
//
#include <exception> 

#include "common_utils.h"

#include <time.h>
#include <random>
#include <sstream>
#include <iostream>
#include <string.h>

using namespace utils;
using namespace std;

unsigned char* CommonUtils::AES_KEY = (unsigned char *) "$L&^E*Usd9k!Ld4%"; // token30天有效时间

AesEncryptor* CommonUtils::aesEncryptor = new AesEncryptor(CommonUtils::AES_KEY);

const long CommonUtils::TOKEN_TIMEOUT = 3600L * 24 * 30; // token30天有效时间




string CommonUtils::GenToken(const unsigned long uid, const string account){
    time_t startTime = time(NULL);
    time_t endTime = startTime + TOKEN_TIMEOUT;
    string randomNumStr = GenRandomStr();

    const int bufSize = 128;
    char tokenChar[bufSize];
    snprintf(tokenChar,bufSize,"%lu:%s:%s:%lu:%lu",uid,account.c_str(),randomNumStr.c_str(),startTime,endTime);
    string tokenAes = aesEncryptor->EncryptString(tokenChar);
    return tokenAes;
}

string CommonUtils::DecryptToken(string token){
    return aesEncryptor->DecryptString(token);
}

/**
 * 生成6位随机数
 */
string CommonUtils::GenRandomStr(){
    int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 9; i > 0; i--) {
        default_random_engine e;
        uniform_int_distribution<unsigned> u(0, i); //随机数分布对象
        int index = u(e);
        int tmp = array[index];
        array[index] = array[i - 1];
        array[i - 1] = tmp;
    }

    stringstream strStream;

    for (int i = 0; i < 6; i++)
        strStream << array[i];

    return strStream.str();
}

void CommonUtils::SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c) {
            std::string::size_type pos1, pos2;
            pos2 = s.find(c);
            pos1 = 0;
            while(std::string::npos != pos2)
            {
                v.push_back(s.substr(pos1, pos2-pos1));

                pos1 = pos2 + c.size();
                pos2 = s.find(c, pos1);
            }
            if(pos1 != s.length())
                v.push_back(s.substr(pos1));
}

string CommonUtils::EncryptPwd(string account, string password){
    if (account.empty() || password.empty()) {
        return "";
    }
    try {      
        
        cout << "info : encryt ac`" << account << " psd`" << password << endl;
	    //用sha256对account进行消息摘要，目的是给password加盐
        std::string sha256_account;
        picosha2::hash256_hex_string(account.c_str(), sha256_account);
        cout << "info : sha256 " << sha256_account << endl;

        //获取加密前password字符数组
        const char* c_password = password.c_str();

        //合并salt到password字符数组
        size_t length = strlen(sha256_account) + strlen(c_password);
        cout << "info :  digest length " << length << endl;
        char c_source[length];
        snprintf(c_source, sizeof(c_source), "%s%s", sha256_account, c_password);
        cout << "info :  digest " << c_source << endl;

        //对字符数组进行MD5计算
        MD5 md5(c_source, length);
        string result = md5.toString();
    	cout << "info : md5 " << result << endl;
    	return result;
    } catch (exception& e) {  
        cout << "error : " << e.what() << endl;
        return "";
    }
}
