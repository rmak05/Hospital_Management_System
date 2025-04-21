/* HOSPITAL MANAGEMENT SYSTEM DATABASE */

DROP DATABASE Hospital_Management;
CREATE DATABASE Hospital_Management;
USE Hospital_Management;

/* Patient registered in the hospital and data stored with unique patient id */
CREATE TABLE patient(
	patient_id BIGINT,
    name VARCHAR(100),
    age INT,
    gender VARCHAR(1),
    phone BIGINT,
    address VARCHAR(200),
    email VARCHAR(200),
    PRIMARY KEY(patient_id)
);

/* Information of the doctors working in the hospital are stored in the database
   with each doctor assigned a unique doctor_id */
CREATE TABLE doctor(
	doctor_id INT,
    name VARCHAR(100),
    age INT,
    gender VARCHAR(1),
    phone BIGINT,
    email VARCHAR(200),
    address VARCHAR(200),
    speciality VARCHAR(100),
    designation VARCHAR(100),
    salary INT,
    PRIMARY KEY(doctor_id)
);

/* This table contains all the rooms of the hospital 
   room type includes doctor's Office, differenct labs for tests and treatements,
   and rooms to admit a patient which can have capacity >= 1 */
CREATE TABLE room(
	room_id VARCHAR(10),
    type VARCHAR(100),
    capacity INT,
    PRIMARY KEY(room_id)
);

/* This table contains all equipments which can be used in hospital in
   different labs for tests and treatements  */
CREATE TABLE equipment(
	equipment_name VARCHAR(100),
    price INT,
    PRIMARY KEY(equipment_name)
);

/* This table stores doctor's office*/
CREATE TABLE has_office(
	doctor_id INT,
    room_id VARCHAR(10),
    PRIMARY KEY(doctor_id),
    FOREIGN KEY(doctor_id) REFERENCES doctor(doctor_id) ON DELETE CASCADE,
    FOREIGN KEY(room_id) REFERENCES room(room_id) ON DELETE CASCADE
);

/* appointment table stores the appointment between a doctor and a patient with 
   date, time, priority index and room id that is doctor's office
   is_pending if 0 means appointment is over and stored as history
   while if it is 1 then appointment is yet to occur */
CREATE TABLE appointment(
	appointment_id INT,
	patient_id BIGINT,
    doctor_id INT,
    room_id VARCHAR(10),
    date VARCHAR(50),
    time VARCHAR(50),
    priority INT,
    is_pending INT,
    PRIMARY KEY(appointment_id),
    FOREIGN KEY(patient_id) REFERENCES patient(patient_id) ON DELETE CASCADE,
    FOREIGN KEY(doctor_id) REFERENCES doctor(doctor_id) ON DELETE CASCADE,
    FOREIGN KEY(room_id) REFERENCES room(room_id) ON DELETE CASCADE
);

/* treated_by stores the information about which patient is treated by which doctor
   this will be updated when doctor will admit a patient in a hospital
   here is_current has two values - 0 and 1
   0 represents that patient was treated in past and now stored as history
   1 represents that patient is currently treated by doctor
   so is_currently keeps track history and present information */
CREATE TABLE treated_by(
	patient_id BIGINT,
    doctor_id INT,
    is_currently INT,
    FOREIGN KEY(patient_id) REFERENCES patient(patient_id) ON DELETE CASCADE,
    FOREIGN KEY(doctor_id) REFERENCES doctor(doctor_id) ON DELETE CASCADE
);

/* is_admitted stores the information that a patient is admitted or not in hospital room
   a patient id will only be pushed in this table when it is admitted to a room
   is_scheduled = 0 means patient is not currently admitted in the room so admit date and time will be null
   is_scheduled = 1 means patient admitted and fill admit date and time
   is_admit = 1 means patient currently admitted in the room so discharge date and time will be null
   otherwise if it is 0 then patient discharged so stores the patient discharged info in past*/
