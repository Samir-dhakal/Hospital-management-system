# Hospital Management System

## Overview
The *Hospital Management System* is a console-based program written in C. It is designed to manage patient and doctor records efficiently using file handling. This project provides a lightweight solution for basic hospital record management.

---

## Features

### 1. Add Patient Records
- Input and store patient details such as:
  - ID
  - Name
  - Phone Number
  - Gender
  - Age
  - Time of Admission
- Records are saved in the file patan.txt.

### 2. View Patient Records
- Display all patient records stored in the system.

### 3. Add Doctor Records
- Input and store doctor details such as:
  - ID
  - Name
  - Phone Number
  - Specialization
- Records are saved in the file doctor.txt.

### 4. View Doctor Records
- Display all doctor records stored in the system.

### 5. Search Patient Records
- Search for a specific patient by their name.

---

## How to Run

### Clone the Repository
git clone <repository-link>
cd hospital-management-system

### Compile the Program
Use a C compiler (e.g., GCC) to compile the program:
gcc hospital_management_system.c -o hospital_management_system

### Run the Program
./hospital_management_system

---

## File Details
- *hospital_management_system.c*: Contains the source code of the program.
- *patan.txt*: Stores patient records (generated after running the program).
- *doctor.txt*: Stores doctor records (generated after running the program).

---

## Example Menu Options
1. Add new patient records.
2. View all patient records.
3. Add doctor records.
4. View all doctor records.
5. Search for a patient by name.
6. Exit the program.

---

## Requirements
- *Programming Language*: C
- *Compiler*: GCC or any standard C compiler

---

## Contribution
Contributions are welcome! If you have ideas for improving the program, feel free to:
1. Fork the repository.
2. Make your changes.
3. Submit a pull request.

---

## Future Enhancements
- Input validation for IDs, phone numbers, and other data fields.
- Enhanced search functionality to allow partial matches.
- Data encryption for securing sensitive records.
- Transition to a graphical user interface (GUI).

---

## License
This project is open-source and available for personal and educational use under the *MIT License*.

---

Feel free to contribute or suggest improvements to make this project more robust!