#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

//Base class
class consumable{
private:
    static int total_consumption_time,total_consumption_days;
    static float total_rating;
    int consump_time,consump_days;
    string name,start_date,end_date;
public:
    float rating;
public:
    consumable(){}//Default constructor
    consumable(string n)//Parameterized constructor
    {
        name=n;
        consump_time=0;
        consump_days=0;
        rating=0.0;
    }
    string getName(){return name;}
    void setRat(float rat)
    {
        total_rating-=rating;
        rating=rat;
        total_rating+=rating;
    }
    void delRat(float rat)
    {
        total_rating-=rat;
    }
    float getRat(){return rating;}
    void setConsump(int time,int days)
    {
        consump_time=time;
        total_consumption_time+=time;
        consump_days=days;
        total_consumption_days+=days;
    }
    float getTotalRat(){return total_rating;}
    int getTotalConsumpTime(){return total_consumption_time;}
    int getTotalConsumpDays(){return total_consumption_days;}
    int getConsumpTime(){return consump_time;}
    int getConsumpDays(){return consump_days;}
    void setStart(string str){start_date=str;}
    string getStart(){return start_date;}
    void setEnd(string str){end_date=str;}
    string getEnd(){return end_date;}
};

//Derived class
class Book:public consumable{
private:
    static int book_consumption_time,book_consumption_days;
    static float total_book_rating;
public:
    Book(){}//Default constructor
    Book(string n):consumable(n){}//Parameterized constructor
    void addConsumption(int time,int days)
    {
        setConsump(time,days);//call on base class
        book_consumption_time+=time;
        book_consumption_days+=days;
    }
    int getConsumptionTime(){return book_consumption_time;}
    int getConsumptionDays(){return book_consumption_days;}
    void setRating(float rat)
    {
        total_book_rating-=rating;
        setRat(rat);//call on base class
        total_book_rating+=rating;
    }
    void delRating(float rat)
    {
        total_book_rating-=rat;
        delRat(rat);//call on base class
    }
    float getRating(){return total_book_rating;}
};

//DErived class
class Series:public consumable{
private:
    static int series_consumption_time,series_consumption_days;
    static float total_series_rating;
public:
    Series(){}//Default constructor
    Series(string n):consumable(n){}//Parameterized constructor
    void addConsumption(int time,int days)
    {
        setConsump(time,days);//call on base class
        series_consumption_time+=time;
        series_consumption_days+=days;
    }
    int getConsumptionTime(){return series_consumption_time;}
    int getConsumptionDays(){return series_consumption_days;}
    void setRating(float rat)
    {
        total_series_rating-=rating;
        setRat(rat);//call on base class
        total_series_rating+=rating;
    }
    void delRating(float rat)
    {
        total_series_rating-=rat;
        delRat(rat);//call on base class
    }
    float getRating(){return total_series_rating;}
};

//Derived class
class Movie:public consumable{
private:
    static int movie_consumption_time,movie_consumption_days;
    static float total_movie_rating;
public:
    Movie(){}//Default constructor
    Movie(string n):consumable(n){}//Parameterized constructor
    void addConsumption(int time,int days)
    {
        setConsump(time,days);//call on base class
        movie_consumption_time+=time;
        movie_consumption_days+=days;
    }
    int getConsumptionTime(){return movie_consumption_time;}
    int getConsumptionDays(){return movie_consumption_days;}
    void setRating(float rat)
    {
        total_movie_rating-=rating;
        setRat(rat);//call on base class
        total_movie_rating+=rating;
    }
    void delRating(float rat)
    {
        total_movie_rating-=rat;
        delRat(rat);//call on base class
    }
    float getRating(){return total_movie_rating;}
};

//Initialization of static variables
int Book::book_consumption_days=0,Book::book_consumption_time=0;
int Series::series_consumption_days=0,Series::series_consumption_time=0;
int Movie::movie_consumption_days=0,Movie::movie_consumption_time=0;
int consumable::total_consumption_days=0,consumable::total_consumption_time=0;
float consumable::total_rating=0.0,Book::total_book_rating=0.0;
float Series::total_series_rating=0.0,Movie::total_movie_rating=0.0;

