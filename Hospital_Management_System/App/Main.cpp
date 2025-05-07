#include "app.hpp"

int main() {
	if (freopen("error.txt", "w", stderr) == nullptr) {
		std::cerr << "Failed to redirect stderr to error.txt" << std::endl;
	}

	App hospital_dbms;

	hospital_dbms.run();

	return 0;
}