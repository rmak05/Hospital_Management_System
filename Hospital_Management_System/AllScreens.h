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
class Doctor_Login_Screen;
class Doctor_Home_Screen;
class Appointment_Screen;
class Patient_Appointment_Screen;
class Presc_Appointment_Screen;
class Tests_Appointment_Screen;
class Admit_Appointment_Screen;
class Patient_Record_Screen;
class Patient_Details_Home_Screen;
class Test_History_Screen;
class Appointment_History_Screen;
class Patient_Details_Screen;
class Test_Results_Screen;
class Presc_Given_Screen;
class My_Information_Screen;
class Data_Entry_Login_Screen;
class Data_Entry_Login_Patient_Screen;
class Pending_Tests_Screen;
class Push_Test_Results_Screen;

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
	std::vector<std::string> extract_form(sf::Vector2f mouse_pos);
	void erase_form();
	void fill_form(std::vector<std::string>& data);
};

class Update_Patient_Screen : public Screen {
private:
	std::vector<std::string> patient_data;

public:
	Update_Patient_Screen(int w_width, int w_height);
	std::vector<std::string> extract_form(sf::Vector2f mouse_pos);
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
	std::vector<std::string> extract_form(sf::Vector2f mouse_pos);
	void erase_form();
	void fill_form(std::vector<std::string>& data);
};

class Doctor_Login_Screen : public Screen {
public:
	Doctor_Login_Screen(int w_width, int w_height);
};

class Doctor_Home_Screen : public Screen {
private:
	std::string doctor_id;

public:
	Doctor_Home_Screen(int w_width, int w_height);
	std::vector<std::string> extract_form(sf::Vector2f mouse_pos);
	void fill_form(std::vector<std::string>& data);
};

class Appointment_Screen : public Screen {
private:
	std::vector<sf::Vector2f> entity_pos;
	int curr_entity_index;
	sf::Vector2f scroll_window_size;
	sf::Vector2f scroll_window_pos;

public:
	Appointment_Screen(int w_width, int w_height);
	std::vector<std::string> extract_form(sf::Vector2f mouse_pos);
	void erase_form();
	void fill_form(std::vector<std::string>& data);
	void scroll_entities(int delta);
};

class Patient_Appointment_Screen : public Screen {
private:
	std::string appointment_id;

public:
	Patient_Appointment_Screen(int w_width, int w_height);
	void erase_form();
	void fill_form(std::vector<std::string>& data);
	std::vector<std::string> extract_form(sf::Vector2f mouse_pos);
};

class Presc_Appointment_Screen : public Screen {
public:
	Presc_Appointment_Screen(int w_width, int w_height);
	void fill_form(std::vector<std::string>& data);
	void erase_form();
	std::vector<std::string> extract_form(sf::Vector2f mouse_pos);
};

class Tests_Appointment_Screen : public Screen {
public:
	Tests_Appointment_Screen(int w_width, int w_height);
	void fill_form(std::vector<std::string>& data);
	void erase_form();
	std::vector<std::string> extract_form(sf::Vector2f mouse_pos);
};

class Admit_Appointment_Screen : public Screen {
private:
	std::string patient_id;
	std::string doctor_id;

public:
	Admit_Appointment_Screen(int w_width, int w_height);
	void fill_form(std::vector<std::string>& data);
	void erase_form();
	std::vector<std::string> extract_form(sf::Vector2f mouse_pos);
};

class Patient_Record_Screen : public Screen {
private:
	std::vector<sf::Vector2f> entity_pos;
	int curr_entity_index;
	sf::Vector2f scroll_window_size;
	sf::Vector2f scroll_window_pos;

public:
	Patient_Record_Screen(int w_width, int w_height);
	std::vector<std::string> extract_form(sf::Vector2f mouse_pos);
	void erase_form();
	void fill_form(std::vector<std::string>& data);
	void scroll_entities(int delta);
};

class Patient_Details_Home_Screen : public Screen {
private:
	std::string patient_id;

public:
	Patient_Details_Home_Screen(int w_width, int w_height);
	void fill_form(std::vector<std::string>& data);
	std::vector<std::string> extract_form(sf::Vector2f mouse_pos);
};

class Test_History_Screen : public Screen {
private:
	std::vector<sf::Vector2f> entity_pos;
	int curr_entity_index;
	sf::Vector2f scroll_window_size;
	sf::Vector2f scroll_window_pos;

public:
	Test_History_Screen(int w_width, int w_height);
	std::vector<std::string> extract_form(sf::Vector2f mouse_pos);
	void erase_form();
	void fill_form(std::vector<std::string>& data);
	void scroll_entities(int delta);
};

class Appointment_History_Screen : public Screen {
private:
	std::vector<sf::Vector2f> entity_pos;
	int curr_entity_index;
	sf::Vector2f scroll_window_size;
	sf::Vector2f scroll_window_pos;

public:
	Appointment_History_Screen(int w_width, int w_height);
	std::vector<std::string> extract_form(sf::Vector2f mouse_pos);
	void erase_form();
	void fill_form(std::vector<std::string>& data);
	void scroll_entities(int delta);
};

class Patient_Details_Screen : public Screen {
public:
	Patient_Details_Screen(int w_width, int w_height);
};

class Test_Results_Screen : public Screen {
public:
	Test_Results_Screen(int w_width, int w_height);
	void fill_form(std::vector<std::string>& data);
	void erase_form();
};

class Presc_Given_Screen : public Screen {
public:
	Presc_Given_Screen(int w_width, int w_height);
	void erase_form();
	void fill_form(std::vector<std::string>& data);
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
	sf::Vector2f scroll_window_size;
	sf::Vector2f scroll_window_pos;

public:
	Pending_Tests_Screen(int w_width, int w_height);
	std::vector<std::string> extract_form(sf::Vector2f mouse_pos);
	void erase_form();
	void fill_form(std::vector<std::string>& data);
	void scroll_entities(int delta);
};

class Push_Test_Results_Screen : public Screen {
public:
	Push_Test_Results_Screen(int w_width, int w_height);
	void erase_form();
	void fill_form(std::vector<std::string>& data);
	std::vector<std::string> extract_form(sf::Vector2f mouse_pos);
};