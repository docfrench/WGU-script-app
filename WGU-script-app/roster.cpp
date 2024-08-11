#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <array>
#include "roster.h"
#include "degree.h"
#include "student.h"
#include "student.cpp"

class Roster {
public:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int Age{};
	int daysInCourse[3];
	//int daysInCourse1{};
	//int daysInCourse2{};
	//int daysInCourse3{};
	DegreeProgram degreeProgram{};
	int rosterSize{};
	Student* classRosterArray = new Student[10];

	Roster(int rosterSize) {
		delete[] classRosterArray;
		Student* classRosterArray = new Student[rosterSize];
	}

	void printInvalidEmails(int rosterSize) {
		std::cout << "Invalid email addresses:" << std::endl;
		for (int i = 0; i < rosterSize; i++)
		{
			std::string emailTemp = classRosterArray[i].getemailAddress();
			if (emailTemp.find("@") == std::string::npos || emailTemp.find(".") == std::string::npos || emailTemp.find(" ") != std::string::npos) // Email address must include '@' and '.' and must not include ' '
			{
				std::cout << classRosterArray[i].getstudentID() << ": " << emailTemp << std::endl;
			}
		}
		std::cout << std::endl;
	}

	void printAll(int rosterSize) {
		std::cout << "Full Roster:" << std::endl;
		for (int i = 0; i < rosterSize; i++)
		{
			classRosterArray[i].print();
		}
		std::cout << std::endl;
	}

	void printAverageDaysInCourse(int rosterSize) 
	{
		std::cout << "Average Days in Course:" << std::endl;
		int dayAverage = 0; 
		for (int i = 0; i < rosterSize; i++)
		{
		dayAverage = (classRosterArray[i].getdaysInCourse1() + classRosterArray[i].getdaysInCourse2() + classRosterArray[i].getdaysInCourse3()) / 3;
		std::cout << classRosterArray[i].getstudentID() << ": " << dayAverage << std::endl;
		}
		std::cout << std::endl;
	}

	
	std::string getDegreeProgramName(DegreeProgram input) { 
		switch (input) {
		case 0: return "SECURITY";
		case 1: return "NETWORK";
		case 2: return "SOFTWARE";
		}
	}//translate enum --> str

	void printByDegreeProgram(DegreeProgram inputString, int rosterSize) {

		std::cout << "Students enrolled in " << getDegreeProgramName(inputString) << ": " << std::endl;
		for (int i = 0; i < rosterSize; i++)
		{
			if (classRosterArray[i].getDegreeProgram() == inputString)
			{
				classRosterArray[i].print();
			}
		}
		std::cout << std::endl;
	}

	void dataParse(const std::string dataIngest[], int rosterSize) {
		int counter = 0;
		DegreeProgram degreeProgram;
		for (int record = 0; record < rosterSize; record++) {
			std::string ingestArray[9];
			std::string studentRecord = dataIngest[record];
			for (int letter = 0; letter < studentRecord.length() + 1; letter++) {
				if (studentRecord[letter] == ',')
				{
					counter++;
				}
				else if (letter == studentRecord.length())
				{
					ingestArray[counter] += studentRecord[letter];
					counter = 0;
					if (ingestArray[8].find("SECU") != std::string::npos)  // Translate str --> enum
					{
						degreeProgram = { SECURITY };
					}
					else if (ingestArray[8].find("SOFT") != std::string::npos)
					{
						degreeProgram = { SOFTWARE };
					}
					else if (ingestArray[8].find("NETW") != std::string::npos)
					{
						degreeProgram = { NETWORK };
					}
					add(ingestArray[0], ingestArray[1], ingestArray[2], ingestArray[3], std::stoi(ingestArray[4]), std::stoi(ingestArray[5]), std::stoi(ingestArray[6]), std::stoi(ingestArray[7]), degreeProgram, record);
				}
				else
				{
					ingestArray[counter] += studentRecord[letter];
				}
			}
		}
	}
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram, int record) {
		classRosterArray[record].setstudentID(studentID);
		classRosterArray[record].setfirstName(firstName);
		classRosterArray[record].setlastName(lastName);
		classRosterArray[record].setemailAddress(emailAddress);
		classRosterArray[record].setAge(age);
		classRosterArray[record].setdaysInCourse1(daysInCourse1);
		classRosterArray[record].setdaysInCourse2(daysInCourse2);
		classRosterArray[record].setdaysInCourse3(daysInCourse3);
		classRosterArray[record].setDegreeProgram(degreeProgram);
	}

	void remove(std::string studentID, int rosterSize) {
		std::cout << "Removing student ID: " << studentID << std::endl;
		int exist = 0; // First check if exists
		for (int i = 0; i < rosterSize; i++)
		{
			if (classRosterArray[i].getstudentID() == studentID)
			{
				exist++;
			}
		}
		if (exist == 0)
		{
			std::cout << "Student with this ID does not exist" << std::endl;
		}
		else // then copy data to new array
		{
			Student* tempArray = new Student[rosterSize];
			int counterTemp = 0;
			for (int i = 0; i < rosterSize; i++)
			{
				tempArray[i].setstudentID(classRosterArray[i].getstudentID());
				tempArray[i].setfirstName(classRosterArray[i].getfirstName());
				tempArray[i].setlastName(classRosterArray[i].getlastName());
				tempArray[i].setemailAddress(classRosterArray[i].getemailAddress());
				tempArray[i].setAge(classRosterArray[i].getAge());
				tempArray[i].setdaysInCourse1(classRosterArray[i].getdaysInCourse1());
				tempArray[i].setdaysInCourse2(classRosterArray[i].getdaysInCourse2());
				tempArray[i].setdaysInCourse3(classRosterArray[i].getdaysInCourse3());
				tempArray[i].setDegreeProgram(classRosterArray[i].getDegreeProgram());
			}
			delete[] classRosterArray;
			Student* classRosterArray = new Student[rosterSize - 1]; // make smaller array and copy back wanted data

			for (int i = 0; i < rosterSize; i++)
			{
				if (tempArray[i].getstudentID() != studentID)
				{
					classRosterArray[counterTemp].setstudentID(tempArray[i].getstudentID());
					classRosterArray[counterTemp].setfirstName(tempArray[i].getfirstName());
					classRosterArray[counterTemp].setlastName(tempArray[i].getlastName());
					classRosterArray[counterTemp].setemailAddress(tempArray[i].getemailAddress());
					classRosterArray[counterTemp].setAge(tempArray[i].getAge());
					classRosterArray[counterTemp].setdaysInCourse1(tempArray[i].getdaysInCourse1());
					classRosterArray[counterTemp].setdaysInCourse2(tempArray[i].getdaysInCourse2());
					classRosterArray[counterTemp].setdaysInCourse3(tempArray[i].getdaysInCourse3());
					classRosterArray[counterTemp].setDegreeProgram(tempArray[i].getDegreeProgram());
					counterTemp++;
				}
				else if (tempArray[i].getstudentID() == studentID)
				{
					std::cout << "Found and deleted: " << tempArray[i].getstudentID() << std::endl << std::endl;
				}
			}
			delete[] tempArray;
		}
	}
	
	~Roster() {
		delete[] classRosterArray;
		std::cout << "destructor called" << std::endl;
	}
};
