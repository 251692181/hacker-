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
		cout << "输入账号:" << endl;
		cout << "__________\b\b\b\b\b\b\b\b\b\b";
		cin >> name;

		cout << "输入密码:" << endl;
		cout << "__________\b\b\b\b\b\b\b\b\b\b";
		//cin >> pwd;
		cinPwd(pwd, sizeof(pwd));

		if (name == "hacker" && !strcmp(pwd ,"123456")) {
			break;
		}
		else {
			cout << "请重新输入\a" << endl;
			cin.clear();   
			fflush(stdin);//cin.ignore(1024, '\n');
			system("pause");
		}
	}
}

void menu() {
	system("cls"); 
	cout << "----菜单----" << endl;
	cout << "1.404攻击-----" << endl;
	cout << "2.篡改攻击----" << endl;
	cout << "3.查看攻击记录-" << endl;
	cout << "4.修复网址-----" << endl;
	cout << "5.退出---------" << endl;
}


int MenuC() {
	int x = 0;
	while (true)
	{   	
		cout << "请选择：";
		cin >> x;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "请重新输入" << endl;
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
	cout << "请输入ID：" << endl;
	scanf_s("%s", id, sizeof(id));
	cout << "-----开始404攻击----" << endl;
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
	cout << "请输入ID：" << endl;
	scanf_s("%s", id, sizeof(id));
	cout << "请输入内容：" << endl;
	cin >> para;

	cout << "-----开始篡改攻击----" << endl;
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
	cout << "请输入ID：" << endl;
	scanf_s("%s", id, sizeof(id));

	cout << "-----开始查看攻击记录----" << endl;

	hk_record(id, response);
	string red = UTF8ToGBK(response);
	cout << red << endl;

	system("pause");


}

void reload() {
	char id[64];
	char response[4096];
	cout << "请输入ID：" << endl;
	scanf_s("%s", id, sizeof(id));

	cout << "-----开始恢复网站----" << endl;

	hk_restore(id, response);
	string red = UTF8ToGBK(response);
	cout << red << endl;

	system("pause");


}


void exit() {
	cout << "退出------" << endl;
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

	//登录
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
			cout << "输入无效！请重新输入！" << endl;
			system("pause");
			break;
		}

	}


	
	














	system("pause");
	return 0;
}