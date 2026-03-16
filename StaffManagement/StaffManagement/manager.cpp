#include "manager.h"

//经理构造函数
Manager::Manager(int ID, string name, int DeptID) {
	this->ID = ID;
	this->name = name;
	this->DeptID = DeptID;
}
//显示个人信息
void Manager::showInfo() {
	cout << "职工编号： " << this->ID
		<< " \t职工姓名： " << this->name
		<< " \t岗位：" << this->getDeptName()
		<< " \t岗位职责：完成老板交给的任务,并下发任务给员工" << endl;
}
//获取岗位名称
string Manager::getDeptName() {
	return "经理";
}