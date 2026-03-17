#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

class Employee : public Worker{
public:
	//普通员工构造函数
	Employee(int ID, string name, int DeptID);
	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};