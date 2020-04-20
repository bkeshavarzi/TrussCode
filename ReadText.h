#ifndef READTEXT_H_INCLUDED
#define READTEXT_H_INCLUDED
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include "Node.h"
#include "Material.h"
#include "Element.h"

vector <Node> ReadNodeFile();
vector <Element> ReadElementFile(vector <Node>);

#endif // READTEXT_H_INCLUDED
