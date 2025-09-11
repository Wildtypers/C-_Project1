#include <iostream>
#include <string>
#include<iomanip>

using namespace std;
// struct creation for accounts
struct account{
    string username;
    string country;
    int age;
    double accountBalance;
};

int main(){
    //Printed out instructions
    cout << "Please enter information to database in the format of <username> <country> <age> <accountBalance>, separated each user by a newline: ";
    account accts[30];
    //setting up variables
    string username;
    string country;
    int age;
    double accountBalance;
    int iterations = 0;
    //inputting in data in struct list
    while(cin >> username >> country >> age >> accountBalance){
        accts[iterations].username = username;
        accts[iterations].country = country;
        accts[iterations].age = age;
        accts[iterations].accountBalance = accountBalance;
        iterations++;
    }
    //calculation for highest account balance
    double highestBalance = 0;
    for (int i = 0; i < iterations; i++)
    {
        if (accts[i].accountBalance > highestBalance)
        {
            highestBalance = accts[i].accountBalance;
        }
    }
    //calculation for sum of account balance for all users
    double acctBalanceSum = 0;
    for (int i = 0; i < iterations; i++)
    {
        acctBalanceSum += accts[i].accountBalance;
    }
    //how many users from Haiti
    int numUsersHaiti = 0;
    for (int i = 0; i < iterations; i++)
    {
        if (accts[i].country == "Haiti")
        {
            numUsersHaiti += 1;
        }
    }
    //Test to see if there is anyone younger than 21
    string youngerThan21 = "No";
    for (int i = 0; i < iterations; i++)
    {
        if (accts[i].age < 21)
        {
            youngerThan21 = "Yes";
        }
    }
    //outputting the result
    cout << "Q: What's the highest account balance among all users?" << endl;
    cout << "A: $" << setprecision(1) << fixed << highestBalance << endl;
    cout << "\nQ: What's the sum of account balance of all users?" << endl;
    cout << "A: $" << setprecision(2) << fixed << acctBalanceSum << endl;
    cout << "\nQ: How many users come from Haiti?" << endl;
    cout << "A: " << numUsersHaiti << endl;
    cout << "\nQ: Do we have any user younger than 21?" << endl;
    cout << "A: "<< youngerThan21<< endl;
    return 0;
}