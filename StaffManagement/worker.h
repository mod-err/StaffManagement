#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker {
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;

	int ID;//职工编号
	string name;//职工姓名
	int DeptID;//职工部门编号
};