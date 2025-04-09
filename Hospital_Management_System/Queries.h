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

class FunctionHolder {
private:
	std::vector<std::function<std::vector<std::string>(std::vector<std::string>)>> funcs;

public:
	FunctionHolder();

	std::vector<std::string> callFunction(FuncType _type, std::vector<std::string> data);
	std::vector<std::string> register_patient(std::vector<std::string>);
};