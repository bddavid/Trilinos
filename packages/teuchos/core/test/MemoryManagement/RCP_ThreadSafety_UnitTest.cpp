#include <iostream>
#include <vector>
#include <thread>
#include <stack>


// trilinos
//#include <Teuchos_DefaultComm.hpp>
#include "Teuchos_RCP.hpp"
#include "Teuchos_Version.hpp"

using namespace std;
using namespace Teuchos;


// toy for testing classes
class A {
public:
  A() {}
  virtual ~A(){}
  virtual void f(){}
};
class B1 : virtual public A {};
class B2 : virtual public A {};
class C : public B1, public B2 {};


int accum = 0;
std::mutex rcp_lock;
void square(int x) {
  int tmp = x*x;
  rcp_lock.lock();
  accum += tmp;
  rcp_lock.unlock();
}

void refCount(shared_ptr<A> aptr, int thread_id)
{
//  rcp_lock.lock();
  stack<shared_ptr<A> > stk;
  for (int i = 0; i < 2*thread_id; i++)
  {
    shared_ptr<A> cpy = aptr;
    stk.push(cpy);
  }
  
  while (!stk.empty()) {
    stk.pop();
  }

}

void refCountRCP(RCP<A> aptr, int thread_id)
{
  rcp_lock.lock();
  stack<RCP<A> > stk;
  for (int i = 0; i < 2*thread_id; i++)
  {
    RCP<A> cpy = aptr;
    stk.push(cpy);
  }
  
  while (!stk.empty()) {
    stk.pop();
  }
  rcp_lock.unlock();
}

int main(int argc, char ** argv) {
  
  // The point of this test is to hammer away at the reference count
  // by calling many copy constructors on our reference counting
  // pointers from within a non blocking threaded method.
  // if the counter on the thread is thread safe then after completing
  // the threaded scope the ref count should have been decremented to 1.
  
  // 1st up c++ shared pointer
  shared_ptr<A> ptr_a(new A);
  cout << "Begin Cpp test.\nIs beginning shared ptr unique: " << (ptr_a.unique() ? "yes" :"no");
  cout << "\nCpp beginning Ref count: " << ptr_a.use_count() << "\n" << endl;

  vector<thread> ths;
  for (int i = 1; i <= 20; i++) {
    ths.push_back(thread(&refCount, ptr_a, i));
  }
  
  for (auto& th : ths) {
    th.join();
  }
  cout << "End Cpp test.\nIs ending shared ptr unique: " << (ptr_a.unique() ? "yes" :"no");
  cout << "\nCpp ending ref count: " << ptr_a.use_count() << endl;
  
  // next perform the same test with RCP
  RCP<A> ptr_a_rcp = rcp(new A);
  cout << "\n\nBegin RCP test.\nIs beginning RCP unique: " << (ptr_a_rcp.has_ownership() ? "yes" :"no");
  cout << "\nRCP beginning Ref count: " << ptr_a_rcp.total_count() << "\n" << endl;

  vector<thread> ths_rcp;
  for (int i = 1; i <= 2; i++) {
    ths_rcp.push_back(thread(&refCountRCP, ptr_a_rcp, i));
  }
  
  for (auto& th : ths_rcp) {
    th.join();
  }
  
  cout << "End RCP test.\nIs ending RCP unique: " << (ptr_a_rcp.has_ownership() ? "yes" :"no");
  cout << "\nRCP ending ref count: " << ptr_a_rcp.total_count() << "\n" << endl;
  
  return 0;
}
