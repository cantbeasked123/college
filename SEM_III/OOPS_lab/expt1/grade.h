using namespace std;
namespace grade
{
    float percentage(int s1,int s2,int s3,int s4,int s5)
    {
        int sum;
        float per;
        sum=s1+s2+s3+s4+s5;
        per=sum*0.2;
        return per;
    }

    char grad(float percentage)
    {
        if(percentage>=85)
            cout<<"O";
        else if(percentage<85&&percentage>=75)
            cout<<"A+";
        else if(percentage<75&&percentage>=65)
            cout<<"A";
        else if(percentage<65&&percentage>=55)
            cout<<"B+";
        else if(percentage<55&&percentage>50)
            cout<<"B";
        else if(percentage<50&&percentage>=40)
            cout<<"P";
        else
            cout<<"F";
}
}
