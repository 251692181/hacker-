#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include "hacker.h"

using namespace std;
#define MAXSIZE 4096




void cinPwd(char pwd[],int size) {
	char c;
	int i = 0;
	while (true){
		c = getch();
		if (c == '\r') {
			pwd[i] == 0;
			break;
		}
		pwd[i++] = c;
		cout << "*";
		
	}
	cout << endl;
}






void login() {
	//string pwd;
	while (true)
	{
		string name;
		char pwd[32];
		system("cls");
		cout << "�����˺�:" << endl;
		cout << "__________\b\b\b\b\b\b\b\b\b\b";
		cin >> name;

		cout << "��������:" << endl;
		cout << "__________\b\b\b\b\b\b\b\b\b\b";
		//cin >> pwd;
		cinPwd(pwd, sizeof(pwd));

		if (name == "hacker" && !strcmp(pwd ,"123456")) {
			break;
		}
		else {
			cout << "����������\a" << endl;
			cin.clear();   
			fflush(stdin);//cin.ignore(1024, '\n');
			system("pause");
		}
	}
}

void menu() {
	system("cls"); 
	cout << "----�˵�----" << endl;
	cout << "1.404����-----" << endl;
	cout << "2.�۸Ĺ���----" << endl;
	cout << "3.�鿴������¼-" << endl;
	cout << "4.�޸���ַ-----" << endl;
	cout << "5.�˳�---------" << endl;
}


int MenuC() {
	int x = 0;
	while (true)
	{   	
		cout << "��ѡ��";
		cin >> x;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "����������" << endl;
			continue;
		}
		else {
			break;
		}
	}
	  return x;
}


void attack404() {
	char id[64];
	char response[4096];
	cout << "������ID��" << endl;
	scanf_s("%s", id, sizeof(id));
	cout << "-----��ʼ404����----" << endl;
	hk_404(id,response);
	string red = UTF8ToGBK(response);
	cout << red << endl;

	system("pause");

}

//int hk_tamper(char *id, char *para, char *response);
void attackCG() {
	char id[64];
	char response[4096];
	string para;
	cout << "������ID��" << endl;
	scanf_s("%s", id, sizeof(id));
	cout << "���������ݣ�" << endl;
	cin >> para;

	cout << "-----��ʼ�۸Ĺ���----" << endl;
	GBKToUTF8(para);
	hk_tamper(id,(char*)para.c_str(), response);
	string red = UTF8ToGBK(response);
	cout << red << endl;

	system("pause");

}
//int hk_record(char *id, char *response);
void record() {
	char id[64];
	char response[4096];
	cout << "������ID��" << endl;
	scanf_s("%s", id, sizeof(id));

	cout << "-----��ʼ�鿴������¼----" << endl;

	hk_record(id, response);
	string red = UTF8ToGBK(response);
	cout << red << endl;

	system("pause");


}

void reload() {
	char id[64];
	char response[4096];
	cout << "������ID��" << endl;
	scanf_s("%s", id, sizeof(id));

	cout << "-----��ʼ�ָ���վ----" << endl;

	hk_restore(id, response);
	string red = UTF8ToGBK(response);
	cout << red << endl;

	system("pause");


}


void exit() {
	cout << "�˳�------" << endl;
	system("pause");


}





void intt() {
	const int WIDTH=40;
	const int HIGHT=15;
	char cmd[128];
	sprintf_s(cmd,"mode con cols=%d lines=%d ",WIDTH,HIGHT);
	system(cmd);


}





int main() {
	intt();

	//��¼
	login();

	while (true)
	{
		menu();    
		int x = MenuC();
		switch (x) {
		case 1:
			system("cls");
			attack404();
			break;
		case 2:
			system("cls");
			attackCG();
			break;
		case 3:
			system("cls");
			record();
			break;
		case 4:
			system("cls");
			reload();
			break;
		case 5:
			system("cls");
			exit();
			return 0;
		default:
			system("cls");
			cout << "������Ч�����������룡" << endl;
			system("pause");
			break;
		}

	}


	
	














	system("pause");
	return 0;
}