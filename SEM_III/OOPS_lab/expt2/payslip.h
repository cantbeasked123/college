using namespace std;

namespace payslip
{
    class Employee
    {
        string name;
        int empID, pos;

        public:
        void setName(string n){name = n;}
        void setEmpID(int id){empID = id;}
        void setPosition(int p){pos = p;}

        string getName(){return name;}
        int getEmpID(){return empID;}
        int getPosition(){return pos;}
    };

    class Pay
    {
        public:
        int basicPay(int pos)
        {
            if(pos==1){return 100000;}
            else if(pos==2){return 80000;}
            else if(pos==3){return 60000;}
            else if(pos==4){return 40000;}
            else if(pos==5){return 20000;}
        }

        int dearAllow(int pos)
        {
            if(pos==1){return 2500;}
            else if(pos==2){return 2000;}
            else if(pos==3){return 1500;}
            else if(pos==4){return 1000;}
            else if(pos==5){return 500;}
        }

        int travelAllow(int pos)
        {
            if(pos==1){return 5000;}
            else if(pos==2){return 4000;}
            else if(pos==3){return 3000;}
            else if(pos==4){return 2000;}
            else if(pos==5){return 1000;}
        }

        int total(int pos)
        {
            return basicPay(pos)+dearAllow(pos)+travelAllow(pos);
        }
    };
}
