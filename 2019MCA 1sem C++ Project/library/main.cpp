#include <windows.h>
#include <stdio.h>
#include <string>
#include <mysql.h>
#include <iostream>
#include <sstream>
#include <conio.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
using namespace std;

void intro()
{

	cout<<"\n\t\t\t*********************************************************************************";
    cout<<"\n\t\t           *  Institute Name *";
        cout<<"\n\t\t\t*************************************************************************************";
    cout<<"\n\t\tMade By: \t           Suraj Rama Yadav  ";
    cout<<"\n\t\tmobail no: \t           8433564425 ";
    cout<<"\t";
	cout<<"\n\n\n\t            TOPIC: LIBRARY MANAGEMENT SYSTEM";
	cout<<"\n\n\n\n\n\n\t\t\t\tPress any key to continue.........";

}
void insertStudent()
{

        stringstream ss;
        int state = 0;

    string name;
    string dept;
    string divison;
    string rollno;
    string bookis="0";

    cout << "\n\t\t            ENTER STUDENT NAME: " ;
    cin >> name;
    cout << "\n\t\t            ENTER STUDENT DEPARTMENT: " ;
    cin >> dept;
    cout << "\n\t\t            ENTER STUDENT DIVISION: " ;
    cin >> divison;
    cout << "\n\t\t            ENTER STUDENT ROLL NUMBER: ";
       cin >> rollno;


        MYSQL *conn;
        MYSQL_ROW row;
        MYSQL_RES *res;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);
        ss << "INSERT INTO student(name,department,division,rollno,bookissue) VALUES('" << name << "','" << dept << "','" << divison << "','" << rollno << "','" << bookis << "')";

        string query1 = ss.str();

        const char *q1 = query1.c_str();
        state = mysql_query(conn, q1);

        if (state == 0)
        {
            cout << "\n\t   INSERTED STUDENT \n\n\n"<< endl;
        }
        else
        {
            cout << "\n\t   CAN NOT INSERT \n\n\n" << endl
                 << mysql_error(conn) << endl;
        }

    }

void fetchStudent()
{
      string temp;
    stringstream ss1;
    string id;

    cout<<"\n\t            SEARCH STUDENT DEATILS\n\n"<<endl;
    cout << "ENTER STUDENT ID :   ";
    cin >> id;

    MYSQL *conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);

    ss1 << "select id from student where id='" << id << "'";
    string query = ss1.str();
    const char *q = query.c_str();
    int state = mysql_query(conn, q);
    if (!state)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            temp = row[0];
        }
    }
    if (id == temp)
    {
    stringstream ss;
    cout<<endl;

    MYSQL *conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);

    ss << "select * from student where id='" << id << "'";
    string query = ss.str();
    const char *q = query.c_str();
    int state = mysql_query(conn, q);

    if (!state)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            cout << "\n\n\t         ID    :   " << row[0] << " " << endl
                 << "\n\n\t         NAME  :   " << row[1] << " " << endl
                 << "\n\n\t         DEPARTMENT  :   " << row[2] << " " << endl
                 << "\n\n\t         DIVISION  :   " << row[3] << " " << endl
                 << "\n\n\t         ROLL NUMBER :   " << row[4] << " " << endl
                 << "\n\n\t         NO OF ISSUE BOOK :   " << row[5] << " " << endl;

        }
    }
      else{
        cout<<"\n\t   USER IS NOT FOUND";
    }

}
 else
    {
        cout << "\n\t   ID DOES NOT EXIST"<<endl;
    }
}


