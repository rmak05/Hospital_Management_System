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

class Doctor_Login_Screen : public Screen {
public:
	Doctor_Login_Screen(int w_width, int w_height);
};

class Doctor_Home_Screen : public Screen {
public:
	Doctor_Home_Screen(int w_width, int w_height);
};

class Appointment_Screen : public Screen {
public:
	Appointment_Screen(int w_width, int w_height);
};

class Patient_Appointment_Screen : public Screen {
public:
	Patient_Appointment_Screen(int w_width, int w_height);
};

class Presc_Appointment_Screen : public Screen {
public:
	Presc_Appointment_Screen(int w_width, int w_height);
};

class Tests_Appointment_Screen : public Screen {
public:
	Tests_Appointment_Screen(int w_width, int w_height);
};

class Admit_Appointment_Screen : public Screen {
public:
	Admit_Appointment_Screen(int w_width, int w_height);
};

class Patient_Record_Screen : public Screen {
public:
	Patient_Record_Screen(int w_width, int w_height);
};

class Patient_Details_Home_Screen : public Screen {
public:
	Patient_Details_Home_Screen(int w_width, int w_height);
};

class Test_History_Screen : public Screen {
public:
	Test_History_Screen(int w_width, int w_height);
};

class Appointment_History_Screen : public Screen {
public:
	Appointment_History_Screen(int w_width, int w_height);
};

class Patient_Details_Screen : public Screen {
public:
	Patient_Details_Screen(int w_width, int w_height);
};

class Test_Results_Screen : public Screen {
public:
	Test_Results_Screen(int w_width, int w_height);
};

class Presc_Given_Screen : public Screen {
public:
	Presc_Given_Screen(int w_width, int w_height);
};

class My_Information_Screen : public Screen {
public:
	My_Information_Screen(int w_width, int w_height);
};

class Data_Entry_Login_Screen : public Screen {
public:
	Data_Entry_Login_Screen(int w_width, int w_height);
};

class Data_Entry_Login_Patient_Screen : public Screen {
public:
	Data_Entry_Login_Patient_Screen(int w_width, int w_height);
};

class Pending_Tests_Screen : public Screen {
private:
	std::vector<sf::Vector2f> entity_pos;
	int curr_entity_index;

public:
	Pending_Tests_Screen(int w_width, int w_height);
	void erase_form();
	void fill_form(std::vector<std::string>& data);
	void scroll_entities(int delta);
};