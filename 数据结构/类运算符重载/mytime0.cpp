#include<iostream>
#include"mytime0.h"
using std::cout;
time::time()
{
    hours = 0;
    mins = 0;
}
time::time(int h,int m)
{
    hours = h;
    mins = m;
}
void time::Addmin(int m)
{
    mins += m;
    while(mins>=60)
    {
        hours++;
        mins -= 60;
    }
}
void time::AddHr(int h)
{
    hours += h;
}
void time::reset(int h,int m)
{
    hours = h;
    mins = m;
}
time time::operator+(const time & t)const//参数用引用加快效率，返回值不用引用是因为如果使用引用，被引用的将会在函数结束的之后删除
{
    time sum;
    sum.mins = mins + t.mins;
    sum.hours = hours + t.hours + sum.mins / 60;
    sum.mins %= 60;
    return sum;
}
time time::operator-(const time & t)const//参数用引用加快效率，返回值不用引用是因为如果使用引用，被引用的将会在函数结束的之后删除
{
    time sum;
    if(mins>=t.mins)
    {
    sum.mins = mins - t.mins;
    sum.hours = hours - t.hours;
    }
    else
    {
        sum.mins = mins + 60 - t.mins;
        sum.hours = hours - t.hours - 1;
    }
    return sum;
}
void time::show() const
{
    cout << hours << " hours," << mins << " minutes";
}

