#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <limits>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <fstream>
#include <sstream>

using namespace std;

void Inventory(int index_number[], string Book_names[], string status[],string Book_author[], int index_size);

void searchBook(int index_number[], string Book_names[], string status[],string Book_author[], int index_size);

void addbook(int index_number[], string Book_names[], string status[],string Book_author[], int & index_size);

void IssueBook (int index_number[], string Book_names[], string status[],string Book_author[], int index_size);

void Recallbook(int index_number[], string Book_names[], string status[],string Book_author[], int index_size);

void clearScreen();

void sleepForSeconds(int seconds);

void saveDataToFile(int index_number[], string Book_names[], string status[], string Book_author[], int index_size);

void loadDataFromFile(int index_number[], string Book_names[], string status[], string Book_author[], int & index_size);

int main() {
    int index_number[10000];
    string Book_names[10000];
    string Book_author[10000];
    string status[10000];

    int index_size = 0,user_choice;

    loadDataFromFile(index_number, Book_names, status,Book_author, index_size);

    do{
            cout<<"========================="<<endl;
            cout<<"Library Management system"<<endl;
            cout<<"========================="<<endl<<endl<<endl;
            cout<<"--------------------"<<endl;
            cout<<"|"<<"1. Check Inventory"<<" |"<<endl;
            cout<<"|"<<"2. Book Search"<<"     |"<<endl;
            cout<<"|"<<"3. Add a new book"<<"  |"<<endl;
            cout<<"|"<<"4. Issue a book"<<"    |"<<endl;
            cout<<"|"<<"5. Recall a book"<<"   |"<<endl;
            cout<<"|"<<"6. Exit"<<"            |"<<endl;
            cout<<"--------------------"<<endl<<endl;

            cout<<"Enter a Choice : ";
            cin>>user_choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch(user_choice){
       case 1:
               Inventory(index_number, Book_names, status,Book_author, index_size);
               break;
       case 2:
               searchBook(index_number, Book_names, status,Book_author, index_size);
               break;
       case 3:
               addbook(index_number, Book_names, status,Book_author, index_size);
               saveDataToFile(index_number, Book_names, status,Book_author, index_size);
                sleepForSeconds(3);
                clearScreen();
               break;
       case 4:
               IssueBook(index_number, Book_names, status,Book_author, index_size);
               saveDataToFile(index_number, Book_names, status,Book_author, index_size);
                sleepForSeconds(3);
                clearScreen();
               break;
       case 5:
               Recallbook(index_number, Book_names, status,Book_author, index_size);
               saveDataToFile(index_number, Book_names, status,Book_author, index_size);
                sleepForSeconds(3);
                clearScreen();
               break;
       case 6:
               cout<<"Exiting........."<<endl;
               break;
       default:
               cout<<"Enter a valid choice"<<endl;
        }
    }while(user_choice!=6);
    return 0;
}






//functions


void Inventory(int index_number[], string Book_names[], string status[],string Book_author[], int index_size) {
    cout<<"_______________________________________________________________________________________________________"<<endl;
    cout<<setw(20)<<"Inventory Number"<<" |";
    cout<<setw(30)<<"Book Name"<<" |";
    cout<<setw(30)<<"Author"<<" |";
    cout<<setw(15)<<"Status"<<" |"<<endl;

    cout<<"======================================================================================================="<<endl<<endl;

    for(int i = 1; i <= index_size; i++){
        cout<<setw(20)<<index_number[i]<<" |";
        cout<<setw(30)<<Book_names[i]<<" |";
        cout<<setw(30)<<Book_author[i]<<" |";
        cout<<setw(15)<<status[i]<<" |"<<endl;
        cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
    }
    cout<<endl<<endl;
}

