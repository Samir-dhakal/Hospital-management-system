Hospital Management System

Overview

The Hospital Management System is a console-based program written in C. It is designed to manage patient and doctor records efficiently using file handling. This project is a lightweight solution for basic hospital record management.

Features

Add Patient Records:

Input and store patient details such as ID, name, phone number, gender, age, and time of admission.

Records are saved in the file patan.txt.

View Patient Records:

Display all patient records stored in the system.

Add Doctor Records:

Input and store doctor details such as ID, name, phone number, and specialization.

Records are saved in the file doctor.txt.

View Doctor Records:

Display all doctor records stored in the system.

Search Patient Records:

Search for a specific patient by their name.

How to Run

Clone the Repository

git clone <repository-url>
cd hospital-management-system

Compile the Program
Use a C compiler (e.g., GCC) to compile the program:

gcc hospital_management_system.c -o hospital_management_system

Run the Program

./hospital_management_system

File Details

hospital_management_system.c: Contains the source code of the program.

patan.txt: Stores patient records (generated after running the program).

doctor.txt: Stores doctor records (generated after running the program).

Example Menu Options

Add new patient records.

View all patient records.

Add doctor records.

View all doctor records.

Search for a patient by name.

Exit the program.

Requirements

Programming Language: C

Compiler: GCC or any standard C compiler

Contribution

Contributions are welcome! If you have ideas for improving the program, feel free to fork the repository, make your changes, and submit a pull request.

Future Enhancements

Input validation for IDs, phone numbers, and other data fields.

Enhanced search functionality to allow partial matches.

Data encryption for securing sensitive records.

Transition to a graphical user interface (GUI).

License

This project is open-source and available for personal and educational use under the MIT License.

Feel free to contribute or suggest improvements to make this project more robust!