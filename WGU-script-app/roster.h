#ifndef ROSTER_H
#define ROSTER_H
#include <string>
#include "degree.h"
#pragma once


void dataParse(const std::string dataIngest[], int rosterSize);

void dataProcess(std::string ingestArray[], int record);

void printInvalidEmails(int rosterSize);

void printAverageDaysInCourse(int indexStudent);

void printByDegreeProgram(DegreeProgram inputString);

void remove(std::string studentID, int rosterSize);

void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram, int record);

#endif