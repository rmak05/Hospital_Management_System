#include "Queries.h"

FunctionHolder::FunctionHolder() {
	funcs.push_back([this](std::vector<std::string> data) { return this->register_patient(data); });

}

std::vector<std::string> FunctionHolder::callFunction(FuncType _type, std::vector<std::string> data) {
	int ind = int(_type);
	if (ind == (-1)) return {"-1"};
	if (ind >= funcs.size()) return { "-1" };
	return funcs[static_cast<int>(_type)](data);
}

std::vector<std::string> FunctionHolder::register_patient(std::vector<std::string> data) {

	try {
		sql::mysql::MySQL_Driver* driver;
		sql::Connection* con;

		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect("tcp://localhost:3306", "root", "");

		con->setSchema("hospital_management");

		sql::Statement* stmt;
		stmt = con->createStatement();

		std::string query =
			"INSERT INTO patient "
			"VALUES "
			"(3, 'Mak', 20, 'M', 774308274, 'kingerishan@gmail.com', '#260,Green Way Street');";

		stmt->execute(query);


		// SQL query to retrieve data from the table
		std::string selectDataSQL = "SELECT * FROM patient";

		sql::ResultSet* res = stmt->executeQuery(selectDataSQL);

		// Loop through the result set and display data
		int count = 0;
		while (res->next()) {
			std::cout << " Name " << ++count << ": "
				<< res->getString("name") << std::endl;
		}

		delete res;
		delete stmt;
		delete con;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error : " << e.what() << std::endl;
	}

	std::cout << "Register Patient called" << "\n";
	return { "0" };
}
