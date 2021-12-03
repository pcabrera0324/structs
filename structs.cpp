#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>


using namespace std;

// student structure
struct student {
    
    string firstname;
    int age;
    string gradelevel;
    float gpa;
};

// function declaration
void getDetail(struct student *,int&p);
void displayDetail(struct student *,int&p);
void menu(struct student*,int&p);
void searchbyname(struct student*,int&p);
void gradelevel(struct student*,int&p);
void gpa(struct student*,int&p);




int main(void) {
    
    // student structure variable
    struct student std[5];
    int p=0;
    
    
    menu(std, p);
    
    
    return 0;
}

// function definition






void getDetail(struct student *ptr,int&p) {
    
    int i;
    
    
    string gradelevels[]={"freshman","sophomore","junior","senior"};
    string noallowed[]={"0","1","2","3","4","5","6","7","8","9"};
    
    for (i = 0; i < 1; i++) {
        cout << "Enter detail of student #" << (p+1);
   
        cout << "\nEnter first name: ";
        cin.ignore();
        getline( cin, ptr[p].firstname );
        
        while (any_of(ptr[p].firstname.begin(), ptr[p].firstname.end(), [](char ch) { return isdigit(ch); }))
        {
            cout << "Numbers are not allowed, input name again: ";
            getline(cin, ptr[p].firstname);
        }
        
       
        cout << "Enter age: ";
        cin >> ptr[p].age;
        
        
        while(!cin>>ptr[p].age)   // validate int
                {
                    cout <<"Error: Enter a number" << endl;
    
                    cin.clear();
                    cin.ignore(123,'\n');
                    
                    cin>>ptr[p].age;
                }
        
    
            
       
        
        cout <<"Enter grade level: [freshman, sophomore, junior, or senior ]: ";
        cin.ignore();
        getline( cin, ptr[p].gradelevel );
        
        
       
            
            
            while (ptr[p].gradelevel!="senior" && ptr[p].gradelevel!="junior" && ptr[p].gradelevel!="freshman" && ptr[p].gradelevel!="sophomore"  )
            {
                cout << "Enter one of these [freshman, sophomore, junior, or senior ] ";
                getline(cin, ptr[p].gradelevel);
                
                
                   
            }
            
            
            
        
        
       
        
        
           
               
        
        
        
     
        
        
        
       
        GPA:
    
        
        cout << "Enter gpa: ";
        
        cin >> ptr[p].gpa;
        
        
        
        while(cin.fail()) {
                cout << "Error" << endl;
                cin.clear();
                cin.ignore(256,'\n');
            goto GPA;
            }

            
       
        
        
                
       
        
           
        
        // update pointer to point at next element
        // of the array std
        
        
        p++;
        ptr++;
        
        
        
        
    }
}

void displayDetail(struct student *ptr,int&p) {
    
    if(p==0)
    {
        cout <<" NO STUDENTS registered yet.." << endl;
        cout <<"\n" << endl;
        menu(ptr,p);
        
    }
    
    // p is number of students;
    int i;
    
    for (i = 0; i <p; i++) {
        cout << "\nDetail of student "<< (i + 1);
        
        // display result via ptr variable
        
        
        cout<<"\nFirst Name: "<< ptr->firstname;
        cout<<"\nAge: "<< ptr->age;
        cout<<"\nGrade level: "<< ptr->gradelevel;
        cout.precision(5);
        cout<<"\nGpa: " << showpoint << setw(2) <<  ptr->gpa << endl;
        
        // update pointer to point at next element
        // of the array std
        ptr++;
        
        
    }
    
}

void searchbyname(struct student*ptr,int&p)
{
    string studetnwanted;
    
    
    
    if(p==0)
    {
        cout <<" NO STUDENTS registered yet.." << endl;
        cout <<"\n" << endl;
        menu(ptr,p);
        
    } else // if students registered
        
    {
        cout << "Please enter the name of the student to search\n";
        
        
        cin.ignore();
        getline( cin, studetnwanted );
        
        while (any_of(studetnwanted.begin(), studetnwanted.end(), [](char ch) { return isdigit(ch); }))
        {
            cout << "Numbers are not allowed, input name again: ";
            getline(cin, studetnwanted);
        }
        
        
        
        
        
        for (int i=0;i<p;i++)
        {
            if(ptr[i].firstname==studetnwanted)
            {
                
                cout<<"\nFirst Name: "<< ptr[i].firstname;
                cout<<"\nAge: "<< ptr[i].age;
                cout<<"\nGrade level: "<< ptr[i].gradelevel;
                cout<<"\nGpa: "<< ptr[i].gpa << endl;
            }
        }
        
        
        
        
        
    }
    
    
    
    
    
    
}




