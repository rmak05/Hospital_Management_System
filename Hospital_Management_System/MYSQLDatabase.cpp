#include "MYSQLDatabase.h"
#include <iostream>
#include <fstream>

MYSQLDatabase::MYSQLDatabase() {
	try {
		_driver = sql::mysql::get_mysql_driver_instance();
		_connection = _driver->connect("tcp://localhost:3306", "root", get_password());
		_connection->setSchema("Hospital_Management");
		_statement = _connection->createStatement();
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
	}

	all_functions.push_back([this](std::vector<std::string> data) { 
		return this->register_patient(data);
    });
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->update_patient(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_patient_data(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->generate_patient_id(data);
	});
}

MYSQLDatabase::~MYSQLDatabase() {
    delete _statement;
    delete _connection;
}

std::string MYSQLDatabase::quote1(std::string str) {
	return (std::string("'") + str + std::string("'"));
}

std::string MYSQLDatabase::quote2(std::string str) {
	return (std::string("\"") + str + std::string("\""));
}

std::string MYSQLDatabase::get_password() {
	std::ifstream password_file;
	password_file.open("password.txt", std::ios::in);

	std::string password;
	std::getline(password_file, password);

	password_file.close();

	return password;
}

std::vector<std::string> MYSQLDatabase::callFunction(FuncType _type, std::vector<std::string> data) {
    if(_type == FuncType::_default) return { "0" };
	
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
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	return { "0" };
}

std::vector<std::string> MYSQLDatabase::update_patient(std::vector<std::string> data) {
	try {
		std::string query, data_string;
		query = "UPDATE patient SET name = " + quote1(data[1]) + ", age = " + data[2] + ", gender = " + quote1(data[3]) + ", phone = " + data[4] + ", address = " + quote1(data[5]) + ", email = " + quote1(data[6]) + "WHERE patient_id = " + data[0] + ";";
		_statement->execute(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	return { "0" };
}

std::vector<std::string> MYSQLDatabase::get_patient_data(std::vector<std::string> data) {
	try {
		std::cout << data[0] << "\n";
		std::string selectDataSQL = "SELECT * FROM patient WHERE patient_id = " + data[0] + ";";
		sql::ResultSet* res = _statement->executeQuery(selectDataSQL);

		res->next();

		std::vector<std::string> returnData;
		returnData.push_back((res->getString("patient_id")));;
		returnData.push_back(res->getString("name"));
		returnData.push_back(res->getString("age"));
		returnData.push_back(res->getString("gender"));
		returnData.push_back(res->getString("phone"));
		returnData.push_back(res->getString("address"));
		returnData.push_back(res->getString("email"));

		delete res;

		returnData.push_back("1");
		return returnData;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}
	return { "-1" };
}

std::vector<std::string> MYSQLDatabase::generate_patient_id(std::vector<std::string>) {
	int num = rand() % 100000;
	std::string _id = "";
	while (num > 0) {
		_id.push_back((num % 10) + '0');
		num /= 10;
	}
	return { _id, "1"};
}