CREATE TABLE is_admitted(
	patient_id BIGINT,
    room_id VARCHAR(10),
    admit_date VARCHAR(50),
    admit_time VARCHAR(50),
    discharge_date VARCHAR(50),
    discharge_time VARCHAR(50),
    disease_name VARCHAR(50),
    is_scheduled INT,
    is_admit INT,
    FOREIGN KEY(patient_id) REFERENCES patient(patient_id) ON DELETE CASCADE,
    FOREIGN KEY(room_id) REFERENCES room(room_id) ON DELETE CASCADE
);

/* For a particular appointment a doctor will give a prescription to the patient
   this table stores that prescription information */
CREATE TABLE prescription(
	appointment_id INT,
    disease_name VARCHAR(100),
    symptoms VARCHAR(200),
    medicine_name VARCHAR(100),
    presc VARCHAR(200),
    PRIMARY KEY(appointment_id),
    FOREIGN KEY(appointment_id) REFERENCES appointment(appointment_id) ON DELETE CASCADE
);

/* This table contains the information for the tests that doctor prescribed to the patient
   test contains the name of the test and results contain the results of the test
   is_scheduled = 0 means it is not scheduled yet so date, time, results will be null
   is_scheduled = 1 meands it is scheduled so only results will be null and date, time for test will be given
   is_pending = 1 means test not completed yet so results will be null
   is_pending = 0 means test completed so results will not be null and this data stored as history */
CREATE TABLE test(
	test_id INT,
	patient_id BIGINT,
    doctor_id INT,
    room_id VARCHAR(10),
    test VARCHAR(100),
    equipment_name VARCHAR(100),
    date VARCHAR(50),
    time VARCHAR(50),
    results VARCHAR(200),
    is_scheduled INT,
    is_pending INT,
    PRIMARY KEY(test_id),
    FOREIGN KEY(patient_id) REFERENCES patient(patient_id) ON DELETE CASCADE,
    FOREIGN KEY(doctor_id) REFERENCES doctor(doctor_id) ON DELETE CASCADE,
    FOREIGN KEY(room_id) REFERENCES room(room_id) ON DELETE CASCADE,
    FOREIGN KEY(equipment_name) REFERENCES equipment(equipment_name) ON DELETE CASCADE
);

