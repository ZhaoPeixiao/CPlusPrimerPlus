#include<iostream>
using namespace std;
#include"Cow.h"
#include"string2.h"
#include"Stock.h"

void ex1()
{
	Cow c1;
	Cow c2("c2", "sleep", 123.4);
	Cow c3("c3", "eat", 456.7);
	Cow c4(c3);

	c1.ShowCow();
	c2.ShowCow();
	c3.ShowCow();
	c4.ShowCow();
}

void ex2()
{
    String2 s1("and i am a C++ student.");
    String2 s2 = "Please enter your name: ";
    String2 s3;
    cout << s2;
    cin >> s3;
    s2 = "My name is " + s3;
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.Stringup();
    cout << "The sting\n" << s2 << "\ncontains " << s2.has('A')
        << " 'A' characters in it.\n";
    s1 = "red";
    String2 rgb[3] = { String2(s1), String2("green"), String2("blue") };
    cout << "Enter the name of a primary color for mixing light: ";
    String2 ans;
    bool success = false;
    while (cin >> ans)
    {
        ans.Stringlow();
        for (int i = 0; i < 3; i++)
        {
            if (ans == rgb[i])
            {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success)
        {
            break;
        }
        else
        {
            cout << "Try again!\n";
        }
    }

    cout << "Bye!\n";
    return;
}

const int STKS = 4;
void ex3()
{
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };

    std::cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; st++)
    {
        std::cout << stocks[st];
    }

    const Stock* top = &stocks[0];
    for (st = 0; st < STKS; st++)
    {
        top = &top->topval(stocks[st]);
    }

    std::cout << "\nMost valuable holding:\n";
    cout << *top;
}

int main()
{
    ex3();

	system("pause");

	return 0;
}