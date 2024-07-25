#include <iostream>
#include <string>
using namespace std;

class home;
class guy
{
public:
    guy();
    ~guy();
    void visit();
    home *h;
};

class home
{
    friend void guy::visit(); // 大同小异

public:
    string livingroom = "客厅";

private:
    string bedroom = "卧室";
};
/*噢，所以上节才说把所有的定义放在外面，因为顺序很重要*/
void guy::visit()
{
    cout << " 好朋友正在访问" << h->livingroom << endl;
    cout << " 好朋友正在访问" << h->bedroom << endl;
}
guy::guy()
{
    h = new home;
}
guy::~guy()
{
    if (h != NULL)
    {
        delete h;
        h = NULL;
    }
}
int main()
{
    guy LiHua;
    LiHua.visit();
    return 0;
}