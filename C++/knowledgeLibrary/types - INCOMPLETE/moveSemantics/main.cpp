/*
    Date:           10-3-2021
    File:           main.cpp
    Version:        1.0
    Status:         COMPLETE
    
    Contributers:   Parker Hooten
                    The Cherno (see Credits)

    Purpose:        To learn about moving semantics and how we can optimize our
                    code through moving rather than copying. Below shows an 
                    extremely basic string class and how we might go about 
                    moving it over to be accessed by a different class.  

    Credits:
        The Cherno:
            -   This code was written by this youtube channel. It was written
                almost completely based on the following link, with the purposes
                of learning about arrays, and better programming practice.
                Link:  https://www.youtube.com/watch?v=ehMg6zvXuMY
*/

#include<iostream>
#include<cstring>

class String{
public:
    String() = default;
    
    String(const char* string){
        printf("Created!\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }

    /*
        Copy Constructor
        -   Takes in lvalue reference
    */
    String(const String& other){
        printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }

    /*
        Move Constructor
        -   Takes in rvalue reference
    */
    String(String&& other) noexcept {
        printf("Moved!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        other.m_Size = 0;
        other.m_Data = nullptr;
    }


    ~String(){
        printf("Destroyed\n");
        delete m_Data;
    }

    void Print(){
        for(uint32_t i = 0; i < m_Size; i++){
            printf("%c", m_Data[i]);
        }
        printf("\n");
    }

private:
    char* m_Data;
    uint32_t m_Size;
};



class Entity{
    public:
        Entity(const String& name)
            : m_Name(name) {}
        
        Entity(String&& name)
            : m_Name((String&&)name) {}
       
        void PrintName(){
            m_Name.Print();
        }

    private:
        String m_Name;
};



int main(){
    Entity entity(String("Cherno"));
    entity.PrintName();

    return 0;
}


