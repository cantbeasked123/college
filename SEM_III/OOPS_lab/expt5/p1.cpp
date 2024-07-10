/*Create two class DM and DB which store the value distances. DM stores distances
in metres and centimetres and DB in feet and inches. Write a program that can
read values for the class objects and add one object of DM with another object of
DB. Use a friend function to carry out the addition operation. The object that
stores the results maybe a DM object or DB object, depending on the units in
which the results required. The display should be in the format of feet and inches
or metres and centimetres depending on the object on display.*/
//22CO16 Joshua B Fernandes 19/09/2023
#include<iostream>
using namespace std;
class DB; 
class DM
 {
public:
    float metre,centimetre;
    void getdata()
     {
         cout<<"Enter metre value: "<<endl;
         cin>>metre;
         cout<<"Enter centimetre value: "<<endl;
         cin>>centimetre;
     }
    friend float add(DM d1,DB d2);
 };
class DB
 {
public:
    float feet,inch;
    void getdata()
     {
         cout<<"Enter feet value: "<<endl;
         cin>>feet;
         cout<<"Enter inch value: "<<endl;
         cin>>inch;
     }
    friend float add(DM d1, DB d2);
 };
float add(DM d1, DB d2)
 {
   float x,y,z;
   x=(d1.metre+(d1.centimetre/100));
   y=(d2.feet+(d2.inch/12));
   int choice;
     do
      {
      	cout<<"\n\n1.Output in metres \n2.Output in feet\n3.Exit\n";
      	cout<<"Enter choice: "<<endl;
      	cin>>choice;
      	switch(choice)
      	 {
      	 	case 1: z=(x+(y*0.3048));                                       //    meters = 0.3048 * feet;
      	 	        cout<<"The sum of the two distances is "<<z<<" m";
      	 	        break;
      	 	case 2: z=(x*(3.2808)+y);                                       //    centimeters = 2.54 * inches;
      	 	        cout<<"The sum of the two distances is "<<z<<" ft";
      	 	        break;
      	 	case 3: exit(0);
      	 	        break;
      	   default: cout<<"Invalid Input\n";
      	 	        break;
		 } 
	  } while(1);
   return z;
 }

int main()
 {
     DM d1;
     DB d2;
     cout<<"Enter the distance in metre and centimetres: "<<endl;
     d1.getdata();
     cout<<"\nEnter the distance in feet and inches: "<<endl;
     d2.getdata();
     add(d1,d2);
     return 0;
 }

