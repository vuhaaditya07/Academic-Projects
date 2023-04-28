#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>
#include <string.h>

using namespace std;
vector<vector<string>> content_seller;
inline void initialize()
{
    cout << "\t\t\t\t========================================================================" << endl;
    cout << "\t\t\t\t|                  WELCOME TO SRM PHARMACY STORE!                      |" << endl;
    cout << "\t\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t\t|   1. Medicine Stock Record Management                                |" << endl;
    cout << "\t\t\t\t|   2. Customer information and Billing System                         |" << endl;
    cout << "\t\t\t\t|   3. Sale and Supplier Management                                    |" << endl;
    cout << "\t\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t\t========================================================================" << endl;
    return;
}

// !MEDICINE STOCK RECORD MANAGEMENT STARTS HERE ->
vector<vector<string>> content;
class Medicine
{
private:
    string medi_name, medi_id;
    string mfg_date, exp_date;
    int medi_quantity;
    float medi_price;

public:
    Medicine()
    {
        ofstream medicine_sheet("stock_record.csv", ios::app);
        cout << "Enter the id of medicine: ";
        cin >> medi_id;
        medicine_sheet << medi_id << ",";
        cout << "Enter the name of medcine: ";
        cin >> medi_name;
        medicine_sheet << medi_name << ",";
        cout << "Enter the manifacturing date: ";
        cin >> mfg_date;
        medicine_sheet << mfg_date << ",";
        cout << "Enter the expiry date: ";
        cin >> exp_date;
        medicine_sheet << exp_date << ",";
        cout << "Enter the price of medicine: ";
        cin >> medi_price;
        medicine_sheet << medi_price << endl;
        medicine_sheet.close();
    }
    ~Medicine()
    {
        // THIS IS A DESTRUCTOR
    }
};
inline void add_medicine()
{
    Medicine m1;
    return;
}
void print_medicines()
{
    vector<string> row;
    string line, word;
    fstream file("stock_record.csv", ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout << "Could not open the file\n";
}
void printing_here()
{
    system("cls");
    print_medicines();
    for (int i = 1; i < content.size(); i++)
    {
        cout << "DETAILS OF MEDICINE " << i << "\n\n";
        cout << "MEDICINE ID: " << content[i][0] << endl;
        cout << "MEDICINE NAME: " << content[i][1] << endl;
        cout << "MANIFACTURING DATE: " << content[i][2] << endl;
        cout << "EXPIRY DATE: " << content[i][3] << endl;
        cout << "PRICE: " << content[i][4] << endl;
        cout << "\n";
    }
    content.clear();
    return;
}
int finding_here(string check)
{
    system("cls");
    print_medicines();
    for (int i = 1; i < content.size(); i++)
    {
        if (content[i][0] == check)
        {
            cout << "DETAILS OF MEDICINE " << i << "\n\n";
            cout << "MEDICINE ID: " << content[i][0] << endl;
            cout << "MEDICINE NAME: " << content[i][1] << endl;
            cout << "MANIFACTURING DATE: " << content[i][2] << endl;
            cout << "EXPIRY DATE: " << content[i][3] << endl;
            cout << "PRICE: " << content[i][4] << endl;
            cout << "\n";
            return i;
        }
    }
    cout << "\aNO SUCH MEDICINE FOUND IN THE STORAGE....." << endl;
    content.clear();
    return 0;
}
int finding_here(string check, int extra)
{
    system("cls");
    print_medicines();
    for (int i = 1; i < content.size(); i++)
    {
        if (content[i][0] == check)
        {
            cout << "DETAILS OF MEDICINE " << i << "\n\n";
            cout << "MEDICINE ID: " << content[i][0] << endl;
            cout << "MEDICINE NAME: " << content[i][1] << endl;
            cout << "MANIFACTURING DATE: " << content[i][2] << endl;
            cout << "EXPIRY DATE: " << content[i][3] << endl;
            cout << "PRICE: " << content[i][4] << endl;
            cout << "\n";
            return stoi(content[i][4]);
        }
    }
    cout << "\aNO SUCH MEDICINE FOUND IN THE STORAGE....." << endl;
    content.clear();
    return 0;
}
// ! <-MEDICINE STOCK RECORD MANAGEMENT ENDS HERE...

// !BILL MANAGEMENT STARTS HERE ->
class Bill
{
public:
    string customer_name;
    string phone_number;
    int no_of_medicines = 0;
    float total_price = 0;
    vector<string> medicine_ids;

    void get()
    {
        cout << "Enter customer name: ";
        cin >> customer_name;
        cout << "Enter customer phone number: ";
        cin >> phone_number;
        cout << "Enter the no. of medicines needed: ";
        cin >> no_of_medicines;
        if (no_of_medicines == 0)
        {
            total_price = 0;
        }
        else
        {
            cout << "HERE ARE THE LIST OF MEDICINES AVAILABLE: " << endl;
            printing_here();
            for (int i = 0; i < no_of_medicines; i++)
            {
                string medicine_id;
                int dummy = 0;
                cout << "Enter Medicine" << i + 1 << " id: ";
                cin >> medicine_id;
                medicine_ids.push_back(medicine_id);
                total_price += finding_here(medicine_id, dummy);
                medicine_ids.clear();
            }
        }
        cout << "HERE IS YOUR BILL: " << endl;
        cout << "TOTAL BILL: " << total_price << "Rs." << endl;
    }
    void add_to_sheet()
    {
        ofstream customer_sheet("customer_record.csv", ios::app);
        customer_sheet << customer_name << ",";
        customer_sheet << phone_number << ",";
        customer_sheet << no_of_medicines << ",";
        for (int i = 0; i < medicine_ids.size(); i++)
        {
            customer_sheet << medicine_ids[i] << " ";
        }
        customer_sheet << ",";
        customer_sheet << total_price << endl;
    }
    Bill()
    {
        // THIS IS A DUMMY CONSTRUCTOR
    }
    ~Bill()
    {
        // THIS IS A DESTRUCTOR
    }
};
vector<Bill> customers;
void print_obj(Bill obj)
{
    cout << "NAME OF THE CUSTOMER: " << obj.customer_name << endl;
    cout << "PHONE NUMBER: " << obj.phone_number << endl;
    cout << "No. of medicines brouught: " << obj.no_of_medicines << endl;
    cout << "Medicine details: " << endl;
    for (int i = 0; i < obj.medicine_ids.size(); i++)
    {
        cout << "MEDICINE " << i + 1 << " ID: " << obj.medicine_ids[i] << endl;
    }
    cout << "TOTAL AMOUNT PAID = " << obj.total_price << endl;
    return;
}
// ! <- BILL MANAGEMENT ENDS HERE...

// !SUPPLIER RECORD MANAGEMENT STARTS HERE ->
class Seller
{
private:
    string supplier_name, supplier_id;
    string lastsupply_date;
    string review;
    int no_of_med;

public:
    Seller()
    {
        ofstream supplier_sheet("supplier_record.csv", ios::app);
        cout << "Enter the id of supplier: ";
        cin >> supplier_id;
        supplier_sheet << supplier_id << ",";
        cout << "Enter the name of supplier: ";
        cin >> supplier_name;
        supplier_sheet << supplier_name << ",";
        cout << "Enter the date: ";
        cin >> lastsupply_date;
        supplier_sheet << lastsupply_date << ",";
        cout << "Enter the number of medicines supplied: ";
        cin >> no_of_med;
        supplier_sheet << no_of_med << ",";
        string supplied_medicines = "";
        for (int i = 0; i < no_of_med; i++)
        {
            string temp;
            cout << "Enter the name of supplied medicine: ";
            cin >> temp;
            supplied_medicines = temp + " " + supplied_medicines;
        }
        supplier_sheet << supplied_medicines << ",";
        cout << "Enter the review about supplier (GOOD/BAD): ";
        cin >> review;
        supplier_sheet << review << endl;
        supplier_sheet.close();
    }
    ~Seller()
    {
        // THIS IS A DESTRUCTOR
    }
};
inline void add_seller()
{
    Seller s1;
    return;
}
void print_supplier()
{
    vector<string> row;
    string line, word;
    fstream file("supplier_record.csv", ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            content_seller.push_back(row);
        }
    }
    else
        cout << "Could not open the file\n";
}
void supplier_details()
{
    system("cls");
    print_supplier();
    for (int i = 1; i < content_seller.size(); i++)
    {
        cout << "DETAILS OF SUPPLIER " << i << "\n\n";
        cout << "SUPPLIER ID: " << content_seller[i][0] << endl;
        cout << "SUPPLIER NAME: " << content_seller[i][1] << endl;
        cout << "SUPPLIED DATE: " << content_seller[i][2] << endl;
        cout << "NO. OF DRUGS SUPPLIED: " << content_seller[i][3] << endl;
        cout << "MEDICINE NAMES: " << content_seller[i][4] << endl;
        cout << "REVIEW: " << content_seller[i][5] << endl;
        cout << "\n";
    }
    content_seller.clear();
    return;
}
void finding_seller(string check)
{
    system("cls");
    print_supplier();
    for (int i = 1; i < content_seller.size(); i++)
    {
        if (content_seller[i][0] == check)
        {
            cout << "DETAILS OF SUPPLIER " << i << "\n\n";
            cout << "SUPPLIER ID: " << content_seller[i][0] << endl;
            cout << "SUPPLIER NAME: " << content_seller[i][1] << endl;
            cout << "SUPPLIED DATE: " << content_seller[i][2] << endl;
            cout << "NO. OF DRUGS SUPPLIED: " << content_seller[i][3] << endl;
            cout << "MEDICINE NAMES: " << content_seller[i][4] << endl;
            cout << "REVIEW: " << content_seller[i][5] << endl;
            cout << "\n";
            return;
        }
    }
    cout << "NO SUCH SELLER FOUND IN THE RECORD....." << endl;
    content_seller.clear();
    return;
}

