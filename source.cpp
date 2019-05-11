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
    int k;
    /*void fileread ()
    {

    }*/
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
    int chab (string bookname, string aut, string izd, int y)        // izmenit info o kn
    {
        int i, j, z, a;
        string l;
        a=0;
        for (i=0; i<k; i++)
        {
            if ((b[i].name == bookname)&&(b[i].autor==aut)&&(b[i].publishing==izd)&&(b[i].year==y))
            {
                a=1;
                chloop:
                cout<<"What you want to change?"<<endl;
                cout<<"1:year of publishing"<<endl;
                cout<<"2:format"<<endl;
                cout<<"3:number of copies"<<endl;
                cout<<"4:number of copies in the library"<<endl;
                cout<<"5:binding"<<endl;
                cout<<"6:series"<<endl;
                cout<<"7:exit"<<endl;
                cin>>z;
                switch (z)
                {
                case 1:
                    {
                    cout<<"year"<<endl;
                    cin>>j;
                    b[i].year = j;
                    goto chloop;
                    break;
                    }
                case 2:
                    {
                    cout<<"enter a number corresponding to the format"<<endl;
                    cout<<" for example: A4=4, A5=5"<<endl;
                    cin>>j;
                    b[i].format = j;
                    goto chloop;
                    break;
                    }
                case 3:
                    {
                    cout<<"number of copies"<<endl;
                    cin>>j;
                    b[i].noc = j;
                    goto chloop;
                    break;
                    }
                case 4:
                    {
                    cout<<"number of copies in the library"<<endl;
                    cin>>j;
                    b[i].n = j;
                    goto chloop;
                    break;
                    }
                case 5:
                    {
                    cout<<"binding"<<endl;
                    cout<<"1 - hard cover"<<endl;
                    cout<<"2 - soft cover"<<endl;
                    cin>>j;
                    if ((j == 1)||(j == 2))
                    {
                        b[i].binding = j;
                    }
                    else
                    {
                        cout<<"error: incorrect value"<<endl;
                    }
                    goto chloop;
                    break;
                    }
                case 6:
                    {
                    cout<<"enter series"<<endl;
                    cin>>l;
                    b[i].series = l;
                    goto chloop;
                    break;
                    }
                case 7:
                    {
                    cout<<"exit"<<endl;
                    cout<<b[i].autor<<endl;
                    cout<<b[i].name<<endl;
                    cout<<b[i].year<<endl;
                    cout<<b[i].binding<<endl;
                    cout<<b[i].format<<endl;
                    cout<<b[i].n<<endl;
                    cout<<b[i].noc<<endl;
                    cout<<b[i].series<<endl;
                    break;
                    }
                default:
                    {
                    cout<<"error"<<endl;
                    goto chloop;
                    }
                }
            }

        }
        return a;
    }
    void printlib ()
    {
        int i;
        for (i=0; i<k; i++)
        {
            cout<<endl;
            cout<<b[i].name<<endl;
            cout<<b[i].autor<<endl;
            cout<<b[i].series<<endl;
            cout<<b[i].publishing<<endl;
            cout<<"year of publishing: ";
            cout<<b[i].year<<endl;
            cout<<"number of pages: ";
            cout<<b[i].page<<endl;
            if (b[i].binding == 1)
            {
                cout<<"hard cover"<<endl;
            }
            else
            {
                cout<<"soft cover"<<endl;
            }
            cout<<"format: A";
            cout<<b[i].format<<endl;
            cout<<"number of copies: ";
            cout<<b[i].noc<<endl;
            cout<<"number of copies in library: ";
            cout<<b[i].n<<endl;
            cout<<endl;
        }
    }
    int searchb (string bookname)     // poisk kn
    {
        int i, a;
        a=0;
        for (i=0; i<k; i++)
        {
            if (b[i].name == bookname)
            {
                a=1;
            cout<<endl;
            cout<<b[i].name<<endl;
            cout<<b[i].autor<<endl;
            cout<<b[i].series<<endl;
            cout<<b[i].publishing<<endl;
            cout<<"year of publishing: ";
            cout<<b[i].year<<endl;
            cout<<"number of pages: ";
            cout<<b[i].page<<endl;
            if (b[i].binding == 1)
            {
                cout<<"hard cover"<<endl;
            }
            else
            {
                cout<<"soft cover"<<endl;
            }
            cout<<"format: A";
            cout<<b[i].format<<endl;
            cout<<"number of copies: ";
            cout<<b[i].noc<<endl;
            cout<<"number of copies in library: ";
            cout<<b[i].n<<endl;
            }
        }
        return a;
    }
    int searcha (string aut)     // poisk po autoru
    {
        int i, a;
        a=0;
        for (i=0; i<k; i++)
        {
            if (b[i].autor == aut)
            {
                a=1;
            cout<<endl;
            cout<<b[i].name<<endl;
            cout<<b[i].autor<<endl;
            cout<<b[i].series<<endl;
            cout<<b[i].publishing<<endl;
            cout<<"year of publishing: ";
            cout<<b[i].year<<endl;
            cout<<"number of pages: ";
            cout<<b[i].page<<endl;
            if (b[i].binding == 1)
            {
                cout<<"hard cover"<<endl;
            }
            else
            {
                cout<<"soft cover"<<endl;
            }
            cout<<"format: A";
            cout<<b[i].format<<endl;
            cout<<"number of copies: ";
            cout<<b[i].noc<<endl;
            cout<<"number of copies in library: ";
            cout<<b[i].n<<endl;
            }
        }
        return a;
    }
    int searchs (string ser)     // poisk po serii
    {
        int i, a;
        a=0;
        for (i=0; i<k; i++)
        {
            if (b[i].series == ser)
            {
                a=1;
            cout<<endl;
            cout<<b[i].name<<endl;
            cout<<b[i].autor<<endl;
            cout<<b[i].series<<endl;
            cout<<b[i].publishing<<endl;
            cout<<"year of publishing: ";
            cout<<b[i].year<<endl;
            cout<<"number of pages: ";
            cout<<b[i].page<<endl;
            if (b[i].binding == 1)
            {
                cout<<"hard cover"<<endl;
            }
            else
            {
                cout<<"soft cover"<<endl;
            }
            cout<<"format: A";
            cout<<b[i].format<<endl;
            cout<<"number of copies: ";
            cout<<b[i].noc<<endl;
            cout<<"number of copies in library: ";
            cout<<b[i].n<<endl;
            }
        }
        return a;
    }
    int searchi (string izd)     // poisk po izdatelu
    {
        int i, a;
        a=0;
        for (i=0; i<k; i++)
        {
            if (b[i].publishing == izd)
            {
                a=1;
            cout<<endl;
            cout<<b[i].name<<endl;
            cout<<b[i].autor<<endl;
            cout<<b[i].series<<endl;
            cout<<b[i].publishing<<endl;
            cout<<"year of publishing: ";
            cout<<b[i].year<<endl;
            cout<<"number of pages: ";
            cout<<b[i].page<<endl;
            if (b[i].binding == 1)
            {
                cout<<"hard cover"<<endl;
            }
            else
            {
                cout<<"soft cover"<<endl;
            }
            cout<<"format: A";
            cout<<b[i].format<<endl;
            cout<<"number of copies: ";
            cout<<b[i].noc<<endl;
            cout<<"number of copies in library: ";
            cout<<b[i].n<<endl;
            }
        }
        return a;
    }

};