void updateStudent()
{

    string temp;
    stringstream ss;
    string id;

    cout<<"\n\t            UPDATE STUDENT DEATILS\n\n"<<endl;
    cout << "\n\n\t        ENTER STUDENT ID :   ";
    cin >> id;

    MYSQL *conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);

    ss << "select id from student where id='" << id << "'";
    string query = ss.str();
    const char *q = query.c_str();
    int state = mysql_query(conn, q);
    if (!state)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            temp = row[0];
        }
    }
    if (id == temp)
    {
        int state = 0;
        stringstream ss;
          string name;
    string dept;
    string divison;
    string rollno;
    string bookis="0";

   cout << "\n\t\t            ENTER STUDENT NAME: " ;
    cin >> name;
    cout << "\n\t\t            ENTER STUDENT DEPARTMENT: " ;
    cin >> dept;
    cout << "\n\t\t            ENTER STUDENT DIVISION: " ;
    cin >> divison;
    cout << "\n\t\t            ENTER STUDENT ROLL NUMBER: ";
       cin >> rollno;


        MYSQL *conn;
        MYSQL_ROW row;
        MYSQL_RES *res;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);

        ss << "update student set name='" << name << "',department='" << dept << "',division='" << divison << "',rollno='" << rollno << "',bookissue='" << bookis << "' where id='" << id << "'";
        string query = ss.str();
        const char *q = query.c_str();
        state = mysql_query(conn, q);

        cout<<endl<<state;

        if (state == 0)
        {
            cout << "\n\t    UPDATE STUDENT DATA OF ID  :   "<< id;
            /*if (!state)
            {
                res = mysql_store_result(conn);
                while (row = mysql_fetch_row(res))
                {
                    cout << "Student id/Roll No.:" << row[0]<< endl
                         << "ITM:" << row[1] << " " << endl
                         << "COA:" << row[2] << " " << endl
                         << "OOPS:" << row[3] << " " << endl
                         << "SEPM:" << row[4] << " " << endl
                         << "MATHS:" << row[5] << endl;
                }
            }
            else
            {
                cout << mysql_error(conn);
            }
            */
        }
        else
        {
            cout << "\n\t    CAN NOT UPDATE, SOME DATABASE PROBLEM"<<endl;
        }
    }
    else
    {
        cout << "\n\t   ID DOES NOT EXIST"<<endl;
    }
}

void deleteStudent()
{
    //cout << "inside delete";
    string temp;
    stringstream ss;
    string id;
    cout<<"\n\t            DELETE STUDENT INFORMATION\n\n"<<endl;
    cout << "\n\n\t        ENTER STUDENT ID  :   ";
    cin >> id;

    MYSQL *conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);

    ss << "select id from student where id='" << id << "'";
    string query = ss.str();
    const char *q = query.c_str();
    int state = mysql_query(conn, q);
    if (!state)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            temp = row[0];
        }
    }
    if (id == temp)
    {
        //cout << "id: " << id << endl;
        //cout << "temp: " << temp << endl;
        //cout << "id matched" << endl;
        stringstream ss1;
        int state = 0;
        MYSQL *conn;
        MYSQL_ROW row;
        MYSQL_RES *res;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);
        ss1 << "delete from student where id='" << id << "'";
        //cout << "id: " << id << endl;
        string query1 = ss1.str();
        //cout << "q1 :   " << query1 << endl;
        const char *q1 = query1.c_str();
        state = mysql_query(conn, q1);
        //cout << "state: " << state;
        if (state == 0)
        {
            cout << "\n\t    DELETED STUDENT ID  :  "<<id<< endl;
        }
        else
        {
            cout << mysql_error(conn) << endl;
        }
    }
    else
    {
        cout << "\n\t    STUDENT NOT EVEN EXIST\n\n"<<endl;
    }
}



void insertbook(){
      stringstream ss;
        int state = 0;

        string isbn;
    string bname;
    string bauther;
    string pub;
    string bedition;
    cout<<"\n\n\t               REGISTER STUDENT";
    cout << " \n\n\t       ENTER BOOK ISBN NUMBER: " ;
    cin >> isbn;
    cout << "\n\n\t        ENTER BOOK NAME: " ;
    cin >> bname;
    cout << "\n\n\t        ENTER BOOK AUTHER NAME: " ;
    cin >> bauther;
     cout << "\n\n\t       ENTER BOOK PUBLICATION: " ;
    cin >> pub;
    cout << "\n\n\t        ENTER BOOK EDITION: " ;
    cin >> bedition;


        MYSQL *conn;
        MYSQL_ROW row;
        MYSQL_RES *res;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);
        ss << "INSERT INTO book(isbn,bname,bauther,publication,bedition) VALUES('" << isbn << "','" << bname << "','" << bauther << "','" << pub << "','" << bedition << "')";

        string query1 = ss.str();

        const char *q1 = query1.c_str();
        state = mysql_query(conn, q1);

        if (state == 0)
        {
            cout << "\n\t     INSERTED STUDENT \n\n\n"<< endl;
        }
        else
        {
            cout << " \n\t    CAN NOT INSERT \n\n\n" << endl
                 << mysql_error(conn) << endl;
        }

    }

