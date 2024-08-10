#include <iostream>
#include <string>
#include <stdlib.h>
#include "degree.h"
#include "student.h"
#include "student.cpp"
#include "roster.cpp"
#include "roster.h"



const std::string studentData[] = { "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Brian,French,bfren41@wgu.edu,37,12,16,32,SOFTWARE" };


int main() {
	std::cout << "Scripting and Programming - Applications - C867" << std::endl << "Written in C++ using Visual Studio 2022" << std::endl << "Brian French | 011693332" << std::endl << std::endl;
	
	int rosterSize = sizeof(studentData) / sizeof(studentData[0]);
	Roster classRoster(rosterSize);

	classRoster.dataParse(studentData, rosterSize);
	classRoster.printAll(rosterSize);
	classRoster.printInvalidEmails(rosterSize);
	classRoster.printAverageDaysInCourse(rosterSize);

	classRoster.printByDegreeProgram({ DegreeProgram::SOFTWARE }, rosterSize);

	classRoster.remove("A3", rosterSize);
	rosterSize--;

	classRoster.printAll(rosterSize);

	classRoster.remove("A3", rosterSize);



	return 0;
}