class comedy : public baselib
{
public:
    int j;
    comedy()
    {
        k=0;
    }
    void addb()                 //vvod informacii nachinaetsa v osnovnoy programme!!!
    {
        cout<<"book title: ";
        cin>>b[k].name;
        cout<<"author: ";
        cin>>b[k].autor;
        cout<<"publishing: ";
        cin>>b[k].publishing;
        cout<<"series: ";
        cin>>b[k].series;
        cout<<"year: ";
        cin>>b[k].year;
        cout<<"page: ";
        cin>>b[k].page;
        cout<<"binding: "<<endl;
        errstc:
        cout<<"1 - hard cover"<<endl;
        cout<<"2 - soft cover"<<endl;
        cin>>j;
        if ((j == 1)||(j == 2))
        {
            b[k].binding = j;
        }
        else
        {
            cout<<"error: incorrect value"<<endl;
            goto errstc;
        }
        cout<<"format (4=A4, 5=A5...): A";
        cin>>b[k].format;
        cout<<"number of copies: ";
        cin>>b[k].noc;
        cout<<"number of copies in library: ";
        cin>>b[k].n;
        k++;
    }
};
class tragedy : public baselib
{
public:
    int j;
    tragedy()
    {
        k=0;
    }
    void addb()                 //vvod informacii nachinaetsa v osnovnoy programme!!!
    {
        cout<<"book title: ";
        cin>>b[k].name;
        cout<<"author: ";
        cin>>b[k].autor;
        cout<<"publishing: ";
        cin>>b[k].publishing;
        cout<<"series: ";
        cin>>b[k].series;
        cout<<"year: ";
        cin>>b[k].year;
        cout<<"page: ";
        cin>>b[k].page;
        cout<<"binding: "<<endl;
        errstt:
        cout<<"1 - hard cover"<<endl;
        cout<<"2 - soft cover"<<endl;
        cin>>j;
        if ((j == 1)||(j == 2))
        {
            b[k].binding = j;
        }
        else
        {
            cout<<"error: incorrect value"<<endl;
            goto errstt;
        }
        cout<<"format (4=A4, 5=A5...): A";
        cin>>b[k].format;
        cout<<"number of copies: ";
        cin>>b[k].noc;
        cout<<"number of copies in library: ";
        cin>>b[k].n;
        k++;
    }
};
class drama : public baselib
{
public:
    int j;
    drama()
    {
        k=0;
    }
    void addb()                 //vvod informacii nachinaetsa v osnovnoy programme!!!
    {
        cout<<"book title: ";
        cin>>b[k].name;
        cout<<"author: ";
        cin>>b[k].autor;
        cout<<"publishing: ";
        cin>>b[k].publishing;
        cout<<"series: ";
        cin>>b[k].series;
        cout<<"year: ";
        cin>>b[k].year;
        cout<<"page: ";
        cin>>b[k].page;
        cout<<"binding:"<<endl;
        errstd:
        cout<<"1 - hard cover"<<endl;
        cout<<"2 - soft cover"<<endl;
        cin>>j;
        if ((j == 1)||(j == 2))
        {
            b[k].binding = j;
        }
        else
        {
            cout<<"error: incorrect value"<<endl;
            goto errstd;
        }
        cout<<"format (4=A4, 5=A5...): A";
        cin>>b[k].format;
        cout<<"number of copies: ";
        cin>>b[k].noc;
        cout<<"number of copies in library: ";
        cin>>b[k].n;
        k++;
    }
};
class lyrical : public baselib
{
public:
    int j;
    lyrical()
    {
        k=0;
    }
    void addb()                 //vvod informacii nachinaetsa v osnovnoy programme!!!
    {
        cout<<"book title: ";
        cin>>b[k].name;
        cout<<"author: ";
        cin>>b[k].autor;
        cout<<"publishing: ";
        cin>>b[k].publishing;
        cout<<"series: ";
        cin>>b[k].series;
        cout<<"year: ";
        cin>>b[k].year;
        cout<<"page: ";
        cin>>b[k].page;
        cout<<"binding:"<<endl;
        errstl:
        cout<<"1 - hard cover"<<endl;
        cout<<"2 - soft cover"<<endl;
        cin>>j;
        if ((j == 1)||(j == 2))
        {
            b[k].binding = j;
        }
        else
        {
            cout<<"error: incorrect value"<<endl;
            goto errstl;
        }
        cout<<"format (4=A4, 5=A5...): A";
        cin>>b[k].format;
        cout<<"number of copies: ";
        cin>>b[k].noc;
        cout<<"number of copies in library: ";
        cin>>b[k].n;
        k++;
    }
};