/* Doctor data */
INSERT INTO doctor VALUES
(101, 'Dr. Ananya Sharma', 45, 'F', 9876543210, 'ananya.sharma@hospital.com', '12 Green Park, Delhi', 'Cardiology', 'Senior Consultant', 180000),
(102, 'Dr. Rajeev Mehra', 50, 'M', 9876543211, 'rajeev.mehra@hospital.com', '25 South City, Mumbai', 'Orthopedics', 'Head of Department', 200000),
(103, 'Dr. Priya Nair', 38, 'F', 9876543212, 'priya.nair@hospital.com', '7 Lake View, Kochi', 'Dermatology', 'Consultant', 130000),
(104, 'Dr. Vikram Sinha', 42, 'M', 9876543213, 'vikram.sinha@hospital.com', '32 Residency Road, Bangalore', 'Neurology', 'Senior Consultant', 175000),
(105, 'Dr. Meenal Kapoor', 36, 'F', 9876543214, 'meenal.kapoor@hospital.com', '11 Model Town, Chandigarh', 'Pediatrics', 'Consultant', 125000),
(106, 'Dr. Sameer Khan', 48, 'M', 9876543215, 'sameer.khan@hospital.com', '56 Marine Drive, Mumbai', 'General Surgery', 'Head Surgeon', 190000),
(107, 'Dr. Sneha Rao', 35, 'F', 9876543216, 'sneha.rao@hospital.com', '22 Banjara Hills, Hyderabad', 'Endocrinology', 'Consultant', 140000),
(108, 'Dr. Arvind Joshi', 52, 'M', 9876543217, 'arvind.joshi@hospital.com', '9 Sector 14, Gurgaon', 'Radiology', 'Head of Department', 195000),
(109, 'Dr. Neha Desai', 40, 'F', 9876543218, 'neha.desai@hospital.com', '8 Ashoka Nagar, Pune', 'Obstetrics & Gynecology', 'Senior Consultant', 170000),
(110, 'Dr. Rohan Das', 34, 'M', 9876543219, 'rohan.das@hospital.com', '10 Indira Nagar, Lucknow', 'Psychiatry', 'Consultant', 120000),
(111, 'Dr. Kavita Iyer', 47, 'F', 9876543220, 'kavita.iyer@hospital.com', '3 Jubilee Hills, Hyderabad', 'Pathology', 'Senior Pathologist', 160000),
(112, 'Dr. Manish Agarwal', 41, 'M', 9876543221, 'manish.agarwal@hospital.com', '21 Park Street, Kolkata', 'Anesthesiology', 'Consultant', 135000),
(113, 'Dr. Leena Paul', 37, 'F', 9876543222, 'leena.paul@hospital.com', '15 MG Road, Bangalore', 'ENT', 'Consultant', 125000),
(114, 'Dr. Siddharth Roy', 44, 'M', 9876543223, 'siddharth.roy@hospital.com', '14 Salt Lake, Kolkata', 'Urology', 'Senior Consultant', 165000),
(115, 'Dr. Ritu Verma', 39, 'F', 9876543224, 'ritu.verma@hospital.com', '5 Vasant Kunj, Delhi', 'Gastroenterology', 'Consultant', 145000),
(116, 'Dr. Nilesh Gupta', 46, 'M', 9876543225, 'nilesh.gupta@hospital.com', '19 Sector 21, Noida', 'Nephrology', 'Senior Consultant', 175000),
(117, 'Dr. Aarti Menon', 39, 'F', 9876543226, 'aarti.menon@hospital.com', '55 Lake Gardens, Kolkata', 'Oncology', 'Consultant', 155000),
(118, 'Dr. Pankaj Verma', 50, 'M', 9876543227, 'pankaj.verma@hospital.com', '88 Kothrud, Pune', 'Pulmonology', 'Senior Consultant', 165000),
(119, 'Dr. Snehal Patil', 34, 'F', 9876543228, 'snehal.patil@hospital.com', '5 Hinjewadi, Pune', 'ENT', 'Consultant', 130000),
(120, 'Dr. Harish Reddy', 45, 'M', 9876543229, 'harish.reddy@hospital.com', '3 Jubilee Hills, Hyderabad', 'Orthopedics', 'Consultant', 160000),
(121, 'Dr. Seema Saxena', 48, 'F', 9876543230, 'seema.saxena@hospital.com', '28 Rajouri Garden, Delhi', 'Dermatology', 'Senior Consultant', 170000),
(122, 'Dr. Ramesh Shetty', 52, 'M', 9876543231, 'ramesh.shetty@hospital.com', '7 Basavanagudi, Bangalore', 'Radiology', 'Consultant', 150000),
(123, 'Dr. Akshita Mehra', 37, 'F', 9876543232, 'akshita.mehra@hospital.com', '14 Model Town, Ludhiana', 'Psychiatry', 'Consultant', 140000),
(124, 'Dr. Deepak Chawla', 43, 'M', 9876543233, 'deepak.chawla@hospital.com', '23 Saket, Delhi', 'Pathology', 'Consultant', 145000),
(125, 'Dr. Pallavi Joshi', 41, 'F', 9876543234, 'pallavi.joshi@hospital.com', '10 Malviya Nagar, Jaipur', 'Gastroenterology', 'Consultant', 150000);

