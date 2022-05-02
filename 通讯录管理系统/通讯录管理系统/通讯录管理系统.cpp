#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

//�����ϵ�˽ṹ��
struct person 
{
	string m_name;
	int m_sex;//1���� 2��Ů
	int m_age;
	string m_phone;
	string m_addr;
};

//���ͨѶ¼�ṹ��
struct addressbooks 
{
	//ͨѶ¼�б������ϵ������
	struct person personarray[MAX];

	//ͨѶ¼�е�ǰ��¼����ϵ�˸���
	int m_size;
};

//0��������溯��
void showmenu()
{
	cout << "*************************" << endl;
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}

//1,�����ϵ��
void addperson(struct addressbooks *abs) //����ṹ��ָ��
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_size == MAX) 
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;//�����ж�void�����޷���ֵ����
	}
	else 
	{
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;

		cout << "�������Ա� " << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;

		while (true)
		{   //�������Ĳ���1��2����������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "�����������������" << endl;
		}

		cout << "�������������䣺 " << endl;
		int age = 0;
		cin >> age;
		abs->personarray[abs->m_size].m_age = age;

		cout << "���������ĵ绰�� " << endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->m_size].m_phone = phone;

		cout << "���������ĵ�ַ�� " << endl;
		string addr;
		cin >> addr;
		abs->personarray[abs->m_size].m_addr =addr;

		//����ͨѶ¼����
		abs->m_size++;
		cout << "��ӳɹ�" << endl;

		system("pause");//�����������
		system("cls");  //��������
	}
}


//2����ʾ��ϵ��
void showperson(struct addressbooks *abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0����Ϊ0����ʾ��¼Ϊ��
	//����Ϊ0����ʾ��ϵ��
	if (abs->m_size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������ " << abs->personarray[i].m_name << "\t";
			cout << "�Ա� " << (abs->personarray[i].m_sex==1?"��":"Ů") << "\t";//��Ŀ�������ֵΪ1����� ��
			cout << "���䣺 " << abs->personarray[i].m_age << "\t";
			cout << "�绰�� " << abs->personarray[i].m_phone << "\t";
			cout << "סַ�� " << abs->personarray[i].m_addr<< endl;
		}
	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ���ڣ������ڣ����ؾ���λ�ã��������ڣ�����-1
//����1 ͨѶ¼��ַ ����2 �Աȵ�����
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

//3��ɾ����ϵ��
void deleteperson(addressbooks *abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;

	string name;
	cin >> name;

	//ret==-1 δ�鵽
	//ret!=-1 �鵽��               ��������ʱҪָ���������ͣ�����ʱֱ��д������
	int ret = isexist(abs, name);//absΪdeleteperson�е��õ�ָ��

	if (ret != -1)
	{
		//����ǰ�ƣ���������ݸ�סǰ���
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_size--;//����ͨѶ¼��������
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//4, ������ϵ��
void findperson(addressbooks *abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	//�ж�ָ����ϵ���Ƿ����
	int ret = isexist(abs, name);
	if (ret != -1)//�ҵ���ϵ��
	{
		cout << "������ " << abs->personarray[ret].m_name<< "\t";
		cout << "�Ա� " << abs->personarray[ret].m_sex << "\t";
		cout << "����: " << abs->personarray[ret].m_age << "\t";
		cout << "�绰: " << abs->personarray[ret].m_phone << "\t";
		cout << "סַ: " << abs->personarray[ret].m_addr << "\t" << endl;
	}
	else//δ�ҵ���ϵ��
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//5���޸���ϵ��
void modifyperson(addressbooks *abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isexist(abs, name);
	if (ret != -1)//�ҵ���ϵ��
	{
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personarray[ret].m_name = name;

		cout << "�������Ա� " << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
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
				cout << "�����������������" << endl;
			}
		}

		cout << "���������䣺 " << endl;
		int age = 0;
		cin >> age;
		abs->personarray[ret].m_age = age;

		cout << "��������ϵ�绰�� " << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].m_phone = phone;

		cout << "�������ͥסַ�� " <<endl;
		string addr;
		cin >> addr;
		abs->personarray[ret].m_addr = addr;

		cout << "�޸ĳɹ�" << endl;
	}
	else//δ�ҵ���ϵ��
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//6�������ϵ��
void claenperson(addressbooks *abs)
{
	abs->m_size = 0;//ֻ�轫��ǰ��ϵ��������Ϊ0���������߼����
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}

int main() 
{
	//����ͨѶ¼�ṹ�����,����abs
	addressbooks abs;

	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_size = 0;
	int select = 0;

	while (true)
	{
		showmenu();

		cin >> select;

		switch (select)
		{
		case 1://1�������ϵ��
			addperson(&abs);//�õ�ַ��������ʵ��
			break;
		case 2://2����ʾ��ϵ��
			showperson(&abs);
			break;
		case 3://3��ɾ����ϵ��

		//{      //switch ��case����ܳ�ʱ���÷���������
		//	cout << "��������ϵ������" << endl;
		//	string name;
		//	cin >> name;

		//	if (isexist(&abs, name) == -1)//absΪ��������&��Ϊ��ַ
		//	{
		//		cout << "���޴���" << endl;
		//	}
		//	else
		//	{
		//		cout << "�ҵ�����" << endl;
		//	}
		//}

			deleteperson(&abs);
			break;
		case 4://4��������ϵ��
			findperson(&abs);
			break;
		case 5://5���޸���ϵ��
			modifyperson(&abs);
			break;
		case 6://6�������ϵ��
			claenperson(&abs);
			break;
		case 0://0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");//���������
			return 0;//�˳�ϵͳ
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}