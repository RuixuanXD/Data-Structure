#include "AVLTree.h"

int main() 
{
  AVLTree t;
  Entry e1(13,"aaa");
  t.put(t.root, e1);
  Entry e2(15,"xzc");
  t.put(t.root, e2);
  Entry e3(36,"saz");
  t.put(t.root, e3);
  Entry e4(5,"brt");
  t.put(t.root, e4);
  Entry e5(6,"wqa");
  t.put(t.root, e5);
  Entry e6(20,"nmj");
  t.put(t.root, e6);
  Entry e7(12,"ghy");
  t.put(t.root, e7);
  t.print(t.root, 0);

  cout << endl << endl;

  t.erase(e3, t.root);
  t.print(t.root, 0);
  t.~AVLTree();

  cout << endl << endl;

  AVLTree t2;
  Entry eout(14, "gxv");
  t2.put(t2.root, t.find(e7)->entry);
  t2.print(t2.root, 0);
  cout << endl;
  AVLTree t3;
  t3.put(t3.root, t.find(eout)->entry);
  t3.print(t3.root, 0);

  cout << endl << endl;

  AVLTree t4;
  Entry a1(13,"aaa");
  t4.put(t4.root, a1);
  Entry a2(15,"xzc");
  t4.put(t4.root, a2);
  Entry a3(36,"saz");
  t4.put(t4.root, a3);
  Entry a4(5,"brt");
  t4.put(t4.root, a4);
  Entry a5(6,"wqa");
  t4.put(t4.root, a5);
  Entry a6(20,"nmj");
  t4.put(t4.root, a6);
  Entry a7(12,"ghy");
  t4.put(t4.root, a7);
  Entry a8(56,"zce");
  t4.put(t4.root, a8);
  Entry a9(44,"hjy");
  t4.put(t4.root, a9);
  Entry a10(34,"ewz");
  t4.put(t4.root, a10);
  Entry a11(59,"bsd");
  t4.put(t4.root, a11);
  Entry a12(23,"xha");
  t4.put(t4.root, a12);
  Entry a13(19,"gjy");
  t4.put(t4.root, a13);
  Entry a14(46,"egy");
  t4.put(t4.root, a14);
  Entry a15(11,"ukm");
  t4.put(t4.root, a15);
  t4.print(t4.root, 0);

  cout << endl << endl;

  t4.erase(a13, t4.root);
  t4.erase(a6, t4.root);
  t4.erase(a2, t4.root);
  t4.erase(a8, t4.root);
  t4.erase(a3, t4.root);
  t4.print(t4.root, 0);
  cout << endl;

  return 0;
}