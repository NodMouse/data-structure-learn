#include<iostream>
#include"mytime0.cpp"
int main()
{
    using std::cout;
    using std::endl;
    time plan;
    time code(2, 40);
    time fix(5, 55);
    time total;

    cout << "plantime :=";
    plan.show();
    cout << endl;
    
    cout << "codetime :=";
    code.show();
    cout << endl;
    
    cout << "fixtime  :=";
    fix.show();
    cout << endl;

    total = code + fix;
    cout << "totaltime:=";
    total.show();
    cout << endl;

    total = fix-code;
    cout << "totaltime-:=";
    total.show();
    cout << endl;
    return 0;
}