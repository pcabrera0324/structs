         // ==========  structures and function call by REFERENCE ======
// this program enables the user to pass a structure to a function and return
// the values to main.
#include <iostream>
#include<iomanip>
#include <string>
using namespace std;
struct date{
				int Month;
				int day;
				int year;
				};
 struct Student{
					  char F_Name[20];
					  char L_Name[30];
					  float GPA;
					  int credits;
					 };
 struct School{
					char schoolName[30];
					char state[5];
					};

void display(Student &,date &,date &, School &);
void  DateFunction(date&);
void StudentInfoFunction(Student &);
void CollegeAttended(School &) ;
int main()
{

 School College;
 Student StuInfo;
 date BirthDay;
 date GraduationDay;
 for (int i = 0; i <3;++i)
 {
 cout << "\n call a function to Enter the student information \n";

  StudentInfoFunction(StuInfo);

 cout << "\n call a function to Enter Birth day information ";
 DateFunction(BirthDay);

 cout << "\n call a function to Enter Graduation day Information ";
  DateFunction(GraduationDay);

 cout << "\n Name of college attended \n";
 CollegeAttended(College);

 cout<< "\n call a function to display all information \n" ;
 display(StuInfo,BirthDay,GraduationDay,College);
  }
  
  system("pause");
 return 0;
 }
//==============================================================================
 void DateFunction(date& day)
 {

  cout<<"\n what month ? ";
  cin >>day.Month;

  cout<<"\n what day ? ";
  cin >>day.day;

  cout<<"\n what year ? ";
  cin >>day.year;

 // cout << "\n hmmmmm So your Birth Day is " << day.Month<<"/"<<day.day<<"/"
 //		<<day.year;

  }
 //=============================================================================
 void  StudentInfoFunction(Student& info)
 {
  cout << "\nStudent first name  " ;
  cin>>info.F_Name;
  cout << " Student Last name  " ;
  cin>>info.L_Name;
  cout << " GPA ";
  cin >>info.GPA;
  cout << " Number of credits ";
  cin >>info.credits;
 
  }
 //=============================================================================
 void display(Student &StuInfo,date &BirthDay,date &GraduationDay,School &Madrasa)
 {
 cout << "*******************************************************"<<endl;
 cout <<" First Name: " <<StuInfo.F_Name<<endl;
 cout << "last Name : " <<StuInfo.L_Name<<endl;
 cout <<"GPA        :  "<<StuInfo.GPA<<endl;
 cout <<"# of Cred  :  " << StuInfo.credits<<endl;
 cout <<"Birth day  :  " << BirthDay.Month<<"/"<<BirthDay.day<<"/"
		<<BirthDay.year<<endl;

 cout << "graduation date is:  " <<GraduationDay.Month<<"/"<<GraduationDay.day<<"/"
		<<GraduationDay.year<<endl;
 cout << " College Attended: "<<  Madrasa.schoolName<<endl;
 cout << " Located in : "<< Madrasa.state<<endl;
  cout << "*******************************************************"<<endl;
  }
//==============================================================================

 void CollegeAttended(School &College)
{
  cout << "what is the name of your College";
  cin >>College.schoolName;
  cout << "Which State is your College in";
  cin>>College.state;
  
 }
