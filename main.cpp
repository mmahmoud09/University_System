#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Person{
public:
    string name;
    int age , id;
    virtual void role()=0;
};

class Employee : public Person{
public :
    int salary = 800;
    void role(){
       Employee emp;
       emp.age =40;
       emp.id =90;
        cout<<"Employee name is : "<<name<<endl;
        cout<<"Employee age is : " <<emp.age<<endl;
        cout<<"Employee salary is : "<<emp.salary<<endl;
    };
};

class Student : public Person{
public :
    float gpa = 3.3;

    void role(){
        Student stu;
        stu.name="Mahmoud";
        stu.age = 20;
        stu.id=23;
        cout<<"Student Name is : "<<name<<endl;
        cout<<"Student age is : "<<stu.age<<endl;
        cout<<"Student id is : "<<stu.id<<endl;
        cout<<"Student GPA is : "<<stu.gpa<<endl;
    };
};

class Instructor : public Person{
public :

     void role(){
         Instructor inst;
         inst.name="MAHMOUD";
         cout<<"Instructor of Computer course "<<endl;
         cout << "the Instructor Name is : " <<name<<endl;
         cout << "Instructor id is : " << inst.id<<endl;
     };
};

class Manager:public Person{
    static Manager* inst ;
    int salary ;
    Manager(){};
    public:
        static Manager* getInst(){
            if(inst == nullptr){
                inst = new Manager;
            }
            return inst;
        };
        void role(){
            Manager* manager;
            cout<<"Manager name is : " << name<<endl;
            cout << "Manager of the faculty computers "<<endl;
        };
        int getSalary(){

            return salary ;
        };
        void setSalary(int num){
            salary = num;
        };
};

class Course{

public:
    Course(){};

    string title = "course1";
    int course_id =1100;
    void details(){
    ifstream stud;
        stud.open("Students.txt");
        Instructor inst;
        inst.name = "AHMED";
        cout << "Course title is : "<<title<<" course id : "<<course_id<<endl;
        cout << "the instructor of the course is : " << inst.name<<endl;
        string name ;
        cout << "Students registered in course : " << endl;
        while(getline(stud,name)){
            cout<<name<<endl;
        }
          stud.close();
    };
};
class Department{
public:
      Department(){};
      string title;
      vector<Course> course = {};
      void details(){
          cout << "The Department Name is : "<<title<<endl;
          cout << "The Number of Courses : "<<course.size()<<endl;
      };
      void addCourse(Course cName){
          course.push_back(cName);
          ofstream courses;
          courses.open("Courses.txt",ios::app);
          courses << cName.title<<endl;
          courses.close();
      };


};
class Faculty{
public:
      Faculty (){};
      string title;
      vector<Student> student;
      vector<Employee> employee;
      vector<Instructor> instractor;
      vector<Department> department;
      Manager *manager = Manager::getInst();

      void details(){
          cout<<"Faculty Name Is : "<< title <<endl;
          cout<<"Number of Employees is : "<<employee.size()<<endl;
          cout<<"Number of Instructors Is : "<<instractor.size()<<endl;
          cout<<"Number of Departments is : "<<department.size()<<endl;
          cout<<"The Manager of the Faculty Is : "<<manager->name<<endl;
      };

      void addStudent(Student stu){
          student.push_back(stu);
          ofstream stud;
          stud.open("Students.txt" , ios::app);
          stud << stu.name <<endl;
          stud.close();
      };
      void addEmployee(Employee emp){
          employee.push_back(emp);
          ofstream empl;
          empl.open("Employees.txt" , ios::app);
          empl << emp.name <<endl;
          empl.close();
      };
      void addInstractor(Instructor inst){
          instractor.push_back(inst);
          ofstream instr;
          instr.open("Instructors.txt" , ios::app);
          instr << inst.name<<endl;
          instr.close();
      };
      void addDepartment(Department depart){
          department.push_back(depart);
          ofstream depar;
          depar.open("Department.txt" , ios::app);
          depar << depart.title<<endl;
          depar.close();
      };

};
class University{
public:
       University(){};
      string title;
      vector<Faculty> faculties;
      Manager* manager = Manager::getInst();
      void details(){
          cout<<"University Name : " << title<<endl ;
          cout<<"Number of faculties is : " <<faculties.size()<<endl;
      };
      void addFaculty(Faculty fac){
          faculties.push_back(fac);
          ofstream facu;
          facu.open("Faculties.txt" , ios::app);
          facu << fac.title <<endl;
          facu.close();
      };
};




Manager* Manager::inst = nullptr;
int main()
{
    int num;
    Manager *manager = Manager::getInst();
    Student student;
    Instructor instructor;
    Employee employee;
    University university;
    Faculty faculty;
    Department department;
    Course course;

    cout<<"*********************************\n";
    cout<<"        Student\n*********************************\n";

    cout << "Enter Student Name : " <<endl;
    cin >> student.name;
    cout << "Enter Faculty : " <<endl;
    cin>> faculty.title;
    cout<<"Enter Course : "<<endl;
    cin>>course.title;
    cout<<"Enter Instructor Name : "<<endl;
    cin>>instructor.name;

    faculty.addInstractor(instructor);
    faculty.addStudent(student);
    university.addFaculty(faculty);
    cout<<"*******************************"<<endl;

    cout<<"             Employee\n*******************************\n";

    cout << "Enter Employee Name : " <<endl;
    cin>> employee.name;
    cout << "Enter the Department : " << endl;
    cin >> department.title;
    cout << "Enter Manager Name : " <<endl;
    cin>> manager->name;
    faculty.addEmployee(employee);
    faculty.addDepartment(department);

    cout<<"______________________________________________"<<endl;

    cout<<"Enter to see details : \n"<<"0->student 1->course 2->instructor 3->employee 4->manager "<<endl;

    cin>>num;
     if(num == 0 )
        {
            student.role();
        }
     if(num == 1 )
        {
            course.details();
        }
     if(num == 2 )
        {
            instructor.role();
        }
     if(num == 3 )
        {
            employee.role();
        }

   if(num == 4 )
        {
            manager->role();
        }
    return 0;
}
