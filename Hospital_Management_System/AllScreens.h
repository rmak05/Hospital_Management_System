#pragma once

#include "Screen.h"

class Home_Screen;
class Front_Desk_Login_Screen;
class Front_Desk_Home_Screen;
class Register_Patient_Screen;
class Update_Patient_Screen;
class Login_Patient_Screen;
class Patient_Home_Screen;
class Update_Login_Patient_Screen;

class Home_Screen : public Screen {
public:
	Home_Screen(int w_width, int w_height);
};

class Front_Desk_Login_Screen : public Screen {
public:
	Front_Desk_Login_Screen(int w_width, int w_height);
};

class Front_Desk_Home_Screen : public Screen {
public:
	Front_Desk_Home_Screen(int w_width, int w_height);
};

class Register_Patient_Screen : public Screen {
public:
	Register_Patient_Screen(int w_width, int w_height);
	std::vector<std::string> extract_form();
	void erase_form();
	void fill_form(std::vector<std::string>& data);
};

class Update_Patient_Screen : public Screen {
private:
	std::vector<std::string> patient_data;

public:
	Update_Patient_Screen(int w_width, int w_height);
	std::vector<std::string> extract_form();
	void erase_form();
	void fill_form(std::vector<std::string>& data);
};

class Login_Patient_Screen : public Screen {
public:
	Login_Patient_Screen(int w_width, int w_height);
};

class Patient_Home_Screen : public Screen {
public:
	Patient_Home_Screen(int w_width, int w_height);
	void erase_form();
	void fill_form(std::vector<std::string>& data);
};

class Update_Login_Patient_Screen : public Screen {
public:
	Update_Login_Patient_Screen(int w_width, int w_height);
	std::vector<std::string> extract_form();
	void erase_form();
	void fill_form(std::vector<std::string>& data);
};