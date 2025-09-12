#ifndef WORKERMI_H_
#define WORKERMI_H_

#include <string>
class Worker
{
private:
    std::string name;
    int id;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Worker() : name("no one"), id(0) {};
    Worker(const std::string & s, int n) : name(s), id(n) {};
    virtual ~Worker() = 0; // pure virtual function
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

class Waiter : virtual public Worker
{
private:
    int panache;
protected:
    void Data() const;
    void Get();
public:
    Waiter() : Worker(), panache(0) {};
    Waiter(const std::string & s, int n, int p = 0) : Worker(s, n), panache(p) {};
    
    Waiter(const Worker & w, int p = 0) : Worker(w), panache(p) {};
    virtual ~Waiter() {};
    virtual void Set();
    virtual void Show() const;
};
class Singer : virtual public Worker
{
protected:
    enum {other, alto, contralto, soprano, bass, baritone, tenor};
    enum {Vtypes = 7};
    void Data() const;
    void Get();
private:
    static std::string pv[Vtypes];
    int voice;
public:
    Singer() : Worker(), voice(other) {};
    Singer(const std::string & s, int n, int v = other) : Worker(s, n), voice(v) {};
    Singer(const Worker & w, int v = other) : Worker(w), voice(v) {};
    void Set();
    void Show() const;
};
class SingingWaiter : public Waiter, public Singer
{
protected:
    void Data() const;
    void Get();
public:
    SingingWaiter() {};
    SingingWaiter(const std::string & s, int n, int p = 0, int v = Singer::other) 
        : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {};
    SingingWaiter(const Worker & w, int p = 0, int v = other) 
        : Worker(w), Waiter(w, p), Singer(w, v) {};
    SingingWaiter(const Waiter & w, int v = Singer::other) 
        : Worker(w), Waiter(w), Singer(w, v) {};
    SingingWaiter(const Singer & s, int p = 0) 
        : Worker(s), Waiter(s, p), Singer(s) {};
    void Set();
    void Show() const;
};

#endif