/*
This is a project for PPS0335-Problem Solving and Programming assignment.
Members:
Joey Lim, J.H.,Chia, Y.W.,Gan, Y.F.,Tan
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class cashier{
    protected:
        float price;
        string product_name,product_id;
        int amount;
    public:
    //for get_Price & count
        void setPrice(){
            this -> price = price;
        }

        void setID(){
            this -> product_id = product_id;
        }

        void setName(){
            this -> product_name = product_name;
        }

        void search_product(){
            ifstream details,view;
            ofstream shoppinglist;
            string product_name,line,product_id,temp,line2;
            float price;
            char choice;
            int amount;
            details.open("items.txt", ios::in);
            shoppinglist.open("shoppinglist.txt", ios::out|ios::trunc);
            view.open("items.txt", ios::in);

            //view the items that exist in the item list
            if(view.is_open()){
                while(getline(view,line)){//to view every line
                    cout<<line<<endl;
                } }
             else{
                cout << "Unable to view." << endl;}

            do{
                cout << "Enter the product id : ";
                cin >> product_id;
                if( (details.is_open()) && (shoppinglist.is_open()) ){
                    while(getline(details,temp)){
                        details>>temp;
                        line.append(temp);
                        if(line.find(product_id) != string::npos){
                            details>>product_name>>price;
                            cout << "Product name : " << product_name << endl;
                            cout << "Price : RM " << price << endl;
                            cout << "Do you want to add this item to your shopping list (Y/N)?  ";
                            cin >> choice;
                            choice = tolower(choice);

                            if (choice == 'y'){
                                cout << "How much do you want?  ";
                                cin >> amount;
                                shoppinglist << product_name << ' ' << price << ' ' << amount << endl;
                            }
                            break;
                        }
                    }
                }
                else{
                    cout << "File is unable to open." << endl;
                }
            }while(product_id != "0000");
            system("pause");
            system("cls");
            details.close();
            view.close();
        }

        void count_product(){
            double sum = 0, sumitem;
            float price;
            int amount;
            string product_name;

            ifstream shoppinglist;
            ofstream bill;
            shoppinglist.open("shoppinglist.txt");
            bill.open("bill.txt", ios::trunc);

            while(shoppinglist >> product_name >> price >> amount){
                sumitem = price * amount;
                sum = sum + sumitem;

                bill << product_name << ' ' << price <<' '<< amount << ' ' << endl;
                cout << product_name << ' ' << price <<' '<< amount << ' ' << endl;
            }
            cout << "Total amount is RM " << sum << endl;
            system("pause");
            system("cls");
        }

};

class admin : public cashier{
    public :
        void add_product(){
            ofstream create_product;//ofstream  means for create and write info in file
            create_product.open("items.txt",ios::out|ios::app);//append means go the end of file
                if(create_product.is_open()){
                    cout << "Please enter the following details : " << endl;
                    cout << "Product ID : ";
                    cin >> product_id;
                    setID();
                    cout << "Product Name : ";
                    cin >> product_name;
                    setName();
                    cout << "Price (RM) : RM ";
                    cin >> price;
                    setPrice();
                    create_product<<product_id<< "\t "<<product_name<<"  "<<price<< endl;//All details that are typed here will be inserted into the file using the ofstream
                    cout << "Product is successfully created." << endl;
                    system("pause");
                    system("cls");
                }
                else{
                    cout << "File is unable to open" << endl; //If file unable is open, this will be the output
                    system("pause");
                    system("cls");
                }
            create_product.close();
        };

        void viewall_product(){
            ifstream view;
            string line;
            view.open("items.txt", ios::in);
            if(view.is_open()){
                while(getline(view,line)){//to view every line
                    cout<<line<<endl;
                }
                system("pause");
                system("cls");
            }
            else{
                cout << "Unable to view." << endl;
                system("pause");
                system("cls");
            }
            view.close();
        };

        void delete_product(){
            string product_id,product_name,line;
            float price;
            ifstream clean;//original file  open for reading
            clean.open("items.txt", ios::in);
            ofstream temp;//temporary file to store original content open for writing only
            temp.open("temp.txt", ios::out);
            cout << "Enter the product id which you want to delete: ";
            cin >> product_id;
            while(getline(clean,line)){ //loop to read every line in items.txt from clean
                if(line.substr(0, product_id.size()) != product_id){/*if the product_name(in the items.txt) is not same with the user's,
                                                                        it will put into the temp file which means user's one(which need to be deleted
                                                                        )will put into the file*/
                    temp<<line<<endl;
                }
            }
            cout << product_id << " is deleted." << endl;
            temp.close();
            clean.close();
            remove("items.txt");
            rename("temp.txt","items.txt");
            system("pause");
            system("cls");
        };

        void edit_product(){
            delete_product();//will clear screen after deleting the product, because there is system pause n clear in delete_product()
            add_product();    //same for this
        };

};

