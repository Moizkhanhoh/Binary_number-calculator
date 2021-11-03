#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <cstdlib>              // Header Files
//#include <graphics.h>
#include <stdio.h>
#include<conio.h>               // for getch() function              
#include<windows.h>
#include<dos.h>
#include<cmath>
#include "project2.h"
void function();
using namespace std;
void gotoxy (int x, int y)
{
         COORD coordinates;     // coordinates is declared as COORD
         coordinates.X = x;     // defining x-axis
         coordinates.Y = y;     //defining  y-axis
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);      
}

void mouseinput()
{
HANDLE hout= GetStdHandle(STD_OUTPUT_HANDLE);
        HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
        INPUT_RECORD InputRecord;
        DWORD Events;
        COORD coord;
        CONSOLE_CURSOR_INFO cci;
        cci.dwSize = 25;
        cci.bVisible = FALSE;
        SetConsoleCursorInfo(hout, &cci);
        SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
        bool EXITGAME = false;
        int buttonX=0, buttonY=1;


       
    while( !EXITGAME )
    {
        ReadConsoleInput(hin, &InputRecord, 1, &Events);
        switch ( InputRecord.EventType ){
                case KEY_EVENT: // keyboard input
               
                case MOUSE_EVENT: // mouse input

                    if(InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
                    {
                        coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
                        coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
                        SetConsoleCursorPosition(hout,coord);
                        SetConsoleTextAttribute(hout,rand() %7+9);

                        if ( (InputRecord.Event.MouseEvent.dwMousePosition.X == buttonX ) &&
                            ( InputRecord.Event.MouseEvent.dwMousePosition.Y == buttonY) ){

                           
                 
                           
                        }

                        cout<<"Hello Iam here! "<< InputRecord.Event.MouseEvent.dwMousePosition.X <<" x "<< InputRecord.Event.MouseEvent.dwMousePosition.Y<<" ";
if(InputRecord.Event.MouseEvent.dwMousePosition.Y == 1 and  InputRecord.Event.MouseEvent.dwMousePosition.X==6 || InputRecord.Event.MouseEvent.dwMousePosition.Y == 19 and  InputRecord.Event.MouseEvent.dwMousePosition.X==5  || InputRecord.Event.MouseEvent.dwMousePosition.Y == 20 and  InputRecord.Event.MouseEvent.dwMousePosition.X==5)
{
//cout<<"MY HELP ==="<<           InputRecord.Event.MouseEvent.dwMousePosition.Y<<endl;
system("cls");
function();
}
                    }// mouse

                    break;
}
}
}


void function()
{
cout<<"  To Start Project Press Password or Press any key to exit:";
string q,ch;
ifstream fin ("password.txt");
getline (fin,q);
//cout<<q<<endl;
cin>>ch;
int n = 0;

BTD(n);
if(ch==q){

char op;
    int num1, num2,result;
//    cout << "Enter a binary number: ";
//    cin >> num1;
//
//    cout << num1 << " in binary = " <<BTD(num1) << "in decimal";
   
   
    cout << "Enter operator either + or - or * or / : ";
    cin >> op;
    cout << "Enter two operands: "<<endl;
    cout<<"Enter first Binary number: ";
    cin >> num1;
    cout<<"Enter Second Binary number: ";
    cin>> num2;
   
   
    switch(op)
    {
        case '+':
        result= BTD(num1)+BTD(num2);
            cout<<"Total  Sum is : " <<result;

            break;
           
        case '-':
        result=BTD(num1)-BTD(num2);
            cout<<"RESULT : " << result;
            break;
           
        case '*':
        result=BTD(num1)*BTD(num2);
            cout<<"MULTIPLICATION IS : " << result;
            break;
           
        case '/':
        result=BTD(num1)/BTD(num2);
            cout <<"RESULT OF DIVISION : "<< result;
            break;
           
        default:
       
            // if the operator is other than +, -, * or /, error message is shown;
            cout << "Error! operator is not correct";
            break;
    }


cout<<endl;


int rem[10],i;
// cout<<"Enter number to convert =";
//cin>>num;

for( i=0; result>0; i++){
rem[i]=result%2;
result=result/2;
// cout<<rem[i];

}

cout<<"Binary of the given number = ";  

for( i=i-1 ;i>=0 ;i--)    
{    
cout<<rem[i];    
}    
  }
 
else{
  cout<<"Your password is wrong"<<endl;
}

}


int main(){

system("cls");
// SetConsoleTextAttribute(hConsole, 8);             //Gray Color Code=8
            HANDLE hConsole;
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
gotoxy(3,0);
            cout<<'\xDA'<<'\xC4';
            for (int i=0; i<30; i++)
                cout<<'\xC4';
            cout<<'\xBF';
            gotoxy(3,1);
            cout<<'\xB3';
            gotoxy(3,2);
            cout<<'\xC0'<<'\xC4';
            for (int i=0; i<30; i++)
                cout<<'\xC4';
            cout<<'\xD9';
            SetConsoleTextAttribute(hConsole, 15);             //White Color Code=12
  gotoxy(6,1);
            cout<<"Note: ";
            SetConsoleTextAttribute(hConsole, 10);             //Green Color Code=10
            cout<<"Click here to Start    ";
            SetConsoleTextAttribute(hConsole, 8);             //Gray Color Code=8
            cout<<'\xB3';
            SetConsoleTextAttribute(hConsole, 15);             //White Color Code=15
            gotoxy(30,1);
           
            mouseinput();
            system("cls");
function();


return 0;
} 

