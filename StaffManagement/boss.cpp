#include "boss.h"

//老板构造函数
Boss::Boss(int ID, string name, int DeptID) {
	this->ID = ID;
	this->name = name;
	this->DeptID = DeptID;
}
//显示个人信息
void Boss::showInfo() {
	cout << "职工编号： " << this->ID
		<< " \t职工姓名： " << this->name
		<< " \t岗位：" << this->getDeptName()
		<< " \t岗位职责：管理公司所有事务" << endl;
}
//获取岗位名称
string Boss::getDeptName() {
	return "老板";
}