/* Room data */
INSERT INTO room VALUES
('R101', 'Doctor Office', 1),
('R102', 'Doctor Office', 1),
('R103', 'Doctor Office', 1),
('R104', 'Doctor Office', 1),
('R105', 'Doctor Office', 1),
('R201', 'Doctor Office', 1),
('R202', 'Doctor Office', 1),
('R203', 'Doctor Office', 1),
('R204', 'Doctor Office', 1),
('R205', 'Doctor Office', 1),
('R301', 'Doctor Office', 1),
('R302', 'Doctor Office', 1),
('R303', 'Doctor Office', 1),
('R304', 'Doctor Office', 1),
('R305', 'Doctor Office', 1),
('R401', 'Doctor Office', 1),
('R402', 'Doctor Office', 1),
('R403', 'Doctor Office', 1),
('R404', 'Doctor Office', 1),
('R405', 'Doctor Office', 1),
('R501', 'Doctor Office', 1),
('R502', 'Doctor Office', 1),
('R503', 'Doctor Office', 1),
('R504', 'Doctor Office', 1),
('R505', 'Doctor Office', 1),

('L101', 'Pathology Lab', 5),
('L102', 'Radiology Lab', 3),
('L103', 'Microbiology Lab', 4),
('L104', 'Biochemistry Lab', 4),
('L105', 'Hematology Lab', 3),
('L201', 'Histopathology Lab', 2),
('L202', 'ECG & Cardiology Lab', 2),
('L203', 'Molecular Biology Lab', 2),
('L204', 'Blood Bank', 3),
('L205', 'Nuclear Medicine Lab', 2),
('L301', 'Clinical Chemistry Lab', 3),
('L302', 'Serology & Immunology Lab', 3),
('L303', 'Audiometry & ENT Lab', 2),
('L304', 'Ophthalmology Lab', 2),
('L305', 'Toxicology Lab', 2),
('L401', 'Virology Lab', 2),
('L402', 'Cytogenetics Lab', 2),
('L403', 'Sleep Study Lab', 2),
('L404', 'Dialysis Unit Lab', 3),
('L405', 'Allergy Testing Lab', 2),
('L501', 'Neonatal Screening Lab', 2),
('L502', 'Occupational Health Lab', 2),
('L503', 'Endocrinology Lab', 2),
('L504', 'Clinical Pharmacology Lab', 2),
('L505', 'Bone Densitometry Lab', 1),

('OT101', 'Operation Theater' , 1),
('OT102', 'Operation Theater' , 1),
('OT201', 'Operation Theater' , 1),
('OT202', 'Operation Theater' , 1),
('OT301', 'Operation Theater' , 1),
('OT302', 'Operation Theater' , 1),
('OT401', 'Operation Theater' , 1),
('OT402', 'Operation Theater' , 1),
('OT501', 'Operation Theater' , 1),
('OT502', 'Operation Theater' , 1),

