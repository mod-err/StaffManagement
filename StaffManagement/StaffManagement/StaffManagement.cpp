#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

int main() {

	//测试：-----------------------
	Worker* worker = NULL;

	worker = new Employee(1, "张三", 1);
	worker->showInfo();

	worker = new Manager(2, "李四", 2);
	worker->showInfo();

	worker = new Boss(3, "位昭", 3);
	worker->showInfo();

	delete worker;
	//---------------------------

	WorkerManager wm;
	int choice = 0;
	while (1) {
		wm.ShowMenu();

		cout << "请输入您的选择：" << endl;
		cin >> choice;

		switch (choice) {
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://增加信息
			break;
		case 2://显示信息
			break;
		case 3://删除信息
			break;
		case 4://修改信息
			break;
		case 5://查找信息
			break;
		case 6://排序信息
			break;
		case 7://清空文件
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}