// ! <- SUPPLIER RECORD MANAGEMENT ENDS HERE...

int main()
{
start:
    initialize();
    cout << "Enter your choice here: ";
    int choice;
    cin >> choice;
    system("CLS");
    switch (choice)
    {
    case 1:
    {
        cout << "================================================================" << endl;
        cout << "|ONLY SRM MEDICAL ASSISTANT CAN ACCESS THE FILE.               |" << endl;
        cout << "|PLEASE LOGIN IF YOU ARE A MEDICAL ASSISTANT                   |" << endl;
        cout << "================================================================" << endl;
        int count = 0;
        do
        {
            string user_id;
            cout << "ENTER USER ID: ";
            cin >> user_id;
            string pass;
            cout << "ENTER PASS: ";
            cin >> pass;
            if (user_id == "SRM_PHARMA" && pass == "123Pharma")
            {
                cout << "================================================================" << endl;
                cout << "|                      LOGIN SUCCESS!!                         |" << endl;
                cout << "================================================================" << endl;
                break;
            }
            else
            {
                cout << "RE-ENTER DETAILS......" << endl;
                count++;
            }
        } while (count <= 3);
        if (count > 3)
        {
            cout << "================================================================" << endl;
            cout << "|                      FAILED TO LOGIN!!                       |" << endl;
            cout << "================================================================" << endl;
            goto start;
        }
        while (true)
        {
            cout << "================================================================" << endl;
            cout << "|1. ADD A MEDICINE                                             |" << endl;
            cout << "|2. PRINT THE MEDICINES IN ORDER                               |" << endl;
            cout << "|3. FIND THE MEDICINE DETAILS                                  |" << endl;
            cout << "|4. FIND THE RECENT CUSTOMERS                                  |" << endl;
            cout << "|5. EXIT!                                                      |" << endl;
            cout << "================================================================" << endl;
            int choice_1;
            cin >> choice_1;
            switch (choice_1)
            {
            case 1:
            {
                add_medicine();
                break;
            }
            case 2:
            {
                printing_here();
                break;
            }
            case 3:
            {
                string n;
                cout << "Enter medicine id number: ";
                cin >> n;
                finding_here(n);
                content.clear();
                break;
            }
            case 4:
            {
                for (int i = 0; i < customers.size(); i++)
                {
                    print_obj(customers[i]);
                }
                break;
            }
            case 5:
            {
                goto start;
            }
            }
        }
    }
    case 2:
    {
        cout << "================================================================" << endl;
        cout << "|           HELLO THERE! WELCOME TO SRM PHARMA STORE           |" << endl;
        cout << "================================================================" << endl;
        Bill obj;
        obj.get();
        customers.push_back(obj);
        obj.add_to_sheet();
        goto start;
    }
    case 3:
    {
        cout << "================================================================" << endl;
        cout << "|ONLY SRM MEDICINE SUPPLIER CAN ACCESS THE FILE.               |" << endl;
        cout << "|PLEASE LOGIN IF YOU ARE A SUPPLIER                            |" << endl;
        cout << "================================================================" << endl;
        int count = 0;
        do
        {
            string user_id;
            cout << "ENTER USER ID: ";
            cin >> user_id;
            string pass;
            cout << "ENTER PASS: ";
            cin >> pass;
            if (user_id == "SRM_ASSIST" && pass == "123Pharma")
            {
                cout << "================================================================" << endl;
                cout << "|                      LOGIN SUCCESS!!                         |" << endl;
                cout << "================================================================" << endl;
                break;
            }
            else
            {
                cout << "RE-ENTER DETAILS......" << endl;
                count++;
            }
        } while (count <= 3);
        if (count > 3)
        {
            cout << "================================================================" << endl;
            cout << "|                      FAILED TO LOGIN!!                       |" << endl;
            cout << "================================================================" << endl;
            goto start;
        }
        while (true)
        {

            cout << "================================================================" << endl;
            cout << "|1. ADD THE DETAILS OF SUPPLIER                                |" << endl;
            cout << "|2. FIND THE MEDICINE SUPPLIER DETAILS                         |" << endl;
            cout << "|3. PRINT ALL THE MEDICINES SUPPLIER DETAILS                   |" << endl;
            cout << "|4. EXIT!                                                      |" << endl;
            cout << "================================================================" << endl;
            int c;
            cin >> c;
            switch (c)
            {
            case 1:
            {
                add_seller();
                break;
            }
            case 2:
            {
                cout << "Enter the id of supplier to be searched: ";
                string check;
                cin >> check;
                finding_seller(check);
                content_seller.clear();
                break;
            }
            case 3:
            {
                supplier_details();
                break;
            }
            case 4:
            {
                goto start;
            }
            }
        }
    }
    default:
    {
        cout << "\t\t\tTHANKS FOR USING OUR TOOL! " << endl;
    }
    }

    return 0;
}
