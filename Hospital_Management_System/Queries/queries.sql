SELECT * 
FROM patient 
WHERE patient_id = 1;


SELECT name, room_id, disease_name 
FROM doctor 
INNER JOIN treated_by 
ON doctor.doctor_id = treated_by.doctor_id 
INNER JOIN is_admitted 
ON treated_by.patient_id = is_admitted.patient_id 
WHERE treated_by.patient_id = 1 AND is_currently = 1 AND is_admit = 1 AND is_scheduled = 1;


SELECT doctor_id, name, speciality, gender 
FROM doctor;


SELECT room_id 
FROM has_office 
WHERE doctor_id = 104; 


(SELECT date, time 
FROM appointment 
WHERE (doctor_id = 104 OR patient_id = 1) AND (is_pending = 1)) 
UNION 
(SELECT date, time 
FROM test 
WHERE patient_id = 1 AND is_scheduled = 1 AND is_pending = 1);


INSERT INTO appointment VALUES 
(14283, 1, 104, 'R102', '2025-4-19', '02:00 PM', 2, 1);


SELECT * 
FROM is_admitted 
WHERE patient_id = 1 AND is_scheduled = 1 AND is_admit = 0;


SELECT * 
FROM patient 
WHERE patient_id = 102;


SELECT * 
FROM patient 
WHERE patient_id = 2;


SELECT name, room_id, disease_name 
FROM doctor 
INNER JOIN treated_by 
ON doctor.doctor_id = treated_by.doctor_id 
INNER JOIN is_admitted 
ON treated_by.patient_id = is_admitted.patient_id 
WHERE treated_by.patient_id = 2 AND is_currently = 1 AND is_admit = 1 AND is_scheduled = 1;


SELECT * 
FROM is_admitted 
WHERE patient_id = 2 AND is_scheduled = 1 AND is_admit = 0;


SELECT test_id, doctor_id, date, time, room_id 
FROM test 
WHERE patient_id = 1 and is_scheduled = 1 and is_pending = 1;


SELECT * 
FROM test 
WHERE test_id = 15;


SELECT doctor_id 
FROM doctor 
WHERE doctor_id = 101;


SELECT appointment_id, patient_id, date, time 
FROM appointment 
WHERE doctor_id = 101 AND is_pending = 1;


SELECT * 
FROM patient 
WHERE patient_id = 2;


SELECT patient_id, patient.name AS patient_name, room_id, disease_name 
FROM patient 
NATURAL JOIN treated_by 
NATURAL JOIN is_admitted 
WHERE doctor_id = 101 AND is_admit = 1;


SELECT * 
FROM patient 
WHERE patient_id = 1;


SELECT * 
FROM patient 
WHERE patient_id = 1;


SELECT doctor.doctor_id, room_id, disease_name 
FROM doctor 
INNER JOIN treated_by 
ON doctor.doctor_id = treated_by.doctor_id 
INNER JOIN is_admitted 
ON treated_by.patient_id = is_admitted.patient_id 
WHERE treated_by.patient_id = 1 AND is_currently = 1 AND is_admit = 1 AND is_scheduled = 1;


SELECT test_id, test, room_id, date, time 
FROM test 
WHERE patient_id = 1 AND is_pending = 0 AND is_scheduled = 1;


SELECT * 
FROM test 
WHERE test_id = 1;


SELECT appointment_id, date, time 
FROM appointment 
WHERE patient_id = 1;


SELECT * 
FROM prescription 
NATURAL JOIN appointment 
WHERE appointment_id = 14283;


SELECT appointment_id, date, time 
FROM appointment 
WHERE patient_id = 1;


SELECT * 
FROM prescription 
NATURAL JOIN appointment 
WHERE appointment_id = 1;


SELECT * 
FROM doctor 
NATURAL JOIN has_office 
WHERE doctor_id = 101;


