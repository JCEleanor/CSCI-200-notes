#include <iostream>
#include <iterator>
using namespace std;

template <typename T>
void print(T anything)
{
  cout << anything << endl;
}

void arrays()
{
  int stores[10];
  static int arr[10];
  char chars[3] = {'A', 'B', 'c'};
  // for (int i = 0; i < size(chars); i++)
  // {
  //   cout << "'" << chars[i] << "'" << endl;
  // }

  print(chars);
}

void contiguous()
{
  const int size = 3;
  int arr[size] = {1, 2, 3};
  print(arr);

  for (int i = 0; i < size; i++)
  {
    print(arr[i]);
  }

  cout << "print address: " << endl;
  for (int i = 0; i < size; i++)
  {
    print(&arr[i]);
  }
}

void cStyleString()
{
}

int main()
{
  arrays();
  // contiguous();
  // string name = "Eleanor";
  // string *pName = &name;
  // float **y;

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
  // cout << "y: " << y << endl;
  // cout << "**y: " << **y << endl;

  // string freePizzas[3] = {"p1", "p2", "p3"};
  // cout << freePizzas << endl; // memory address: 0x304bc6d50
}