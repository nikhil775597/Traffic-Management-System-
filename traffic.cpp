#include <iostream>
#include <iomanip>
using namespace std;
class vehicle
{
private:
    char vehicle_number[100];
    int type;

public:
    void set_vehicle()
    {

        cout << "Enter Vehicle Type: " << endl;
        cout << "1)two_wheeler\n2)four_wheeler" << endl;
        cin >> type;
        cout << "Enter Vehicle Number: " << endl;
        cin >> vehicle_number;
    }
    void get_vehicle()
    {
        cout << "\t\t|" << "Vehicle Number : " << vehicle_number << setw(9) << "|" << endl;
        if (type == 1)
        {
            cout << "\t\t|" << "Vehicle type : " << "Two Wheeler"
                                                    " "
                 << setw(7) << "|" << endl;
        }
        else
        {
            cout << "\t\t|" << "Vehicle type : " << "Four Wheeler" << setw(7) << "|" << endl;
        }
    }
};
class bank : public vehicle
{
private:
    int acc_no, balance;

public:
    void set_bank()
    {
        acc_no = rand() % 10000;
        cout << "Bank Account Number: " << acc_no << endl;
        balance = (rand() % 2000) + 1000;
        cout << "Owner Balance: " << balance << endl;
    }
    void get_bank()
    {

        cout << "\t\t|" << "Bank Account Number: " << acc_no << setw(9) << "|" << endl;
        if (balance > 0)
            cout << "\t\t|" << "Balance: " << balance << setw(21) << "|" << endl;
    }
    void update_bank(int fine)
    {
        if (fine > balance)
            cout << "|" << "Pay " << fine << "rs" << " before month end" << setw(8) << "|" << endl;
        balance = balance - fine;
    }
};
class fine
{
private:
    bank *veh;
    int crime;
    int fine_amt;

public:
    int set_fine(bank *ptr)
    {
        cout << "Enter Crime Type: ";
        cout << "1)signal_broke\n2)No Helmet and Licence" << endl;
        cin >> crime;
        if (crime == 1)
            fine_amt = 500;
        if (crime == 2)
            fine_amt = 800;
        static int total = 0;
        total = total + fine_amt;
        cout << "Total Fine Collected: " << total << endl;

        veh = ptr;
        return fine_amt;
    }
    void get_fine()
    {
        cout << "Crime type: " << crime;
        cout << "Fine amt: " << fine_amt;
    }
    void execute()
    {
        veh->update_bank(fine_amt);
    }
};
void dowork()
{
    cout << "Enter the details culprit " << endl;
    bank *ptr;
    ptr = new bank();
    ptr->set_vehicle();
    cout << " " << endl;
    cout << "Message:Owner details are sent" << endl;
    ptr->set_bank();
    fine f;
    int result = f.set_fine(ptr);

    cout << "Receipt is here..." << endl;
    cout << " " << "-----------------------------------" << endl;
    cout << "\t\t|" << "**Traffic-Signal Recipt**" << setw(7) << "|" << endl;
    cout << "\t\t|" << "Your fine is: " << result << "rs" << setw(15) << "|" << endl;
    f.execute();
    cout << "\t\t|" << "Vehicle details" << setw(17) << "|" << endl;
    ptr->get_vehicle();
    cout << "\t\t|" << "Bank details" << setw(20) << "|" << endl;
    ptr->get_bank();
    cout << "\t\t-----------------------------------" << endl;
    cout << " " << endl;
}
int main()
{
    int choice;
    static int count = 0;
    cout << "*Welcome to traffic-management system*" << endl;
    while (1)
    {
        cout << "Hello Officer!!! Did anyone broke the rule?" << endl;
        cout << "1)Yes\n2)No" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            dowork();
            break;
        case 2:
            cout << "Fine! No Fine" << endl;
            cout << count << " Culprits broke the rule today?!" << endl;
            exit(0);
        }
        count++;
    }
    return 0;
}