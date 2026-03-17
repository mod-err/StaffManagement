#pragma once
#include <iostream>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

#define FILENAME "empFile.txt"

class WorkerManager {
public:
	WorkerManager();
	~WorkerManager();
	//菜单
	void ShowMenu();
	//退出系统
	void exitSystem();
	//添加职工
	void addEmploy();
	//保存职工数据
	void save();
	//记录文件中人数
	int empNum;
	//员工数组指针
	Worker** empArray;
};