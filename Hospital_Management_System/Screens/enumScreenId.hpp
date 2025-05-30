#pragma once

enum class ScreenId;

enum class ScreenId {
	_exit                   = (-2),
	_default                = (-1),
	home                    = 0,
	frontdesk_login         = 1,
	frontdesk_home          = 2,
	patient_register        = 3,
	patient_update          = 4,
	patient_login           = 5,
	patient_home            = 6,
	update_login_patient    = 7,
	doctor_login            = 8,
	doctor_home             = 9,
	appointment             = 10,
	patient_appointment     = 11,
	presc_appointment       = 12,
	tests_appointment       = 13,
	admit_appointment       = 14,
	patient_record          = 15,
	patient_details_home    = 16,
	test_history            = 17,
	appointment_history     = 18,
	patient_details         = 19,
	test_results            = 20,
	presc_given             = 21,
	my_information          = 22,
	dataentry_login         = 23,
	dataentry_login_patient = 24,
	pending_tests           = 25,
	push_test_results       = 26,
	patient_information     = 27,
	admit                   = 28, 
	discharge               = 29,
	schedule_appointment    = 30,
	schedule_tests          = 31,
	admit_history           = 32,
	choose_room             = 33,
	frontdesk_admit_patient = 34,
	admin_login             = 35,
	admin_home              = 36,
	appointment_slots       = 37,
	approve_appointment     = 38,
	test_slots              = 39,
	approve_test            = 40,
	manage_doctor           = 41,
	register_doctor         = 42,
	delete_doctor           = 43,
	update_doctor           = 44,
	update_doctor_details   = 45,
	view_doctor_filters     = 46,
	view_doctor             = 47,
	view_patient_filters    = 48,
	view_patient            = 49,
	manage_patient          = 50
};