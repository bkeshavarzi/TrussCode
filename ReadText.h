#ifndef READTEXT_H_INCLUDED
#define READTEXT_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <Eigen/Dense>
#include "Node.h"
#include "Element.h"
using namespace std;
using namespace Eigen;

vector <Node> ReadNodeFile();
vector <Element> ReadElementFile(vector <Node>);
#endif // READTEXT_H_INCLUDED
