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
    void fileread(book tb)
    {
        b[k]=tb;
        k++;
    }
    book getb(int i)
    {
        return b[i];
    }
    int getk()
    {
        return k;
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
                cout<<endl<<"What you want to change?"<<endl;
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
                    cout<<b[i].series<<endl<<endl;
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
            cout<<"title:               "<<b[i].name<<endl;
            cout<<"author:              "<<b[i].autor<<endl;
            cout<<"series:              "<<b[i].series<<endl;
            cout<<"publishing:          "<<b[i].publishing<<endl;
            cout<<"year of publishing:  ";
            cout<<b[i].year<<endl;
            cout<<"number of pages:     ";
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
            cout<<"author:  "<<b[i].autor<<endl;
            cout<<"series:  "<<b[i].series<<endl;
            cout<<"publish: "<<b[i].publishing<<endl;
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
            cout<<"title:   "<<b[i].name<<endl;
            cout<<"author:  "<<b[i].autor<<endl;
            cout<<"series:  "<<b[i].series<<endl;
            cout<<"publish: "<<b[i].publishing<<endl;
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
            cout<<"title:   "<<b[i].name<<endl;
            cout<<"author:  "<<b[i].autor<<endl;
            cout<<"series:  "<<b[i].series<<endl;
            cout<<"publish: "<<b[i].publishing<<endl;
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
            cout<<"title:   "<<b[i].name<<endl;
            cout<<"author:  "<<b[i].autor<<endl;
            cout<<"series:  "<<b[i].series<<endl;
            cout<<"publish: "<<b[i].publishing<<endl;
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
        cout<<endl;
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
        cout<<endl;
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
        cout<<endl;
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
        cout<<endl;
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
        cout<<endl;
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
        cout<<endl;
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
        cout<<endl;
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
        cout<<endl;
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
            cout<<"-----------------------------------"<<endl;
            cout<<"tragedy:"<<endl;
            tb->printlib();
            cout<<"-----------------------------------"<<endl;
            cout<<"drama:"<<endl;
            db->printlib();
            cout<<"-----------------------------------"<<endl;
            cout<<"lyrical:"<<endl;
            lb->printlib();
            cout<<endl;
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

        int sti(string s)
        {
            int x, i, a;
            x = s.length();
            a=0;
            for(i = 0; i < x; i++)
            {
                a =10*a+(s[i]-'0');
            }
            return a;
        }
        void fileread()
        {
            int i, j, gn;
            string tmp, buf;
            string  ty, tp, tbind, tf, tnoc, tn;
            int iy, ip, ib, iform, inoc, inum;
            book tbook;
            ifstream f("datalibrary.txt");
            if (!f.is_open())
                cout << "error: no such file"<<endl;
            else
            {
                gn =0;
                while (f)
                {
                    f >> buf;
                    if (buf == "===")
                    {
                        goto endfl;
                    }
                    if ((buf == "comedy")||(buf == "tragedy")||(buf == "drama")||(buf == "lyrical"))
                    {
                        if (buf == "comedy")
                            gn =1;
                        if (buf == "tragedy")
                            gn =2;
                        if (buf == "drama")
                            gn =3;
                        if (buf == "lyrical")
                            gn =4;
                    }
                    else
                    {
                        tbook.name = buf;
                        f >> buf; tbook.autor = buf;
                        f >> buf; tbook.publishing = buf;
                        f >> buf; tbook.series = buf;
                        f >> buf; ty = buf;
                        f >> buf; tp = buf;
                        f >> buf; tbind = buf;
                        f >> buf; tf = buf;
                        f >> buf; tnoc = buf;
                        f >> buf; tn = buf;
                        tbook.year = sti(ty);
                        tbook.page = sti(tp);
                        tbook.binding = sti(tbind);
                        tbook.format = sti(tf);
                        tbook.noc = sti(tnoc);
                        tbook.n = sti(tn);
                        if (gn == 1)
                        {
                            cb->fileread(tbook);
                        }
                        if (gn == 2)
                        {
                            tb->fileread(tbook);
                        }
                        if (gn == 3)
                        {
                            db->fileread(tbook);
                        }
                        if (gn == 4)
                        {
                            lb->fileread(tbook);
                        }
                    }
                }
                endfl:
                f.close();
            }
        }
        void filesave()
        {
            int n, i;
            ofstream fout("datalibrary.txt");
            n=cb->getk();
            fout<<"comedy"<<endl;
            for (i=0; i<n; i++)
            {
                book tmp = cb->getb(i);
                fout<<tmp.name<<' '<<tmp.autor<<' '<<tmp.publishing<<' '<<tmp.series<<' '<<tmp.year<<' '<<tmp.page<<' '<<tmp.binding<<' '<<tmp.format<<' '<<tmp.noc<<' '<<tmp.n<<endl;
            }
            n=tb->getk();
            fout<<"tragedy"<<endl;
            for (i=0; i<n; i++)
            {
                book tmp = tb->getb(i);
                fout<<tmp.name<<' '<<tmp.autor<<' '<<tmp.publishing<<' '<<tmp.series<<' '<<tmp.year<<' '<<tmp.page<<' '<<tmp.binding<<' '<<tmp.format<<' '<<tmp.noc<<' '<<tmp.n<<endl;
            }
            n=db->getk();
            fout<<"drama"<<endl;
            for (i=0; i<n; i++)
            {
                book tmp = db->getb(i);
                fout<<tmp.name<<' '<<tmp.autor<<' '<<tmp.publishing<<' '<<tmp.series<<' '<<tmp.year<<' '<<tmp.page<<' '<<tmp.binding<<' '<<tmp.format<<' '<<tmp.noc<<' '<<tmp.n<<endl;
            }
            n=lb->getk();
            fout<<"lyrical"<<endl;
            for (i=0; i<n; i++)
            {
                book tmp = lb->getb(i);
                fout<<tmp.name<<' '<<tmp.autor<<' '<<tmp.publishing<<' '<<tmp.series<<' '<<tmp.year<<' '<<tmp.page<<' '<<tmp.binding<<' '<<tmp.format<<' '<<tmp.noc<<' '<<tmp.n<<endl;
            }
            fout<<"==="<<endl;
            fout.close();
        }
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
            libr->fileread();
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
    libr->filesave();
    cout<<"end"<<endl;
    return 0;
}
