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
    book* b;
    void fileread ()
    {

    }
    void addb ()
    {

    }
    void delb ()
    {

    }
    void chab ()        // izmenit info o kn
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
