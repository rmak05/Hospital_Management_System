# Hospital Management System

This application was made as a part of the course **Database Systems Laboratory (CS3P002)**. This application can be used to maintain records of patients and doctors; and schedule tests and appointments; while having different kinds of data access to various users.

## Tech Stack
- **C++** - Core programming language
- **SFML (Simple and Fast Multimedia Library)** - GUI and multimedia handling
- **MySQL** - Database
- **MySQL Connector C++** - Interface between C++ and MySQL

## Overview of Users

- <u>**Front Desk Operator**</u>

    - Register a new patient.
    - Update patient details.
    - Admit and discharge a patient.
    - Schedule tests and appointments.
    - View a patient's admit history.

- <u>**Data Entry Operator**</u>
    - Push test results.

- <u>**Doctor**</u>

    - Check patient details.
    - Check appointments.
    - Write prescriptions for patients.
    - Send admit requests for patients.
    - Send test requests for patients.

- <u>**Admin**</u>

    - Add, Delete and Update doctor details.
    - View all doctors' details.

## Hospital Workflow

- **Patient Visit and Registration**

    - The Front desk operator registers a new patient.
    - The Front desk operator also schedules an appointment for the patient as per available time slots.

- **Doctor's Appointment**

    - On the scheduled date of the appointment, the doctor accesses the appointment details.
    - The Doctor will issue a prescription if necessary.
    - The Doctor can raise admit and test requests.

- **Handling Requests**

    - The Front desk operator processes and confirms the admit requests.
    - The Front desk operator schedules the tests as raised by the doctor as per available time slots.
    - The Front desk operator can discharge the patients once they have recovered.

- **Tests Management**

    - The Data entry operator can check pending tests of a patient.
    - The Data entry operator updates the system with test results once they have been completed.

- **Follow-up by Doctor**

    - The Doctor can view the test results pushed by the data entry operator.
    - The Doctor can also review the patient's medical history and records.

- **Admin Control**

    - Can register a new doctor.
    - Can update or delete the details of an existing doctor.
    - Can view the details of all doctors, using various filters like age, gender, salary and specialty

## **Contributors**

- **Ravilisetty Makarandh - 22CS01002** ([@rmak05](https://github.com/rmak05))
- **Ishan Kinger - 22CS01014** ([@ishankinger](https://github.com/ishankinger))