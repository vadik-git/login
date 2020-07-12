#include<iostream>
#include<list>
#include<string>
#include<cctype>
using namespace std;


class BadLogin :public exception {
private:
public:
	BadLogin(const string &msg):exception (msg.c_str()) {

	}


};
class ManySymbol :public exception {
private:
public:
	ManySymbol(const string &msg) :exception(msg.c_str()) {
	}


};
class IncorectLogin :public exception {
public:
	IncorectLogin(const string &msg):exception(msg.c_str()){}
};
class IncorectPassw :public exception {
public:
	IncorectPassw(const string &msg) :exception(msg.c_str()) {}
};
class BadPassw :public exception {
public:
	BadPassw(const string &msg) :exception(msg.c_str()) {}
};
class BadPassw1 :public exception {
public:
	BadPassw1(const string &msg) :exception(msg.c_str()) {}
};
struct Login {
	string login;
	string password;
};
class Registration {
	list<Login>listLogin;
	Login logins;

	void chekLogin() {
		for (Login log : listLogin) {
			if (logins.login == log.login) {
				throw BadLogin("This login is already there");//cout << "EROOR LOG" << endl;
			}
		}
	}
	void symbol() {

			if (logins.password.size()>=8) {
				throw ManySymbol("your password many sumbol");
			}
	}
	void incorectLogin() {
		for (Login log : listLogin) {
			if (logins.login != log.login) {
				throw IncorectLogin("INCORECT LOGIN");
			}
		}
	}
	void incorectPassw() {
		for (Login log : listLogin) {
			if (logins.password != log.password) {
				throw IncorectPassw("INCORECT PASSWORD");
			}
		}
	}
	void badPasswd() {
		for (int i = 0; i < logins.login.length(); i++) {
			if (logins.password[i] >= 'A' && logins.password[i] <= 'Z') {
				throw BadPassw("YOUR PASSWORD BIG LITERS");
			}
		}
	}
	void badPasswd1() {
		for (int i = 0; i < logins.login.length(); i++) {
			if (logins.password[i] >= '0' && logins.password[i] <= '9') {
				throw BadPassw1("YOUR PASSWORD Numbers");
			}
		}
	}

public:
	void registration() {

		cout << "Enter login" << endl;
		cin >> logins.login;
		try {
			chekLogin();
		}
		catch (exception&ex) {
			cout << ex.what() << endl;
			return;
		}
		cout << "Enter password" << endl;
		cin >> logins.password;
		try {
			symbol();

		}
		catch (exception&ex) {
			cout << ex.what() << endl;
			return;
		}
		try {
			badPasswd();

		}
		catch (exception&ex) {
			cout << ex.what() << endl;
			return;
		}
		try {
			badPasswd1();

		}
		catch (exception&ex) {
			cout << ex.what() << endl;
			return;
		}
	
		listLogin.push_back(logins);
	}
	void autorization() {
		cout << "Enter login" << endl;
		cin >> logins.login;
		try {
			incorectLogin();
		}
		catch (exception&ex) {
			cout << ex.what() << endl;
			return;
		}
		cout << "Enter password" << endl;
		cin >> logins.password;
		try {
			incorectPassw();
		}
		catch (exception&ex) {
			cout << ex.what() << endl;
			return;
		}
		for (Login log : listLogin) {
			if (logins.login == log.login && logins.password == log.password) {
				cout << "HELLO WELCOME TO MY WORLD" << endl;
			}
		}
		
	}
	void watch() {
		for (Login log : listLogin) {
			cout << "LOGIN >> " << log.login << endl;
			cout << "PASSWORD >>" << log.password << endl;
		}
	}
};

int main() {

	Registration reg;
	Login logins;
	int action;  
	do {
		cout << "1.REGISTRATION " << endl;
		cout << "2.WATCH LOGIN AND PASSWD" << endl;
		cout << "3.AUTORIZATION" << endl;
		cin >> action;
		switch (action) {
		case 1:
			reg.registration();
		
			break;
		case 2:
			reg.watch();
			break;
		case 3:
			reg.autorization();
			break;
		case 0:
			break;
		}
		
	} while (action != 0);
	system("pause");
	return 0;
}