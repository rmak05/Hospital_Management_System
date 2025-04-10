#pragma once

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <vector>
#include <functional>
#include "enumFuncType.h"

class MYSQLDatabase;

class MYSQLDatabase {
private:
	sql::mysql::MySQL_Driver *_driver;
	sql::Connection *_connection;
	sql::Statement *_statement;

	std::vector<std::function<std::vector<std::string>(std::vector<std::string>)>> all_functions;

	std::string quote1(std::string str);
	std::string quote2(std::string str);

	std::string get_password();
	std::vector<std::string> register_patient(std::vector<std::string>);

public:
	MYSQLDatabase();
	~MYSQLDatabase();

	std::vector<std::string> callFunction(FuncType _type, std::vector<std::string> data);
};