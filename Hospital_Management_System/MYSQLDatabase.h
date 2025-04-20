#pragma once

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <vector>
#include <string>
#include <functional>
#include <fstream>
#include <random>
#include "enumFuncType.h"

class MYSQLDatabase;

class MYSQLDatabase {
private:
	sql::mysql::MySQL_Driver *_driver;
	sql::Connection *_connection;
	sql::Statement *_statement;

	std::vector<std::function<std::vector<std::string>(std::vector<std::string>)>> all_functions;

	std::mt19937 rand_gen;
	std::uniform_int_distribution<> uni_7_digit_gen;
	std::uniform_int_distribution<> uni_3_digit_gen;
	std::ofstream query_file;

	bool execute(std::string query);
	sql::ResultSet* executeQuery(std::string query);

	std::string quote1(std::string str);
	std::string quote2(std::string str);

	std::string get_password();
	std::vector<std::string> register_patient(std::vector<std::string>);
	std::vector<std::string> update_patient(std::vector<std::string>);
	std::vector<std::string> get_patient_data(std::vector<std::string>);
	std::vector<std::string> generate_patient_id(std::vector<std::string>);
	std::vector<std::string> get_patient_med_data(std::vector<std::string> data);
	std::vector<std::string> get_patient_tests(std::vector<std::string> data);
	std::vector<std::string> get_test_data(std::vector<std::string> data);
	std::vector<std::string> push_test_data(std::vector<std::string> data);
	std::vector<std::string> get_appointment_data(std::vector<std::string> data);
	std::vector<std::string> check_doctor_id(std::vector<std::string> data);
	std::vector<std::string> get_appointment_patient_data(std::vector<std::string> data);
	std::string generate_test_id();
	std::vector<std::string> get_meeting_data(std::vector<std::string> data);
	std::vector<std::string> push_presc(std::vector<std::string> data);
	std::vector<std::string> push_tests(std::vector<std::string> data);
	std::vector<std::string> admit_patient(std::vector<std::string> data);
	std::vector<std::string> appointment_done(std::vector<std::string> data);
	std::vector<std::string> get_patient_record(std::vector<std::string> data);
	std::vector<std::string> get_test_history(std::vector<std::string> data);
	std::vector<std::string> get_complete_test_data(std::vector<std::string> data);
	std::vector<std::string> get_appointment_history(std::vector<std::string> data);
	std::vector<std::string> get_presc_data(std::vector<std::string> data);
	std::vector<std::string> get_patient_information(std::vector<std::string> data);
	std::vector<std::string> get_doctor_data(std::vector<std::string> data);
	std::vector<std::string> get_admit_request(std::vector<std::string> data);
	std::vector<std::string> get_room_data(std::vector<std::string> data);
	std::vector<std::string> get_room_patient_id(std::vector<std::string> data);
	std::vector<std::string> frontdesk_admit_patient(std::vector<std::string> data);
	std::vector<std::string> get_discharge_details(std::vector<std::string> data);
	std::vector<std::string> frontdesk_discharge_patient(std::vector<std::string> data);
	std::vector<std::string> get_admit_history(std::vector<std::string> data);
	std::vector<std::string> get_doctor_speciality(std::vector<std::string> data);
	int get_hour(std::string& _time);
	std::vector<std::string> get_appointment_slots(std::vector<std::string> data);
	std::vector<std::string> confirm_appointment(std::vector<std::string> data);
	std::string generate_appointment_id();
	std::vector<std::string> add_appointment(std::vector<std::string> data);
	std::vector<std::string> get_schedule_test(std::vector<std::string> data);
	std::vector<std::string> get_test_slots(std::vector<std::string> data);
	std::vector<std::string> confirm_test(std::vector<std::string> data);
	std::vector<std::string> add_test(std::vector<std::string> data);
	std::string generate_doctor_id();
	std::vector<std::string> get_doctor_id(std::vector<std::string> data);
	std::vector<std::string> add_doctor(std::vector<std::string> data);
	std::vector<std::string> delete_doctor(std::vector<std::string> data);
	std::vector<std::string> get_doctor_details(std::vector<std::string> data);
	std::vector<std::string> update_doctor(std::vector<std::string> data);
	std::vector<std::string> view_doctor(std::vector<std::string> data);

public:
	MYSQLDatabase();
	~MYSQLDatabase();

	std::vector<std::string> callFunction(FuncType _type, std::vector<std::string> data);
};