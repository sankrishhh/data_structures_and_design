// Online C++ compiler to run C++ program online
#include <iostream>
#include <stdexcept>

using namespace std;

class MyString{
    int m_size;// carry the length of the string
    char* m_data;//carry the char array.
public:
    //default constructor
    MyString()
    {
        m_size = 0;
        m_data = new char[1];
        m_data[0] = '\0';
    }
    //destructor
    ~MyString()
    {
        delete[] m_data;
    }
    //parameterised constructor
    MyString(const char* data)
    {
        m_size = 0;
        while(data[m_size] != '\0')
            m_size++;
        m_data = new char[m_size+1];
        for(int i=0; i<m_size; i++)
            m_data[i] = data[i];
        m_data[m_size] = '\0';
    }
    //copy constructor
    MyString(MyString& other)
    {
        cout<<"copy constructor called \n";
        m_size = other.m_size;
        m_data = new char[m_size + 1];
        for(int i=0; i<m_size; i++)
            m_data[i] = other.m_data[i];
        m_data[m_size] = '\0';
    }
    //copy assignment operator
    MyString& operator=(MyString& other)
    {
        if(this != &other)
        {
            cout<<"copy assignment operator called \n";
            delete[] m_data;
            m_size = other.m_size;
            m_data = new char[m_size + 1];
            for(int i=0; i< m_size; i++)
                m_data[i] = other.m_data[i];
            m_data[m_size] = '\0';
        }
        return *this;
    }
    //move constructor
    MyString(MyString&& other) noexcept
    {
        cout<<"Move constructor called \n";
        m_size = other.m_size;
        m_data = other.m_data;
        other.m_size = 0;
        other.m_data = nullptr;
    }
    //move assignment operator
    MyString& operator=(MyString&& other)
    {
        cout<<"Move Assignment operator called \n";
        if(this != &other)
        {
            delete[] m_data;
            m_size = other.m_size;
            m_data = new char[m_size + 1];
            for(int i=0; i< m_size; i++)
                m_data[i] = other.m_data[i];
            m_data[m_size] = '\0';
            
            //delete old ptr.
            other.m_size = 0;
            other.m_data = nullptr;
        }
        return *this;
    }
    
    //return string length
    int length()
    {
        return m_size;
    }
    //Concatenation operator
    MyString operator+(const MyString& other)
    {
        int new_length = m_size + other.m_size;
        char*  temp = new char[new_length+1];
        for(int i=0; i< m_size; i++)
            temp[i] = m_data[i];
        for(int i=0; i<other.m_size; i++)
            temp[m_size+i] = other.m_data[i];
        temp[new_length] = '\0';
        MyString result(temp);
        return result;
    }
    //comparisoin operator
    bool operator==(MyString& other)
    {
        if(m_size != other.m_size)
            return false;
        for(int i=0; i<m_size; i++)
        {
            if(m_data[i] != other.m_data[i]) 
                return false;
        }
        return true;
    }
    bool operator!=(MyString& other)
    {
        return !(other == *this);
    }
    //print the string
    void print()
    {
        cout<<"Printing the string: \n";
        for(int i=0; i<m_size; i++)
        {
            cout<<m_data[i];
        }
        cout<<endl;
    }
    //access operator
    char& operator[](int index)
    {
     if(index >=m_size)
        throw out_of_range("index out of range");
     return m_data[index];
    }
    
    //const correctness
    const char& operator[](int index) const
    {
     if(index >=m_size)
        throw out_of_range("index out of range");
     return m_data[index];
    }
    
};




int main() {
    // Write C++ code here
    MyString str("sanjay");
    MyString str2(str);
    MyString str1 = move(str);
    MyString concate_obj = str1+str2;
    concate_obj.print();
    if(str1 == str2)
        cout<<"both strings are same \n";
    if(concate_obj != str1)
        cout<<"both strings are different \n";
    MyString str3;
    str3 = str2;
    

    return 0;
}
