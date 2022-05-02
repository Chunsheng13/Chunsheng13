#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

//设计联系人结构体
struct person 
{
	string m_name;
	int m_sex;//1，男 2，女
	int m_age;
	string m_phone;
	string m_addr;
};

//设计通讯录结构体
struct addressbooks 
{
	//通讯录中保存的联系人数组
	struct person personarray[MAX];

	//通讯录中当前记录的联系人个数
	int m_size;
};

//0，定义界面函数
void showmenu()
{
	cout << "*************************" << endl;
	cout << "***** 1，添加联系人 *****" << endl;
	cout << "***** 2，显示联系人 *****" << endl;
	cout << "***** 3，删除联系人 *****" << endl;
	cout << "***** 4，查找联系人 *****" << endl;
	cout << "***** 5，修改联系人 *****" << endl;
	cout << "***** 6，清空联系人 *****" << endl;
	cout << "***** 0，退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

//1,添加联系人
void addperson(struct addressbooks *abs) //定义结构体指针
{
	//判断通讯录是否人满
	if (abs->m_size == MAX) 
	{
		cout << "通讯录已满，无法添加" << endl;
		return;//用于中断void类型无返回值函数
	}
	else 
	{
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;

		cout << "请输入性别： " << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;

		while (true)
		{   //如果输入的不是1或2，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "输入错误，请重新输入" << endl;
		}

		cout << "请输入您的年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->personarray[abs->m_size].m_age = age;

		cout << "请输入您的电话： " << endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->m_size].m_phone = phone;

		cout << "请输入您的地址： " << endl;
		string addr;
		cin >> addr;
		abs->personarray[abs->m_size].m_addr =addr;

		//更新通讯录人数
		abs->m_size++;
		cout << "添加成功" << endl;

		system("pause");//按任意键继续
		system("cls");  //清屏操作
	}
}


//2，显示联系人
void showperson(struct addressbooks *abs)
{
	//判断通讯录中人数是否为0，若为0，提示记录为空
	//若不为0，显示联系人
	if (abs->m_size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名： " << abs->personarray[i].m_name << "\t";
			cout << "性别： " << (abs->personarray[i].m_sex==1?"男":"女") << "\t";//三目运算符，值为1，输出 男
			cout << "年龄： " << abs->personarray[i].m_age << "\t";
			cout << "电话： " << abs->personarray[i].m_phone << "\t";
			cout << "住址： " << abs->personarray[i].m_addr<< endl;
		}
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在，若存在，返回具体位置，若不存在，返回-1
//参数1 通讯录地址 参数2 对比的姓名
int isexist(addressbooks *abs ,string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personarray[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}

//3，删除联系人
void deleteperson(addressbooks *abs)
{
	cout << "请输入您要删除的联系人" << endl;

	string name;
	cin >> name;

	//ret==-1 未查到
	//ret!=-1 查到了               函数定义时要指明参数类型，调用时直接写参数名
	int ret = isexist(abs, name);//abs为deleteperson中调用的指针

	if (ret != -1)
	{
		//数据前移，后面的数据盖住前面的
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_size--;//更新通讯录中人数；
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//4, 查找联系人
void findperson(addressbooks *abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	//判断指定联系人是否存在
	int ret = isexist(abs, name);
	if (ret != -1)//找到联系人
	{
		cout << "性名： " << abs->personarray[ret].m_name<< "\t";
		cout << "性别： " << abs->personarray[ret].m_sex << "\t";
		cout << "年龄: " << abs->personarray[ret].m_age << "\t";
		cout << "电话: " << abs->personarray[ret].m_phone << "\t";
		cout << "住址: " << abs->personarray[ret].m_addr << "\t" << endl;
	}
	else//未找到联系人
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//5，修改联系人
void modifyperson(addressbooks *abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = isexist(abs, name);
	if (ret != -1)//找到联系人
	{
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personarray[ret].m_name = name;

		cout << "请输入性别： " << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true) 
		{
			cin >> sex;
			if(sex==1||sex==2)
			{
				abs->personarray[ret].m_sex = sex;
				break;
			}
			else 
			{
				cout << "输入错误，请重新输入" << endl;
			}
		}

		cout << "请输入年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->personarray[ret].m_age = age;

		cout << "请输入联系电话： " << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].m_phone = phone;

		cout << "请输入家庭住址： " <<endl;
		string addr;
		cin >> addr;
		abs->personarray[ret].m_addr = addr;

		cout << "修改成功" << endl;
	}
	else//未找到联系人
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//6，清空联系人
void claenperson(addressbooks *abs)
{
	abs->m_size = 0;//只需将当前联系人数量置为0，即可做逻辑清空
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}

int main() 
{
	//创建通讯录结构体变量,名称abs
	addressbooks abs;

	//初始化通讯录中当前人员个数
	abs.m_size = 0;
	int select = 0;

	while (true)
	{
		showmenu();

		cin >> select;

		switch (select)
		{
		case 1://1，添加联系人
			addperson(&abs);//用地址传递修饰实参
			break;
		case 2://2，显示联系人
			showperson(&abs);
			break;
		case 3://3，删除联系人

		//{      //switch 中case代码很长时，用方括号括起
		//	cout << "请输入联系人姓名" << endl;
		//	string name;
		//	cin >> name;

		//	if (isexist(&abs, name) == -1)//abs为变量，加&变为地址
		//	{
		//		cout << "查无此人" << endl;
		//	}
		//	else
		//	{
		//		cout << "找到此人" << endl;
		//	}
		//}

			deleteperson(&abs);
			break;
		case 4://4，查找联系人
			findperson(&abs);
			break;
		case 5://5，修改联系人
			modifyperson(&abs);
			break;
		case 6://6，清空联系人
			claenperson(&abs);
			break;
		case 0://0，退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");//任意键继续
			return 0;//退出系统
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}