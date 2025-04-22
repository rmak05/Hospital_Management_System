#include "MYSQLDatabase.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <set>

MYSQLDatabase::MYSQLDatabase() {
	rand_gen = std::mt19937((unsigned)std::chrono::steady_clock::now().time_since_epoch().count());
	uni_7_digit_gen = std::uniform_int_distribution<>(1000000, 9999999);
	uni_3_digit_gen = std::uniform_int_distribution<>(100, 999);

	query_file.open("Queries/live_queries.sql", std::ios::out);

	try {
		_driver = sql::mysql::get_mysql_driver_instance();
		_connection = _driver->connect("tcp://localhost:3306", "root", get_password());
		_connection->setSchema("Hospital_Management");
		_statement = _connection->createStatement();

	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		exit(EXIT_FAILURE);
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
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_patient_tests(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_test_data(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->push_test_data(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_appointment_data(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->check_doctor_id(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_appointment_patient_data(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_meeting_data(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->push_presc(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->push_tests(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->admit_patient(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->appointment_done(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_patient_record(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_test_history(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_complete_test_data(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_appointment_history(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_presc_data(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_patient_information(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_doctor_data(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_admit_request(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_room_data(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_room_patient_id(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->frontdesk_admit_patient(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_discharge_details(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->frontdesk_discharge_patient(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_admit_history(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_doctor_speciality(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_appointment_slots(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->confirm_appointment(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->add_appointment(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_schedule_test(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_test_slots(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->confirm_test(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->add_test(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_doctor_id(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->add_doctor(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->delete_doctor(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->get_doctor_details(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->update_doctor(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->view_doctor(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->check_frontdesk_login(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->check_dataentry_login(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->check_doctor_login(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->check_admin_login(data);
	});
	all_functions.push_back([this](std::vector<std::string> data) {
		return this->view_patient(data);
	});
}

MYSQLDatabase::~MYSQLDatabase() {
	delete _statement;
	delete _connection;

	query_file.close();
}

bool MYSQLDatabase::execute(std::string query) {
	query_file << query << std::endl << std::endl << std::endl;

	return _statement->execute(query);
}

sql::ResultSet* MYSQLDatabase::executeQuery(std::string query) {
	query_file << query << std::endl << std::endl << std::endl;

	return _statement->executeQuery(query);
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
		/* 
		INSERT INTO patient VALUES
		(1, 'Alice Smith', 30, 'F', 9876543210, '123 Park St, Cityville', 'alice@example.com'),
		(2, 'Bob Johnson', 45, 'M', 9876543211, '456 Lake Rd, Townville', 'bob@example.com');
		*/
		std::string query, data_string;
		query = std::string("INSERT INTO patient VALUES \n(") + data[0] + ", " + quote1(data[1]) + ", " + data[2] + ", " + quote1(data[3]) + ", " + data[4] + ", " + quote1(data[5]) + ", " + quote1(data[6]) + ");";
		execute(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	std::vector<std::string> returnData = data;
	if(!returnData.empty()) returnData.pop_back();
	if(!returnData.empty()) returnData.pop_back();
	returnData.push_back("");
	returnData.push_back("");
	returnData.push_back("");

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::update_patient(std::vector<std::string> data) {
	try {
		/*
		UPDATE patient
		SET name = , age = , ..
		WHERE patient_id = data[0];
		*/
		std::string query;
		query = "UPDATE patient \nSET name = " + quote1(data[1]) + ", age = " + data[2] + ", gender = " + quote1(data[3]) + ", phone = " + data[4] + ", address = " + quote1(data[5]) + ", email = " + quote1(data[6]) + "\nWHERE patient_id = " + data[0] + ";";
		execute(query);
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
		SELECT name, room_id, disease_name
		FROM doctor
		INNER JOIN treated_by
		ON doctor.doctor_id = treated_by.doctor_id
		INNER JOIN is_admitted
		ON treated_by.patient_id = is_admitted.patient_id
		WHERE treated_by.patient_id = 1 AND is_currently = 1 AND is_admit = 1 AND is_scheduled = 1;
		*/

		std::string query;
		query = "SELECT name, room_id, disease_name \nFROM doctor \nINNER JOIN treated_by \nON doctor.doctor_id = treated_by.doctor_id \nINNER JOIN is_admitted \nON treated_by.patient_id = is_admitted.patient_id "
			"\nWHERE treated_by.patient_id = " + data[0] + " AND is_currently = 1 AND is_admit = 1 AND is_scheduled = 1;";

		sql::ResultSet* res = executeQuery(query);
		if (res->next()) {
			returnData.push_back(res->getString("name"));
			returnData.push_back(res->getString("room_id"));
			returnData.push_back(res->getString("disease_name"));
		}
		else {
			returnData.push_back("");
			returnData.push_back("");
			returnData.push_back("");
		}
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::get_patient_data(std::vector<std::string> data) {
	try {
		/*
		SELECT * 
		FROM patient 
		WHERE patient_id = data[0];
		*/
		std::string selectDataSQL = "SELECT * \nFROM patient \nWHERE patient_id = " + data[0] + ";";
		sql::ResultSet* res = executeQuery(selectDataSQL);

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

		if(returnData.size() == 0) return {"-1"};

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
	int patient_id;
	bool found = false;

	while (!found) {
		patient_id = uni_7_digit_gen(rand_gen);
		try {
			/*
			SELECT patient_id
			FROM patient
			WHERE patient_id = patient_id;
			*/
			std::string query;
			query = "SELECT patient_id \nFROM patient \nWHERE patient_id = " + std::to_string(patient_id) + ";";
			sql::ResultSet* res = executeQuery(query);

			if (!(res->next())) {
				found = true;
			}

			delete res;
		}
		catch (sql::SQLException& e) {
			std::cerr << "SQL Error : " << e.what() << std::endl;
			return { "-1" };
		}
	}

	return {std::to_string(patient_id), "1"};

	/*std::time_t timestamp = std::time(NULL);
	std::tm *curr_time = std::localtime(&timestamp);

	int patient_id = ((curr_time->tm_year + 1900) * 100000) + (curr_time->tm_hour * 3600) + (curr_time->tm_min * 60) + (curr_time->tm_sec);

	return {std::to_string(patient_id), "1"};*/
}

std::vector<std::string> MYSQLDatabase::get_patient_med_data(std::vector<std::string> data) {
	data = get_patient_data(data);

	if(data.size() == 1) return {"-1"};

	std::vector<std::string> returnData = data;
	if(!returnData.empty()) returnData.pop_back();
	if(!returnData.empty()) returnData.pop_back();
	if(!returnData.empty()) returnData.pop_back();

	try {
		/*
		SELECT name, room_id, disease_name
		FROM doctor
		INNER JOIN treated_by
		ON doctor.doctor_id = treated_by.doctor_id
		INNER JOIN is_admitted
		ON treated_by.patient_id = is_admitted.patient_id
		WHERE treated_by.patient_id = 1 AND is_currently = 1 AND is_admit = 1 AND is_scheduled = 1;
		*/

		std::string query;
		query = "SELECT name, room_id, disease_name \nFROM doctor \nINNER JOIN treated_by \nON doctor.doctor_id = treated_by.doctor_id \nINNER JOIN is_admitted \nON treated_by.patient_id = is_admitted.patient_id "
			"\nWHERE treated_by.patient_id = " + data[0] + " AND is_currently = 1 AND is_admit = 1 AND is_scheduled = 1;";

		sql::ResultSet* res = executeQuery(query);
		if (res->next()) {
			returnData.push_back(res->getString("name"));
			returnData.push_back(res->getString("room_id"));
			returnData.push_back(res->getString("disease_name"));
		}
		else {
			returnData.push_back("");
			returnData.push_back("");
			returnData.push_back("");
		}
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::get_patient_tests(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	try {
		/*
		SELECT test_id, doctor_id, date, time, room_id
		FROM test
		WHERE patient_id = data[0] and is_scheduled = 1 and is_pending = 1;
		*/
		std::string query;
		query = "SELECT test_id, doctor_id, date, time, room_id \nFROM test \nWHERE patient_id = " + data[0] + " and is_scheduled = 1 and is_pending = 1;";
		sql::ResultSet* res = executeQuery(query);

		while (res->next()) {
			returnData.push_back(res->getString("test_id"));
			returnData.push_back(res->getString("doctor_id"));
			returnData.push_back(res->getString("date"));
			returnData.push_back(res->getString("time"));
			returnData.push_back(res->getString("room_id"));
			returnData.push_back("#");
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	//if(returnData.empty()) return {"-1"};

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::get_test_data(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	try {
		/*
		SELECT *
		FROM test
		WHERE test_id = data[0];
		*/
		std::string query;
		query = "SELECT * \nFROM test \nWHERE test_id = " + data[0] + ";";
		sql::ResultSet* res = executeQuery(query);

		if (res->next()) {
			returnData.push_back(res->getString("test_id"));
			returnData.push_back(res->getString("patient_id"));
			returnData.push_back(res->getString("doctor_id"));
			returnData.push_back(res->getString("room_id"));
			returnData.push_back(res->getString("equipment_name"));
			returnData.push_back(res->getString("test"));
			returnData.push_back(res->getString("date"));
			returnData.push_back(res->getString("time"));
			returnData.push_back("");
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	if(returnData.empty()) return {"-1"};

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::push_test_data(std::vector<std::string> data) {
	try {
		/*
		UPDATE test 
		SET results = data[1], is_pending = 0
		WHERE test_id = data[0];
		*/
		std::string query;
		query = "UPDATE test \nSET results = " + quote1(data[1]) + ", is_pending = 0 \nWHERE test_id = " + data[0] + ";";
		execute(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}
	return { "0" };
}

std::vector<std::string> MYSQLDatabase::get_appointment_data(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	try {
		/*
		SELECT appointment_id, patient_id, date, time
		FROM appointment
		WHERE doctor_id = data[0] AND is_pending = 1;
		*/
		std::string query;
		query = "SELECT appointment_id, patient_id, date, time \nFROM appointment \nWHERE doctor_id = " + data[0] + " AND is_pending = 1;";
		sql::ResultSet* res = executeQuery(query);

		while (res->next()) {
			returnData.push_back(res->getString("appointment_id"));
			returnData.push_back(res->getString("patient_id"));
			returnData.push_back(res->getString("date"));
			returnData.push_back(res->getString("time"));
			returnData.push_back("#");
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	//if(returnData.empty()) return {"-1"};

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::check_doctor_id(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	try {
		/*
		SELECT doctor_id
		FROM doctor
		WHERE doctor_id = data[0];
		*/
		std::string query;
		query = "SELECT doctor_id \nFROM doctor \nWHERE doctor_id = " + data[0] + ";";
		sql::ResultSet* res = executeQuery(query);

		if (res->next()) {
			returnData.push_back(res->getString("doctor_id"));
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	if(returnData.empty()) return {"-1"};

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::get_appointment_patient_data(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	returnData.push_back(data[0]);
	std::vector<std::string> temp = get_patient_data({data[1]});
	for(auto itr : temp) returnData.push_back(itr);

	return returnData;
}

std::string  MYSQLDatabase::generate_test_id() {
	int test_id;
	bool found = false;

	while (!found) {
		test_id = uni_7_digit_gen(rand_gen);
		try {
			/*
			SELECT test_id
			FROM test
			WHERE test_id = test_id;
			*/
			std::string query;
			query = "SELECT test_id \nFROM test \nWHERE test_id = " + std::to_string(test_id) + ";";
			sql::ResultSet* res = executeQuery(query);

			if (!(res->next())) {
				found = true;
			}

			delete res;
		}
		catch (sql::SQLException& e) {
			std::cerr << "SQL Error : " << e.what() << std::endl;
			return { "-1" };
		}
	}

	return std::to_string(test_id);
}


std::vector<std::string> MYSQLDatabase::get_meeting_data(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	try {
		/*
		SELECT appointment_id, patient_id, doctor_id
		FROM appointment
		WHERE appointment_id = data[0];
		*/
		std::string query;
		query = "SELECT appointment_id, patient_id, doctor_id \nFROM appointment \nWHERE appointment_id = " + data[0] + ";";
		sql::ResultSet* res = executeQuery(query);

		if (res->next()) {
			returnData.push_back(res->getString("appointment_id"));
			returnData.push_back(res->getString("patient_id"));
			returnData.push_back(res->getString("doctor_id"));
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	returnData.push_back(generate_test_id());
	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::push_presc(std::vector<std::string> data) {
	try {
		/*
		INSERT INTO prescripton VALUES
		(1, 'Pneumonia', 'Cough, Fever, Breathlessness', 'Azithromycin', 'Take 500mg daily for 5 days');
		*/
		std::string query, data_string;
		query = std::string("INSERT INTO prescription VALUES \n(") + data[0] + ", " + quote1(data[1]) + ", " + quote1(data[2]) + ", " + quote1(data[3]) + ", " + quote1(data[4]) + ");";
		execute(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	return { "0" };
}

std::vector<std::string> MYSQLDatabase::push_tests(std::vector<std::string> data) {
	try {
		/*
		INSERT INTO test VALUES
		(16, 1, 101, 'R201', 'Blood Test', 'Glucometer', NULL, NULL, NULL, 0, 1);
		*/
		std::string query, data_string;
		query = std::string("INSERT INTO test VALUES \n(") + data[0] + ", " + data[1] + ", " + data[2] + ", " + quote1(data[4]) + ", " + quote1(data[3]) + ", " + quote1(data[5]) + ", NULL, NULL, NULL, 0, 1);";
		execute(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	return { "0" };
}

std::vector<std::string> MYSQLDatabase::admit_patient(std::vector<std::string> data) {
	try {
		/*
		INSERT INTO is_admitted VALUES
		(2, NULL, NULL, NULL, NULL, NULL, 'Appendicitis',0,1);
		*/
		std::string query, data_string;
		query = std::string("INSERT INTO is_admitted VALUES \n(") + data[0] + ", NULL, NULL, NULL, NULL, NULL, " + quote1(data[2]) + ", 0, 1);";
		execute(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	try {
		/*
		INSERT INTO treated_by VALUES
		(1, 101, 1);
		*/
		std::string query, data_string;
		query = std::string("INSERT INTO treated_by VALUES \n(") + data[0] + ", " + data[1] + ", 1);";
		execute(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	return { "0" };
}

std::vector<std::string> MYSQLDatabase::appointment_done(std::vector<std::string> data) {
	try {
		/*
		UPDATE appointment 
		SET is_pending = 0
		WHERE appointment_id = data[0];
		*/
		std::string query;
		query = "UPDATE appointment \nSET is_pending = 0 \nWHERE appointment_id = " + data[0] + ";";
		execute(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	return { "0" };
}

std::vector<std::string> MYSQLDatabase::get_patient_record(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	//returnData.push_back(data[0]);

	try {
		/*
		SELECT patient_id, patient.name AS patient_name, room_id, disease_name
		FROM patient
		NATURAL JOIN treated_by
		NATURAL JOIN is_admitted
		WHERE doctor_id = data[0] AND is_admit = 1;
		*/
		std::string query;
		query = "SELECT patient_id, patient.name AS patient_name, room_id, disease_name \nFROM patient \nNATURAL JOIN treated_by \nNATURAL JOIN is_admitted \nWHERE doctor_id = " + data[0] + " AND is_admit = 1;";
		sql::ResultSet* res = executeQuery(query);

		while (res->next()) {
			returnData.push_back(res->getString("patient_id"));
			returnData.push_back(res->getString("patient_name"));
			returnData.push_back(res->getString("room_id"));
			returnData.push_back(res->getString("disease_name"));
			returnData.push_back("#");
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::get_test_history(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	try {
		/*
		SELECT test_id, test, room_id, date, time
		FROM test
		WHERE patient_id = data[0] AND is_pending = 0 AND is_scheduled = 1;
		*/
		std::string query;
		query = "SELECT test_id, test, room_id, date, time \nFROM test \nWHERE patient_id = " + data[0] + " AND is_pending = 0 AND is_scheduled = 1;";
		sql::ResultSet* res = executeQuery(query);

		while (res->next()) {
			returnData.push_back(res->getString("test_id"));
			returnData.push_back(res->getString("test"));
			returnData.push_back(res->getString("room_id"));
			returnData.push_back(res->getString("date"));
			returnData.push_back(res->getString("time"));
			returnData.push_back("#");
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	//if(returnData.empty()) return {"-1"};

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::get_complete_test_data(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	try {
		/*
		SELECT *
		FROM test
		WHERE test_id = data[0];
		*/
		std::string query;
		query = "SELECT * \nFROM test \nWHERE test_id = " + data[0] + ";";
		sql::ResultSet* res = executeQuery(query);

		if (res->next()) {
			returnData.push_back(res->getString("test_id"));
			returnData.push_back(res->getString("test"));
			returnData.push_back(res->getString("patient_id"));
			returnData.push_back(res->getString("doctor_id"));
			returnData.push_back(res->getString("room_id"));
			returnData.push_back(res->getString("equipment_name"));
			returnData.push_back(res->getString("date"));
			returnData.push_back(res->getString("time"));
			returnData.push_back(res->getString("results"));
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	if(returnData.empty()) return {"-1"};

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::get_appointment_history(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	try {
		/*
		SELECT appointment_id, date, time
		FROM appointment
		WHERE patient_id = data[0] AND is_pending = 0;
		*/
		std::string query;
		query = "SELECT appointment_id, date, time \nFROM appointment \nWHERE patient_id = " + data[0] + " AND is_pending = 0;";
		sql::ResultSet* res = executeQuery(query);

		while (res->next()) {
			returnData.push_back(res->getString("appointment_id"));
			returnData.push_back(res->getString("date"));
			returnData.push_back(res->getString("time"));
			returnData.push_back("#");
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	//if(returnData.empty()) return {"-1"};

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::get_presc_data(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	try {
		/*
		SELECT *
		FROM prescription
		NATURAL JOIN appointment
		WHERE appointment_id = data[0];
		*/
		std::string query;
		query = "SELECT * \nFROM prescription \nNATURAL JOIN appointment \nWHERE appointment_id = " + data[0] + ";";
		sql::ResultSet* res = executeQuery(query);

		if (res->next()) {
			returnData.push_back(res->getString("appointment_id"));
			returnData.push_back(res->getString("patient_id"));
			returnData.push_back(res->getString("doctor_id"));
			returnData.push_back(res->getString("date"));
			returnData.push_back(res->getString("time"));
			returnData.push_back(res->getString("disease_name"));
			returnData.push_back(res->getString("symptoms"));
			returnData.push_back(res->getString("medicine_name"));
			returnData.push_back(res->getString("presc"));
		}
		else {
			for (int i = 0; i < 9; i++) returnData.push_back("");
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::get_patient_information(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	try {
		/*
		SELECT * 
		FROM patient
		WHERE patient_id = data[0];
		*/
		std::string selectDataSQL = "SELECT * \nFROM patient \nWHERE patient_id = " + data[0] + ";";
		sql::ResultSet* res = executeQuery(selectDataSQL);

		if (res->next()) {
			returnData.push_back(res->getString("patient_id"));
			returnData.push_back(res->getString("name"));
			returnData.push_back(res->getString("age"));
			returnData.push_back(res->getString("gender"));
			returnData.push_back(res->getString("phone"));
			returnData.push_back(res->getString("address"));
			returnData.push_back(res->getString("email"));
		}

		if (returnData.size() == 0) return { "-1" };

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	try {
		/*
		SELECT doctor_id, room_id, disease_name
		FROM doctor
		INNER JOIN treated_by
		ON doctor.doctor_id = treated_by.doctor_id
		INNER JOIN is_admitted
		ON treated_by.patient_id = is_admitted.patient_id
		WHERE treated_by.patient_id = 1 AND is_currently = 1 AND is_admit = 1 AND is_scheduled = 1;
		*/

		std::string query;
		query = "SELECT doctor.doctor_id, room_id, disease_name \nFROM doctor \nINNER JOIN treated_by \nON doctor.doctor_id = treated_by.doctor_id \nINNER JOIN is_admitted \nON treated_by.patient_id = is_admitted.patient_id "
			"\nWHERE treated_by.patient_id = " + data[0] + " AND is_currently = 1 AND is_admit = 1 AND is_scheduled = 1;";

		sql::ResultSet* res = executeQuery(query);
		if (res->next()) {
			returnData.push_back(std::to_string(res->getInt("doctor_id")));
			returnData.push_back(res->getString("room_id"));
			returnData.push_back(res->getString("disease_name"));
		}
		else {
			returnData.push_back("");
			returnData.push_back("");
			returnData.push_back("");
		}
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::get_doctor_data(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	try {
		/*
		SELECT *
		FROM doctor
		NATURAL JOIN has_office
		WHERE doctor_id = data[0];
		*/
		std::string query;
		query = "SELECT * \nFROM doctor \nNATURAL JOIN has_office \nWHERE doctor_id = " + data[0] + ";";
		sql::ResultSet* res = executeQuery(query);

		if (res->next()) {
			returnData.push_back(res->getString("doctor_id"));
			returnData.push_back(res->getString("name"));
			returnData.push_back(res->getString("age"));
			returnData.push_back(res->getString("gender"));
			returnData.push_back(res->getString("room_id"));
			returnData.push_back(res->getString("speciality"));
			returnData.push_back(res->getString("phone"));
			returnData.push_back(res->getString("address"));
			returnData.push_back(res->getString("email"));
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	if(returnData.empty()) return {"-1"};

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::get_admit_request(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	returnData.push_back(data[0]);
	try {
		/*
		SELECT doctor_id
		FROM is_admitted
		INNER JOIN treated_by
		ON is_admitted.patient_id = treated_by.patient_id
		WHERE is_admitted.patient_id = data[0] AND is_scheduled = 0 AND is_admit = 1 AND is_currently = 1;
		*/

		std::string query;
		query = "SELECT doctor_id \nFROM is_admitted \nINNER JOIN treated_by \nON is_admitted.patient_id = treated_by.patient_id "
			" \nWHERE is_admitted.patient_id = " + data[0] + " AND is_scheduled = 0 AND is_admit = 1 AND is_currently = 1;";
		sql::ResultSet* res = executeQuery(query);

		if (res->next()) {
			returnData.push_back(res->getString("doctor_id"));
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::get_room_data(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	try {
		/*
		SELECT room.room_id AS Room_ID, (room.capacity - COALESCE((SELECT COUNT(is_admitted.patient_id)
		FROM is_admitted
		WHERE is_scheduled = 1 AND is_admit = 1 AND is_admitted.room_id = room.room_id
		GROUP BY is_admitted.room_id),0)
		) AS Left_Capacity
		FROM room
		WHERE room.room_id LIKE 'P%';
		*/

		std::string query;
		query = "SELECT room.room_id AS Room_ID, (room.capacity - COALESCE((SELECT COUNT(is_admitted.patient_id) "
			"\nFROM is_admitted "
			"\nWHERE is_scheduled = 1 AND is_admit = 1 AND is_admitted.room_id = room.room_id "
			"\nGROUP BY is_admitted.room_id), 0) "
			"\n) AS Left_Capacity "
			"\nFROM room "
			"\nWHERE room.room_id LIKE 'P%';";

		sql::ResultSet* res = executeQuery(query);
		while (res->next()) {
			returnData.push_back(std::to_string(res->getInt("Left_Capacity")));
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	returnData.push_back(data[0]);
	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::get_room_patient_id(std::vector<std::string> data) {
	std::vector<std::string> returnData = data;
	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::frontdesk_admit_patient(std::vector<std::string> data) {
	try {
		/*
		UPDATE is_admitted
		SET is_scheduled = 1, room_id = data[1], admit_date = .. , admit_time = ..
		WHERE patient_id = data[0] AND is_scheduled = 0;
		*/
		auto now = std::chrono::system_clock::now();
		std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

		std::ostringstream date_stream;
		date_stream << std::put_time(std::localtime(&now_time_t), "%Y-%m-%d");
		std::string date_str = date_stream.str();

		std::ostringstream time_stream;
		time_stream << std::put_time(std::localtime(&now_time_t), "%H:%M:%S");
		std::string time_str = time_stream.str();

		std::string query;
		query = "UPDATE is_admitted \nSET is_scheduled = 1, room_id = " + quote1(data[1]) + ", admit_date = " + quote1(date_str) + ", admit_time = " + quote1(time_str)+" \nWHERE patient_id = " + data[0] + " AND is_scheduled = 0;";
		execute(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	return get_patient_med_data(data);
}

std::vector<std::string> MYSQLDatabase::get_discharge_details(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	returnData.push_back(data[0]);
	try {
		/*
		SELECT doctor_id, room_id
		FROM is_admitted
		INNER JOIN treated_by
		ON is_admitted.patient_id = treated_by.patient_id
		WHERE is_admitted.patient_id = data[0] AND is_scheduled = 1 AND is_admit = 1 AND is_currently = 1;
		*/

		std::string query;
		query = "SELECT doctor_id, room_id \nFROM is_admitted \nINNER JOIN treated_by \nON is_admitted.patient_id = treated_by.patient_id "
			" \nWHERE is_admitted.patient_id = " + data[0] + " AND is_scheduled = 1 AND is_admit = 1 AND is_currently = 1;";
		sql::ResultSet* res = executeQuery(query);

		if (res->next()) {
			returnData.push_back(res->getString("doctor_id"));
			returnData.push_back(res->getString("room_id"));
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::frontdesk_discharge_patient(std::vector<std::string> data) {
	try {
		/*
		UPDATE is_admitted
		SET is_admit = 0, discharge_date = .. , discharge_time = ..
		WHERE patient_id = data[0] AND is_scheduled = 1 AND is_admit = 1;
		*/
		auto now = std::chrono::system_clock::now();
		std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

		std::ostringstream date_stream;
		date_stream << std::put_time(std::localtime(&now_time_t), "%Y-%m-%d");
		std::string date_str = date_stream.str();

		std::ostringstream time_stream;
		time_stream << std::put_time(std::localtime(&now_time_t), "%H:%M:%S");
		std::string time_str = time_stream.str();

		std::string query;
		query = "UPDATE is_admitted \nSET is_admit = 0, discharge_date = " + quote1(date_str) + ", discharge_time = " + quote1(time_str) + " \nWHERE patient_id = " + data[0] + " AND is_scheduled = 1 AND is_admit = 1;";
		execute(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	try {
		/*
		UPDATE treated_by
		SET is_currently = 0
		WHERE patient_id = data[0] AND doctor_id = data[1];
		*/
		std::string query, data_string;
		query = std::string("UPDATE treated_by \nSET is_currently = 0 \nWHERE patient_id = " + data[0] + " AND doctor_id = " + data[1] + ";");
		execute(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	return get_patient_med_data(data);
}

std::vector<std::string> MYSQLDatabase::get_admit_history(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	try {
		/*
		SELECT *
		FROM is_admitted
		WHERE patient_id = data[0] AND is_scheduled = 1 AND is_admit = 0;
		*/
		std::string query;
		query = "SELECT * \nFROM is_admitted \nWHERE patient_id = " + data[0] + " AND is_scheduled = 1 AND is_admit = 0;";
		sql::ResultSet* res = executeQuery(query);

		while (res->next()) {
			returnData.push_back(res->getString("room_id"));
			returnData.push_back(res->getString("admit_date"));
			returnData.push_back(res->getString("admit_time"));
			returnData.push_back(res->getString("discharge_date"));
			returnData.push_back(res->getString("discharge_time"));
			returnData.push_back("#");
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	//if(returnData.empty()) return {"-1"};

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::get_doctor_speciality(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	try {
		/*
		SELECT doctor_id, name, speciality, gender
		FROM doctor;
		*/
		std::string query;
		query = "SELECT doctor_id, name, speciality, gender \nFROM doctor;";
		sql::ResultSet* res = executeQuery(query);

		while (res->next()) {
			returnData.push_back(res->getString("doctor_id"));
			returnData.push_back(res->getString("name"));
			returnData.push_back(res->getString("speciality"));
			returnData.push_back(res->getString("gender"));
			returnData.push_back("#");
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	//if(returnData.empty()) return {"-1"};

	returnData.push_back(data[0]);
	returnData.push_back("1");
	return returnData;
}

int MYSQLDatabase::get_hour(std::string& _time) {
	int hour = 10 * (_time[0] - '0') + (_time[1] - '0');
	if(_time[6] == 'P') hour += 12;

	return hour;
}

std::vector<std::string> MYSQLDatabase::get_appointment_slots(std::vector<std::string> data) {
	std::set<std::string> used_slots;
	std::vector<std::string> returnData;
	std::string doctor_office;

	try {
		/*
		SELECT room_id
		FROM has_office
		WHERE doctor_id = data[0];
		*/
		std::string query;
		query = "SELECT room_id \nFROM has_office \nWHERE doctor_id = " + data[0] + "; ";
		sql::ResultSet* res = executeQuery(query);

		if (res->next()) {
			doctor_office = res->getString("room_id");
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	try {
		/*
		(SELECT date, time
		FROM appointment
		WHERE (doctor_id = data[0] OR patient_id = data[1]) AND (is_pending = 1))
		UNION
		(SELECT date, time
		FROM test
		WHERE patient_id = data[1] AND is_scheduled = 1 AND is_pending = 1);
		*/
		std::string query;
		query = "(SELECT date, time \nFROM appointment \nWHERE (doctor_id = " + data[0] + " OR patient_id = " + data[1] + ") AND (is_pending = 1)) \nUNION \n(SELECT date, time \nFROM test \nWHERE patient_id = " + data[1] + " AND is_scheduled = 1 AND is_pending = 1);";

		sql::ResultSet* res = executeQuery(query);

		while (res->next()) {
			std::string slot = res->getString("date") + " " + res->getString("time");
			used_slots.insert(slot);
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	std::vector<std::string> slot_times = {"09:00 AM", "09:30 AM", "10:00 AM", "10:30 AM", "11:00 AM", "11:30 AM", "02:00 PM", "02:30 PM", "03:00 PM", "03:30 PM", "05:00 PM", "05:30 PM", "06:00 PM", "06:30 PM"};

	std::time_t timestamp = std::time(NULL);

	for (int i = 0; i < 5; i++) {
		std::tm *curr_time = std::localtime(&timestamp);
		int year = curr_time->tm_year + 1900;
		int month = curr_time->tm_mon + 1;
		int day = curr_time->tm_mday;
		int hour = curr_time->tm_hour;
		std::string curr_date;
		curr_date += std::to_string(year) + "-";
		curr_date += std::to_string(month) + "-";
		curr_date += std::to_string(day);

		if (i == 0) {
			for (std::string default_slot : slot_times) {
				if (hour + 1 <= get_hour(default_slot)) {
					std::string available_slot = curr_date + " " + default_slot;
					if(used_slots.count(available_slot) == 0){
						returnData.push_back(curr_date);
						returnData.push_back(default_slot);
						returnData.push_back(doctor_office);
						returnData.push_back("#");
					}
				}
			}
		}
		else {
			for (std::string default_slot : slot_times) {
				std::string available_slot = curr_date + " " + default_slot;
				if(used_slots.count(available_slot) == 0){
					returnData.push_back(curr_date);
					returnData.push_back(default_slot);
					returnData.push_back(doctor_office);
					returnData.push_back("#");
				}
			}
		}

		timestamp += (std::time_t)86400;
	}

	returnData.push_back(data[0]);
	returnData.push_back(data[1]);

	/*for (auto itr : returnData) {
	std::cout << itr << std::endl;
	}*/

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::confirm_appointment(std::vector<std::string> data) {
	data.push_back("1");
	return data;
}

std::string MYSQLDatabase::generate_appointment_id() {
	int appointment_id;
	bool found = false;

	while (!found) {
		appointment_id = uni_7_digit_gen(rand_gen);
		try {
			/*
			SELECT appointment_id
			FROM appointment
			WHERE appointment_id = appointment_id;
			*/
			std::string query;
			query = "SELECT appointment_id \nFROM appointment \nWHERE appointment_id = " + std::to_string(appointment_id) + ";";
			sql::ResultSet* res = executeQuery(query);

			if (!(res->next())) {
				found = true;
			}

			delete res;
		}
		catch (sql::SQLException& e) {
			std::cerr << "SQL Error : " << e.what() << std::endl;
			return { "-1" };
		}
	}

	return std::to_string(appointment_id);
}

std::vector<std::string> MYSQLDatabase::add_appointment(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	try {
		/*
		INSERT INTO appointment VALUES
		(1, 1, 101, 'R101', '2025-04-10', '10:00 AM', 2, 1);
		*/
		std::string query;
		query = "INSERT INTO appointment VALUES \n(" + generate_appointment_id() + ", " + data[1] + ", " + data[0] + ", " + quote1(data[2]) + ", " + quote1(data[3]) + ", " + quote1(data[4]) + ", 2, 1);";
		execute(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	returnData.push_back("0");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::get_schedule_test(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	try {
		/*
		SELECT test_id, doctor_id, room_id, test
		FROM test
		WHERE patient_id = data[0] AND is_scheduled = 0;
		*/
		std::string query;
		query = "SELECT test_id, doctor_id, room_id, test \nFROM test \nWHERE patient_id = " + data[0] + " AND is_scheduled = 0;";
		sql::ResultSet* res = executeQuery(query);

		while (res->next()) {
			returnData.push_back(res->getString("test_id"));
			returnData.push_back(res->getString("doctor_id"));
			returnData.push_back(res->getString("room_id"));
			returnData.push_back(res->getString("test"));
			returnData.push_back("#");
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::get_test_slots(std::vector<std::string> data) {
	std::set<std::string> used_slots;
	std::vector<std::string> returnData;
	std::string doctor_id;
	std::string patient_id;
	std::string room_id;

	try {
		/*
		SELECT doctor_id, patient_id, room_id
		FROM test
		WHERE test_id = data[0];
		*/
		std::string query;
		query = "SELECT doctor_id, patient_id, room_id \nFROM test \nWHERE test_id = " + data[0] + ";";
		sql::ResultSet* res = executeQuery(query);

		if (res->next()) {
			doctor_id = res->getString("doctor_id");
			patient_id = res->getString("patient_id");
			room_id = res->getString("room_id");
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	try {
		/*
		(SELECT date, time
		FROM appointment
		WHERE patient_id = patient_id AND is_pending = 1)
		UNION
		(SELECT date, time
		FROM test
		WHERE (patient_id = patient_id AND is_scheduled = 1 AND is_pending = 1) OR (room_id + room_id));
		*/
		std::string query;
		query = "(SELECT date, time \nFROM appointment \nWHERE patient_id = " + patient_id + " AND is_pending = 1) \nUNION \n(SELECT date, time \nFROM test \nWHERE (patient_id = " + patient_id + " AND is_scheduled = 1 AND is_pending = 1) OR (room_id = " + quote1(room_id) + "));";

		sql::ResultSet* res = executeQuery(query);

		while (res->next()) {
			std::string slot = res->getString("date") + " " + res->getString("time");
			used_slots.insert(slot);
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	std::vector<std::string> slot_times = {"09:00 AM", "09:30 AM", "10:00 AM", "10:30 AM", "11:00 AM", "11:30 AM", "02:00 PM", "02:30 PM", "03:00 PM", "03:30 PM", "05:00 PM", "05:30 PM", "06:00 PM", "06:30 PM"};

	std::time_t timestamp = std::time(NULL);

	for (int i = 0; i < 5; i++) {
		std::tm *curr_time = std::localtime(&timestamp);
		int year = curr_time->tm_year + 1900;
		int month = curr_time->tm_mon + 1;
		int day = curr_time->tm_mday;
		int hour = curr_time->tm_hour;
		std::string curr_date;
		curr_date += std::to_string(year) + "-";
		curr_date += std::to_string(month) + "-";
		curr_date += std::to_string(day);

		if (i == 0) {
			for (std::string default_slot : slot_times) {
				if (hour + 1 <= get_hour(default_slot)) {
					std::string available_slot = curr_date + " " + default_slot;
					if(used_slots.count(available_slot) == 0){
						returnData.push_back(curr_date);
						returnData.push_back(default_slot);
						returnData.push_back(room_id);
						returnData.push_back("#");
					}
				}
			}
		}
		else {
			for (std::string default_slot : slot_times) {
				std::string available_slot = curr_date + " " + default_slot;
				if(used_slots.count(available_slot) == 0){
					returnData.push_back(curr_date);
					returnData.push_back(default_slot);
					returnData.push_back(room_id);
					returnData.push_back("#");
				}
			}
		}

		timestamp += (std::time_t)86400;
	}

	returnData.push_back(data[0]);

	/*for (auto itr : returnData) {
	std::cout << itr << std::endl;
	}*/

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::confirm_test(std::vector<std::string> data) {
	data.push_back("1");
	return data;
}

std::vector<std::string> MYSQLDatabase::add_test(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	try {
		/*
		UPDATE test
		SET date = data[1], time = data[2], is_scheduled = 1
		WHERE test_id = data[0];
		*/
		std::string query;
		query = "UPDATE test \nSET date = " + quote1(data[1]) + ", time = " + quote1(data[2]) + ", is_scheduled = 1 \nWHERE test_id = " + data[0] + ";";
		execute(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	returnData.push_back("0");
	return returnData;
}

std::string MYSQLDatabase::generate_doctor_id() {
	int doctor_id;
	bool found = false;

	while (!found) {
		doctor_id = uni_3_digit_gen(rand_gen);
		try {
			/*
			SELECT doctor_id
			FROM doctor
			WHERE doctor_id = doctor_id;
			*/
			std::string query;
			query = "SELECT doctor_id \nFROM doctor \nWHERE doctor_id = " + std::to_string(doctor_id) + ";";
			sql::ResultSet* res = executeQuery(query);

			if (!(res->next())) {
				found = true;
			}

			delete res;
		}
		catch (sql::SQLException& e) {
			std::cerr << "SQL Error : " << e.what() << std::endl;
			return { "-1" };
		}
	}

	//try {
	//	/*
	//	SELECT MAX(doctor_id) AS id
	//	FROM doctor;
	//	*/
	//	std::string query;
	//	query = "SELECT MAX(doctor_id) AS id \nFROM doctor;";
	//	sql::ResultSet* res = executeQuery(query);

	//	if (res->next()) {
	//		doctor_id = std::stoi(res->getString("id"));
	//	}
	//	else {
	//		doctor_id = 101;
	//	}

	//	delete res;
	//}
	//catch (sql::SQLException& e) {
	//	std::cerr << "SQL Error : " << e.what() << std::endl;
	//	return { "-1" };
	//}

	return std::to_string(doctor_id);
}

std::vector<std::string> MYSQLDatabase::get_doctor_id(std::vector<std::string> data) {
	return {generate_doctor_id(), "1"};
}

std::vector<std::string> MYSQLDatabase::add_doctor(std::vector<std::string> data) {
	try {
		/* 
		INSERT INTO doctor VALUES
		(101, 'Dr. Ananya Sharma', 45, 'F', 9876543210, 'ananya.sharma@hospital.com', '12 Green Park, Delhi', 'Cardiology', 'Senior Consultant', 180000);
		*/
		std::string query, data_string;
		query = "INSERT INTO doctor VALUES \n(" + data[0] + ", " + quote1(data[1]) + ", " + data[2] + ", " + quote1(data[3]) + ", " + data[4] + ", " + quote1(data[5]) + ", " + quote1(data[6]) + ", " + quote1(data[7]) + ", " + quote1(data[8]) + ", " + data[9] + ");";
		execute(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	std::vector<std::string> returnData;

	returnData.push_back("0");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::delete_doctor(std::vector<std::string> data) {
	try {
		/* 
		DELETE
		FROM doctor
		WHERE doctor_id = data[0];
		*/
		std::string query, data_string;
		query = "DELETE \nFROM doctor \nWHERE doctor_id = " + data[0] + ";";
		execute(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	std::vector<std::string> returnData;

	returnData.push_back("0");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::get_doctor_details(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	try {
		/*
		SELECT *
		FROM doctor
		WHERE doctor_id = data[0];
		*/
		std::string query;
		query = "SELECT * \nFROM doctor \nWHERE doctor_id = " + data[0] + ";";
		sql::ResultSet* res = executeQuery(query);

		if (res->next()) {
			returnData.push_back(res->getString("doctor_id"));
			returnData.push_back(res->getString("name"));
			returnData.push_back(res->getString("age"));
			returnData.push_back(res->getString("gender"));
			returnData.push_back(res->getString("phone"));
			returnData.push_back(res->getString("email"));
			returnData.push_back(res->getString("address"));
			returnData.push_back(res->getString("speciality"));
			returnData.push_back(res->getString("designation"));
			returnData.push_back(res->getString("salary"));
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	if(returnData.empty()) return {"-1"};

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::update_doctor(std::vector<std::string> data) {
	try {
		/*
		UPDATE doctor
		SET name = data[1], age = data[2], gender = data[3], phone = data[4], email = data[5], address = data[6], speciality = data[7], designation = data[8], salary = data[9]
		WHERE doctor_id = data[0];
		*/
		std::string query;
		query = "UPDATE doctor \nSET name = " + quote1(data[1]) + ", age = " + data[2] + ", gender = " + quote1(data[3]) + ", phone = " + data[4] + ", email = " + quote1(data[5]) + ", address = " + quote1(data[6]) + ", speciality = " + quote1(data[7]) + ", designation = " + quote1(data[8]) + ", salary = " + data[9] + "\nWHERE doctor_id = " + data[0] + ";";
		execute(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	return {"0"};
}

std::vector<std::string> MYSQLDatabase::view_doctor(std::vector<std::string> data) {
	if(data[0] == "") data[0] = "0";
	if(data[1] == "") data[1] = "200";
	if(data[2] == "") data[2] = "0";
	if(data[3] == "") data[3] = "1000000000";

	std::vector<std::string> returnData;
	try {
		/*
		SELECT doctor_id, speciality, age, gender, salary
		FROM doctor
		WHERE age >= data[0] AND age <= data[1] AND salary >= data[2] AND salary <= data[3] AND gender = data[4] AND speciality = data[5];
		*/
		std::string query;
		query = "SELECT doctor_id, speciality, age, gender, salary \nFROM doctor \nWHERE age >= " + data[0] + " AND age <= " + data[1] + " AND salary >= " + data[2] + " AND salary <= " + data[3];
		if(data[4] != "") query += " AND gender = " + quote1(data[4]);
		if(data[5] != "") query += " AND speciality = " + quote1(data[5]);
		query += ";";
		sql::ResultSet* res = executeQuery(query);

		while (res->next()) {
			returnData.push_back(res->getString("doctor_id"));
			returnData.push_back(res->getString("speciality"));
			returnData.push_back(res->getString("age"));
			returnData.push_back(res->getString("gender"));
			returnData.push_back(res->getString("salary"));
			returnData.push_back("#");
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	returnData.push_back("1");
	return returnData;
}

std::vector<std::string> MYSQLDatabase::check_frontdesk_login(std::vector<std::string> data) {
	if(data[0] == "123") return {"0"};
	else return {"-1"};
}

std::vector<std::string> MYSQLDatabase::check_dataentry_login(std::vector<std::string> data) {
	if(data[0] == "456") return {"0"};
	else return {"-1"};
}

std::vector<std::string> MYSQLDatabase::check_doctor_login(std::vector<std::string> data) {
	if(data[0] == "789") return {"0"};
	else return {"-1"};
}

std::vector<std::string> MYSQLDatabase::check_admin_login(std::vector<std::string> data) {
	if(data[0] == "0192") return {"0"};
	else return {"-1"};
}

std::vector<std::string> MYSQLDatabase::view_patient(std::vector<std::string> data) {
	if(data[0] == "") data[0] = "0";
	if(data[1] == "") data[1] = "200";

	std::vector<std::string> returnData;
	try {
		/*
		SELECT patient_id, disease_name, age, gender, room_id
		FROM patient
		LEFT NATURAL JOIN is_admitted
		WHERE age >= data[0] AND age <= data[1] AND gender = data[2] AND room_id = data[3] AND disease_name = data[4];
		*/
		std::string query;
		query = "SELECT patient.patient_id AS id, disease_name, age, gender, room_id \nFROM patient \nLEFT JOIN is_admitted\nON patient.patient_id = is_admitted.patient_id \nWHERE age >= " + data[0] + " AND age <= " + data[1];
		if(data[2] != "") query += " AND gender = " + quote1(data[2]);
		if(data[3] != "") query += " AND (is_admit = 1 AND room_id = " + quote1(data[3]) + ")";
		if(data[4] != "") query += " AND (is_admit = 1 AND disease_name = " + quote1(data[4]) + ")";
		query += ";";
		sql::ResultSet* res = executeQuery(query);

		while (res->next()) {
			returnData.push_back(res->getString("id"));
			returnData.push_back(res->getString("disease_name"));
			returnData.push_back(res->getString("age"));
			returnData.push_back(res->getString("gender"));
			returnData.push_back(res->getString("room_id"));
			returnData.push_back("#");
		}

		delete res;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
		return { "-1" };
	}

	returnData.push_back("1");
	return returnData;
}