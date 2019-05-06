#include <iostream>
#include <fstream>
using namespace std;

struct book
{
    string name;        //  nazvanie kn
    string autor;       //  autor
    string publishing;  //  izdatel
    string series;      //  seriya
    int year;           //  god sozdaniya
    int page;           //  stranici
    int binding;        //  pereplet    (1-tverdiy 2-myagkiy)
    int format;         //  format kn  (4=A4 5=A5 ...)
    int noc;            //  tirag
    int n;              //  kol-vo
};

class baselib           //  abstr fabr
{
public:
    book *b = new book [30];
    int k=0;
    void fileread ()
    {

    }
    virtual void addb () = 0;   //zavisit ot janra
    void delb (string bookname, string aut, string izd, int y)
    {
        int i=0;
        int j=0;
        for (i=0; i<k; i++)
        {
            if ((b[i].name == bookname)&&(b[i].autor==aut)&&(b[i].publishing==izd)&&(b[i].year==y))
            {
                for (j=i; j<k-1; j++)
                {
                    b[j]=b[j+1];
                }
                k--;
            }
        }
    }
    void chab (string bookname, string aut, string izd, int y)        // izmenit info o kn
    {
        int i;
        cout<<"What you want to change?"<<endl;
        cout<<"1:year of publishing"<<endl;
        cout<<"2:format"<<endl;
        cout<<"3:number of copies"<<endl;
        cout<<"4:number of copies in the library"<<endl;
        cout<<"5:binding"<<endl;
        cout<<"6:series"<<endl;
        cin>>i;
        switch (i)
        {
        case 1:

        case 2:

        case 3:

        case 4:

        case 5:

        case 6:

        default:

        }
    }
    void printlib ()
    {

    }
    void searchb ()     // poisk kn
    {

    }
    void searcha ()     // poisk po autoru
    {

    }
    void searchs ()     // poisk po serii
    {

    }
    void searchi ()     // poisk po izdatelu
    {

    }

};
