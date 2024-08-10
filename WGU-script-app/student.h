#ifndef STUDENT_H
#define STUDENT_H
#pragma once

void setstudentID(std::string studentID);

void setfirstName(std::string firstName);
void setlastName(std::string lastName);
void setemailAddress(std::string emailAddress);
void setAge(int Age);
void setdaysInCourse1(int daysInCourse1);
void setdaysInCourse2(int daysInCourse2);
void setdaysInCourse3(int daysInCourse3);
void setDegreeProgram(enum DegreeProgram);

void print();

#endif