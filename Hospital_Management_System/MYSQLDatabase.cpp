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
		return this->get_admit_history(data);
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
		/* 
		INSERT INTO patient VALUES
		(1, 'Alice Smith', 30, 'F', 9876543210, '123 Park St, Cityville', 'alice@example.com'),
		(2, 'Bob Johnson', 45, 'M', 9876543211, '456 Lake Rd, Townville', 'bob@example.com');
		*/
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
		SELECT name, room_id, disease_name
		FROM doctor
		INNER JOIN treated_by
		ON doctor.doctor_id = treated_by.doctor_id
		INNER JOIN is_admitted
		ON treated_by.patient_id = is_admitted.patient_id
		WHERE treated_by.patient_id = 1 AND is_currently = 1 AND is_admit = 1 AND is_scheduled = 1;
		*/

		std::string query;
		query = "SELECT name, room_id, disease_name FROM doctor INNER JOIN treated_by ON doctor.doctor_id = treated_by.doctor_id INNER JOIN is_admitted ON treated_by.patient_id = is_admitted.patient_id "
			"WHERE treated_by.patient_id = " + data[0] + " AND is_currently = 1 AND is_admit = 1 AND is_scheduled = 1;";

		sql::ResultSet* res = _statement->executeQuery(query);
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
		SELECT * FROM patient 
		WHERE patient_id = data[0];
		*/
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
	//std::this_thread::sleep_for(std::chrono::seconds(1));

	std::time_t timestamp = std::time(NULL);
	std::tm *curr_time = std::localtime(&timestamp);

	int patient_id = ((curr_time->tm_year + 1900) * 100000) + (curr_time->tm_hour * 3600) + (curr_time->tm_min * 60) + (curr_time->tm_sec);

	return {std::to_string(patient_id), "1"};
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
		query = "SELECT name, room_id, disease_name FROM doctor INNER JOIN treated_by ON doctor.doctor_id = treated_by.doctor_id INNER JOIN is_admitted ON treated_by.patient_id = is_admitted.patient_id "
			"WHERE treated_by.patient_id = " + data[0] + " AND is_currently = 1 AND is_admit = 1 AND is_scheduled = 1;";

		sql::ResultSet* res = _statement->executeQuery(query);
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
		query = "SELECT test_id, doctor_id, date, time, room_id FROM test WHERE patient_id = " + data[0] + " and is_scheduled = 1 and is_pending = 1;";
		sql::ResultSet* res = _statement->executeQuery(query);

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
		query = "SELECT * FROM test WHERE test_id = " + data[0] + ";";
		sql::ResultSet* res = _statement->executeQuery(query);

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
		query = "UPDATE test SET results = " + quote1(data[1]) + ", is_pending = 0 WHERE test_id = " + data[0] + ";";
		_statement->execute(query);
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
		query = "SELECT appointment_id, patient_id, date, time FROM appointment WHERE doctor_id = " + data[0] + " AND is_pending = 1;";
		sql::ResultSet* res = _statement->executeQuery(query);

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
		query = "SELECT doctor_id FROM doctor WHERE doctor_id = " + data[0] + ";";
		sql::ResultSet* res = _statement->executeQuery(query);

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
	std::time_t timestamp = std::time(NULL);
	std::tm* curr_time = std::localtime(&timestamp);

	int test_id = ((curr_time->tm_year + 1900) * 100000) + (curr_time->tm_hour * 3600) + (curr_time->tm_min * 60) + (curr_time->tm_sec);
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
		query = "SELECT appointment_id, patient_id, doctor_id FROM appointment WHERE appointment_id = " + data[0] + ";";
		sql::ResultSet* res = _statement->executeQuery(query);

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
		query = std::string("INSERT INTO prescription VALUES (") + data[0] + ", " + quote1(data[1]) + ", " + quote1(data[2]) + ", " + quote1(data[3]) + ", " + quote1(data[4]) + ");";
		_statement->execute(query);
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
		query = std::string("INSERT INTO test VALUES (") + data[0] + ", " + data[1] + ", " + data[2] + ", " + quote1(data[4]) + ", " + quote1(data[3]) + ", " + quote1(data[5]) + ", NULL, NULL, NULL, 0, 1);";
		_statement->execute(query);
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
		query = std::string("INSERT INTO is_admitted VALUES (") + data[0] + ", NULL, NULL, NULL, NULL, NULL, " + quote1(data[2]) + ", 0, 1);";
		_statement->execute(query);
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
		query = std::string("INSERT INTO treated_by VALUES (") + data[0] + ", " + data[1] + ", 1);";
		_statement->execute(query);
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
		query = "UPDATE appointment SET is_pending = 0 WHERE appointment_id = " + data[0] + ";";
		_statement->execute(query);
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
		query = "SELECT patient_id, patient.name AS patient_name, room_id, disease_name FROM patient NATURAL JOIN treated_by NATURAL JOIN is_admitted WHERE doctor_id = " + data[0] + " AND is_admit = 1;";
		sql::ResultSet* res = _statement->executeQuery(query);

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
		query = "SELECT test_id, test, room_id, date, time FROM test WHERE patient_id = " + data[0] + " AND is_pending = 0 AND is_scheduled = 1;";
		sql::ResultSet* res = _statement->executeQuery(query);

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
		query = "SELECT * FROM test WHERE test_id = " + data[0] + ";";
		sql::ResultSet* res = _statement->executeQuery(query);

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
		WHERE patient_id = data[0];
		*/
		std::string query;
		query = "SELECT appointment_id, date, time FROM appointment WHERE patient_id = " + data[0] + ";";
		sql::ResultSet* res = _statement->executeQuery(query);

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
		query = "SELECT * FROM prescription NATURAL JOIN appointment WHERE appointment_id = " + data[0] + ";";
		sql::ResultSet* res = _statement->executeQuery(query);

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

std::vector<std::string> MYSQLDatabase::get_patient_information(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	try {
		/*
		SELECT * FROM patient
		WHERE patient_id = data[0];
		*/
		std::string selectDataSQL = "SELECT * FROM patient WHERE patient_id = " + data[0] + ";";
		sql::ResultSet* res = _statement->executeQuery(selectDataSQL);

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
		query = "SELECT doctor.doctor_id, room_id, disease_name FROM doctor INNER JOIN treated_by ON doctor.doctor_id = treated_by.doctor_id INNER JOIN is_admitted ON treated_by.patient_id = is_admitted.patient_id "
			"WHERE treated_by.patient_id = " + data[0] + " AND is_currently = 1 AND is_admit = 1 AND is_scheduled = 1;";

		sql::ResultSet* res = _statement->executeQuery(query);
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
		query = "SELECT * FROM doctor NATURAL JOIN has_office WHERE doctor_id = " + data[0] + ";";
		sql::ResultSet* res = _statement->executeQuery(query);

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

std::vector<std::string> MYSQLDatabase::get_admit_history(std::vector<std::string> data) {
	std::vector<std::string> returnData;
	try {
		/*
		SELECT *
		FROM is_admitted
		WHERE patient_id = data[0] AND is_scheduled = 1 AND is_admit = 0;
		*/
		std::string query;
		query = "SELECT * FROM is_admitted WHERE patient_id = " + data[0] + " AND is_scheduled = 1 AND is_admit = 0;";
		sql::ResultSet* res = _statement->executeQuery(query);

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