void fetchbook()
{
    string temp;
    stringstream ss1;
    string id;

    cout<<"\n\t            BOOK DEATILS\n\n"<<endl;
    cout << "\n\t    ENTER BOOK ISBN NO  :   ";
    cin >> id;

    MYSQL *conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);

    ss1 << "select isbn from book where isbn='" << id << "'";
    string query = ss1.str();
    const char *q = query.c_str();
    int state = mysql_query(conn, q);
    if (!state)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            temp = row[0];
        }
    }
    if (id == temp)
    {

    stringstream ss;

    cout<<endl;

    MYSQL *conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);

    ss << "select * from book where isbn='" << id << "'";
    string query = ss.str();
    const char *q = query.c_str();
    int state = mysql_query(conn,q);

    if (!state)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {

                 cout<< "\n\n\t    ISBN NUMBER  :   " << row[0] << " " << endl
                 << "\n\n\t        NAME OF BOOK :   " << row[1] << " " << endl
                 << "\n\n\t        AUTHER OF BOOK  :   " << row[2] << " " << endl
                 << "\n\n\t        BOOK PUBLICATION :   " << row[3] << " " << endl
                 << "\n\n\t        BOOK EDITION :   " << row[4] << "th" << endl;


        }
    }
    else{
        cout<<"\n\n\t      ISBN NO NOT FOUND";
    }
}
 else
    {
        cout << "\n\n\t     ISBN NO NOT FOUND"<<endl;
    }
}

void updatebook()
{
     string temp;
    stringstream ss1;
    string id;

    cout<<"\n\t            UPDATE BOOK DEATILS\n\n"<<endl;
    cout << "\n\t      ENTER BOOK ISBN NO  :   ";
    cin >> id;

    MYSQL *conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);

    ss1 << "select isbn from book where isbn='" << id << "'";
    string query = ss1.str();
    const char *q = query.c_str();
    int state = mysql_query(conn, q);
    if (!state)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            temp = row[0];
        }
    }
    if (id == temp)
    {
        int state = 0;
        stringstream ss;
            string sid;
            string pub;
    string bname;
    string bauther;
    string bedition;
     cout << " \n\n\t       ENTER BOOK ISBN NUMBER: " ;
    cin >> sid;
    cout << "\n\n\t        ENTER BOOK NAME: " ;
    cin >> bname;
    cout << "\n\n\t        ENTER BOOK AUTHER NAME: " ;
    cin >> bauther;
     cout << "\n\n\t       ENTER BOOK PUBLICATION: " ;
    cin >> pub;
    cout << "\n\n\t        ENTER BOOK EDITION: " ;
    cin >> bedition;

        MYSQL *conn;
        MYSQL_ROW row;
        MYSQL_RES *res;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);

        ss << "update book set isbn='" << sid << "',bname='" << bname << "',bauther='" << bauther << "',publication='" << pub << "',bedition='" << bedition << "' where isbn='" << id << "'";
        string query = ss.str();
        const char *q = query.c_str();
        state = mysql_query(conn, q);

        cout<<endl<<state;

        if (state == 0)
        {
            cout << "\n\n\t    STUDENT DATA UPDATED";
            /*if (!state)
            {
                res = mysql_store_result(conn);
                while (row = mysql_fetch_row(res))
                {
                    cout << "Student id/Roll No.:" << row[0]<< endl
                         << "ITM:" << row[1] << " " << endl
                         << "COA:" << row[2] << " " << endl
                         << "OOPS:" << row[3] << " " << endl
                         << "SEPM:" << row[4] << " " << endl
                         << "MATHS:" << row[5] << endl;
                }
            }
            else
            {
                cout << mysql_error(conn);
            }
            */
        }
        else
        {
            cout << "\n\n\t    CAN NOT UPDATE, SOME DATABASE PROBLEM"<<endl;
        }
    }
    else
    {
        cout << "\n\n\t     ISBN NO NOT FOUN"<<endl;
    }
}

