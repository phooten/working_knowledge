#include "vector.h"

/*
void vector::operator< (std::string TYPE){

}
*/


/*
    Default constructor
*/
vector::vector(){
    m_capacity = 10;
    m_size = 0;
    vectorPtr = new int[m_capacity];

    // initialize default size
    for(int i = 0; i < m_capacity; i++){
        vectorPtr[i] = 0;
    }     


}


/*
    Constructor
*/
vector::vector(int size){
    m_capacity = size;
    m_size = 0;
    vectorPtr = new int[m_capacity];

    // initialize default size
    for(int i = 0; i < m_capacity; i++){
        vectorPtr[i] = 0;
    }     
}


/*  
    Deconstructor
*/
vector::~vector(){

}


/*
    NOT IN USE, PROGRESS PAUSED while working on resize
*/
bool vector::push_back(int value){
    if(m_size >= m_capacity){   // size should never be more than capacity, only =
        bool resize;
        resize = this->upSize();
        if(!resize){                
            return false;
        }
    }

    int* curr = vectorPtr;
    int tmpCount = 0;
    while(curr != NULL && tmpCount < m_capacity){
        curr++;
        tmpCount++;
    }

    // IF returning here, bigger issue, vector max size
    if (tmpCount > m_capacity){
        return false;
    }

    // successfully added
    *curr = value;

    return true;
}


/*
    Purpose:    to re allocate memory in the array. There are serval ways to
                add more memory: double it, constant increase( i.e. 50 each time)
                Increasing by 1/4 the size seems reasonable.
*/
bool vector::upSize(){
    int newSize = m_capacity * 5/4;     // 25 % bigger
    
    if(newSize <= M_INTMAX * 3 / 4 ){     // 75% of (2 ^ 14)
        int* newVectorPtr;

        newVectorPtr = new int[newSize];

        // Copying old vector into new vector
        for(int i = 0; i < m_size; i++){
            newVectorPtr[i] = vectorPtr[i];
        }

        for(int i = m_size; i < m_capacity; i++){
            newVectorPtr[i] = 0;
        }


        // Update vector values and clean up
        delete[] vectorPtr;
        vectorPtr = newVectorPtr;
        m_capacity = newSize;
        // m_size stays the same
        return true;
    } 

    // Can't go bigger
    return false;
}

bool vector::downSize(){
    
    int newCapacity = m_capacity * 3/4;     // 75 % smaller
    if(newCapacity >= 1){
        int* newVectorPtr;

        newVectorPtr = new int[newCapacity];

        // Copying old vector into new vector.
        //  * This WILL cut off numbers if not called correctly
        for(int i = 0; i < newCapacity; i++){
            newVectorPtr[i] = vectorPtr[i];
        }

        // Update vector values and clean up
        delete[] vectorPtr;
        vectorPtr = newVectorPtr;
        m_capacity = newCapacity;
        if(m_size > m_capacity){        // m_size doesn't change if <= capacity
            m_size = m_capacity;
        }
        return true;
    } 

    // Cant go smaller
    return false;
}



/*
    Purpose:    To return the first value in the vector

    Return:     the first value of the vector
*/
int vector::front(){
    // if vectorPtr != Null
    return *vectorPtr;
}

/*
    Purpose:    To return the last value in the vector

    Return:     the last value of the vector
*/
int vector::back(){
    if(m_size >= 1){
        return *vectorPtr;
    } else {
        return -1;  // needs to be null or error
    }
}


/*
    Purpose:    To return the capacity of the vector

    Return:     the capacity of the vector
*/
int vector::capacity(){
    return m_capacity;
}


/*
    Purpose:    To return the size in the vector

    Return:     the size of the vector
*/
int vector::size(){
    return m_size;
}

void vector::print(){
    for(int i = 0; i < m_size; i++){
        std::cout << vectorPtr[i] << ", " << std::endl;
    }
}