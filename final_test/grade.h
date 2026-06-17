#pragma once
#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>

#include "Student_info.h"

// 오버로딩 함수
double grade(double, double, double);
double grade(double, double, const vector<double>&);

#endif
