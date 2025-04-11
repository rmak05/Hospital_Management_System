#include "MYSQLDatabase.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

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
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_patient_med_data(data);
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

	std::vector<std::string> returnData = data;
	if(!returnData.empty()) returnData.pop_back();
	if(!returnData.empty()) returnData.pop_back();

	try {
		/*
		SELECT name
		FROM doctor
		NATURAL JOIN
		treated_by
		WHERE patient_id = data[0];
		*/
		std::string query;
		query = "SELECT name FROM doctor NATURAL JOIN treated_by WHERE patient_id = " + data[0] + ";";
		sql::ResultSet* res = _statement->executeQuery(query);

		if(res->next()) returnData.push_back(res->getString("name"));
		else returnData.push_back("");

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	try {
		/*
		SELECT disease_name
		FROM disease
		NATURAL JOIN
		has_disease
		WHERE patient_id = data[0];
		*/
		std::string query;
		query = "SELECT disease_name FROM disease NATURAL JOIN has_disease WHERE patient_id = " + data[0] + ";";
		sql::ResultSet* res = _statement->executeQuery(query);

		if(res->next()) returnData.push_back(res->getString("disease_name"));
		else returnData.push_back("");

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	try {
		/*
		SELECT room_id
		FROM room
		NATURAL JOIN
		is_admitted
		WHERE patient_id = data[0];
		*/
		std::string query;
		query = "SELECT room_id FROM room NATURAL JOIN is_admitted WHERE patient_id = " + data[0] + ";";
		sql::ResultSet* res = _statement->executeQuery(query);

		if(res->next()) returnData.push_back(res->getString("room_id"));
		else returnData.push_back("");

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	returnData.push_back("1");
	return returnData;

	//return { "0" };
}

std::vector<std::string> MYSQLDatabase::update_patient(std::vector<std::string> data) {
	try {
		std::string query;
		query = "UPDATE patient SET name = " + quote1(data[1]) + ", age = " + data[2] + ", gender = " + quote1(data[3]) + ", phone = " + data[4] + ", address = " + quote1(data[5]) + ", email = " + quote1(data[6]) + "WHERE patient_id = " + data[0] + ";";
		_statement->execute(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	std::vector<std::string> returnData = data;
	if(!returnData.empty()) returnData.pop_back();
	if(!returnData.empty()) returnData.pop_back();

	try {
		/*
		SELECT name
		FROM doctor
		NATURAL JOIN
		treated_by
		WHERE patient_id = data[0];
		*/
		std::string query;
		query = "SELECT name FROM doctor NATURAL JOIN treated_by WHERE patient_id = " + data[0] + ";";
		sql::ResultSet* res = _statement->executeQuery(query);

		if(res->next()) returnData.push_back(res->getString("name"));
		else returnData.push_back("");

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	try {
		/*
		SELECT disease_name
		FROM disease
		NATURAL JOIN
		has_disease
		WHERE patient_id = data[0];
		*/
		std::string query;
		query = "SELECT disease_name FROM disease NATURAL JOIN has_disease WHERE patient_id = " + data[0] + ";";
		sql::ResultSet* res = _statement->executeQuery(query);

		if(res->next()) returnData.push_back(res->getString("disease_name"));
		else returnData.push_back("");

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	try {
		/*
		SELECT room_id
		FROM room
		NATURAL JOIN
		is_admitted
		WHERE patient_id = data[0];
		*/
		std::string query;
		query = "SELECT room_id FROM room NATURAL JOIN is_admitted WHERE patient_id = " + data[0] + ";";
		sql::ResultSet* res = _statement->executeQuery(query);

		if(res->next()) returnData.push_back(res->getString("room_id"));
		else returnData.push_back("");

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	returnData.push_back("1");
	return returnData;
	//return { "0" };
}

std::vector<std::string> MYSQLDatabase::get_patient_data(std::vector<std::string> data) {
	try {
		//std::cout << data[0] << "\n";
		std::string selectDataSQL = "SELECT * FROM patient WHERE patient_id = " + data[0] + ";";
		sql::ResultSet* res = _statement->executeQuery(selectDataSQL);

		std::vector<std::string> returnData;
		if (res->next()) {
			returnData.push_back(res->getString("patient_id"));
			returnData.push_back(res->getString("name"));
			returnData.push_back(res->getString("age"));
			returnData.push_back(res->getString("gender"));
			returnData.push_back(res->getString("phone"));
			returnData.push_back(res->getString("address"));
			returnData.push_back(res->getString("email"));
		}
		//res->next();

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

std::vector<std::string> MYSQLDatabase::get_patient_med_data(std::vector<std::string> data) {
	data = get_patient_data(data);

	std::vector<std::string> returnData = data;
	if(!returnData.empty()) returnData.pop_back();
	if(!returnData.empty()) returnData.pop_back();
	if(!returnData.empty()) returnData.pop_back();

	try {
		/*
		SELECT name
		FROM doctor
		NATURAL JOIN
		treated_by
		WHERE patient_id = data[0];
		*/
		std::string query;
		query = "SELECT name FROM doctor NATURAL JOIN treated_by WHERE patient_id = " + data[0] + ";";
		sql::ResultSet* res = _statement->executeQuery(query);

		if(res->next()) returnData.push_back(res->getString("name"));
		else returnData.push_back("");

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	try {
		/*
		SELECT disease_name
		FROM disease
		NATURAL JOIN
		has_disease
		WHERE patient_id = data[0];
		*/
		std::string query;
		query = "SELECT disease_name FROM disease NATURAL JOIN has_disease WHERE patient_id = " + data[0] + ";";
		sql::ResultSet* res = _statement->executeQuery(query);

		if(res->next()) returnData.push_back(res->getString("disease_name"));
		else returnData.push_back("");

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	try {
		/*
		SELECT room_id
		FROM room
		NATURAL JOIN
		is_admitted
		WHERE patient_id = data[0];
		*/
		std::string query;
		query = "SELECT room_id FROM room NATURAL JOIN is_admitted WHERE patient_id = " + data[0] + ";";
		sql::ResultSet* res = _statement->executeQuery(query);

		if(res->next()) returnData.push_back(res->getString("room_id"));
		else returnData.push_back("");

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::generate_patient_id(std::vector<std::string>) {
	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::time_t timestamp = std::time(NULL);
	std::tm *curr_time = std::localtime(&timestamp);

	int patient_id = ((curr_time->tm_year + 1900) * 100000) + (curr_time->tm_hour * 3600) + (curr_time->tm_min * 60) + (curr_time->tm_sec);

	return {std::to_string(patient_id), "1"};
}