#pragma once

enum class ScreenId;

enum class ScreenId {
	_default			 = (-1),
	home				 = 0,
	frontdesk_login		 = 1,
	frontdesk_home		 = 2,
	patient_register	 = 3,
	patient_update		 = 4,
	patient_login		 = 5,
	patient_home		 = 6,
	update_login_patient = 7,
	doctor_login         = 8,
	doctor_home          = 9,
	appointment          = 10,
	patient_appointment  = 11,
	presc_appointment    = 12,
	tests_appointment    = 13,
	admit_appointment    = 14,
	patient_record       = 15,
	patient_details_home = 16,
	test_history         = 17,
	appointment_history  = 18,
	patient_details      = 19,
	test_results         = 20,
	presc_given          = 21,
	my_information       = 22
};