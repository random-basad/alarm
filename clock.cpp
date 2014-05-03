#include <iostream>
#include <string>
#include <fstream>
#include <pwd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <sstream>
using namespace std;
string*msg=new string[30];
int*tim=new int[30];
int size=0;

int str2int(string str){
	stringstream ss(str);
	int i;
	ss >> i;
	return i;
}

int second(string tim){
	time_t t=time(0);
	struct tm * now = localtime( & t );
	int hour=(str2int(tim.substr(0,2))-now->tm_hour);
	int minuts=(str2int(tim.substr(2,2))-now->tm_min);
	int second=(str2int(tim.substr(4,2))-now->tm_sec);
	int totle= (hour*60*60+minuts*60+second);
	return (totle<0 ? totle+60*60*24 : totle );
}

void readfile(){
	string home=string((char*)getpwuid(getuid())->pw_dir);
	string file=home+"/.time";
	const char*filename=file.c_str();
	ifstream f1;
	f1.open(filename);
	string line;
	while(getline(f1,line)){
		if(line=="" || line[0]=='>')
			continue;
		tim[size]=second(line.substr(0,6));
		msg[size]=line.substr(7,line.length()-7);
		size++;
	}
	f1.close();
}



int main(int argc,char**argv){
	readfile();
	if(string(argv[1])=="num")
		cout<<size<<endl;
	else if(string(argv[1])=="tim")
		cout<<tim[str2int(string(argv[2]))]<<endl;
	else
		cout<<msg[str2int(string(argv[2]))]<<endl;


return 0;}
