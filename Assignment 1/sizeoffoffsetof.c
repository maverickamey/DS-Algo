#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
//#define offsetof(s,m) (size_t)&(((s *)0)->m)    instead of offsetof
#include <stddef.h>                      //offset is stored in this library and further as below syntax to find it
typedef struct emp_ {                    //typedef data_type new_name
char emp_name[30];
unsigned int emp_id;
unsigned int age;
struct emp_ *mgr;
float salary;
} emp_t;

typedef struct _student {
char stud_name[32];
int rollno;
int age;
} student_t;
int main()
{
emp_t Amey;
student_t Parth;


//printf("Size of emp_t=%ld\n",sizeof(Amey));
printf("Size of emp_t_emp_name=%ld\n",sizeof(Amey.emp_name));
printf("Size of emp_t_emp_id=%ld\n",sizeof(Amey.emp_id));
printf("Size of emp_t_emp_age=%ld\n",sizeof(Amey.age));
printf("Size of emp_t_emp_mgr=%ld\n",sizeof(Amey.mgr));
printf("Size of emp_t_emp_salary=%ld\n",sizeof(Amey.salary));
//printf("Size of emp_t=%u",sizeof(emp_t.mgr));
printf("Size of student_name=%ld\n",sizeof(Parth.stud_name));	
printf("Size of student_rollno=%ld\n",sizeof(Parth.rollno));
printf("Size of student_age=%ld\n",sizeof(Parth.age));
printf("Offset of emp_t_emp_name=%ld\n",offsetof(emp_t,emp_name));
printf("Offset of emp_t_emp_id=%ld\n",offsetof(emp_t,emp_id));
printf("Offset of emp_t_emp_age=%ld\n",offsetof(emp_t,age));
printf("Offset of emp_t_emp_mgr=%ld\n",offsetof(emp_t,mgr));
printf("Offset of emp_t_emp_salary=%ld\n",offsetof(emp_t,salary));
printf("Offset of student_name=%ld\n",offsetof(student_t,stud_name));
printf("Offset of student_rollno=%ld\n",offsetof(student_t,rollno));
printf("Offset of student_age=%ld\n",offsetof(student_t,age));
	return 0;

	
	
}
