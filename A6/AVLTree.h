#include "Entry.h"
using namespace std;

class AVLTree
{
  public:
  struct Node
  {
    Node *left;
    Node *right;
    int height;
    Entry entry;
    Node()
    {
      left = nullptr;
      right = nullptr;
      height = 0;
    }
  };
  int Size;
  Node *root;
  AVLTree()
  {
    root = nullptr; Size = 0;
  }
  ~AVLTree(){root = nullptr; Size = 0;}
  bool empty(){return root == nullptr;}
  int size(){return Size;}
  int getHeight(Node *t){return t == NULL ? -1 : t->height;}
  int max(int l, int r){return l > r ? l : r;}

  void rotateWithLeftChild( Node * & k2 )
    {
        Node *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max( getHeight( k2->left ), getHeight( k2->right ) ) + 1;
        k1->height = max( getHeight( k1->left ), k2->height ) + 1;
        k2 = k1;
    }


  void rotateWithRightChild( Node * & k1 )
  {
        Node *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max( getHeight( k1->left ), getHeight( k1->right ) ) + 1;
        k2->height = max( getHeight( k2->right ), k1->height ) + 1;
        k1 = k2;
  }

  void doubleWithRightChild( Node * & k1 )
    {
        rotateWithLeftChild( k1->right );
        rotateWithRightChild( k1 );
    }

  void doubleWithLeftChild( Node * & k3 )
  {
        rotateWithRightChild( k3->left );
        rotateWithLeftChild( k3 );
  }

  

  Node* findMin(Node *t) const
  {
    if(t == nullptr)
      return nullptr;
    if(t->left == nullptr )
      return t;
    return findMin(t->left);
  }

  Node* findMax(Node *t) const
  {
    if(t != nullptr)
      while(t->right != nullptr)
        t = t->right;
    return t;
  }

  
  void put(Node *&treeNode, Entry data)
  {
    if(treeNode == NULL)
    {
      treeNode = new Node;
      treeNode->left = NULL;
      treeNode->right = NULL;
      treeNode->entry = data;
    }
 
    else if (treeNode->entry > data) 
    {
      put(treeNode->left,data);
      if (getHeight(treeNode->left) - getHeight(treeNode->right) == 2)
      {
       if(data < treeNode->left->entry) 
         rotateWithLeftChild(treeNode);
        else              
          doubleWithLeftChild(treeNode);
      }
    } 
    else if (treeNode->entry < data)
    {
      put(treeNode->right,data);
      if(getHeight(treeNode->right) - getHeight(treeNode->left) == 2)
      {
        if (data > treeNode->right->entry)
          rotateWithRightChild(treeNode);
        else
          doubleWithRightChild(treeNode);
      }
    } 
    else ;
    treeNode->height = max(getHeight(treeNode->left),getHeight(treeNode->right)) + 1;
  }

  void balance(Node *&t)
    {
      if(t == nullptr)
        return;
      if(getHeight(t->left) - getHeight(t->right ) > 1)
      {
        if(getHeight( t->left->left ) >= getHeight( t->left->right))
        {
          rotateWithLeftChild(t);
        }
        else
        {
          doubleWithLeftChild(t);
        }
      }
      else
      {
        if( getHeight(t->right) - getHeight(t->left) > 1)
          if( getHeight(t->right->right) >= getHeight(t->right->left))
          {
            rotateWithRightChild(t);
          }
          else
          {
              doubleWithRightChild(t);  
          }
      }     
      t->height = max( getHeight(t->left), getHeight(t->right)) + 1;
    }





  void erase(Entry k, Node *&t)
  {
    if( t == nullptr )
      return;   
        
    if(k < t->entry)
      erase(k, t->left);
    else if(t->entry < k)
      erase(k, t->right);
    else if(t->left != nullptr && t->right != nullptr) 
    {
      t->entry = findMin(t->right)->entry;
      erase(t->entry, t->right);
    }
    else
    {
       Node *oldNode = t;
      t = (t->left != nullptr) ? t->left : t->right;
      delete oldNode;
    }
    balance(t);
    Size--;
  }


  Node* getEnd()
  {
    Node *t = new Node;
    t->entry.key = -1;
    return t;
  }

  Node* find(Entry k)
  {
    Node *temp = new Node;
    temp = root;
    while(temp != nullptr)
    {
      if(k.key == temp->entry.key)
      {
        return temp;
      }
      else if(k.key < temp->entry.key)
      {
        temp = temp->left;
      }
      else if(k.key > temp->entry.key)
      {
        temp = temp->right;
      }
    }
    return getEnd();
  }

  void print(Node *treeNode, int space)
  {
    if (treeNode != NULL)
    {
      for(int i=0;i<space;i++) 
      {
      cout<<"   ";
      }
      cout << treeNode->entry.key << "("<<treeNode->height + 1 << ")" << endl;
      print(treeNode->left,space+1);
      print(treeNode->right,space+1);
    }
    else
    {
      for(int i = 0;i < space; i++)
      {
        cout << "   ";
      }
    cout << "L (0)" << endl;
    }
  }
};