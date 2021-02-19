#ifndef PERSON_H_
#define PERSON_H_
#include <string>

class Person
{
private:
	std::string firstname;
	std::string lastname;

protected:
	virtual void Data() const;

public:
	Person(const char* fn = "none", const char* ln = "none")
		: firstname(fn), lastname(ln) {}
	// no explicit copy constructor function
	virtual ~Person() {}
	virtual void Show() const;
	virtual void Set();
};

class Gunslinger : virtual public Person
{
private:
	double drawtime;
	int notches;

protected:
	void Data() const;

public:
	Gunslinger(const char* fn = "none", const char* ln = "none",
		double d = 0.0, int n = 0)
		: Person(fn, ln), drawtime(d), notches(n) {}
	double Draw() const { return drawtime; }
	double Notches() const { return notches; }
	void Show() const;
	void Set();
};

class PokerPlayer : virtual public Person
{
public:
	PokerPlayer(const char* fn = "none", const char* ln = "none")
		: Person(fn, ln) {}
	int Draw() const;
};

class BadDude : public PokerPlayer, public Gunslinger
{
protected:
	void Data() const;

public:
	double Gdraw() const { return Gunslinger::Draw(); }
	double Cdraw() const { return PokerPlayer::Draw(); }
	void Show() const;
	void Set();
};
#endif