int main()
{
   int res,type,time,days;
   string name,start,endd,a[4]={"","book","series","movie"},temp;
   float rat;
   vector<Book> B;
   vector<Series> S;
   vector<Movie> M;
   while(1)
   {
       cout<<"Enter 1 to add a consumable"<<endl<<"Enter 2 to edit a consumable"<<endl;
       cout<<"Enter 3 to delete a consumable"<<endl<<"Enter 4 to see the list of consumables"<<endl;
       cout<<"Enter 5 to see overall info"<<endl<<"Enter -1 to exit"<<endl;
       cin>>res;
       if(res==-1)
        break;
       else if(res==1)
       {
           cout<<"Enter 1 for book, 2 for series or 3 for movie:"<<endl;
           cin>>type;
           cout<<"Enter name of the "<<a[type]<<":"<<endl;
           cin.ignore();
           getline(cin,name);
           cout<<"Enter starting date in the format YYYY-MM-DD(Enter 0 to skip):"<<endl;
           cin.ignore();
           getline(cin,start);
           cout<<"Enter ending date in the format YYYY-MM-DD(Enter 0 to skip):"<<endl;
           cin.ignore();
           getline(cin,endd);
           cout<<"Enter rating of this "<<a[type]<<"(Enter -1 to skip):"<<endl;
           cin>>rat;
           if(type==1)
           {
               Book obj(name);
               if(start!="0")
                obj.setStart(start);
               if(endd!="0")
                obj.setEnd(endd);
               if(rat!=-1)
                obj.setRating(rat);
               B.push_back(obj);
           }
           else if(type==2)
            {
               Series obj(name);
               if(start!="0")
                obj.setStart(start);
               if(endd!="0")
                obj.setEnd(endd);
               if(rat!=-1)
                obj.setRating(rat);
               S.push_back(obj);
           }
           else
           {
               Movie obj(name);
               if(start!="0")
                obj.setStart(start);
               if(endd!="0")
                obj.setEnd(endd);
               if(rat!=-1)
                obj.setRating(rat);
               M.push_back(obj);
           }
           cout<<endl<<"Successfully added a consumable!!!"<<endl<<endl;
       }
       else if(res==2)
       {
           cout<<"Enter 1 for book, 2 for series or 3 for movie:"<<endl;
           cin>>type;
           cout<<"Enter name of the "<<a[type]<<":"<<endl;
           cin.ignore();
           getline(cin,name);
           if(type==1)
           {
               vector<Book>::iterator it;
               for(it=B.begin();it!=B.end();it++)
               {
                   if(it->getName()==name)
                   {
                       break;
                   }
               }
               if(it==B.end()){cout<<endl<<"Could not find this "<<a[type]<<"!!!"<<endl<<endl;}
               else{
               if(it->getEnd()==""){
               cout<<"Enter ending date in the format YYYY-MM-DD:"<<endl;
               cin.ignore();
               getline(cin,endd);
               cout<<"Enter consumption time in hrs:"<<endl;
               cin>>time;
               cout<<"Enter the number of days of consumption:"<<endl;
               cin>>days;
               cout<<"Enter the changed rating(Enter -1 to skip):"<<endl;
               cin>>rat;
               it->setEnd(endd);
               it->addConsumption(time,days);
               if(rat!=-1)
               it->setRating(rat);
               cout<<endl<<"Successfully edited a consumable!!!"<<endl<<endl;
               }
               else
               {
                   cout<<endl<<"You can not edit this consumable anymore!!!"<<endl<<endl;
               }
               }
           }
           else if(type==2)
           {
               vector<Series>::iterator it;
               for(it=S.begin();it!=S.end();it++)
               {
                   if(it->getName()==name)
                   {
                       break;
                   }
               }
               if(it==S.end()){cout<<endl<<"Could not find this "<<a[type]<<"!!!"<<endl<<endl;}
               else{
               if(it->getEnd()==""){
               cout<<"Enter ending date in the format YYYY-MM-DD:"<<endl;
               cin.ignore();
               getline(cin,endd);
               cout<<"Enter consumption time in hrs:"<<endl;
               cin>>time;
               cout<<"Enter the number of days of consumption:"<<endl;
               cin>>days;
               cout<<"Enter the changed rating(Enter -1 to skip):"<<endl;
               cin>>rat;
               it->setEnd(endd);
               it->addConsumption(time,days);
               if(rat!=-1)
               it->setRating(rat);
               cout<<endl<<"Successfully edited a consumable!!!"<<endl<<endl;
               }
               else
               {
                   cout<<endl<<"You can not edit this consumable anymore!!!"<<endl<<endl;
               }
               }
           }
           else
           {
               vector<Movie>::iterator it;
               for(it=M.begin();it!=M.end();it++)
               {
                   if(it->getName()==name)
                   {
                       break;
                   }
               }
               if(it==M.end()){cout<<endl<<"Could not find this "<<a[type]<<"!!!"<<endl<<endl;}
               else{
               if(it->getEnd()==""){
               cout<<"Enter ending date in the format YYYY-MM-DD:"<<endl;
               cin.ignore();
               getline(cin,endd);
               cout<<"Enter consumption time in hrs:"<<endl;
               cin>>time;
               cout<<"Enter the number of days of consumption:"<<endl;
               cin>>days;
               cout<<"Enter the changed rating(Enter -1 to skip):"<<endl;
               cin>>rat;
               it->setEnd(endd);
               it->addConsumption(time,days);
               if(rat!=-1)
               it->setRating(rat);
               cout<<endl<<"Successfully edited a consumable!!!"<<endl<<endl;
               }
               else
               {
                   cout<<endl<<"You can not edit this consumable anymore!!!"<<endl<<endl;
               }
               }
           }
       }
       else if(res==3)
       {
           cout<<"Enter 1 for book, 2 for series or 3 for movie:"<<endl;
           cin>>type;
           cout<<"Enter name of the "<<a[type]<<":"<<endl;
           cin.ignore();
           getline(cin,name);
           if(type==1)
           {
               vector<Book>::iterator it;
               for(it=B.begin();it!=B.end();it++)
               {
                   if(it->getName()==name)
                   {
                       it->delRating(it->getRat());
                       B.erase(it);
                       break;
                   }
               }
               if(it==B.end()){cout<<endl<<"Could not find this "<<a[type]<<"!!!"<<endl<<endl;}
               else{cout<<endl<<"Successfully deleted a consumable"<<endl<<endl;}
           }
           else if(type==2)
           {
               vector<Series>::iterator it;
               for(it=S.begin();it!=S.end();it++)
               {
                   if(it->getName()==name)
                   {
                       it->delRating(it->getRat());
                       S.erase(it);
                       break;
                   }
               }
               if(it==S.end()){cout<<endl<<"Could not find this "<<a[type]<<"!!!"<<endl<<endl;}
               else{cout<<endl<<"Successfully deleted a consumable"<<endl<<endl;}
           }
           else
           {
               vector<Movie>::iterator it;
               for(it=M.begin();it!=M.end();it++)
               {
                   if(it->getName()==name)
                   {
                       it->delRating(it->getRat());
                       M.erase(it);
                       break;
                   }
               }
               if(it==M.end()){cout<<endl<<"Could not find this "<<a[type]<<"!!!"<<endl<<endl;}
               else{cout<<endl<<"Successfully deleted a consumable"<<endl<<endl;}
           }
       }
       else if(res==4)
       {
           int in;
           cout<<"Enter 1 to see list of consumables of specific type"<<endl;
           cout<<"or 2 to see details of an specific item:"<<endl;
           cin>>in;
           cout<<"Enter 1 for book, 2 for series or 3 for movie:"<<endl;
           cin>>type;
           if(in==1)
           {
               cout<<"Name"<<setw(30)<<"Days of consumption"<<"  "<<"Hours of consumption";
               cout<<"  "<<"Rating"<<endl;
               if(type==1)
               {
                   vector<Book>::iterator it;
                   for(it=B.begin();it!=B.end();it++)
                   {
                       temp=it->getName();
                       cout<<setw(2)<<it->getName()<<setw(27-temp.length())<<it->getConsumpDays()<<setw(19)<<it->getConsumpTime();
                       cout<<setw(14)<<it->getRating()<<endl;
                   }
               }
               else if(type==2)
               {
                   vector<Series>::iterator it;
                   for(it=S.begin();it!=S.end();it++)
                   {
                       temp=it->getName();
                       cout<<setw(2)<<it->getName()<<setw(27-temp.length())<<it->getConsumpDays()<<setw(19)<<it->getConsumpTime();
                       cout<<setw(14)<<it->getRating()<<endl;
                   }
               }
               else
               {
                   vector<Movie>::iterator it;
                   for(it=M.begin();it!=M.end();it++)
                   {
                       temp=it->getName();
                       cout<<setw(2)<<it->getName()<<setw(27-temp.length())<<it->getConsumpDays()<<setw(19)<<it->getConsumpTime();
                       cout<<setw(14)<<it->getRating()<<endl;
                   }
               }
           }
           else
           {
               cout<<"Enter name of the "<<a[type]<<":"<<endl;
               cin.ignore();
               getline(cin,name);
               cout<<"Name"<<setw(30)<<"Days of consumption"<<"  "<<"Hours of consumption";
               cout<<"  "<<"Rating"<<endl;
               if(type==1)
               {
                   vector<Book>::iterator it;
                   for(it=B.begin();it!=B.end();it++)
                   {
                       if(it->getName()==name)
                       {
                           temp=it->getName();
                           cout<<setw(2)<<it->getName()<<setw(27-temp.length())<<it->getConsumpDays()<<setw(19)<<it->getConsumpTime();
                           cout<<setw(14)<<it->getRat()<<endl;
                           break;
                       }
                   }
                   if(it==B.end()){cout<<endl<<"Could not find this "<<a[type]<<"!!!"<<endl<<endl;}
               }
               else if(type==2)
               {
                   vector<Series>::iterator it;
                   for(it=S.begin();it!=S.end();it++)
                   {
                       if(it->getName()==name)
                       {
                           temp=it->getName();
                           cout<<setw(2)<<it->getName()<<setw(27-temp.length())<<it->getConsumpDays()<<setw(19)<<it->getConsumpTime();
                           cout<<setw(14)<<it->getRat()<<endl;
                           break;
                       }
                   }
                   if(it==S.end()){cout<<endl<<"Could not find this "<<a[type]<<"!!!"<<endl<<endl;}
               }
               else
               {
                   vector<Movie>::iterator it;
                   for(it=M.begin();it!=M.end();it++)
                   {
                       if(it->getName()==name)
                       {
                           temp=it->getName();
                           cout<<setw(2)<<it->getName()<<setw(27-temp.length())<<it->getConsumpDays()<<setw(19)<<it->getConsumpTime();
                           cout<<setw(14)<<it->getRat()<<endl;
                           break;
                       }
                   }
                   if(it==M.end()){cout<<endl<<"Could not find this "<<a[type]<<"!!!"<<endl<<endl;}
               }
           }
           cout<<endl;
       }
       else
       {
           int szb=B.size(),szs=S.size(),szm=M.size();
           cout<<"        "<<"Consumption time"<<"  "<<"Consumption days"<<"  "<<"Average rating";
           cout<<"  "<<"Number of consumables"<<endl;
           Book book;
           cout<<"Book"<<"    "<<setw(10)<<book.getConsumptionTime()<<setw(16)<<book.getConsumptionDays();
           cout<<setw(16)<<book.getRating()/max(1,szb)<<setw(18)<<szb<<endl;
           Series series;
           cout<<"Series"<<"  "<<setw(10)<<series.getConsumptionTime()<<setw(16)<<series.getConsumptionDays();
           cout<<setw(16)<<series.getRating()/max(1,szs)<<setw(18)<<szs<<endl;
           Movie movie;
           cout<<"Movie"<<"   "<<setw(10)<<movie.getConsumptionTime()<<setw(16)<<movie.getConsumptionDays();
           cout<<setw(16)<<movie.getRating()/max(1,szm)<<setw(18)<<szm<<endl;
           consumable con;
           cout<<endl<<"Total"<<"   "<<setw(10)<<con.getTotalConsumpTime()<<setw(16)<<con.getTotalConsumpDays();
           cout<<setw(16)<<con.getTotalRat()/max(1,szb+szs+szm)<<setw(18)<<szb+szs+szm<<endl;
           cout<<endl;
       }
   }
   return 0;
}
