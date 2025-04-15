#pragma once

enum class FuncType;

enum class FuncType {
	_default						= (-1),
	register_patient				= 0,
	update_patient					= 1,
	get_patient_data				= 2,
	generate_patient_id				= 3,
	get_patient_med_data			= 4,
	get_patient_tests				= 5,
	get_test_data					= 6,
	push_test_data                  = 7,
	get_appointment_data			= 8,
	check_doctor_id					= 9,
	get_appointment_patient_data	= 10,
	get_meeting_data                = 11,
	push_presc                      = 12,
	push_tests                      = 13,
	admit_patient                   = 14,
	appointment_done                = 15,
	get_patient_record				= 16,
	get_test_history				= 17,
	get_complete_test_data			= 18,
	get_appointment_history			= 19,
	get_presc_data					= 20,
	get_patient_information         = 21,
	get_doctor_data					= 22
};