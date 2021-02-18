#pragma once
#ifndef CD1_H_
#define CD1_H_

#include <iostream>

class Cd
{
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;

public:
    Cd(const char* s1, const char* s2, int n, double x);
    Cd(const Cd& d);
    Cd();
    virtual ~Cd();
    virtual void Report() const;
    virtual Cd& operator=(const Cd& d);
};

class Classic : public Cd
{
private:
    char mainfile[20];

public:
    Classic(const char* s1, const char* s2, const char* s3, int n, double x);
    Classic(const Cd& d, char* s3);
    Classic(const Classic& d);
    Classic();
    virtual ~Classic();
    virtual void Report() const;
    virtual Classic& operator=(const Classic& d);
};
#endif // !CD1_H_