#include "workerManager.h"
//构造函数
WorkerManager::WorkerManager() {
	//初始化人数
	this->empNum = 0;
	//初始化数组指针
	this->empArray = NULL;
}
//析构函数
WorkerManager::~WorkerManager() {
	if (this->empArray != NULL) {
		delete[] empArray;
		this->empArray = NULL;
	}
}
//菜单
void WorkerManager::ShowMenu() {
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//添加职工
void WorkerManager::addEmploy() {
	cout << "请输入增加职工的数量：" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0) {
		//计算新空间的大小
		int newSize = this->empNum + addNum;
		//开辟新空间
		Worker** newSpace = new Worker*[newSize];
		/*
		①在堆区创建建一个普通员工对象，地址是0x100
		Worker* p = new Employee(1001, "张三", 1); p里存的是0x100
		②如果有多个员工对象，那就需要很多个（文件）Worker*，这时候就需要指针数组（文件夹）Worker*[newSize]
		③该指针数组Worker*[newSize]有很多格子[][][].....，每一个格子都可以存放一个Worker*，[Worker*][Worker*].....
		④newSpace二级指针，存放（文件夹的地址）数组的首地址，拿着newSpace，就能找到文件夹；打开文件夹的第i个格子（newSpace[i]），就能拿到第i个员工的门牌号worker（Worker*）；
		*/
		//如果原空间非空
		if (empArray != NULL) {
			//将原空间的内容拷贝到新空间
			for (int i = 0; i < this->empNum; i++) {
				newSpace[i] = this->empArray[i];//指针偏移：newSpace[i]等价于*(newSpace + i)
			}
		}
		//输入新数据
		for (int i = 0; i < addNum; i++) {
			int id;//编号
			string name;//姓名
			int dSelect;//职务

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;
			while (1) {
				cout << "请输入该职工的岗位：" << endl;
				cout << "1：普通职工" << endl;
				cout << "2：经理" << endl;
				cout << "3：老板" << endl;
				cin >> dSelect;
				if (dSelect == 1 || dSelect == 2 || dSelect == 3) {
					//父类指针
					Worker* worker = NULL;//worker存放的是能找到员工的地址

					switch (dSelect) {
					case 1:
						worker = new Employee(id, name, 1);//父类指针指向子类对象
						break;
					case 2:
						worker = new Employee(id, name, 2);
						break;
					case 3:
						worker = new Employee(id, name, 3);
						break;
					default:
						break;
					}
					newSpace[i + this->empNum] = worker;
					break;//跳出while循环
				}
				else {
					cout << "输入有误，请重新输入" << endl;
				}
			}
		}
		//释放原对象
		delete[] this->empArray;
		//更改新的空间指向
		this->empArray = newSpace;
		//更新员工个数
		this->empNum = newSize;
		//提示信息
		cout << "成功添加" << addNum << "名员工信息" << endl;
		//保存数据
		this->save();
	}
	else {
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");//停住：请按任意键继续
	system("cls");//清屏
}

//保存职工数据
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->empNum; i++) {
		ofs << this->empArray[i]->ID << " "
			<< this->empArray[i]->name << " "
			<< this->empArray[i]->DeptID << " ";
	}
	ofs.close();
}

//退出系统
void WorkerManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}