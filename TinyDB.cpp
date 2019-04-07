#include "TinyDB.h"
#include <string>
#include <cstring>

TinyDB::TinyDB()
{
	m_mysql = mysql_init(NULL);
	if(m_mysql==NULL)
    {
        std::cout << "Init Error:" << mysql_error(m_mysql) << std::endl;
        exit(-1);
    }
    mysql_query(m_mysql,"set kaifa utf-8");
}

TinyDB::~TinyDB()
{
	if(m_mysql!=NULL)
    {
        mysql_close(m_mysql);
        mysql_library_end();
    }
}

bool TinyDB::InitDB(const char *host, const char *user, const char *pwd, const char *db_name, const unsigned int port)
{
    if(!mysql_real_connect(m_mysql, host, user, pwd, db_name, port, NULL, 0))
    {
    	std::cout << "Connect Error: " << mysql_error(m_mysql) << std::endl;
        return false;
    }

    return true;
}

bool TinyDB::QuerySQL(const char *sql)
{
	if (mysql_real_query(m_mysql, sql, strlen(sql)))
	{
	    std::cout << "Query Error: " << mysql_error(m_mysql) << std::endl;
	    return false;
    }

    MYSQL_RES *result;    //指向查询结果的指针
	MYSQL_ROW rows;       //按行返回的查询信息

    result = mysql_store_result(m_mysql);
    if(result!=NULL)
    {
        std::cout << "id\tname\tphone" << std::endl; 
    	while ((rows=mysql_fetch_row(result))) 
			std::cout << rows[0] << "\t" << rows[1] << "\t" << rows[2] << std::endl;

		mysql_free_result(result); // 释放结果集
    }


	return true;
}

bool TinyDB::InsertDelUpdateSQL(const char *sql)
{
	if (mysql_real_query(m_mysql, sql, strlen(sql)))
	{
	    std::cout << "InsertDelUpdateSQL Error: " << mysql_error(m_mysql) << std::endl;
	    return false;
    }

    if(mysql_field_count(m_mysql) == 0)
    {
        int num_rows = mysql_affected_rows(m_mysql);
        std::cout << "InsertDelUpdateSQL OK, effect num_rows: " << num_rows << std::endl;
    }
}

