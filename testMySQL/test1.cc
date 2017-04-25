#include<mysql/mysql.h>
#include<iostream>
#include <string>

using namespace std;

int main()
{
	MYSQL mysql;
    mysql_init(&mysql);
    mysql_real_connect(&mysql, "localhost", "root", "root", "test",0, NULL, 0);
    string sql = "insert into t1 (id,name) values (2, 'java2'),(3, 'java3');";
	mysql_query(&mysql, sql.c_str());
	sql = "insert into student(id,name) values(1,'txh')";
	mysql_query(&mysql, sql.c_str());
	mysql_close(&mysql);

}