void searchBook(int index_number[], string Book_names[], string status[],string Book_author[], int index_size){
    int matches_found=0,search_type;
    string temp;
    cout<< "-------------------------------------------------------------------------------------------------------\nSearch for a particular book"<<endl;
    cout<<"Select search type :\n 1. Search by Book name  \n 2. Search by Author name"<<endl;
    while(true){
        cout<<"Enter your choice : ";
        cin>>temp;
        stringstream ss(temp);
        if(ss>>search_type && ss.eof()){
            break;
        }
        else {
            cout<<"Please enter either 1 or 2"<<endl;
            break;
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if(search_type<3 && search_type>0){
    if(search_type==1){

    string userkeyword;
    cout << "Enter Book name or a keyword to search: ";
    getline(cin, userkeyword);
    for (char &c : userkeyword) {
        c = tolower(c);
    }
    int userinputlength=userkeyword.length();

    if(userkeyword!="")

    for (int i = 1; i <= index_size; i++) {
            string adjustedbooklength=Book_names[i].substr(0,userinputlength);
        if (userkeyword == adjustedbooklength) {
            cout<<"Match Found: "<<endl;
            cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
            cout<<setw(20)<<index_number[i]<<" |";
            cout<<setw(30)<<Book_names[i]<<" |";
            cout<<setw(30)<<Book_author[i]<<" |";
            cout<<setw(15)<<status[i]<<" |"<<endl;
            cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
            matches_found++;
        }
    }

    else {
        cout<<"No Match Found !"<<endl;
    }
    cout<<"Matches found : "<<matches_found<<endl;}


    else if (search_type==2){

    string userkeyword;
    cout << "Enter Author name or a keyword to search: ";
    getline(cin, userkeyword);
    for (char &c : userkeyword) {
        c = tolower(c);
    }
    int userinputlength=userkeyword.length();

    if(userkeyword!="")

    for (int i = 1; i <= index_size; i++) {
            string adjustedbooklength=Book_author[i].substr(0,userinputlength);
        if (userkeyword == adjustedbooklength) {
            cout<<"Match Found: "<<endl;
            cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
            cout<<setw(20)<<index_number[i]<<" |";
            cout<<setw(30)<<Book_names[i]<<" |";
            cout<<setw(30)<<Book_author[i]<<" |";
            cout<<setw(15)<<status[i]<<" |"<<endl;
            cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
            matches_found++;
        }
    }

    else {
        cout<<"No Match Found !"<<endl;
    }
    cout<<"Matches found : "<<matches_found<<endl;
    }
   }
   else {
    cout<<"Enter a valid choice"<<endl;
   }
   cout<<endl<<endl;
}

void addbook(int index_number[], string Book_names[], string status[],string Book_author[], int & index_size){
    cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
    if (index_size < 10000) {
        string new_book,new_author;
        cout<<"Enter Book name: ";
        getline(cin, new_book);
        for (char &c : new_book) {
        c = tolower(c);
    }

    cout<<"Enter Author name: ";
        getline(cin, new_author);
        for (char &c : new_author) {
        c = tolower(c);
    }

        if(new_book != ""||new_author != ""){

        index_size++;
        index_number[index_size] = index_size;
        Book_names[index_size] = new_book;
        Book_author[index_size] = new_author;
        status[index_size] = "Available";

        cout<<"Book added to inventory.\n";
        }
        else{
            cout<<"Book name or Author name cant be left empty"<<endl;
        }

        Inventory(index_number, Book_names, status, Book_author, index_size);
    } else {
        cout<<"Error: Inventory is full. Cannot add more books.\n";
    }
    cout<<endl<<endl;
}


void IssueBook (int index_number[], string Book_names[], string status[],string Book_author[], int index_size){
    cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
    string issuebookname;
    int match_found;
    cout<<"Enter a Book name : ";
    getline(cin, issuebookname);
    for (char &c : issuebookname) {
        c = tolower(c);
    }
     int userinputlength=issuebookname.length();

    if (issuebookname!= ""){
    cout<<"_______________________________________________________________________________________________________"<<endl;
    cout<<setw(20)<<"Inventory Number"<<" |";
    cout<<setw(30)<<"Book Name"<<" |";
    cout<<setw(30)<<"Author"<<" |";
    cout<<setw(15)<<"Status"<<" |"<<endl;
    cout<<"======================================================================================================="<<endl<<endl;
    for (int i = 1; i <= index_size; i++) {

            string adjustedbooklength=Book_names[i].substr(0,userinputlength);

        if (issuebookname == adjustedbooklength && status[i]!= "issued") {
            cout<<setw(20)<<index_number[i]<<" |";
            cout<<setw(30)<<Book_names[i]<<" |";
            cout<<setw(30)<<Book_author[i]<<" |";
            cout<<setw(15)<<status[i]<<" |"<<endl;
            cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
            match_found++;
    }
   }
   if(match_found==0) {
        cout<<"-------------------------------------------No match found!---------------------------------------------"<<endl;
    }
    cout<<endl<<endl<<match_found<<" Matches found"<<endl;
  }
    else {
        cout<<"Please enter a book name"<<endl;
    }
    if (match_found!=0){
    int userinputinventorynumber;
    cout<<"Enter the inventory number of the book you want to issue : ";
    cin>>userinputinventorynumber;

    if( userinputinventorynumber!=0 && status[userinputinventorynumber]!= "issued" && userinputinventorynumber<=index_size){
        status[userinputinventorynumber] = "issued";
        cout<<"Book: "<<Book_names[userinputinventorynumber]<<" Has been issued"<<endl;
    }
    else if (userinputinventorynumber==0 ||userinputinventorynumber>index_size){
        cout<<"Inventory number "<<userinputinventorynumber<<" doesn't exist"<<endl;
    }
    else if (status[userinputinventorynumber]=="issued"){
        cout<<"Book has already been issued"<<endl;
    }
   }
   cout<<endl<<endl;
}


void Recallbook(int index_number[], string Book_names[], string status[],string Book_author[], int index_size){
    cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
        string recallbookname;
    int match_found;
    cout<<"Enter a Book name : ";
    getline(cin, recallbookname);
    for (char &c : recallbookname) {
        c = tolower(c);
    }
     int userinputlength=recallbookname.length();

    if (recallbookname!= ""){
    cout<<"_______________________________________________________________________________________________________"<<endl;
    cout<<setw(20)<<"Inventory Number"<<" |";
    cout<<setw(30)<<"Book Name"<<" |";
    cout<<setw(30)<<"Author"<<" |";
    cout<<setw(15)<<"Status"<<" |"<<endl;
    cout<<"======================================================================================================="<<endl<<endl;
    for (int i = 1; i <= index_size; i++) {

            string adjustedbooklength=Book_names[i].substr(0,userinputlength);

        if (recallbookname == adjustedbooklength && status[i]!= "available") {
            cout<<setw(20)<<index_number[i]<<" |";
            cout<<setw(30)<<Book_names[i]<<" |";
            cout<<setw(30)<<Book_author[i]<<" |";
            cout<<setw(15)<<status[i]<<" |"<<endl;
            cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
            match_found++;
    }
   }
   if(match_found==0) {
        cout<<"-------------------------------------------No match found!---------------------------------------------"<<endl;
    }
    cout<<endl<<endl<<match_found<<" Matches found"<<endl;
  }
    else {
        cout<<"Please enter a book name"<<endl;
    }
    if (match_found!=0){
    int userinputinventorynumber;
    cout<<"Enter the inventory number of the book you want to recall : ";
    cin>>userinputinventorynumber;

    if( userinputinventorynumber!=0 && status[userinputinventorynumber]!= "available" && userinputinventorynumber<=index_size){
        status[userinputinventorynumber] = "available";
        cout<<"Book: "<<Book_names[userinputinventorynumber]<<" Has been recalled"<<endl;
    }
    else if (userinputinventorynumber==0 ||userinputinventorynumber>index_size){
        cout<<"Inventory number "<<userinputinventorynumber<<" doesn't exist"<<endl;
    }
    else if (status[userinputinventorynumber]=="available"){
        cout<<"Book has already been recalled"<<endl;
    }
   }
   cout<<endl<<endl;
}

// utility


void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void sleepForSeconds(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}


void saveDataToFile(int index_number[], string Book_names[], string status[], string Book_author[], int index_size) {
    ofstream file("library_data.txt");
    if (!file.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    for (int i = 1; i <= index_size; i++) {
        file << index_number[i] << "|"
             << Book_names[i] << "|"
             << Book_author[i] << "|"
             << status[i] << "\n";
    }
    file.close();
}
void loadDataFromFile(int index_number[], string Book_names[], string status[], string Book_author[], int &index_size) {
    ifstream file("library_data.txt");
    if (!file.is_open()) {
        cerr << "Error opening file for reading. Starting with default data." << endl;
        return;
    }
    index_size = 0;
    while (file >> index_number[index_size + 1]) {
        file.ignore();
        getline(file, Book_names[index_size + 1], '|');
        getline(file, Book_author[index_size + 1], '|');
        file >> status[index_size + 1];
        index_size++;
    }
    file.close();
}
