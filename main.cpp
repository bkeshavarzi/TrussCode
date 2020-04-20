#include <iostream>
#include "Node.h"
#include <vector>
#include "Material.h"
#include "Element.h"
#include "ReadText.h"
#include <algorithm>

using namespace std;

//bool myfunction (int i,int j) { return (i>j); }
int main()
{
    //vector <Node> NV=ReadNodeFile();
    //cout << NV.size() <<endl;
    //vector <Element> EV=ReadElementFile(NV);
    /*
    vector <int> m;
    vector<int>::iterator n;
    m.push_back(10);m.push_back(2);m.push_back(-5);m.push_back(85);m.push_back(10);
    sort(m.begin(),m.end(),myfunction);
    n=unique(m.begin(),m.end());
    m.resize(distance(m.begin(), n));
    //cout << m.begin() <<endl;
    for (n = m.begin(); n != m.end(); ++n) {
        cout << *n << " ";
    }
    */
    //if (2>1) cout <<"HHHH" <<endl;
    //if (2>1) cout <<"HHHH" <<endl;
    MatrixXd a;
    a=MatrixXd::Zero(5,5);
    a([0,2],1)=85;
}
