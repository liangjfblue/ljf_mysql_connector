#include "TinyDB.h"

const char *g_host_name = "192.168.153.129";
const char *g_user_name = "root";
const char *g_password = "qwe123";
const char *g_db_name = "mytest";
const unsigned int g_db_port = 3306;

const char *g_query_sql = "select * from kaifa";
const char *g_insert_sql = "insert into kaifa(name, phone) values('test', 8888888)";

int main(int argc, char const *argv[])
{
	TinyDB *tiny_db = new TinyDB();

	tiny_db->InitDB(g_host_name, g_user_name, g_password, g_db_name, g_db_port);

	tiny_db->InsertDelUpdateSQL(g_insert_sql);
	tiny_db->QuerySQL(g_query_sql);

	delete tiny_db;

	return 0;
}
