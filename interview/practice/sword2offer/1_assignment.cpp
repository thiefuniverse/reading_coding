#include <iostream>
#include <utility>
#include <cstring>

class CMyString {
 public:
  CMyString(char* pData = nullptr);
  CMyString(const CMyString& str);
  CMyString& operator=(const CMyString& str);
  void print() {
    if (m_pData) {
      std::cout<< m_pData <<std::endl;
    } else {
      std::cout<< "NULL" <<std::endl;
    }
  }
  ~CMyString(void);
 private:
  char* m_pData;
};

CMyString::CMyString(char *pData) {
  if (pData == nullptr) {
    m_pData = pData;
  } else {
    size_t len = strlen(pData);
    m_pData = new char[len+1];
    memcpy(m_pData, pData, len+1);
  }
}

CMyString::CMyString(const CMyString& str){
  if (str.m_pData == nullptr) {
    m_pData = str.m_pData;
  } else {
    size_t len = strlen(str.m_pData);
    m_pData = new char[len+1];
    memcpy(m_pData, str.m_pData, len+1);
  }

}

CMyString::~CMyString() {
  if (m_pData != nullptr) {
    std::cout<< "release str: " << m_pData<<std::endl;
    delete [] m_pData;
    m_pData = nullptr;
  }
}

CMyString& CMyString::operator= (const CMyString& other) {
   // if (this == &other) {
   //   return *this;
   // }
   // if (m_pData != nullptr) {
   //   delete [] m_pData;
   //   m_pData = nullptr;
   // }
   // if (other.m_pData != nullptr) {
      CMyString another(other.m_pData);
      std::swap(another.m_pData, m_pData);
    //}
    return *this;
  }

int main(int argc, char *argv[]) {
  char m1[] = "wonderful";
  char m2[] = "thiefuniverse";
  CMyString s1(m1);
  CMyString s2(m2);
  s2.print();
  s2 = s1;
  s2.print();
  return 0;
}
