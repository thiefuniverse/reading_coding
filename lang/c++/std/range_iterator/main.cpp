#include <iostream>
#include "Thief_Iterator.hpp"

using namespace std;
using namespace detail_range;
void test_range(void)
{
  cout<<"range(9,5,-1):";
  for(auto m:range(9,5,-1))
  {
    cout<<" "<<m;
  }
  cout<<endl;
  
  
  cout<<"range(3,7):";
  for(auto m:range(3,7))
  {
    cout<<" "<<m;
  }
  
  cout<<endl<<"range(16):";
  for(auto m:range(16))
  {
    cout<<" "<<m;
  }
  
  cout<<endl<<"range(3,7,2):";
  for(auto m:range(3,7,2))
  {
    cout<<" "<<m;
  }
  cout<<endl<<"range(2.5,5.0,0.5):";
  for(auto m:range(2.5,5.0,0.5))
  {
    cout<<" "<<m;
  }
  cout<<endl<<"range(7,3,-1):";
  for(auto m:range(7,3,-1))
  {
    cout<<" "<<m;
  }
}


int main() {
  test_range();
}