void menu(struct student*ptr,int&p)
{
    char selection;
    
    do
    {
        cout<<"***********************************\n";
        cout<<"Please choose one of the following:\n";
        cout<<"|----------------------------------|"<<endl;
        cout<<"|1. Register a Student             |"<<endl;
        cout<<"|2. Search Student by Name         |"<<endl;
        cout<<"|3. Print Students by GPA > ..     |"<<endl;
        cout<<"|4. Print Students by grade level  |"<<endl;
        cout<<"|5. Print All Current students     |"<<endl;
        cout<<"|----------------------------------|"<<endl;
        cout<<" 6. Exit"<<endl;
        cout<<" "<<endl;
        cout<<"Your choice: ";
        cin >> selection;
        cout << endl;
        
        switch (selection)
        {
            case '1':
                cout<<"***********************************\n";
                cout<<"| Student Registration            |"<<endl;
                cout<<"|---------------------------------|"<<endl;
                getDetail(ptr, p);
                cout << "\n";
                break;
                
            case '2':
                searchbyname(ptr, p);
                cout << "\n";
                break;
            case '3':
                gpa(ptr, p);
                cout << "\n";
                break;
                
            case '4':
                gradelevel(ptr, p);
                cout << "\n";
                break;
                
            case '5':
                cout<<"***********************************\n";
                cout<<"| Print all Student               |"<<endl;
                cout<<"|---------------------------------|"<<endl;
                displayDetail(ptr, p);
                cout << "\n";
                break;
                
            case '6':
                cout << "Goodbye.\n";
                exit(0);
                break;
                
            default: cout <<selection << "is not a valid menu item.\n";
                
                cout << endl;
        }
        
    }while (selection != 0 );
}



void gradelevel(struct student*ptr,int&p)
{
    string studetnwanted;
    
    
    
    if(p==0)
    {
        cout <<" NO STUDENTS registered yet.." << endl;
        cout <<"\n" << endl;
        menu(ptr,p);
        
    } else // if students registered
        
    {
        cout << "Enter grade level in order to print all students [freshman,sophomore,junior, orsenior ]: " << endl;
        //  cout "Enter grade level in order to print all students [freshman, sophomore, junior, or senior ]: "
        
        
        
        
        
        cin.ignore();
        getline( cin, studetnwanted );
        
        
       
            
            
            while (studetnwanted!="senior" && studetnwanted!="junior" && studetnwanted!="freshman" && studetnwanted!="sophomore"  )
            {
                cout << "Enter one of these [freshman, sophomore, junior, or senior ] ";
                getline(cin, studetnwanted);
                
                
                   
            }
        
        
        
        
        
        for (int i=0;i<p;i++)
        {
            if(ptr[i].gradelevel==studetnwanted)
            {
                
                cout<<"\nFirst Name: "<< ptr[i].firstname;
                cout<<"\nAge: "<< ptr[i].age;
                cout<<"\nGrade level: "<< ptr[i].gradelevel;
                cout<<"\nGpa: "<< ptr[i].gpa << endl;
            }
        }
        
        
        
        
        
    }
    
    
    
    
    
    
}


void gpa(struct student*ptr,int&p)
{
    int gpawanted;
    
    
    
    if(p==0)
    {
        cout <<" NO STUDENTS registered yet.." << endl;
        cout <<"\n" << endl;
        menu(ptr,p);
        
    } else // if students registered
        
    {
        
    GPA:
        cout << "enter value in order print students above: " << endl;
        //  cout "Enter grade level in order to print all students [freshman, sophomore, junior, or senior ]: "
       
        
        
 

    
   
    
    cin >> gpawanted;
    
    
    
    while(cin.fail()) {
            cout << "Error" << endl;
            cin.clear();
            cin.ignore(256,'\n');
        goto GPA;
        }
      
        
        
        
        for (int i=0;i<p;i++)
        {
            if(ptr[i].gpa>gpawanted)
            {
                
                cout<<"\nFirst Name: "<< ptr[i].firstname;
                cout<<"\nAge: "<< ptr[i].age;
                cout<<"\nGrade level: "<< ptr[i].gradelevel;
                cout<<"\nGpa: "<< ptr[i].gpa << endl;
            }
        }
        
        
        
        
        
    }
    
    
    
    
    
    
}
