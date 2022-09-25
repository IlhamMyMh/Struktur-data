#include<iostream>
#define maxsize 10
using namespace std;

class Stack
{
    int top;
    int a[maxsize];
public:
    Stack();
    bool ispenuh();
    bool iskosong();
    void push(int x);
    void pop();
    void menampilkan();
    void Top();
    void Size();
};

Stack::Stack()    //default stack
    {
        top=0;
    }

bool Stack::ispenuh()    //jika bagian atas tumpukan sama dengan elemen maksimum yang diizinkan di tumpukan, ukurannya penuh dan tidak dapat mendorong elemen.
    {
        if(top==maxsize)
            return true;
        else
            return false;
    }

bool Stack::iskosong()   //jika stack di top 0, maka tidak ada yang ditampilkan.
    {
        if(top==0)
            return true;
        else
            return false;
    }

void Stack::push(int x)
{
    if(ispenuh())
    {
        cout<<"Stack penuh"<<endl;
        return;
    }
    else
    a[top]=x;  //jika tumpukan tidak penuh, elemen didorong ke tumpukan di indeks teratas array tumpukan.
    top++;
}

void Stack::pop()
{
    if(iskosong())
    {
        cout<<"tidak ada di list"<<endl;
        return;
    }
    else
        top--;   //jika tumpukan tidak kosong (bila bagian atas tidak sama dengan nol) elemen dapat dikeluarkan dari tumpukan (elemen dapat dihapus dari indeks tumpukan teratas)
        cout<<"pops "<<a[top]<<endl;
}

void Stack::menampilkan()   //displays the elements of the stack
    {
        int i;
        if(top==0)
        {
            cout<<"tidak ada yang dapat ditampilkan"<<endl;
        }
        else
        cout<<"Displaying"<<endl;
        for(i=0;i<top;i++)
        {
            cout<<a[i]<<endl;
        }
    }

void Stack::Top()   //displays the top most element in the array of stack
{
    cout<<"top is "<<a[top-1]<<endl;
}

void Stack::Size()    //displays the size of stack
{
    cout<<"size of Stack is "<<top<<endl;
}

int main()
{
    Stack s;
    int ch,element,result;
    while(1)
    {
        cout<<"###################### Program Stack C++ Modif #######################"<<endl;
        cout<<"*--------------------------------------------------------------------*"<<endl;
        cout<<"1.PUSH  2.POP  3.DISPLAY  4.ISFULL  5.ISEMPTY  6.TOP  7.SIZE  8.EXIT "<<endl;
        cout<<"*--------------------------------------------------------------------*"<<endl;
    cin>>ch;
    if(ch==1)
    {
        cout<<"Masukan Data : ";
        cin>>element;
        s.push(element);
    }
    else if(ch==2)
    {
        s.pop();
    }
    else if(ch==3)
    {
        s.menampilkan();
    }
    else if(ch==4)
    {
        if(s.ispenuh())
            cout<<"STACK IS FULL"<<endl;
        else
            cout<<"STACK IS NOT FULL"<<endl<<"YOU CAN PUSH"<<endl;
    }
    else if(ch==5)
    {
        if(s.iskosong())
            cout<<"STACK IS EMPTY"<<endl;
        else
            cout<<"STACK IS NOT EMPTY"<<endl<<"YOU CAN POP"<<endl;
    }
    else if(ch==6)
    {
        s.Top();
    }
    else if(ch==7)
    {
        s.Size();
    }
    else
    return 0;
    }
    return 0;
}
