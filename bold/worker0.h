#ifndef WORKER0_H_
#define WORKER0_H_

#include <string>

class Worker{
private:
    std::string fullname;
    long id;
public:
    Worker(): fullname("no one"), id(0L) {};
    Worker(const std::string &name, long idnum): fullname(name), id(idnum) {};
    virtual ~Worker() = 0;
    virtual void Set();
    virtual void Show() const;
};

class Waiter : public Worker {
private:
    int panache;
public:
    Waiter() : Worker(), panache(0) {};
    Waiter(const std::string &name, long idnum, int p = 0) 
        : Worker(name, idnum), panache(p) {};
        Waiter(const Worker & w, int p = 0)
        : Worker(w), panache(p) {};
    void Set();
    void Show() const;
};
class Singer : public Worker {
protected:
    enum { other, alto, contralto, soprano, bass, baritone, tenor };
    enum { Vtypes = 7 };
private:
    int voice;
    static std::string pv[Vtypes];
public:
    Singer() : Worker(), voice(other) {};
    Singer(const std::string &name, long idnum, int v = other)
        : Worker(name, idnum), voice(v) {};
    Singer(const Worker & w, int v = other)
        : Worker(w), voice(v) {};
    void Set();
    void Show() const;
};

#endif