class mainlib
{
    private:
        comedy* cb;
        tragedy* tb;
        drama* db;
        lyrical* lb;
        int genre;
    public:
        mainlib()
        {
            cb = new comedy;
            tb = new tragedy;
            db = new drama;
            lb = new lyrical;
        }

        void printlib()
        {
            cout<<"comedy:"<<endl;
            cb->printlib();
            cout<<"tragedy:"<<endl;
            tb->printlib();
            cout<<"drama:"<<endl;
            db->printlib();
            cout<<"lyrical:"<<endl;
            lb->printlib();
        }

        void addb()
        {
            cout<<"enter information about the book:"<<endl;
            cout<<"genre: "<<endl;
            errstgc:
            cout<<"1 - comedy   3 - drama"<<endl;
            cout<<"2 - tragedy  4 - lyrical"<<endl;
            cin>>genre;
            switch (genre)
            {
            case 1:
                {
                cb->addb();
                break;
                }
            case 2:
                {
                tb->addb();
                break;
                }
            case 3:
                {
                db->addb();
                break;
                }
            case 4:
                {
                lb->addb();
                break;
                }
            default:
                {
                cout<<"error"<<endl;
                goto errstgc;
                }
            }
        }

        void delb ()
        {
            int y, g;
            string bookname, aut, izd;
            cout<<"enter information about the book you want to delete:"<<endl;
            cout<<"genre:"<<endl;
            cout<<"1 - comedy   3 - drama"<<endl;
            cout<<"2 - tragedy  4 - lyrical"<<endl;
            cin>>g;
            cout<<"book title: ";
            cin>>bookname;
            cout<<"author: ";
            cin>>aut;
            cout<<"publishing: ";
            cin>>izd;
            cout<<"year of publishing: ";
            cin>>y;
            if (g == 1)
                cb->delb(bookname, aut, izd, y);
            if (g == 2)
                tb->delb(bookname, aut, izd, y);
            if (g == 3)
                db->delb(bookname, aut, izd, y);
            if (g == 4)
                lb->delb(bookname, aut, izd, y);
        }
        void chab()
        {
            int y, g, a;
            string bookname, aut, izd;
            cout<<"enter information about the book you want to change:"<<endl;
            cout<<"genre:"<<endl;
            cout<<"1 - comedy   3 - drama"<<endl;
            cout<<"2 - tragedy  4 - lyrical"<<endl;
            cin>>g;
            cout<<"book title: ";
            cin>>bookname;
            cout<<"author: ";
            cin>>aut;
            cout<<"publishing: ";
            cin>>izd;
            cout<<"year of publishing: ";
            cin>>y;
            if (g == 1)
                a = cb->chab(bookname, aut, izd, y);
            if (g == 2)
                a = tb->chab(bookname, aut, izd, y);
            if (g == 3)
                a = db->chab(bookname, aut, izd, y);
            if (g == 4)
                a = lb->chab(bookname, aut, izd, y);
            if (a == 0)
                cout<<"error: there is no such book"<<endl;
        }