void deletebook()

{

  string temp;
    stringstream ss1;
    string id;

    cout<<"\n\t            DELETE BOOK \n\n"<<endl;
    cout << "ENTER BOOK ISBN NO  :   ";
    cin >> id;

    MYSQL *conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);

    ss1 << "select isbn from book where isbn='" << id << "'";
    string query = ss1.str();
    const char *q = query.c_str();
    int state = mysql_query(conn, q);
    if (!state)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            temp = row[0];
        }
    }
    if (id == temp)
    {

        stringstream ss1;
        int state = 0;
        MYSQL *conn;
        MYSQL_ROW row;
        MYSQL_RES *res;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);
        ss1 << "delete from book where isbn='" << id << "'";
        //cout << "id: " << id << endl;
        string query1 = ss1.str();
        //cout << "q1 :   " << query1 << endl;
        const char *q1 = query1.c_str();
        state = mysql_query(conn, q1);
        //cout << "state: " << state;
        if (state == 0)
        {
            cout << "DELETED ISBN NO   :   "<<id<< endl;
        }
        else
        {
            cout << mysql_error(conn) << endl;
        }
    }
    else
    {
        cout << "ISBN NO NOT FOUN"<<endl;
    }
}
void booking()
{
      string id;
     cout << " \n\n\t     ENTER STUDENT ID : " ;
    cin >> id;
       string temp;
          string b="1";
    stringstream ss1;


    MYSQL *conn1;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn1 = mysql_init(0);
    conn1 = mysql_real_connect(conn1, "localhost", "root", "", "lib", 0, NULL, 0);

    ss1<< "select bookissue from student where id='" << id << "'";
    string query = ss1.str();
    const char *q = query.c_str();
    int state = mysql_query(conn1, q);
    if (!state)
    {
        res = mysql_store_result(conn1);
        while (row = mysql_fetch_row(res))
        {
            temp = row[0];
        }
    }
       if(temp==b)
    {


        cout<<"\n\n\t     ONLY 1 BOOK ISSUED";
        getch();
    }
    else{

     stringstream ss;
        int state = 0;


    string isbn;

    cout << " \n\n\t     ENTER BOOK ISBN NO: " ;
    cin >> isbn;
  const int MAXLEN = 80;
    char s[MAXLEN];
    time_t t = time(0);
    strftime(s, MAXLEN, "%Y/%m/%d", localtime(&t));

     MYSQL *conn;

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);
        ss << "INSERT INTO booking(id,isbn,bkdate) VALUES('" << id << "','" << isbn << "','" << s << "')";

        string query1 = ss.str();

        const char *q1 = query1.c_str();
        state = mysql_query(conn, q1);

        if (state == 0)
        {


        stringstream ss2;

        string bookis="1";

        MYSQL *conn2;

        conn2 = mysql_init(0);
        conn2 = mysql_real_connect(conn2, "localhost", "root", "", "lib", 0, NULL, 0);

        ss2 << "update student set bookissue='" << bookis << "' where id='" << id << "'";
        string query = ss2.str();
        const char *q = query.c_str();
        state = mysql_query(conn2, q);



        cout << "\n\n\t    BOOK IS ISSUED SUCCESSFULLY "<< endl;
        cout<<"\n\t   PLEASE NOTE :- Write The Current Date On Your Library Card ";
        cout<<"\n\t   And Submit Within 15 days FINE RS 1/per After 15 days peroid";
        getch();
        }
        else
        {

            cout << " \n\n\t    STUDENT ID OR BOOK ISBN NO NOT FOUND \n\n\n" << endl;
            getch();

        }
    }


    }


