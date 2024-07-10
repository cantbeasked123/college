/*Kristen is a contender for gold medal of her high school. She wants to know how
many students (if any) have scored higher than her in the exams given during this
semester. Create a class named Student with the following specifications
An variable named scores to hold a student's 5 exam scores. A void input()
function that reads integers and saves them to. An int calculateTotalScore() friend
function that returns the sum of the student's scores.
Read 5 scores for every student & save them to scores. Display how many
students have got score higher than Kristen.*/
//22CO16 Joshua B Fernandes 19/09/2023
#include<iostream>
using namespace std;
class student
{
    int scores[5];
    public:
    void input()
    {
        cout<<"Enter the marks of 5 subjects: "<<endl;
        for(int i=0;i<5;i++)
        {
            cin>>scores[i];
        }
    }
    friend int calculateTotalScore(student s);
};

int calculateTotalScore(student s)
{
    int sum=0,i;
    for(i=0;i<5;i++)
    {
        sum=sum+s.scores[i];
    }
    return sum;
}

int main()
{
    int no_of_students,count=0,i;
    cout<<"Enter the number of students:"<<endl;
    cin>>no_of_students;
    student s[no_of_students];
    cout<<"Enter Kristen's marks:"<<endl;
    s[0].input();

    for(i=1;i<no_of_students;i++)
    {
        cout<<"Enter marks of student No."<<i+1<<endl;
        s[i].input();
    }

    for(i=1;i<no_of_students;i++)
    {
        if(calculateTotalScore(s[0])<calculateTotalScore(s[i]))
        {
            count++;
        }
    }
    cout<<"Total number of students who have scored more than Kristen is:"<<count<<endl;
}
