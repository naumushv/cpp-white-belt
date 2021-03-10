#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <ctype.h>
#include <cctype>
#include <iterator>
#include <cstring>
#include <cstdio>
using namespace std;

struct Specialization {
	string spec;
	explicit Specialization(string value){
		spec = value;
	}
};

 struct Course {
	string cour;
	explicit Course(string value){
		cour = value;
		}
};

 struct Week {
	string wee;
	explicit Week(string value){
		wee = value;
			}
};

struct LectureTitle {
  string specialization;
  string course;
  string week;

  LectureTitle (Specialization sp, Course crs, Week www){
	  specialization = sp.spec;
	  course = crs.cour;
	  week = www.wee;
  }
};

int main() {


  return 0;
}

