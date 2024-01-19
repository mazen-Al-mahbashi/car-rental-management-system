
#include <iostream>
#include <conio.h>
 #include <fstream>
#include <windows.h>
 #include <string.h>
 #include <stdio.h>
 #include <time.h>
 #include <cstdlib>

 using namespace std;

void customerData();
 int carCount();
 int custCount();
 int rate(int, int);
 void newCustData();
 void carData ();
void admin();
 void user();
 void menu();
 void fullscreen();
 void art();
 void exitArt();
 void newCarData();
 void delCar();
 void displayCar();
 void existingCust();
 void load();
 void load_CHECK();
 void gotoxy(int , int );
 void time();
 void Boarder();
 int countUser();
 void tNc();
 void readUserPass();
 void availCar();
 int countAvail();
 const string currentDateTime();
 const string Date();
 void date();
 void dispAvailCar();
 void GotoXY(int , int );
 void load_EXIT();
 void load_UPDATE();
 void newUserPass();
 void password();
 void resetAvail();
 void showCarData();
 void welcome();



 struct car
 {
 char plate_num[];
 char brand[];
 char model[];
 float capacity;
 char colour[];
 float rate_per_hour;
 float rate_per_half;
 float rate_per_day;
 char transmission[];
 };

 struct customer
 {
 int id;
 char name[];
 char phone[];
 char ic[];
 char address[];
 };

 struct pass
 {
 int ID;
 char passWord[];

 };

 pass userPass[];
 car rent[];
 customer cust[];
 car avail[];

 void fullscreen()
 {
 keybd_event(VK_MENU,x,,);
 keybd_event(VK_RETURN,xc,,);
 keybd_event(VK_RETURN,xc,KEYEVENTF_KEYUP,);
 keybd_event(VK_MENU,x,KEYEVENTF_KEYUP,);
 }

 const string currentDateTime()
 {
 time_t now = time();
 struct tm tstruct;
 char buf[];
 tstruct = *localtime(&now);
 strftime(buf, sizeof(buf), "%d/%m/%Y TIME: %X", &tstruct);

 return buf;
 }

 const string Date()
 {
 time_t now = time();
 struct tm tstruct;
 char buf[];
 tstruct = *localtime(&now);
 strftime(buf, sizeof(buf), "%d/%m/%Y TIME: %X", &tstruct);

 return buf;
 }

 void time()
 {
 int i=;

 while( i<)
 {
 Boarder();
 gotoxy(,);
 std::cout <<"\n\n\n\n\n\t |\t\t\t\tDATE: "<<currentDateTime() << std::endl;
 Sleep();
 system("cls");
 i++;
 }
 menu();
 }

 void date()
 {
 cout <<"\n\t |\t\t\t\t\t\tDATE: "<<Date()<<endl;

 }

 void readUserPass()
 {
 ifstream ifs;
 ifs.open("UserPass.txt");

 int i;
 while(!ifs.eof())
 {
 ifs>>userPass[i].ID;
 ifs.ignore();
 ifs.getline(userPass[i].passWord,);
 i++;
 }
 ifs.close();
 }

 void password()
 {
 Boarder();

 countUser();
 string password;
 char c;
 gotoxy(,);
 cout << "\n\n\n\n\t |\t\t\tPASSWORD: ";

 while(c != '\r') //Loop until 'Enter' is pressed
 {
 c = getch();
 if(c == )
 {
 switch(getch())
 {
 default:
 break;
 };
 }
 else if(c == '\b') //If the 'Backspace' key is pressed
 {
 if(password.size() != ) //If the password string contains data, erase last c
 {
 cout << "\b \b";
 password.erase(password.size() - , );
 }
 continue;
 }
 else if(c <= '' && c >= '' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') //
 {
 password += c;
 cout << "*";
 }
 else
 continue;
 }

 for(int i=; i<countUser();i++)
 {
 if(password.compare(userPass[i].passWord)==)
 {
 system("cls");
 load_CHECK();
 admin();
 }
 }


 if(password == "a")
 {
 system("cls");
 load_CHECK();
 admin();
 }

 else
 cout<<"\n\t |\t\t\tWrong Password.. Call Administrator";
 cout<<"\n\t |\t\t\tReturning to Main Menu.."<<endl;
 cout<<"\n\t |\t\t\t";
 Sleep();
 cout<<"\n\t |\t\t\tPress Enter to Continue.";
 cout<<"\n\t |\t\t\t";
 getch();
 menu();



 }

 void gotoxy(int x, int y)
 {

 COORD coord;

 coord.X = x;

 coord.Y = y;

 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

 }

 void load()
 {
 Boarder();

 int timer =+ rand()%;
 int row,col,r,c,q;
 gotoxy(,);
 cout<<"BOOTING UP...";
 gotoxy(,);
 for(r=;r<=timer;r++)
 {
 for(q=;q<=;q++);//to display the character slowly
 printf("%c",);
 }
 Sleep();
 system("cls");
 }

 void load_CHECK()
 {
 Boarder();
 int timer = rand()%+;
 int row,col,r,c,q;
 gotoxy(,);
 printf("LOG IN...");
 gotoxy(,);
 for(r=;r<=timer;r++)
 {
 for(q=;q<=;q++);//to display the character slowly
 printf("%c",);
 }
 Sleep();
 system("cls");
 }

 void load_UPDATE()
 {
 Boarder();

 int row,col,r,c,q;
 int timer = rand()%+;
 gotoxy(,);
 printf("UPDATING DATABASE...");
 gotoxy(,);
 for(r=;r<=timer;r++)
 {
 for(q=;q<=;q++);//to display the character slowly
 printf("%c",);
 }
 Sleep();
 system("cls");
 }

 void load_EXIT()
 {
 Boarder();

 int row,col,r,c,q;
 int timer = rand()%+;
 gotoxy(,);
 printf("LOGGING OFF...");
 gotoxy(,);
 for(r=;r<=timer;r++)
 {
 for(q=;q<=;q++);//to display the character slowly
 printf("%c",);
 }
 Sleep();
 system("cls");
 }

 void GotoXY(int x, int y)
 {
 HANDLE a;
 COORD b;
 fflush(stdout);
 b.X = x;
 b.Y = y;
 a = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleCursorPosition(a,b);
 }

 void Boarder()
 {
 int i;
 system("cls");
 for(i=;i<;i++)
 {
 GotoXY(i,);
 cout<<"=";
 GotoXY(i,);
 cout<<"=";
 }
 for(i=;i<;i++)
 {
 GotoXY(,i);
 cout<<"|";
 GotoXY(,i);
 cout<<"|";
 }
 }

 void art()
 {

 Boarder();
 gotoxy(, );

 ifstream ifs ("art.txt");
 string Lines = "";

 if (ifs)
 {
 while (ifs.good ())
 {
 string TempLine;
 getline (ifs , TempLine);
 TempLine += "\n";

 Lines += TempLine;
 }

 cout << Lines;
 date();
 }

 ifs.close ();
 }

 void welcome()
 {

 Boarder();
 gotoxy(, );
 ifstream ifs ("welcome.txt");
 string Lines = "";

 if (ifs)
 {
 while (ifs.good ())
 {
 string TempLine;
 getline (ifs , TempLine);
 TempLine += "\n";

 Lines += TempLine;
 }

 cout << Lines;


 }
 cout<<"\n\t |\t\t\t\t\t\t\t";
 ifs.close ();
 Sleep();

 }

 void exitArt()
 {
 Boarder();
 gotoxy(, );
 ifstream ifs ("exit art.txt");
 string Lines = " ";

 if (ifs)
 {
 while (ifs.good ())
 {
 string TempLine;
 getline (ifs , TempLine);
 TempLine += "\n";

 Lines += TempLine;
 }

 cout << Lines;

 }
 cout<<"\n\t |\t\t\t\t\t\t\t";
 ifs.close ();
 Sleep();
 exit();
 }

 int rate(int hour, int j)
 {
 int hour_, hour_, hour_;
 int total, total_, total_, total_;

 hour_=hour/;
 hour_=(hour - hour_*)/;
 hour_=(hour - hour_* - hour_*)/;

 total_ = hour_ * rent[j].rate_per_day;
 total_ = hour_ * rent[j].rate_per_half;
 total_ = hour_ * rent[j].rate_per_hour;

 total = total_ + total_ + total_;
 return total;
 }

 void customerData()
 {
 ifstream ifs;
 ifs.open("Customer.txt");
 int custNum = ;

 while (!ifs.eof())
 {
 ifs >> cust[custNum].id;
 ifs.ignore();
 ifs.getline(cust[custNum].name,,';');
 ifs.getline(cust[custNum].phone,,';');
 ifs.getline(cust[custNum].ic,,';');
 ifs.getline(cust[custNum].address,);
 custNum++;
 }

 ifs.close();
 }

 int carCount()
 {
 int numOfCar = ;
 ifstream ifs("car rental.txt");

 string word;
 while (getline(ifs, word))
 {
 if (!word.empty())
 numOfCar++;
 }

 ifs.close();

 return numOfCar;
 }

 int custCount()
 {
 int numOfCust = ;
 ifstream ifs("Customer.txt");

 string word;
 while (getline(ifs, word))
 {
 if (!word.empty())
 numOfCust++;
 }

 ifs.close();

 return numOfCust;
 }

 int countUser()
 {
 int numOfCust = ;
 ifstream ifs("UserPass.txt");

 string word;
 while (getline(ifs, word))
 {
 if (!word.empty())
 numOfCust++;
 }

 ifs.close();

 return numOfCust;
 }

 int countAvail()
 {
 int numOfCust = ;
 ifstream ifs("available.txt");

 string word;
 while (getline(ifs, word))
 {
 if (!word.empty())
 numOfCust++;
 }

 ifs.close();

 return numOfCust;
 }

 void displayCar()
 {
 cout << "\t | Plate Number\tBrand\t Model\tCapacity Colour Rate Per Hour
 cout << "\t | ==================================================================
 for (int i = ; i < carCount(); i++)
 {
 cout << "\t | " << rent[i].plate_num << "\t\t" << rent[i].brand << "\t
 << rent[i].colour << "\t " <<rent[i].rate_per_hour << "\t\t "
 << "\t\t " << rent[i].transmission << endl;
 }
 }

 void dispAvailCar()
 {
 cout << "\t | Plate Number\tBrand\t Model\tCapacity Colour Rate Per Hour
 cout << "\t | ==================================================================
 for (int i = ; i < countAvail(); i++)
 {
 cout << "\t | " << avail[i].plate_num << "\t\t" << avail[i].brand << "\
 << avail[i].colour << "\t " <<avail[i].rate_per_hour << "\t\t
 << "\t\t " << avail[i].transmission << endl;
 }
 }

 void existingCust()
 {


 int tempCust, hour, userID;
 char carSelect[];
 tempCust = custCount() - ;
 ofstream log;
 log.open("Log.txt", fstream::app);
 ofstream ofs;
 ofs.open("temp.txt");
 cout<<"\n\n\n\n";
 cout << endl;

 cout<<"\n\n";
 art();
 cout << endl;

 cout << "\n\t |\t\t\t\tPlease enter user ID : ";
 cin >> userID;

 for (int i =  ; i < custCount() ; i++)
 {
 if (userID == cust[i].id)
 {
 cout<<"\n\t |\t\t\t\t\tWELCOME ";
 cout << cust[i].name;
 log <<"\nNAME: "<< cust[i].name;
 cout<<"\t |\tID ";
 cout << cust[i].id;
 cout << "\n\n";
 log<<"\nPHONE: "<<cust[i].phone;
 log<<"\nIC: "<<cust[i].ic;
 }
 }


 dispAvailCar();

 cout<<"\n\n\t |\t\t\t\t\tPlease select car";
 cout<<"\n\t |\t\t\t\t\tPlate Number : ";
 cin >> ws;
 cin.getline(carSelect,);
 int x=countAvail();
 for(int i = ; i < countAvail(); i++)
 {
 if (strcmp(carSelect,avail[i].plate_num) != )
 {
 ofs << avail[i].plate_num;
 ofs << " ";
 ofs << avail[i].brand;
 ofs << " ";
 ofs << avail[i].model;
 ofs << " ";
 ofs << avail[i].capacity;
 ofs << " ";
 ofs << avail[i].colour;
 ofs << " ";
 ofs << avail[i].rate_per_hour;
 ofs << " ";
 ofs << avail[i].rate_per_half;
 ofs << " ";
 ofs << avail[i].rate_per_day;
 ofs << " ";
 ofs << avail[i].transmission;
 if(i != countAvail())
 {
 ofs<<endl;
 }


 }
 }

 ofs.close();

 remove("available.txt");
 rename("temp.txt","available.txt");
 cout << "\t |\t\t\t\t\tHours of rent : ";
 cin >> hour;
 int j;
 for(int i = ; i < carCount(); i++)
 {
 if (strcmp(carSelect,rent[i].plate_num) == )
 {
 j = i;

 log<<"\nCAR: "<<rent[i].plate_num;
 log<<"\nBRAND: "<<rent[i].brand;
 log<<"\nMODEL: "<<rent[i].model;
 log <<"\nHOUR: "<< hour;
 log <<"\nPAYMENT: "<< rate(hour,j);
 }
 }

 cout << "\t |\t\t\t\tPrice for " << hour << " hours of rent : RM ";
 cout << rate(hour,j);

 log <<"\nDATE: "<<currentDateTime();
 log<<"\n==========================================================";
 log.close();

 Sleep();
 system("cls");
 menu();
 }

 void newCustData ()
 {
 cout<<"\n\n";
 art();
 cout << endl;

 availCar();
 ofstream ofs,log;
 ofs.open("Customer.txt", fstream::app);
 log.open("Log.txt", fstream::app);
 ofs << endl;
 ofstream availTemp;
 availTemp.open("availtemp.txt");
 cout<<"\n\n\n\n";
 cout << endl;


 cust[custCount()].id = custCount() + ;
 ofs << cust[custCount()].id;
 ofs << ";";


 cout << "\n\n";
 cout << "\n\t |\t\t\t\t\t Please enter the data below : " << endl;

 cout << "\n\t |\t\t\t\t\t Name : ";
 cin >> ws;
 cin.getline(cust[custCount()].name,);
 ofs << cust[custCount()].name<<";";
 log <<"\nNAME: "<< cust[custCount()].name;

 cout << "\t |\t\t\t\t\t Phone Number : ";
 cin.getline(cust[custCount()].phone,);
 ofs << cust[custCount()].phone;
 ofs << ";";
 log <<"\nPHONE: "<< cust[custCount()].phone;


 cout << "\t |\t\t\t\t\t IC : ";
 cin.getline(cust[custCount()].ic,);
 ofs << cust[custCount()].ic;
 ofs << ";";
 log <<"\nIC: "<< cust[custCount()].ic;

 cout << "\t |\t\t\t\t\t Address : ";
 cin.getline(cust[custCount()].address,);
 ofs << cust[custCount()].address;

 ofs.close();


 system("cls");

 int tempCust, hour;
 char carSelect[];
 tempCust = custCount() - ;

 cout<<"\n\n\n\n";
 art();
 cout << endl;

 cout<<"\n\t |\t\t\tWELCOME ";
 cout << cust[tempCust].name;
 cout<<"\t |\tID ";
 cout << cust[tempCust].id;
 cout << "\n\n";

 dispAvailCar();

 cout<<"\n\n\t |\tPlease select car";
 cout<<"\n\t |\tPlate Number : ";
 cin >> ws;
 cin.getline(carSelect,);

 int x=countAvail();

 for(int i = ; i < countAvail(); i++)
 {
 if (strcmp(carSelect,avail[i].plate_num) != )
 {
 availTemp << avail[i].plate_num;
 availTemp << " ";
 availTemp << avail[i].brand;
 availTemp << " ";
 availTemp << avail[i].model;
 availTemp << " ";
 availTemp << avail[i].capacity;
 availTemp << " ";
 availTemp << avail[i].colour;
 availTemp << " ";
 availTemp << avail[i].rate_per_hour;
 availTemp << " ";
 availTemp << avail[i].rate_per_half;
 availTemp << " ";
 availTemp << avail[i].rate_per_day;
 availTemp << " ";
 availTemp << avail[i].transmission;
 if(i != countAvail())
 {
 availTemp<<endl;
 }


 }
 }

 ofs.close();

 remove("available.txt");
 rename("availtemp.txt","available.txt");

 cout << "\t |\tHours of rent : ";
 cin >> hour;
 int j;
 for(int i = ; i < carCount(); i++)
 {
 if (strcmp(carSelect,rent[i].plate_num) == )
 {
 j = i;
 rate(hour,j);
 log<<"\nCAR: "<<rent[i].plate_num;
 log<<"\nBRAND: "<<rent[i].brand;
 log<<"\nMODEL: "<<rent[i].model;
 log <<"\nHOUR: "<< hour;
 log <<"\nPAYMENT: "<< rate(hour,j);

 }
 }



 cout << "\n\t |\tPrice for " << hour << " hours of rent : RM ";
 cout << rate(hour,j);

 log <<"\nDATE: "<<currentDateTime();
 log<<"\n==========================================================";
 log.close();
 availTemp.close();
 availCar();

 Sleep();
 system("cls");
 menu();
 }

 void newCarData()
 {
 cout<<"\n\n";
 art();
 cout << endl;

 ofstream ofs;
 ofs.open("car rental.txt" , fstream::app);
 ofs<<endl;

 int newCar = carCount() + ;
 cout << "\n\n";
 cout << "\n\t |\t\t\t\t\t Please enter the car data below : " << endl;

 cout << "\n\t |\t\t\t\t\t Plate Number : ";
 cin >> ws;
 cin.getline(rent[newCar].plate_num,);
 ofs << rent[newCar].plate_num;
 ofs << " ";

 cout << "\t |\t\t\t\t\t Brand : ";
 cin.getline(rent[newCar].brand,);
 ofs << rent[newCar].brand;
 ofs << " ";

 cout << "\t |\t\t\t\t\t Model : ";
 cin.getline(rent[newCar].model,);
 ofs << rent[newCar].model;
 ofs << " ";

 cout << "\t |\t\t\t\t\t Capacity : ";
 cin >> rent[newCar].capacity;
 ofs << rent[newCar].capacity;
 ofs << " ";

 cout << "\t |\t\t\t\t\t Colour : ";
 cin >> ws;
 cin.getline(rent[newCar].colour,);
 ofs << rent[newCar].colour;
 ofs << " ";

 cout << "\t |\t\t\t\t\t Rate Per Hour : ";
 cin >> rent[newCar].rate_per_hour;
 ofs << rent[newCar].rate_per_hour;
 ofs << " ";

 cout << "\t |\t\t\t\t\t Rate Per  Hour : ";
 cin >> rent[newCar].rate_per_half;
 ofs << rent[newCar].rate_per_half;
 ofs << " ";

 cout << "\t |\t\t\t\t\t Rate Per  Hour : ";
 cin >> rent[newCar].rate_per_day;
 ofs << rent[newCar].rate_per_day;
 ofs << " ";

 cout << "\t |\t\t\t\t\t Tranmission (A/M) : ";
 cin >> ws;
 cin.getline(rent[newCar].transmission,);
 ofs << rent[newCar].transmission;

 ofs.close();
 system("cls");

 carData();
 admin();
 }

 void availCar ()
 {
 ifstream ifs;
 ifs.open("available.txt");
 int carNum = ;

 while(!ifs.eof())
 {
 ifs.getline(avail[carNum].plate_num,,' ');
 ifs.getline(avail[carNum].brand,,' ');
 ifs.getline(avail[carNum].model,,' ');
 ifs >> avail[carNum].capacity;
 ifs.ignore();
 ifs.getline(avail[carNum].colour,,' ');
 ifs >> avail[carNum].rate_per_hour;
 ifs.ignore();
 ifs >> avail[carNum].rate_per_half;
 ifs.ignore();
 ifs >> avail[carNum].rate_per_day;
 ifs.ignore();
 ifs.getline(avail[carNum].transmission,);
 carNum++;
 ifs>>ws;
 }

 ifs.close();
 }

 void resetAvail()
 {
 Boarder();
 ofstream ofs;
 ofs.open("temp.txt");

 for(int i = ; i < carCount(); i++)
 {
 ofs << rent[i].plate_num;
 ofs << " ";
 ofs << rent[i].brand;
 ofs << " ";
 ofs << rent[i].model;
 ofs << " ";
 ofs << rent[i].capacity;
 ofs << " ";
 ofs << rent[i].colour;
 ofs << " ";
 ofs << rent[i].rate_per_hour;
 ofs << " ";
 ofs << rent[i].rate_per_half;
 ofs << " ";
 ofs << rent[i].rate_per_day;
 ofs << " ";
 ofs << rent[i].transmission;
 if(i != carCount())
 {
 ofs<<endl;
 }


 }




 ofs.close();
 remove("available.txt");
 rename("temp.txt","available.txt");

 admin();

 }

 void newUserPass()
 {
 Boarder();
 ofstream ofs;
 ofs.open("UserPass.txt", fstream::app);

 userPass[countUser()].ID = countUser()+;


 string password;
 char c;
 gotoxy(,);
 cout << "\n\n\n\n\t |\t\t\tID(DEFAULT): "<<userPass[countUser()].ID;
 cout << "\n\t |\t\t\tADD PASSWORD: ";

 while(c != '\r') //Loop until 'Enter' is pressed
 {
 c = getch();
 if(c == )
 {
 switch(getch())
 {
 default:
 break;
 };
 }
 else if(c == '\b') //If the 'Backspace' key is pressed
 {
 if(password.size() != ) //If the password string contains data, erase last c
 {
 cout << "\b \b";
 password.erase(password.size() - , );
 }
 continue;
 }
 else if(c <= '' && c >= '' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') //
 {
 password += c;
 cout << "*";
 }
 else
 continue;
 }


 strcpy(userPass[countUser()].passWord,password.c_str());

 ofs<<userPass[countUser()].ID;
 ofs<<";";
 ofs<<userPass[countUser()].passWord;
 ofs<<endl;

 system("cls");
 admin();

 }

 void showCarData()
 {


 int x;
 cout<<"\n\n";
 art();
 cout << endl;

 cout << "\t | Plate Number\tBrand\t Model\tCapacity Colour Rate Per Hour
 cout << "\t | ==================================================================
 for (int i = ; i < carCount(); i++)
 {
 cout << "\t | " << rent[i].plate_num << "\t\t" << rent[i].brand << "\t "
 << rent[i].colour << "\t " <<rent[i].rate_per_hour << "\t\t "
 << "\t\t " << rent[i].transmission << endl;
 }
 cout << "\n\n";
 cout<<"\n\t |\t\t\t\t\t . BACK";
 cout<<"\n\t |\t\t\t\t\t . MAIN MENU"<<endl<<"\n\n";
 cout<<"\t |\t\t\t\t\tINPUT :";
 cin >> x;

 system("cls");

 if (x==)
 {
 admin();
 }

 if (x==)
 {
 menu();
 }

 }

 void carData ()
 {
 ifstream ifs;
 ifs.open("car rental.txt");
 int carNum = ;

 while(!ifs.eof())
 {
 ifs.getline(rent[carNum].plate_num,,' ');
 ifs.getline(rent[carNum].brand,,' ');
 ifs.getline(rent[carNum].model,,' ');
 ifs >> rent[carNum].capacity;
 ifs.ignore();
 ifs.getline(rent[carNum].colour,,' ');
 ifs >> rent[carNum].rate_per_hour;
 ifs.ignore();
 ifs >> rent[carNum].rate_per_half;
 ifs.ignore();
 ifs >> rent[carNum].rate_per_day;
 ifs.ignore();
 ifs.getline(rent[carNum].transmission,);
 carNum++;
 ifs>>ws;
 }

 ifs.close();
 }

 void admin()
 {
 int x;
 cout<<"\n\n\n\n";
 art();
 cout << endl;

 cout<<"\n\t |\t\t\t\t\t\t\t . ADD ADMIN";
 cout<<"\n\t |\t\t\t\t\t\t\t . SHOW DATA";
 cout<<"\n\t |\t\t\t\t\t\t\t . ADD CAR";
 cout<<"\n\t |\t\t\t\t\t\t\t . DELETE CAR";
 cout<<"\n\t |\t\t\t\t\t\t\t . RESET AVAILABLE CAR";
 cout<<"\n\t |\t\t\t\t\t\t\t . LOG OFF"<<endl<<"\n";
 cout<<"\t |\t\t\t\t\t\t\tINPUT :";
 cin>>x;


 system("cls");

 if (x==)
 {
 load_EXIT();
 menu();
 }

 else if (x==)
 {
 showCarData();
 }

 else if (x==)
 {
 newCarData();
 }

 else if (x==)
 {
 delCar();
 }
 else if (x==)
 {
 newUserPass();
 }
 else if(x==)
 system("cls");
 resetAvail();
 }

 void user()
 {

 int x;

 art();
 cout << endl;


 cout<<"\n\t |\t\t\t\t\t\t\t . NEW";
 cout<<"\n\t |\t\t\t\t\t\t\t . EXISTING";
 cout<<"\n\t |\t\t\t\t\t\t\t . MAIN MENU"<<endl;
 cout<<"\n\n\t |\t\t\t\t\t\t\tINPUT :";
 cin>>x;

 system("cls");
 if (x==)
 {
 newCustData();
 }

 else if (x==)
 {
 system("cls");
 load_UPDATE();
 existingCust();
 }

 else if (x==)
 {
 menu();
 }




 }

 void menu()
 {

 int x;
 art();

 cout << endl;
 cout<<"\n\t |\t\t\t\t\t\t\t . ADMIN";
 cout<<"\n\t |\t\t\t\t\t\t\t . USER";
 cout<<"\n\t |\t\t\t\t\t\t\t . T%C";
 cout<<"\n\t |\t\t\t\t\t\t\t . EXIT"<<endl<<"\n";
 cout<<"\n\t |\t\t\t\t\t\t\tINPUT :";
 cin>>x;


 system("cls");

 if (x==)
 {
 user();
 }

 else if (x==)
 {
 password();
 }

 if(x==)
 {

 tNc();
 getch();
 }

 if(x==)
 time();

 else if (x==)
 {
 cout << "\n\n\n\n";
 exitArt();
 Sleep();
 exit();
 }

 else if (x==)
 {
 fullscreen();
 menu();
 }





 }

 void delCar()
 {
 char plate[];

 ofstream ofs;
 ofs.open("temp.txt");

 cout<<"\n\n\n\n";
 art();
 cout << endl;
 displayCar();

 cout << "\n\n";
 cout << "\t | \t\tEnter the car plate number that are going to be deleted (CAPITA
 cout<< "\t | \t\t\t\t\t\t\t";
 cin >> ws;
 cin.getline(plate,);
 int x=carCount();
 for(int i = ; i < carCount(); i++)
 {
 if (strcmp(plate,rent[i].plate_num) != )
 {
 ofs << rent[i].plate_num;
 ofs << " ";
 ofs << rent[i].brand;
 ofs << " ";
 ofs << rent[i].model;
 ofs << " ";
 ofs << rent[i].capacity;
 ofs << " ";
 ofs << rent[i].colour;
 ofs << " ";
 ofs << rent[i].rate_per_hour;
 ofs << " ";
 ofs << rent[i].rate_per_half;
 ofs << " ";
 ofs << rent[i].rate_per_day;
 ofs << " ";
 ofs << rent[i].transmission;
 if(i != carCount())
 {
 ofs<<endl;
 }


 }
 }

 ofs.close();

 remove("car rental.txt");
 rename("temp.txt","car rental.txt");
 system("cls");
 carData();
admin();
 }
 void tNc()
 {
 art();
 cout<<endl;
 cout<<"\n\t |\t\t\t. MINIMUM RENT TIME IS  HOURS";
 cout<<"\n\t |\t\t\t. RISK BY YOUR OWN";
 cout<<"\n\t |\t\t\t. INCASE ACCIDENT, ALL COSTING IS PAID BY THE DRIVER";
 cout<<"\n\t |\t\t\t. PREPARE ITEM AS BELOW";
 cout<<"\n\t |\t\t\t \COPY OF IC, LICENSE";
 cout<<"\n\t |\t\t\t \DEPOSIT (BASED ON CAR TYPE)";
 cout<<"\n\t |\t\t\t. ADDITIONAL CHARGE IF LATE";
 cout<<"\n\t |\t\t\t. SAFE DRIVE!";
 cout<<"\n\n\n\n\t |\t\t\t PRESS ANY KEY TO CONTINUE :
 cout<<"\n\t |\t\t\t ";

 getch();
 menu();
 }
main()
 {

 fullscreen();
  Boarder();
 readUserPass();
 availCar();
 carData();
 menu();

}
