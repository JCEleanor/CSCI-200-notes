#include <iostream>
using namespace std;

int main()
{
  string name = "Eleanor";
  string *pName = &name;
  float **y;

  // * dereferencing
  // & address of
  /**
   * name:Eleanor
     pName:0x309a86d88
     *pName:Eleanor // adding * dereferencing address to get the value
   */
  // cout << "name:" << name << endl;
  // cout << "pName:" << pName << endl;
  // cout << "*pName:" << *pName << endl;
  cout << "y: " << y << endl;
  cout << "**y: " << **y << endl;

  // string freePizzas[3] = {"p1", "p2", "p3"};
  // cout << freePizzas << endl; // memory address: 0x304bc6d50
}