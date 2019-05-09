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
        int i, j;
        string l;
        for (i=0; i<k; i++)
        {
            if ((b[i].name == bookname)&&(b[i].autor==aut)&&(b[i].publishing==izd)&&(b[i].year==y))
            {
                chloop:
                cout<<"What you want to change?"<<endl;
                cout<<"1:year of publishing"<<endl;
                cout<<"2:format"<<endl;
                cout<<"3:number of copies"<<endl;
                cout<<"4:number of copies in the library"<<endl;
                cout<<"5:binding"<<endl;
                cout<<"6:series"<<endl;
                cout<<"7:exit"<<endl;
                cin>>i;
                switch (i)
                {
                case 1:
                    cout<<"year"<<endl;
                    cin>>j;
                    b[i].year = j;
                    goto chloop;
                case 2:
                    cout<<"enter a number corresponding to the format"<<endl;
                    cout<<" for example: A4=4, A5=5"<<endl;
                    cin>>j;
                    b[i].format = j;
                    goto chloop;
                case 3:
                    cout<<"number of copies"<<endl;
                    cin>>j;
                    b[i].noc = j;
                    goto chloop;
                case 4:
                    cout<<"number of copies in the library"<<endl;
                    cin>>j;
                    b[i].n = j;
                    goto chloop;
                case 5:
                    cout<<"binding"<<endl;
                    cout<<"1 - hard cover"<<endl;
                    cout<<"2 - soft cover"<<endl;
                    cin>>j;
                    b[i].binding = j;
                    goto chloop;
                case 6:
                    cout<<"enter series separate by comma"<<endl;
                    cin>>l;
                    b[i].series = l;
                    goto chloop;
                case 7:
                    cout<<"exit"<<endl;
                    cout<<b[i].autor<<endl;
                    cout<<b[i].name<<endl;
                    cout<<b[i].year<<endl;
                    cout<<b[i].binding<<endl;
                    cout<<b[i].format<<endl;
                    cout<<b[i].n<<endl;
                    cout<<b[i].noc<<endl;
                    cout<<b[i].series<<endl;
                default:
                    cout<<"error"<<endl;
                    goto chloop;
                }
            }

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
