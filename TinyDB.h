#ifndef __TINYDB_H__
#define __TINYDB_H__
#include <iostream>
#include <string>
#include <mysql/mysql.h>

#define MAX_BUF_SIZE 1024 // 缓冲区最大字节数

class TinyDB
{
public:
	TinyDB();
	~TinyDB();
	
	bool InitDB(const char *host, const char *user, const char *pwd, const char *db_name, const unsigned int port);
    //bool ExeSQL(const char *sql);

    bool QuerySQL(const char *sql);
    bool InsertDelUpdateSQL(const char *sql);

private:
	MYSQL *m_mysql;          //连接mysql句柄指针
    //MYSQL_RES *m_result;    //指向查询结果的指针
    //MYSQL_ROW m_row;       //按行返回的查询信息
};



#endif