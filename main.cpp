#include <iostream>
#include "Node.h"
#include <vector>
#include "Material.h"
#include "Element.h"
#include "ReadText.h"

using namespace std;

int main()
{
    vector <Node> NV=ReadNodeFile();
    vector <Element> EV=ReadElementFile(NV);
    vector <Node> n;
    for (int i=0; i <EV.size(); i++)
    {
        n=EV[i].getnode();
        cout << EV[i].getid() <<"\t"<<n[0].getid()<<"\t"<<n[1].getid()<< endl;
    }

}
