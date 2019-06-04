#include "server_conf.h"
#include <stdlib.h>
#include "source/libs/json/json.h"
#include <string>
#include <iostream>
#include <fstream>
#include "../../utils/log_utils.h"

#define LOGE(msg) utils::LogUtil::LOGE(msg);
#define LOGD(msg) utils::LogUtil::LOGD(msg);

namespace manager
{

using std::cout;
using std::endl;
using std::ifstream;

ServerConfig::ServerConfig()
{
    try
    {
        getConf();
    }
    catch (const std::exception &e)
    {
        LOGE(e.what())
        exit(EXIT_FAILURE);
    }
}

void ServerConfig::getConf()
{
    ifstream ifs;
    ifs.open("source/conf/server_conf.json");
    if (!ifs.good())
    {
        LOGE("open server_conf.json error")
        exit(EXIT_FAILURE);
    }

    Json::Value root;
    Json::Reader reader;
    if (!reader.parse(ifs, root, false))
    {
        LOGE("server_conf.json reader error")
        exit(EXIT_FAILURE);
    }

    Json::FastWriter fw;
    LOGD("server_conf.json | " + fw.write(root));
    
    ServerConfig::REDIS_IP = root["REDIS_IP"].asString();
    ServerConfig::REDIS_POST = root["REDIS_POST"].asInt();
    ServerConfig::MYSQL_HOST = root["MYSQL_HOST"].asString();
    ServerConfig::MYSQL_USER = root["MYSQL_USER"].asString();
    ServerConfig::MYSQL_POST = root["MYSQL_POST"].asInt();
    ServerConfig::MYSQL_PASSWORD = root["MYSQL_PASSWORD"].asString();
    ServerConfig::MYSQL_DB_NAME = root["MYSQL_DB_NAME"].asString();
    ServerConfig::MYSQL_CHARSET = root["MYSQL_CHARSET"].asString();

    ifs.close();
}

string ServerConfig::getRedisIP()
{
    return ServerConfig::REDIS_IP;
}

int ServerConfig::getRedisPort()
{
    return ServerConfig::REDIS_POST;
}

string ServerConfig::getMySqlHost()
{
    return ServerConfig::MYSQL_HOST;
}
string ServerConfig::getMySqlUser()
{
    return ServerConfig::MYSQL_USER;
}
int ServerConfig::getMySqlPort()
{
    return ServerConfig::MYSQL_POST;
}
string ServerConfig::getMySqlPassword()
{
    return ServerConfig::MYSQL_PASSWORD;
}
string ServerConfig::getMySqlDBName()
{
    return ServerConfig::MYSQL_DB_NAME;
}
string ServerConfig::getMySqlCharset()
{
    return ServerConfig::MYSQL_CHARSET;
}

} // namespace manager