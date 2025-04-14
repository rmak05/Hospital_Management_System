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
	get_patient_record				= 11
};