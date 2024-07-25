#include <iostream>
using namespace std;

class cpu
{
public:
    virtual void calculate() = 0;
};
class videocard
{
public:
    virtual void display() = 0;
};
class memory
{
public:
    virtual void storage() = 0;
};

class intelcpu : public cpu
{
public:
    void calculate()
    {
        cout << "intel的cpu开始工作了" << endl;
    }
};
class intelvideocard : public videocard
{
public:
    void display()
    {
        cout << "intel的显卡开始工作了" << endl;
    }
};
class intelmemory : public memory
{
public:
    void storage()
    {
        cout << "intel的内存开始工作了" << endl;
    }
};

class hpcpu : public cpu
{
public:
    void calculate()
    {
        cout << "惠普的cpu开始工作了" << endl;
    }
};
class hpvideocard : public videocard
{
public:
    void display()
    {
        cout << "惠普的显卡开始工作了" << endl;
    }
};
class hpmemory : public memory
{
public:
    void storage()
    {
        cout << "惠普的内存开始工作了" << endl;
    }
};
class computer
{
public:
    void work()
    {
        m_c->calculate();
        m_v->display();
        m_m->storage();
    }
    computer(cpu *c, videocard *v, memory *m)
    {
        m_c = c;
        m_v = v;
        m_m = m;
    }
    ~computer()
    {
        if (m_c != NULL)
        {
            delete m_c;
            m_c = NULL;
        }
        if (m_v != NULL)
        {
            delete m_v;
            m_v = NULL;
        }
        if (m_m != NULL)
        {
            delete m_m;
            m_m = NULL;
        }
    }

private:
    cpu *m_c;
    videocard *m_v;
    memory *m_m;
};

void f()
{
    computer *thinkpad = new computer(new intelcpu, new intelvideocard, new intelmemory);
    thinkpad->work();
    delete thinkpad;
    cout <<"-------------------------"<<endl;
    computer *thinkpad1 = new computer(new intelcpu, new hpvideocard, new hpmemory);
    thinkpad1->work();
    delete thinkpad1;
}
int main()
{
    f();
    return 0;
}