void returnbook()
{
    string temp1;
    stringstream ss4;
    string id;

    cout<<"\n\t            RETURN A BOOK \n\n"<<endl;
    cout << "\n\n\t        ENTER STUDENT ID  :   ";
    cin >> id;

    MYSQL *conn4;
    MYSQL_ROW row2;
    MYSQL_RES *res2;
    conn4 = mysql_init(0);
    conn4 = mysql_real_connect(conn4, "localhost", "root", "", "lib", 0, NULL, 0);

    ss4 << "select id from student where id='" << id << "'";
    string query = ss4.str();
    const char *q = query.c_str();
    int state2 = mysql_query(conn4, q);
    if (!state2)
    {
        res2 = mysql_store_result(conn4);
        while (row2 = mysql_fetch_row(res2))
        {
            temp1 = row2[0];
        }
    }

     stringstream ss5;
    ss5 << "select * from booking where id='" << id << "'";
    string query5 = ss5.str();
    const char *q5 = query5.c_str();
    int state5 = mysql_query(conn4,q5);

    if (!state5)
    {
        res2 = mysql_store_result(conn4);
        while (row2 = mysql_fetch_row(res2))
        {
            cout << "\n\t    BOOKING ID    :   " << row2[0] << " " << endl
                 << "\n\t    STUDENT ID :   " << row2[1] << " " << endl
                 << "\n\t    ISBN NUMBER :   " << row2[2] << " " << endl
                 << "\n\t    BOOK ISSUED DATE  :   " << row2[3] << " " << endl;
        }


    }

    if (id == temp1)
    {


       string game;
          string b="0";
    stringstream ss1;

    MYSQL *conn1;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn1 = mysql_init(0);
    conn1 = mysql_real_connect(conn1, "localhost", "root", "", "lib", 0, NULL, 0);

    ss1<< "select bookissue from student where id='" << id << "'";
    string query = ss1.str();
    const char *q = query.c_str();
    int state = mysql_query(conn1, q);
    if (!state)
    {
        res = mysql_store_result(conn1);
        while (row = mysql_fetch_row(res))
        {
            game = row[0];
        }
    }
       if(game==b)
    {
        cout<<"\n\n\t      BOOK IS NOT ISSUED BY STUDENT";
        getch();
    }
    else{
    string temp10;
    stringstream ss3;
    string rn;
    MYSQL *conn;
    MYSQL_ROW row3;
    MYSQL_RES *res3;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);
    ss3 << "SELECT DATEDIFF(CURDATE(),`bkdate`) as d from booking where `id`=5";
    string query3 = ss3.str();
    const char *q3 = query3.c_str();
    int state3 = mysql_query(conn, q3);
    if (!state3)
    {
        res3 = mysql_store_result(conn);

        while (row3 = mysql_fetch_row(res3))
        {
           temp10=row3[0];
        }

    }

    stringstream geek(temp10);

    // The object has the value 12345 and stream
    // it to the integer x
    int temp4 = 0;
    geek >> temp4;








     stringstream ss;
        int state=0;

        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);
       ss << "delete from booking where id='" << id << "'";

        string query1 = ss.str();

        const char *q1 = query1.c_str();
        state = mysql_query(conn, q1);

        if (state == 0)
        {


        stringstream ss2;

        string bookis="0";

        MYSQL *conn2;

        conn2 = mysql_init(0);
        conn2 = mysql_real_connect(conn2, "localhost", "root", "", "lib", 0, NULL, 0);

        ss2 << "update student set bookissue='" << bookis << "' where id='" << id << "'";
        string query = ss2.str();
        const char *q = query.c_str();
        state = mysql_query(conn2, q);


        cout << "\n\t     No OF Days    :   " << temp4 << " " << endl;
        if(temp4 < 16)
        {
        cout << "\n\n\t      BOOK IS RETURN SUCCESSFULLY \n\n\n"<< endl;
        getch();
        }
        else{
            int p=temp4 - 15;
            cout<<"\n\n\t    LATE SUBMISSION OF BOOK FINE IS:"<<p<<" Rs";
            cout << "\n\n\t      BOOK IS RETURN SUCCESSFULLY \n\n\n"<< endl;
            getch();
        }




        }
        else
        {
            cout << " \n\n\t     STUDENT ID NOT FOUND \n\n\n" << endl;
            getch();

        }

    }


    }


 else
    {

        cout << "\n\n\t      STUDENT ID NOT FOUND"<<endl;
        getch();
    }
}

