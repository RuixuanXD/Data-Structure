#include "Entry.h"


class QuadNode
{
  public:
  int key;
  Entry e;
  QuadNode *prev;
  QuadNode *next;
  QuadNode *down;
  QuadNode *top;
  QuadNode():key(e.getKey()), prev(nullptr), next(nullptr), down(nullptr), top(nullptr){}
};

class Exception
{
  private:
  string e;
  public:
  Exception(string str):e(str){}
};


class SkipList
{
private:
  QuadNode *head;
  int level;
  int Size;

public:
  SkipList()
  {
    head = new QuadNode;
    head->key = INT_MIN;
    QuadNode *tail = new QuadNode;
    tail->key = INT_MAX;
    head->next = tail;
    tail->prev = head;
    level = 1;
    Size = 0;
  }

  ~SkipList(){delete head;}

  Entry& find(int k)
  {
    QuadNode *x = head;
    while(x->down != nullptr)
    {
      x = x->down;
    }
    while(x->next != nullptr)
    {
      if(x->next->key == k)
      {
        return x->next->e;
      }
    }
    throw Exception("Did not find the key");
  }

  Entry& greaterEntry(int k)
  {
    QuadNode *x = head;
    while(x->down != nullptr)
    {
      x = x->down;
    }
    while(x->next != nullptr)
    {
      if(x->next->key > k)
      {
        return x->next->e;
      }
      if(x->next->key == INT_MAX)
      {
        break;
      }
      x = x->next;
    }
    throw Exception("the entry with the lowest key that is greater than k is infinity");
  }

  Entry& lessEntry(int k)
  {
    QuadNode *x = head;
    while(x->down != nullptr)
    {
      x = x->down;
    }
    while(x->next != nullptr)
    {
      if(x->next->key >= k && x->key == INT_MIN)
      {
        break;
      }
      else if(x->next->key >= k)
      {
        return x->e;
      }
      x = x->next;
    }
    throw Exception("the entry with the greatest key that is less than k is minus infinity");
  }

  void bindNewNode(QuadNode *x, QuadNode *p)
  {
    if(!x->next)
    {
      x->next = p;
      p->prev = x;
    }
    else{
      p->next = x->next;
      x->next->prev = p;
      p->prev = x;
      x->next = p;
    }
  }

  void put(int k, string v)
  {
    QuadNode *p = new QuadNode;
    p->key = k;
    p->e.setKey(k);
    p->e.setData(v);
    QuadNode *x = head;
    while(1)
    {
      if(x->key <= k)
      {
        if(x->next)
        {
          x = x->next;
        }
        else if(x->down)
        {
          x = x->down;
        }
        else
        {
          break;
        }
      }
      else if(x->prev->down)
      {
        x = x->prev->down;
      }
      else
      {
        x = x->prev;
        break;
      }
    }
    if(x->key == k)
    {
      this->erase(k);
    }

      bindNewNode(x, p);
      while(rand() % 2)
      {
        QuadNode *highp = new QuadNode;
        highp->key = k;
        highp->e.setKey(k);
        highp->e.setData(v);
        while(!x->top && x->prev)
        {
          x = x->prev;
        }
        if(x->top)
        {
          x = x->top;
          bindNewNode(x, highp);
          highp->down = p;
          p->top = highp;
        }
        else
        {
          QuadNode * top1 = new QuadNode;
          x = top1;
          top1->key = INT_MIN;
          top1->down = head;
          head->top = top1;
          head = top1;
          bindNewNode(top1, highp);
          highp->down = p;
          p->top = highp;
          QuadNode *top2 = new QuadNode;
          while(head->next != nullptr)
          {
            head = head->next;
          }
          top2->key = INT_MAX;
          top2->down = head;
          head->top = top2;
          head = top2;
          bindNewNode(highp, top2);
          top2->down = head;
          head->top = top2;
          head = top1;
          ++level;
        }
        p = highp;
      }
    ++Size;
  }


  void erase(int k)
  {
    QuadNode *x = head;
    while(1)
    {
      if(x->key == k)
      {
        break;
      }
      else if(x->key < k)
      {
        if(x->next)
        {
          x = x->next;
        }
        else if(x->down)
        {
          x = x->down;
        }
        else
        {
          throw Exception("Did not find the key");
        }
      }
      else if(x->prev->down)
      {
        x = x->prev->down;
      }
      else
      {
        throw Exception("Did not find the key");
      }
    }
    if(x)
    {
      while (x->down)
      {
        QuadNode *y = x->down;
        if(!x->next)
        {
          if(x->prev == head && head->down)
          {
            head = head->down;
            head->top = nullptr;
            delete x->prev;
            --level;
          }
          else
          {
            x->prev->next = nullptr;
          }
        }
          else
          {
            x->prev->next = x->next;
            x->next->prev = x->prev;
          }
        
        x = y;
      }
      if(!x->next)
        {
          if(x->prev == head && head->down)
          {
            head = head->down;
            head->top = nullptr;
            delete x->prev;
            --level;
          }
          else
          {
            x->prev->next = nullptr;
          }
        }
          else
          {
            x->prev->next = x->next;
            x->next->prev = x->prev;
          }
        
      --Size;
    }
  }

  int size(){return Size;}
  bool empty(){return Size == 0;}

  void print()
  {
    QuadNode *h = head;
    QuadNode *bottomHead = head;
    while(bottomHead->down != nullptr)
    {
      bottomHead = bottomHead->down;
    }
    while(h)
    {
      QuadNode *curr = h;
      QuadNode *bottomCurr = bottomHead;
      while(bottomCurr)
      {
        if(bottomCurr->key == INT_MIN)
        {
          cout << "-inf--";
          curr = curr->next;
        }
        else if(bottomCurr->key == INT_MAX)
        {
          cout << "inf";
        }
        else if(curr->key == bottomCurr->key)
        {
          cout << curr->key << "--";
          curr = curr->next;
        }
        else 
        {
          cout << "----";
        }
        bottomCurr = bottomCurr->next;
      }
      h = h->down;
      cout << endl;
    }
  }
};