('P101', 'General Ward', 6),
('P102', 'General Ward', 6),
('P103', 'Semi Private Room', 2),
('P104', 'Semi Private Room', 2),
('P105', 'Semi Private Room', 2),
('P106', 'Semi Private Room', 2),
('P107', 'Semi Private Room', 2),
('P108', 'Private Room', 1),
('P109', 'Private Room', 1),
('P110', 'Private Room', 1),
('P111', 'Private Room', 1),
('P112', 'Private Room', 1),
('P113', 'Private Room', 1),
('P114', 'Private Room', 1),
('P115', 'Private Room', 1),
('P201', 'General Ward', 6),
('P202', 'General Ward', 6),
('P203', 'Semi Private Room', 2),
('P204', 'Semi Private Room', 2),
('P205', 'Semi Private Room', 2),
('P206', 'Semi Private Room', 2),
('P207', 'Semi Private Room', 2),
('P208', 'Private Room', 1),
('P209', 'Private Room', 1),
('P210', 'Private Room', 1),
('P211', 'Private Room', 1),
('P212', 'Private Room', 1),
('P213', 'Private Room', 1),
('P214', 'Private Room', 1),
('P215', 'Private Room', 1),
('P301', 'General Ward', 6),
('P302', 'General Ward', 6),
('P303', 'Semi Private Room', 2),
('P304', 'Semi Private Room', 2),
('P305', 'Semi Private Room', 2),
('P306', 'Semi Private Room', 2),
('P307', 'Semi Private Room', 2),
('P308', 'Private Room', 1),
('P309', 'Private Room', 1),
('P310', 'Private Room', 1),
('P311', 'Private Room', 1),
('P312', 'Private Room', 1),
('P313', 'Private Room', 1),
('P314', 'Private Room', 1),
('P315', 'Private Room', 1),
('P401', 'General Ward', 6),
('P402', 'General Ward', 6),
('P403', 'Semi Private Room', 2),
('P404', 'Semi Private Room', 2),
('P405', 'Semi Private Room', 2),
('P406', 'Semi Private Room', 2),
('P407', 'Semi Private Room', 2),
('P408', 'Private Room', 1),
('P409', 'Private Room', 1),
('P410', 'Private Room', 1),
('P411', 'Private Room', 1),
('P412', 'Private Room', 1),
('P413', 'Private Room', 1),
('P414', 'Private Room', 1),
('P415', 'Private Room', 1),
('P501', 'General Ward', 6),
('P502', 'General Ward', 6),
('P503', 'Semi Private Room', 2),
('P504', 'Semi Private Room', 2),
('P505', 'Semi Private Room', 2),
('P506', 'Semi Private Room', 2),
('P507', 'Semi Private Room', 2),
('P508', 'Private Room', 1),
('P509', 'Private Room', 1),
('P510', 'Private Room', 1),
('P511', 'Private Room', 1),
('P512', 'Private Room', 1),
('P513', 'Private Room', 1),
('P514', 'Private Room', 1),
('P515', 'Private Room', 1);


/* Equipment data */
INSERT INTO equipment VALUES
('MRI Scanner', 15000000),
('CT Scanner', 12000000),
('X-Ray Machine', 3500000),
('Ultrasound Machine', 2500000),
('ECG Machine', 150000),
('Defibrillator', 200000),
('Ventilator', 500000),
('Dialysis Machine', 800000),
('Hematology Analyzer', 1200000),
('Biochemistry Analyzer', 1000000),
('Centrifuge Machine', 300000),
('Toxicology Analyzer', 900000),
('Viral Load Analyzer', 950000),
('Genetic Sequencer', 5000000),
('Sleep Study Monitor', 600000),
('Allergy Testing Kit', 80000),
('Neonatal Screening Device', 200000),
('Endocrine Hormone Analyzer', 1100000),
('Audiometer', 350000),
('Bone Densitometer (DEXA)', 2500000),
('Anesthesia Workstation', 2500000),
('Operating Table', 1200000),
('Surgical Microscope', 1800000),
('Therapeutic Drug Monitoring System', 750000),
('Pathology Microscope', 200000),
('Pulmonary Function Test (PFT) Machine', 600000),
('Infusion Pump', 90000),
('Sterilizer (Autoclave)', 400000),
('Digital Mammography System', 4000000),
('Endoscopy Unit', 2200000);

/* has_office data */
INSERT INTO has_office VALUES
(101, 'R101'),
(102, 'R102'),
(103, 'R103'),
(104, 'R104'),
(105, 'R105'),
(106, 'R201'),
(107, 'R202'),
(108, 'R203'),
(109, 'R204'),
(110, 'R205'),
(111, 'R301'),
(112, 'R302'),
(113, 'R303'),
(114, 'R304'),
(115, 'R305'),
(116, 'R401'),
(117, 'R402'),
(118, 'R403'),
(119, 'R404'),
(120, 'R405'),
(121, 'R501'),
(122, 'R502'),
(123, 'R503'),
(124, 'R504'),
(125, 'R505');

SELECT * FROM patient; 
SELECT * FROM doctor;
SELECT * FROM room;
SELECT * FROM equipment;
SELECT * FROM has_office;
SELECT * FROM treated_by;
SELECT * FROM is_admitted;
SELECT * FROM test;
SELECT * FROM appointment;
SELECT * FROM prescription;