void showbooking()
{


    string temp;
    stringstream ss1;
    string id;

    cout<<"\n\t            SEARCH ISSUED BOOK DEATILS\n\n"<<endl;
    cout << "ENTER STUDENT ID  :   ";
    cin >> id;

    MYSQL *conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);

    ss1 << "select id from student where id='" << id << "'";
    string query = ss1.str();
    const char *q = query.c_str();
    int state = mysql_query(conn, q);
    if (!state)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            temp = row[0];
        }
    }


    if (id == temp)
    {
        string temp5;
    stringstream ss5;

    MYSQL *conn5;
    MYSQL_ROW row5;
    MYSQL_RES *res5;
    conn5 = mysql_init(0);
    conn5 = mysql_real_connect(conn5, "localhost", "root", "", "lib", 0, NULL, 0);

    ss5 << "select bookissue from student where id='" << id << "'";
    string query5 = ss5.str();
    const char *q5 = query5.c_str();
    int state5 = mysql_query(conn5, q5);
    if (!state5)
    {
        res5 = mysql_store_result(conn5);
        while (row5 = mysql_fetch_row(res5))
        {
            temp5 = row5[0];
        }
    }


    if(temp5=="1")
    {





    stringstream ss;

    cout<<endl;

    MYSQL *conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);

    ss << "select * from booking where id='" << id << "'";
    string query = ss.str();
    const char *q = query.c_str();
    int state = mysql_query(conn,q);

    if (!state)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            cout << "\n\t    BOOKING ID    :   " << row[0] << " " << endl
                 << "\n\t    STUDENT ID :   " << row[1] << " " << endl
                 << "\n\t    ISBN NUMBER :   " << row[2] << " " << endl
                 << "\n\t    BOOKING DATE AND TIME  :   " << row[3] << " " << endl;


        }
    }

    else{

        cout<<"\n\n\t   STUDENT ID NOT FOUND";

    }
    }
    else{

        cout<<"\n\n\n\t    BOOK IS NOT ISSUED BY THIS STUDENT";

    }
    }
 else
    {

        cout << "\n\n\t   STUDENT ID NOT FOUND"<<endl;
    }
}

