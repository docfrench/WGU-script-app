#pragma once
#include <iostream>
#include <stdlib.h>
#include "student.h"
#include "degree.h"

class Student {
	private:
		std::string studentID;
		std::string firstName;
		std::string lastName;
		std::string emailAddress;
		int Age;
		int daysInCourse1;
		int daysInCourse2;
		int daysInCourse3;
		DegreeProgram degreeProgram;

	public:
		//Getters
		std::string getstudentID() {
			return studentID;
		}
		std::string getfirstName() {
			return firstName;
		}
		std::string getlastName() {
			return lastName;
		}
		std::string getemailAddress() {
			return emailAddress;
		}
		int getAge() {
			return Age;
		}
		int getdaysInCourse1() {
			return daysInCourse1;
		}
		int getdaysInCourse2() {
			return daysInCourse2;
		}
		int getdaysInCourse3() {
			return daysInCourse3;
		}
		DegreeProgram getDegreeProgram() {
			return degreeProgram;
		}
		std::string getDegreeProgramName(DegreeProgram input) {
			switch (input) {
			case DegreeProgram::SECURITY: return "SECURITY";
			case DegreeProgram::NETWORK: return "NETWORK";
			case DegreeProgram::SOFTWARE: return "SOFTWARE";
			}
		}
		void print() {
			std::cout << this->studentID << "\t";
			std::cout << "First Name: " << this->firstName << "\t";
			std::cout << "Last Name: " << this->lastName << "\t";
			std::cout << "Age: " << this->Age << "\t";
			std::cout << "daysInCourse: { " << this->daysInCourse1 << ", " << this->daysInCourse2 << ", " << this->daysInCourse3 << " }\t";
			std::cout << "Degree Program: " << getDegreeProgramName(this->degreeProgram) << "\t" << std::endl;
		}

		//Setters
		void setstudentID(std::string studentID) {
			this->studentID = studentID;
		}
		void setfirstName(std::string firstName) {
			this->firstName = firstName;
		}
		void setlastName(std::string lastName) {
			this->lastName = lastName;
		}
		void setemailAddress(std::string emailAddress) {
			this->emailAddress = emailAddress;
		}
		void setAge(int Age) {
			this->Age = Age;
		}
		void setdaysInCourse1(int daysInCourse1) {
			this->daysInCourse1 = daysInCourse1;
		}
		void setdaysInCourse2(int daysInCourse2) {
			this->daysInCourse2 = daysInCourse2;
		}
		void setdaysInCourse3(int daysInCourse3) {
			this->daysInCourse3 = daysInCourse3;
		}

		void setDegreeProgram(DegreeProgram degreeProgram) {
			this->degreeProgram = degreeProgram;
		}
		//Constructor
		
		Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int Age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
		{
			this->studentID = studentID;
			this->firstName = firstName;
			this->lastName = lastName;
			this->emailAddress = emailAddress;
			this->Age = Age;
			this->daysInCourse1 = daysInCourse1;
			this->daysInCourse2 = daysInCourse2;
			this->daysInCourse3 = daysInCourse3;
			this->degreeProgram = degreeProgram;
		}
		Student() {
			this->studentID = "Z0";
			this->firstName = "Tommy";
			this->lastName = "Test";
			this->emailAddress = "no_emailAddress";
			this->Age = 101;
			this->daysInCourse1 = 4000;
			this->daysInCourse2 = 20;
			this->daysInCourse3 = 300;
			this->degreeProgram = { NETWORK };
		}
		
		
};
