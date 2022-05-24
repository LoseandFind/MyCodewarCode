#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
typedef struct Race
{
  int number;
  struct Race* last;
  struct Race* next;
}Race;
int main()
{
  Race head;
  Race player[20];
  head.number=0;
  head.next=&player[0];
  head.last=nullptr;
  Race end;
  end.number=0;
  end.last=&player[19];
  end.next=nullptr;
  unordered_map<int,Race*> player_num;
  for(int i=0;i<=19;i++)
 {
   if(i==0)
   {
      player[0].number=1;
      player[0].last=&head;
      player[0].next=&player[1];
      player_num.insert(pair<int,Race*>(1,&player[0]));
   }
   else if(i==19)
   {
     player[19].number=20;
     player[19].last=&player[18];
     player[19].next=&end;
     player_num.insert(pair<int,Race*>(20,&player[19]));
   }
   else
   {
     player[i].number=i+1;
     player[i].last=&player[i-1];
     player[i].next=&player[i+1];
     player_num.insert(pair<int,Race*>(i+1,&player[i]));
   }
 }
  int champion=2;
  string events="9 O 17 O 9 O 12 O 2 O 12 O 9 O 1 O 5 O 12 O 17 O 20 O 16 O 7 O 2 O 8 O 16 O 14 O 3 O 14 O 11 O 16 O 1 O 13 O 8 O 14 O 5 O 12 O 4 O";
  int tmp=0;
  for(int i=0;i<events.length();i++)
  {
     if(events[i]!='I'&&events[i]!='O')
     {
      string num;
      while(events[i]!=' ')
      {
        num+=events[i];
        i++;
      }
      tmp=stoi(num);
     }
     else
     {
       if(events[i]=='O')
       {
         Race* p=player_num[tmp];
         Race* q=player_num[tmp]->last;
         q->last->next=p;
         p->last=q->last;
         q->next=p->next;
         p->next->last=q;
         p->next=q;
         p->last=q->last;
         q->last=p;
       }
       else
       {
        if(tmp==champion)
        {
          cout<<-1<<endl;
          return 0;
        }
        Race* p=player_num[tmp];
        p->next->last=p->last;
        p->last->next=p->next;
        p->last=p->next=nullptr;
       
       }
       i++;
     }
  }
  int race=0;
  Race* it=&head;
  for(it;it!=player_num[champion];it=it->next) race++;
  cout<<race<<endl;

 return 0;
}
