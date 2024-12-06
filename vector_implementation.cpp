// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

template <typename T>
class MyVector
{
  int m_size;
  int* m_data;
  int m_capacity;
  
  //reallocate to create a continguous memory for the vector
  // once the vector is filled. Helper Function
  void reallocate(int capacity)
  {
      m_capacity = capacity;
      T* temp = new T[m_capacity];
      for(int i=0; i<m_size; i++)
      {
          temp[i] = m_data[i];
      }
      delete[] m_data;
      m_data = temp;
  }
  
 public:
 //constructor
  MyVector()
  {
      m_size = 0;
      m_capacity = 0;
      m_data = nullptr;
  }
  //parameterised constructor
  MyVector(int capacity) : m_size(0), m_capacity(capacity), m_data(new T[m_capacity]){}
  
  //destructor
  ~MyVector()
  {
      delete[] m_data;
  }
  
  //copy constructor
  MyVector(MyVector& other)
  {
      m_size = other.m_size;
      m_capacity = other.m_capacity;
      m_data = new T[m_capacity];
      for(int i=0; i< m_size; i++)
      {
          m_data[i] = other.m_data[i];
      }
  }
  
  //copy assignment operator
  MyVector& operator=(MyVector& other)
  {
      if(this != &other )
      {
          delete[] m_data;
          m_size = other.m_size;
          m_capacity = other.m_capacity;
          m_data = new T[m_capacity];
          for(int i=0; i< m_size; i++)
          {
              m_data[i] = other.m_data[i];
          }
      }
      return *this;
  }
  
  //Move constructor
  MyVector(MyVector&& other) noexcept : m_size(other.m_size), m_capacity(other.m_capacity), m_data(other.m_data)
  {
      other.m_size = 0;
      other.m_capacity = 0;
      other.m_data = nullptr;
  }
  
  //move assignment operator
  MyVector& operator=(MyVector&& other) noexcept
  {
      if(this != &other)
      {
          delete[] m_data;
          
          m_size = other.m_size;
          m_capacity = other.m_capacity;
          m_data = other.m_data;
          
          other.m_size = 0;
          other.m_capacity = 0;
          other.m_data = nullptr;
      }
      return *this;
  }
  
  
  void push_back(const T& val)
  {
    if(m_size == m_capacity)
        reallocate(m_size == 0 ? 1:2*m_capacity);
    m_data[m_size] = val;
    m_size++;
  }
  
  //return element of given index
  T& operator[](int index)
  {
      if(index >= m_size)
        throw out_of_range("Index out of range");
      return m_data[index];
  }
  
  //getsize function
  int size()
  {
      return m_size;
  }
  
  void print()
  {
      cout<<"The vector elements are \n";
      for(int i=0; i<m_size; i++)
      {
          cout<<m_data[i]<< "\n";
      }
  }
  
};

int main() {
    MyVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.print();

    MyVector<int> vec2 = vec;  // Copy constructor
    vec2.print();
    
    MyVector<int> vec3;
    vec3 = vec2;  // Copy assignment operator
    vec3.print();

    MyVector<int> vec4 = std::move(vec3);  // Move constructor
    vec4.print();

    MyVector<int> vec5;
    vec5 = std::move(vec4);  // Move assignment operator
    vec5.print();

    return 0;
}
