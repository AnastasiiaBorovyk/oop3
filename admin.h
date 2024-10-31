#pragma once
#include "car.h"

using namespace::std;

class Admin {
private:
	string adminName;

public:
	string requestStatus;

	Admin(string aN, string rQ);
};