void allbooks()
{
     stringstream ss1;

    cout<<endl;

    MYSQL *conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);

    ss1 << "select * from book";
    string query = ss1.str();
    const char *q = query.c_str();
    int state = mysql_query(conn,q);


    if (!state)
    {
        res = mysql_store_result(conn);
        //int result=mysql_num_fields(res);
        while (row = mysql_fetch_row(res))
        {

               cout  << "\n\n\t    ISBN NUMBER  :   " << row[0] << " " << endl
                 << "\n\n\t        NAME OF BOOK :   " << row[1] << " " << endl
                 << "\n\n\t        AUTHER OF BOOK  :   " << row[2] << " " << endl
                 << "\n\n\t        BOOK PUBLICATION :   " << row[3] << " " << endl
                 << "\n\n\t        BOOK EDITION :   " << row[4] << "th" << endl
                 <<"---------------------------------------"<<endl;

        }
    }
    else{
            getch();
        cout<<"\n\t     NO ENTRY IN DATABASE";
    }
}
    void allbooking()
    {
     stringstream ss1;

    cout<<endl;

    MYSQL *conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);

    ss1 << "select * from booking";
    string query = ss1.str();
    const char *q = query.c_str();
    int state = mysql_query(conn,q);


    if (!state)
    {
        res = mysql_store_result(conn);
        //int result=mysql_num_fields(res);
        while (row = mysql_fetch_row(res))
        {
            cout << "\n\n\t   BOOKIN ID    :   " << row[0] << " " << endl
                 << "\n\n\t   STUDENT ID:   " << row[1] << " " << endl
                 << "\n\n\t   ISBN NUMBER :   " << row[2] << " " << endl
                 << "\n\n\t   DATE AND TIME OF ISSUE :   " << row[3] << " " << endl
                 <<"---------------------------------------"<<endl;

        }
    }
    else{
            getch();
        cout<<"\n\n\t NO ENTRY IN DATABASE";
    }
    }
    void allstudent()
    {
        stringstream ss;
     MYSQL *conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);

    ss << "select * from student";
    string query = ss.str();
    const char *q = query.c_str();
    int state = mysql_query(conn, q);

    if (!state)
    {
        res = mysql_store_result(conn);
        while (row = mysql_fetch_row(res))
        {
            cout << "\n\n\t    ID    :   " << row[0] << " " << endl
                 << "\n\n\t    NAME  :   " << row[1] << " " << endl
                 << "\n\n\t    DEPARTMENT  :   " << row[2] << " " << endl
                 << "\n\n\t    DIVISION  :   " << row[3] << " " << endl
                 << "\n\n\t    ROLL NUMBER :   " << row[4] << " " << endl
                 << "\n\n\t    NO OF ISSUE BOOK :   " << row[5] << " " << endl
                 <<"-------------------------------------------"<<endl;

        }
    }
      else{
            getch();
        cout<<"\n\n\t     NO ENTRY IN DATABASE";
    }

}

 void report()
 {
     system("CLS");
    cout << " \n\n\t     Report  " << endl;

    stringstream ss;


    MYSQL *conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    conn = mysql_init(0);

    conn = mysql_real_connect(conn, "localhost", "root", "", "lib", 0, NULL, 0);
    ss << "SELECT COUNT(*) as total FROM student";
    string query = ss.str();
    const char *q = query.c_str();

    int state = mysql_query(conn,q);

    if (!state)
    {
        res = mysql_store_result(conn);


        while (row = mysql_fetch_row(res))
        {
            cout << " \n\n\t     Total Student : " << row[0];
        }

    }
    stringstream ss2;
        MYSQL_ROW row2;
    MYSQL_RES *res2;
      ss2 << "SELECT COUNT(*) as total1 FROM book";
    string query2 = ss2.str();
    const char *q2 = query2.c_str();
    int state2 = mysql_query(conn,q2);
    if (!state2)
    {
        res2 = mysql_store_result(conn);

        while (row2 = mysql_fetch_row(res2))
        {
            cout << " \n\n\t     Total Books : " << row2[0];
        }

    }
    stringstream ss3;
    MYSQL_ROW row3;
    MYSQL_RES *res3;
      ss3 << "SELECT COUNT(*) as total2 FROM booking";
    string query3 = ss3.str();
    const char *q3 = query3.c_str();
    int state3 = mysql_query(conn,q3);
    if (!state3)
    {
        res3 = mysql_store_result(conn);

        while (row3 = mysql_fetch_row(res3))
        {
            cout << " \n\n\t     Total Book Issue : " << row3[0];
        }

    }
 }

