#include "MYSQLDatabase.h"
#include <iostream>
#include <fstream>

MYSQLDatabase::MYSQLDatabase() {
	try {
		_driver = sql::mysql::get_mysql_driver_instance();
		_connection = _driver->connect("tcp://localhost:3306", "root", get_password());
		_connection->setSchema("hospital_management");
		_statement = _connection->createStatement();
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
	}

	all_functions.push_back([this](std::vector<std::string> data) { 
    return this->register_patient(data);
    });
}

MYSQLDatabase::~MYSQLDatabase() {
    delete _statement;
    delete _connection;
}

std::string MYSQLDatabase::quote1(std::string str) {
	return std::string("'") + str + std::string("'");
}

std::string MYSQLDatabase::quote2(std::string str) {
	return std::string("\"") + str + std::string("\"");
}

std::string MYSQLDatabase::get_password() {
	std::ifstream password_file;
	password_file.open("password.txt", std::ios::in);

	std::string password;
	std::getline(password_file, password);

	return password;
}

std::vector<std::string> MYSQLDatabase::callFunction(FuncType _type, std::vector<std::string> data) {
    if(_type == FuncType::_default) return { "-1" };
	
	int ind = int(_type);
    if (ind < 0) return { "-1" };
    if (ind >= all_functions.size()) return { "-1" };
    return all_functions[static_cast<int>(_type)](data);
}

std::vector<std::string> MYSQLDatabase::register_patient(std::vector<std::string> data) {
	try {
		std::string query, data_string;

		query = std::string("INSERT INTO patient VALUES (") + data[0] + ", " + quote1(data[1]) + ", " + data[2] + ", " + quote1(data[3]) + ", " + data[4] + ", " + quote1(data[5]) + ", " + quote1(data[6]) + ");";

		_statement->execute(query);

		/*std::string selectDataSQL = "SELECT * FROM patient";
		sql::ResultSet* res = _statement->executeQuery(selectDataSQL);

		int count = 0;
		while (res->next()) {
			std::cout << " Name " << ++count << ": "
				<< res->getString("name") << std::endl;
		}

		delete res;*/
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
	}

	return { "0" };
}