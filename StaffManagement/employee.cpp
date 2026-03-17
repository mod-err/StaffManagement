#include "employee.h"

//普通员工构造函数
Employee::Employee(int ID, string name, int DeptID) {
	this->ID = ID;
	this->name = name;
	this->DeptID = DeptID;
}
//显示个人信息
void Employee::showInfo() {
	cout << "职工编号： " << this->ID
		 << " \t职工姓名： " << this->name
		 << " \t岗位：" << this->getDeptName()
		 << " \t岗位职责：完成经理交给的任务" << endl;
}
//获取岗位名称
string Employee::getDeptName() {
	return "员工";
}
