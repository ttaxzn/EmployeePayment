#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Employee.h"
using namespace std;

int main ()
{
ifstream fin;
ofstream fout;

string op;
int ID;
string firstname;
string lastname;
string fullname;
int raise;
vector <Employee> empvect;
int i;
fin.open("input.txt");
while(fin.good())
{
    fin >> op;
    if(op=="PAY")
    {
        for(i=0; i<empvect.size(); i++)
        {
            empvect.at(i).pay();
        }
    }
    if(op=="NEW")
    {
        fin >> ID;
        fin >> firstname;
        fin >> lastname;
        fullname = firstname + " " + lastname;
        Employee emp(ID, fullname);
        empvect.push_back(emp);
    }
    if(op=="RAISE")
    {
        fin >> ID;
        for(i=0; i<empvect.size(); i++)
        {
        if(empvect.at(i).getEmployeeID()==ID)
        {
            fin >> raise;
            empvect.at(i).giveRaise(raise);
        }
        }
    }
    if(op=="FIRE")
    {
        fin >> ID;
        for(i=0; i<empvect.size(); i++)
        {
            if(empvect.at(i).getEmployeeID()==ID)
            {
                empvect.at(i).fire();
            }
        }
    }
    
}
fout.open("output.txt");

for(i=0; i<empvect.size(); i++)
{
    if(empvect.at(i).isEmployed()==true)
    {
    fout << "Name, ID ###: " << empvect.at(i).getName() << ", " << empvect.at(i).getEmployeeID() << endl;
    fout << "Current pay rate: $" << empvect.at(i).getPayRate() << endl;
    fout << "Pay earned to date: $" << empvect.at(i).getBalance() << endl;
    fout << endl;
    }
    
    if(empvect.at(i).isEmployed()==false)
    {
    fout << "Name, ID ###: " << empvect.at(i).getName() << ", " << empvect.at(i).getEmployeeID() << endl;
    fout << "Not employed with the company." << endl;
    fout << "Pay earned to date: $" << empvect.at(i).getBalance() << endl;
    fout << endl;    
    }
}
}