class lib{

public:void  login()
{
    intro();
    getch();

START:
    system("CLS");
    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tADMIN LOGIN";
    string un;
    char pass[32];
    int i = 0;
    char a;
    cout << "\n\n\n\t\t\t\t\tENTER USERNAME   :   ";
    cin >> un;
    cout << "\n\n\t\t\t\t\tENTER PASSWORD   :   ";
    for (i = 0;;)
    {
        a = getch();
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
        {
            pass[i] = a;
            ++i;
            cout << "*";
        }
        if (a == '\b' && i >= 1)
        {
            cout << "\b \b";
            --i;
        }
        if (a == '\r')
        {
            pass[i] = '\0';
            break;
        }
    }
    if (i <= 4)
    {
        cout << "\n\n\n\t\t\t\t\tnminimum 4 digit needed";
        goto START;
    }
    std::string s(pass);

    if (un == "admin" && s == "12345")
    {
        system("CLS");
        user();
    }
    else
    {
        cout << "\n\n\n\t\t\t\t\tINCORRECT USERNAME OR PASSWORD";
        cout << "\n\n\n\t\t\t\t\tPress Any Key To Login Again........";
        getch();
        system("CLS");
        goto START;
    }
}
public: void user(){

system("CLS");
    int ch;

    cout<<"\n\n\n\tMAIN MENU";
    cout<<"\n\n\t1.ISSUE A BOOK";
    cout<<"\n\n\t2.RETURN A BOOK";
    cout<<"\n\n\t3.DISPLAY ALL BOOK";
    cout<<"\n\n\t4.DISPLAY SPECIFIC ISSUE BOOK";
     cout<<"\n\n\t5.DISPLAY SPECIFIC STUDENT RECORD ";
    cout<<"\n\n\t6.ADMINISTRATOR MENU";
    cout<<"\n\n\t7.EXIT MENU";

    cout<<"\n\n\tPlease Enter Your Choice (1-4) ";
    cin>>ch;
    switch(ch)
    {

    case 1:system("CLS");
        booking();
        user();
        break;
        case 2:system("CLS");
    returnbook();
    user();
        break;
        case 3:system("CLS");

            allbooks();
            getch();
            user();
        break;
          case 4:system("CLS");

            showbooking();
            getch();
            user();
        break;
             case 5:system("CLS");
            fetchStudent();
            getch();
            user();

        break;
        case 6:
            system("CLS");
            menu();
        case 7:
            exit(0);
            default:cout<<"\nInvalid Choice\nTRY AGAIN\n";
    }



}


public: void menu()
{
     int ch2;
    cout<<"\n\n\n\tADMINISTRATOR MENU";
    cout<<"\n\n\t1.CREATE STUDENT RECORD";
    cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORD";
    cout<<"\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD ";
    cout<<"\n\n\t4.MODIFY STUDENT RECORD";
    cout<<"\n\n\t5.DELETE STUDENT RECORD";
    cout<<"\n\n\t6.CREATE BOOK ";
    cout<<"\n\n\t7.DISPLAY ALL BOOKS ";
    cout<<"\n\n\t8.DISPLAY SPECIFIC BOOK ";
    cout<<"\n\n\t9.MODIFY BOOK ";
    cout<<"\n\n\t10.DELETE BOOK ";
    cout<<"\n\n\t11.DISPLAY ALL ISSUE BOOK ";
    cout<<"\n\n\t12.REPORT ";
    cout<<"\n\n\t13.BACK TO MAIN MENU";
    cout<<"\n\n\tPlease Enter Your Choice (1-11) ";
    cin>>ch2;
    switch(ch2)
    {
    case 1:system("CLS");
        insertStudent();
        getch();
        menu();
        break;
        case 2:system("CLS");

            allstudent();
             getch();
            menu();

        break;
        case 3:system("CLS");
            fetchStudent();
            getch();
            menu();

        break;
        case 4: system("CLS");
            updateStudent();
            getch();

            menu();
        break;
        case 5:system("CLS");
            deleteStudent();

            getch();
            menu();
        break;
        case 6:system("CLS");
            insertbook();
            getch();
            menu();
        break;
        case 7:system("CLS");
            allbooks();
            getch();
            menu();
        break;
        case 8:system("CLS");
             fetchbook();
             getch();

            menu();
        break;
        case 9: system("CLS");
            updatebook();
            getch();

            menu();
        break;
        case 10:system("CLS");
            deletebook();
            getch();

            menu();
        break;
        case 11:system("CLS");
            allbooking();
            getch();

            menu();
        break;
         case 12:system("CLS");

            report();
            getch();

            menu();
        break;
        case 13:system("CLS");
            user();

        break;

        default:cout<<"\nInvalid Choice\nTRY AGAIN\n";




    }

    }




};

int main()
{


    lib obj;
obj.login();


    //allstudent();
    //allbooking();
//booking();
//showbooking();
//allbooks();
//returnbook();
   /* intro();

    insertStudent();
    fetchStudent();
    updateStudent();
    deleteStudent();
    insertbook();
    fetchbook();
    updatebook();
    deletebook();
*/



    return 0;
}