void showMenu_cashier(){
        cout << "1. Calculate price of product "<< endl;
        cout << "2. Exit "<< endl;

    };

    void showMenu_admin(){
        cout << "Welcome, dear Admin. "<<endl;
        cout << "1. Add product "<< endl;
        cout << "2. View all product "<< endl;
        cout << "3. Search  product "<< endl;
        cout << "4. Edit  product "<< endl;
        cout << "5. Calculate price of product "<< endl;
        cout << "6. Delete product "<< endl;
        cout << "7. Exit "<< endl;


    };

int main(){
    int choice,select;//select : Select whether you are the customer
    string password = "blekblekblek";
    string input_password;
    admin x;
    cashier u;

cout<< "              ##################################################################################"<<endl;
cout<< "              ##################################################################################"<<endl;
cout<< "              ########                               WELCOME                              ######"<<endl;
cout<< "              ########                                  TO                                ######"<<endl;
cout<< "              ########                             BLEK MARKET                            ######"<<endl;
cout<< "              ##################################################################################"<<endl;
cout<< "              ##################################################################################"<<endl<<endl;

cout<< " --------------------------------------------------------------------------------------------------------------------"<<endl;

do{
cout<< "                            ******************************************************"<<endl;
cout<< "                            ******************     WHO ARE YOU ?? ****************"<<endl;
cout<< "                            *************** 1.       CASHIER         *************"<<endl;
cout<< "                            *************** 2.        ADMIN          *************"<<endl;
cout<< "                            ******************************************************"<<endl<<endl;
cout<< " Please key in 1 if you are the cashier and 2 if you are the admin. :) "<<endl;
cout<< " NOTE: You can key in any number to exit."<<endl;
cout<< " Choice : ";
cin>> select;
system("cls");

switch (select){
cout.setf(ios::fixed);
cout.precision(2);
cout.setf(ios::showpoint);
case 1:
    do {
            showMenu_cashier();
            cout<<endl;
            cout << "Please key in your choice (Example: 1) : ";
            cin>>choice;
            system("cls");
            switch (choice){

            case 1:
            u.search_product();
            u.count_product();
            break;

            case 2:
            break;

            default:
                cout<< "Invalid input"<<endl;
            }
    }while(choice!=2);
    break;

case 2:
            cout<< "Please key in the password for admin : ";
            cin>>input_password;
            if (input_password==password){
                do{
                    system("cls");
                    showMenu_admin();
                    cout<<endl;
                    cout << "Please key in your choice (Example: 1) : ";
                    cin>>choice;
                    system("cls");
                    switch (choice){
                    case 1:
                    x.add_product();
                    break;

                    case 2:
                    x.viewall_product();
                    break;

                    case 3:
                    u.search_product();
                    break;

                    case 4:
                    x.edit_product();
                    break;

                    case 5:
                    u.search_product();
                    u.count_product();
                    break;

                    case 6:
                    x.delete_product();
                    break;

                    case 7:
                    break;

                    default:
                    cout << "Invalid input" << endl;
                        }
                    }while(choice!=7);
                }
                else{
                cout<< "Invalid password. Please leave this page. "<<endl;
                system("pause");
                system("cls");
                }
 break;
default:
    cout<< "Good byeeeeeeeeeeeeeeeeeeee!"<<endl;

}
}while(select==1||select==2);

    return 0;
}
