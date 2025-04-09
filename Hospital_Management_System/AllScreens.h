#pragma once

#include "Screen.h"

class Home_Screen;
class Front_Desk_Login_Screen;
class Front_Desk_Home_Screen;
class Register_Patient_Screen;
class Update_Patient_Screen;
class Login_Patient_Screen;

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
};

class Update_Patient_Screen : public Screen {
public:
	Update_Patient_Screen(int w_width, int w_height);
};

class Login_Patient_Screen : public Screen {
public:
	Login_Patient_Screen(int w_width, int w_height);
};

class Patient_home_Screen : public Screen {
public:
	Patient_home_Screen(int w_width, int w_height);
};