        void searchlib()
        {
            int i, a;
            string sl;
            cout<<"search by:"<<endl;
            cout<<"1 - book title   3 - author"<<endl;
            cout<<"2 - publishing   4 - series"<<endl;
            cin>>i;
            switch (i)
            {
            case 1:
                {
                cout<<"enter book title: ";
                cin>>sl;
                cout<<"comedy:"<<endl;
                a = cb->searchb(sl);
                if (a == 0)
                    cout<<"no such book"<<endl;
                cout<<"tragedy:"<<endl;
                a = tb->searchb(sl);
                if (a == 0)
                    cout<<"no such book"<<endl;
                cout<<"drama:"<<endl;
                a = db->searchb(sl);
                if (a == 0)
                    cout<<"no such book"<<endl;
                cout<<"lyrical:"<<endl;
                a = lb->searchb(sl);
                if (a == 0)
                    cout<<"no such book"<<endl;
                    break;
                }
            case 2:
                {
                cout<<"enter the publisher: ";
                cin>>sl;
                cout<<"comedy:"<<endl;
                a = cb->searchi(sl);
                if (a == 0)
                    cout<<"no such book"<<endl;
                cout<<"tragedy:"<<endl;
                a = tb->searchi(sl);
                if (a == 0)
                    cout<<"no such book"<<endl;
                cout<<"drama:"<<endl;
                a = db->searchi(sl);
                if (a == 0)
                    cout<<"no such book"<<endl;
                cout<<"lyrical:"<<endl;
                a = lb->searchi(sl);
                if (a == 0)
                    cout<<"no such book"<<endl;
                break;
                }
            case 3:
                {
                cout<<"enter book author: ";
                cin>>sl;
                cout<<"comedy:"<<endl;
                a = cb->searcha(sl);
                if (a == 0)
                    cout<<"no such book"<<endl;
                cout<<"tragedy:"<<endl;
                a = tb->searcha(sl);
                if (a == 0)
                    cout<<"no such book"<<endl;
                cout<<"drama:"<<endl;
                a = db->searcha(sl);
                if (a == 0)
                    cout<<"no such book"<<endl;
                cout<<"lyrical:"<<endl;
                a = lb->searcha(sl);
                if (a == 0)
                    cout<<"no such book"<<endl;
                break;
                }
            case 4:
                {
                cout<<"enter the series in which the book consists: ";
                cin>>sl;
                cout<<"comedy:"<<endl;
                a = cb->searchs(sl);
                if (a == 0)
                    cout<<"no such book"<<endl;
                cout<<"tragedy:"<<endl;
                a = tb->searchs(sl);
                if (a == 0)
                    cout<<"no such book"<<endl;
                cout<<"drama:"<<endl;
                a = db->searchs(sl);
                if (a == 0)
                    cout<<"no such book"<<endl;
                cout<<"lyrical:"<<endl;
                a = lb->searchs(sl);
                if (a == 0)
                    cout<<"no such book"<<endl;
                break;
                }
            default:
                {
                cout<<"error"<<endl;
                }
            }
        }
/*
        void save()
        {
            ofstream fin;
            fin.open("save.sav",std::ios::out);
            fin<<rm->getamt()<<"\t"<<vm->getamt()<<endl;
            for (int i = 0; i < rm->getamt();++i)
            {
                mark temp = rm->getmark(i);
                fin<<temp.country<<"\t"<<temp.emittype<<"\t"<<temp.material<<"\t"<<temp.name<<"\t"<<temp.prestory<<"\t"<<temp.purpose<<"\t"<<temp.shape<<endl;
            }
            for (int i = 0; i < vm->getamt();++i)
            {
                mark temp = vm->getmark(i);
                fin<<temp.country<<"\t"<<temp.emittype<<"\t"<<temp.material<<"\t"<<temp.name<<"\t"<<temp.prestory<<"\t"<<temp.purpose<<"\t"<<temp.shape<<endl;
            }
            fin.close();
        }
        void load()
        {
            vm->deleteall();
            rm->deleteall();
            int amt1, amt2;
            string t;
            mark temp;
            ifstream fout;
            try
            {
                fout.open("save.sav",std::ios::out);
                getline(fout,t,'\t');
                amt1 = stoi(t);
                getline(fout,t);
                amt2 = stoi(t);
                for (int i = 0; i < amt1; i++)
                {
                    getline(fout,t,'\t'); temp.country = t;
                    getline(fout,t,'\t'); temp.emittype = t[0];
                    getline(fout,t,'\t'); temp.material = t[0];
                    getline(fout,t,'\t'); temp.name = t;
                    getline(fout,t,'\t'); temp.prestory = t;
                    getline(fout,t,'\t'); temp.purpose = t[0];
                    getline(fout,t); temp.shape = t[0];
                    rm->getfromfile(temp);
                }
                for (int i = 0; i < amt2; i++)
                {
                    getline(fout,t,'\t'); temp.country = t;
                    getline(fout,t,'\t'); temp.emittype = t[0];
                    getline(fout,t,'\t'); temp.material = t[0];
                    getline(fout,t,'\t'); temp.name = t;
                    getline(fout,t,'\t'); temp.prestory = t;
                    getline(fout,t,'\t'); temp.purpose = t[0];
                    getline(fout,t); temp.shape = t[0];
                    vm->getfromfile(temp);
                }
                fout.close();
            }
            catch(int error)
            {
                cout<<"Error! File is corrupt or non-existent!"<<endl;
            }
        } */
};


int main()
{
    int i;
    mainlib* libr = new mainlib;
    mainmenu:
    cout<<"1 - add book     5 - print library"<<endl;
    cout<<"2 - delete book  6 - search"<<endl;
    cout<<"3 - change book  7 - quit"<<endl;
    cout<<"4 - add from file"<<endl;
    cin>>i;
    switch(i)
    {
    case 1:
        {
            libr->addb();
            goto mainmenu;
            break;
        }
    case 2:
        {
            libr->delb();
            goto mainmenu;
            break;
        }
    case 3:
        {
            libr->chab();
            goto mainmenu;
            break;
        }
    case 4:
        {
            //??????????????????????????????????????????????????????????????????????
            goto mainmenu;
            break;
        }
    case 5:
        {
            libr->printlib();
            goto mainmenu;
            break;
        }
    case 6:
        {
            libr->searchlib();
            goto mainmenu;
            break;
        }
    case 7:
        {
            goto exitmenu;
            break;
        }
    default:
        {
            cout<<"error"<<endl;
            goto mainmenu;
        }
    }
    exitmenu:
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!dobavit sohranenie!!!!!!!!!!!!!!!!!!!!!!!!!!
    cout<<"end"<<endl;
    cin>>i;
    return 0;
}
