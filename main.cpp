#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

void home();
void mainpage();
int main();
class Student
{
private:
    int regNo;
    char name[50];
    int age;
    int year;
    char course[5];

public:
    void insertRecord(){
        cout<<"1.Insert Regestration Number.";
        cin>>regNo;
        cout<<"2.Insert Name.";
        cin.ignore();
        cin>>name;
        cout<<"3.Insert age.";
        cin.ignore();
        cin>>age;
        cout<<"4.Insert Year_of_Study.";
        cin>>year;
        cout<<"5.Insert Course_of_study.";
        cin.ignore();
        cin.getline(course, 5);
        cout<<"Press any key to return to main menu;";
        getch();

    }
    void displayRecord(){
        cout<<"1.RegNum."<<regNo<<endl;
        cout<<"2.Name."<<name<<endl;
        cout<<"3.age."<<age<<endl;
        cout<<"4.YOS."<<year<<endl;
        cout<<"5.COS."<<course<<endl;
        cout<<"######################################"<<endl;
    }
    int retregNo(){
        return regNo;
    }
    int retAge(){
        return age;
    }
    string retName(){
        string n= char name[];
        return n;
    }
};

class Welcome
{
private:
    char uname[50]="user";
    char pword[50]="pass";
    int counter=0;
public:
    void check_info(string n, string p){
        if (n == uname){
            if (p == pword){
                cout<<"login successfull\n";
                getch();
                system("cls");
                mainpage();
            }else{
                cout<<"\npassword is incorrect";
                getch();
                system("cls");
                main();
            }
        }else{
                cout<<"\nInvalid username";
                getch();
                system("cls");
                main();
            }
    }
    void login(){
        string n, p;
        char nn[50], pw[50];
        cout<<"Username:";
        cin.getline(nn, 50);
        cout<<"\nPassword:";
        cin.getline(pw, 50);
        n = nn;
        p = pw;
        check_info(n, p);
        }
    void welcomepage(){
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"----------------------------|WELCOME TO THIS SCHOOL|--------------------------"<<endl;
        cout<<"------------------------------|MANAGEMENT SYSTEM|-----------------------------"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
    }
};
void searchRecord(int n, int reg){
    fstream fp;
    int found = 0;
    fp.open("users.dat", ios::in|ios::out|ios::binary|ios::app);
    Student st;
    while(fp.read((char*)&st, sizeof(st))){
        if(st.retregNo()== reg){
                found ++;
                st.displayRecord();
                getch();
        }
    }
    if (found == 0){
        cout<<"no result found\n";
        getch();
    }
    getch();
    }
void searchRecordAge(int n, int age){
    fstream fp;
    int found=0;
    fp.open("users.dat", ios::in|ios::out|ios::binary|ios::app);
    Student st;
    while(fp.read((char*)&st, sizeof(st))){
        if(st.retAge() == age){
            found++;
            st.displayRecord();
            getch();
        }
    }
    if(found==0){
        cout<<"no result found\n";
        getch();
    }
}
void searchRecordName(int n, char name){
    fstream fp;
    int found=0;
    fp.open("users.dat",ios::in|ios::out|ios::binary|ios::app);
    Student st;
    while(fp.read((char*)&st, sizeof(st))){
        if(st.retName == &name){
            found++;
            st.displayRecord();
            getch();
        }
    }
    if(found==0){
        cout<<"No records found\n";
        getch();
    }
}
void new_record(){
   fstream fp;
   Student st;
   fp.open("users.dat", ios::in|ios::out|ios::binary|ios::app);
   if(!fp){
            cout<<"file could not be opened";
            getch();
           }
  st.insertRecord();
  fp.write((char*)&st, sizeof(st));
  fp.close();

}
void read(){
    fstream fp;
    Student st;
    fp.open("users.dat",ios::in|ios::out|ios::binary);
    while(fp.read((char*)&st, sizeof(st))){
         st.displayRecord();
    }
    fp.close();
    getch();
    mainpage();

}
int main(){
    Welcome W1;
    W1.welcomepage();
    W1.login();
    system("cls");
}
 void mainpage(){

        int num;
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<"------------------------|SCHOOL MANAGEMENT SYSTEM|------------------------------"<<endl;
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<"1.Insert Record."<<endl;
        cout<<"2.Display All Records."<<endl;
        cout<<"3.Search Record using Roll No."<<endl;
        cout<<"4.Search Record using other attributes."<<endl;
        cout<<"5.Sort Records."<<endl;
        cout<<"6.Modify Record."<<endl;
        cout<<"7.Delete Record."<<endl;
        cout<<"8.Exit."<<endl;

        cout<<"Choose[1,2,3,4,5,6,7,8]"<<endl;
        cin>>num;

        switch(num){
        case 8:
            system("cls");

            break;
        case 1:
            system("cls");
            new_record();
            mainpage();
            break;
        case 2:
            system("cls");
            read();
            break;
        case 3:
            system("cls");
            int reg;
            cout<<"Search student using admission number: ";
            cin>>reg;

            searchRecord(1, reg);
            //getch();
            //cin>>reg;

            break;
        case 4:
            system("cls");
			int age;
			char name;
			int num1;
			cout<<"1.Search by age."<<endl;
			cout<<"2.Search by name."<<endl;
			cin>>num1;
			switch(num1){
            case 1:
                system("cls");
                cout<<"Search records by age: ";
                cin>>age;

                searchRecordAge(2, age);
                //getch();
                //cin>>age;
                break;
            case 2:
                system("cls");
                cout<<"Search records by name: ";
                cin>>name;

                searchRecordName(3, name);
                //getch();
                //cin>>name;
			}
            break;
        case 5:
            system("cls");
            break;
        case 6:
            system("cls");
            break;
        case 7:
            system("cls");
            break;
       default:
            cout<<"Please choose number in the square bracket."<<endl;
        break;
        }
    }
