#include "ReadText.h"


vector <Node> ReadNodeFile()
{
  ifstream fid ("Node.txt");
  if (!fid.is_open())
  {
      cout << "Can''t open the Node input file" << endl;

  } else {

      int id;
      double xc,yc;
      bool xr,yr;
      Node obj;
      int counter=0;
      vector <Node> NodalVector;
      while (!fid.eof())
      {
          fid >> id >> xc >> yc >> xr >> yr;
          obj.setid(id);
          obj.setcord(xc,yc);
          NodalVector.push_back(obj);
          counter++;
      }
      fid.close();
      return NodalVector;
  }

}

void ReadElementFile(vector <Node> NV)
{
    ifstream fid ("Element.txt");
    Element obj;
    if (!fid.is_open())
    {

      cout << "Can''t open the Element input file" << endl;

    } else {
      cout << "Open the file :)))" <<endl;
      int id,inode,jnode;
      double A;
      vector <Node> temp;
      temp.push_back(NV[0]);
      temp.push_back(NV[1]);
      vector <Element> ElementVector;


      while (!fid.eof())
      {
         fid >> id >> inode >> jnode >> A;
         obj.SetId(id);
         cout << inode <<"\t"<<jnode<<endl;
         temp[0]=NV[inode-1];temp[1]=NV[jnode-1];
         obj.SetNode(temp);
         obj.SetA(A);
         ElementVector.push_back(obj);
      }
      fid.close();

      //return ElementVector;
    }
}
