// Tea Abuselidze
// 11-16-21
// 

#include <string>
#include "Employee.h"
using namespace std;

// Constructor
	Employee::Employee(int id, string myName)
    {
        employeeID=id;
        name=myName;
        payRate=10;
        employed=true;
        balance=0;
    }

	int Employee::getEmployeeID()
    {
        return employeeID;
    }

	double Employee::getPayRate()
    {
        return payRate;
    }


	double Employee::getBalance()
    {
        return balance;
    }


	string Employee::getName()
    {
        return name;
    }

	// Function to give the raise. It takes in a percent in whole numbers 
	// (ex: 5 for 5%)
	void Employee::giveRaise(int rate)
    {
        double percent;
        percent=rate;
        percent=1+(percent/100);
        payRate=payRate*percent;
    }


	// Pays the employee
	void Employee::pay()
    {
        if(employed==true)
        {
        balance=balance+payRate;
        }
    }


	void Employee::fire()
    {
        employed=false;
        payRate=0;
        
    }

	// Returns if the Employee is currently employed
	bool Employee::isEmployed()
    {
        return employed;
    }

