#include "vector.h"

/*
void vector::operator< (std::string TYPE){

}
*/


/*
    Default constructor
*/
vector::vector(){
    debug(std::cout << "__vector::vector()__" << std::endl);
    
    // debug vars:
    //-----------
    *m_null = 7777777;
    //-----------
    
    m_capacity = 10;
    m_size = 0;
    vectorPtr = new int[m_capacity];
    if(vectorPtr == NULL){
        std::cout << "[ ERROR: vector::vector(int size) ]: could not allocate new int[m_capacity]"  
                  << std::endl;
    } else {

        // initialize default size
        for(int i = 0; i < m_capacity; i++){
            //vectorPtr[i] = 0;
            vectorPtr[i] = -1;
        }
    }     


}


/*
    Constructor
*/
vector::vector(int size){
    // debug vars:
    //-----------
    *m_null = 7777777;
    //-----------
    
    debug(std::cout << "__vector::vector(int size)__" << std::endl);

    m_capacity = size;
    m_size = 0;
    vectorPtr = new int[m_capacity];
    if(vectorPtr == NULL){
        std::cout << "[ ERROR: vector::vector(int size) ]: could not allocate new int[m_capacity]"  
                  << std::endl;
    } else {
        // initialize default size
        for(int i = 0; i < m_capacity; i++){
            vectorPtr[i] = 0;
        }     
    }
}


/*  
    Deconstructor
*/
vector::~vector(){
    
    debug(std::cout << "__vector::~vector()__" << std::endl);


    delete[] vectorPtr;
    delete m_null;
}

/*
    Purpose:    to re-allocate memory in the array in order to increase the size
                then de-allocate the old memory
    
    Return:    if upsize was successful (true) or not (false)
*/
bool vector::upSize(){
    debug(std::cout << "__vector::upSize()__" << std::endl);

    
    // int newCapacity = m_capacity * 5/4;         // 25 % bigger    
    int newCapacity = m_capacity * 1.25;         // 25 % bigger    
    
    if(newCapacity <= M_INTMAX * 3 / 4 ){       // 75% of (2 ^ 14)
        int* newVectorPtr;
        
        newVectorPtr = new int[newCapacity];
        if(newVectorPtr == NULL){    
            std::cout << "[ ERROR: vector::upSize() ]: could not allocate new int[newSize]" 
                      << std::endl;
        }

        // Copying old vector into new vector
        for(int i = 0; i < m_size; i++){
            newVectorPtr[i] = vectorPtr[i];
        }
        
        // Initializes new values
        for(int i = m_size; i < newCapacity; i++){
            newVectorPtr[i] = -1;
        }


        // Update vector values and clean up
        delete[] vectorPtr;
        vectorPtr = newVectorPtr;
        m_capacity = newCapacity;
        // m_size stays the same
        
        return true;
    } 

    // Can't go bigger
    return false;
}


/*
    Purpose:    to re-allocate memory in the array in order to decrease the size
                then de-allocate the old memory
    
    Return:    if downSize was successful (true) or not (false)
*/
bool vector::downSize(){
    debug(std::cout << "__vector::downSize()__" << std::endl);

    // int newCapacity = m_capacity * 3/4;     // 75 % smaller
    int newCapacity = m_capacity * 0.75;     // 75 % smaller
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
    Purpose:    Add a value to the end of the vector

    Argurments: int value - The value to be added to the vector

    Return:     true if adding it was successfull, false if it was not successful 
*/
bool vector::push_back(int value){
    debug(std::cout << "__vector::push_back(int value)__" <<  " " << value << std::endl);

    if(m_size >= m_capacity){   // size should never be more than capacity, only =      
        bool resize;
        resize = this->upSize();
        if(!resize){               
            std::cout << "[ERROR vector::push_back() ] -> m_size > m_capacity, resize = false" << std::endl;
            return false;
        }
    }

    int* curr = vectorPtr;
    int tmpCount = 0;
    
    while(*curr != -1 && tmpCount < m_capacity){
        // std::cout << *curr << std::endl; 
        curr++;
        tmpCount++;
    }
    /* 
    while(curr != NULL && tmpCount < m_capacity){
        std::cout << *curr << std::endl; 
        curr++;
        tmpCount++;
    }
    */
    
    // IF returning here, bigger issue, vector max size
    if (tmpCount > m_capacity){
        
        return false;
    }

    // successfully added
    m_size++;
    *curr = value;

    return true;
}

/*
    Purpose:    insert a position somewhere in the vector. 0 is the start of the 
                vector. This will not reach the end of the vector. Use push_back()
                if you wish to add to the end. 

    Argurment:  int position - The position to be inserted from the vector

    Return:     true if erasing was successfull, false if it was not successful 
*/
bool vector::insert(int position, int value){
    debug(std::cout << "__vector::insert(int position, int value)__" << std::endl);

    // Checks position validity
    if(position >= m_size || position < 0){   // size should never be more than capacity, only =      
        std::cout << "[ERROR vector::insert(int position, int value) ] -> position < 1 || position > m_size " << std::endl;
        return false;
    } 

    // Checks if upSize is needed
    if(m_size >= m_capacity){         
        bool resize;
        resize = this->upSize();
        if(!resize){     
            std::cout << "[ERROR vector::insert() ] -> m_size > m_capacity, resize = false" << std::endl;
            return false;
        }
    }

    // Moves everything down to allow for insert
    for(int i = m_size - 1; i >= position; i--){
        vectorPtr[i + 1] = vectorPtr[i];
    }
    vectorPtr[position] = value;
    
    // clean up
    m_size++;
    
    return true;
}

/*
    Purpose:    Erase a position somwhere in the vector. 0 is the start of the 
                vector

    Argurments: int position - The position to be erased from the vector

    Return:     true if erasing was successfull, false if it was not successful 
*/
bool vector::erase(int position){
    debug(std::cout << "__vector::erase(int position)__" <<  " pos: " << position << std::endl);

    // Checks position validity
    if(position >= m_size || position < 0){   // size should never be more than capacity, only =      
        std::cout << "[ERROR vector::erase() ] -> position < 1 || position > m_size " << std::endl;
        return false;
    } 

    // moves back everthing after position
    for(int i = position; i < m_size - 1; i++){
        vectorPtr[i] = vectorPtr[i + 1];
    }
    vectorPtr[m_size - 1] = -1;
    
    // clean up
    m_size--;
    if(m_size <= m_capacity * 0.75 ){
        this->downSize();
    }
    
    return true;
}

/*
    Purpose:    searches for value in the vector

    Argurments: int value - The value to be searched for

    Return:     position of the value, or -1 if couldn't be found 
*/
int vector::search(int value){
    debug(std::cout << "__vector::search(int value)__" << std::endl);


    if(m_size < 1){         
        std::cout << "[ERROR vector::search() ] -> m_size < 1 " << std::endl;
        return -1;
    }

    for(int position = 0; position < m_size; position++){
        if(vectorPtr[position] == value){
            return position;
        }
    }

    std::cout << "[ vector::search(int value) ]: " << value << " could not be found" << std::endl;
    return -1;
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
    Purpose:    To return the first position in the vector

    Return:     the first position of the vector
*/
int* vector::frontPosition(){
    // if vectorPtr != Null
    return vectorPtr;
}


/*
    Purpose:    To return the last value in the vector

    Return:     the last value of the vector
*/
int vector::back(){
    if(m_size >= 1){
        return vectorPtr[m_size - 1];

    }

    std::cout << "[ ERROR (int vector::back()): Vector size is <1 ] " << std::endl;

    return -1;  // needs to be null or error
}


/*
    Purpose:    To return the last position in the vector

    Return:     the last position of the vector or a NULL pointer
*/
int vector::backPosition(){
    if(m_size >= 1){
        return m_size - 1;
    }

    std::cout << "[ ERROR (int* vector::backPosition()): Vector size is <1 ] " << std::endl;

    return -1;  // needs to be null or error

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
    debug(std::cout << "__vector::print()__" << std::endl);

    std::string results = "";

    for(int i = 0; i < m_size; i++){
        // vectorString.append(vectorPtr[i]);
        results += std::to_string(vectorPtr[i]);
        results += ", ";
    }

    if (!results.empty()) {
        results.pop_back();
        results.pop_back();
    } else {
        std::cout << "[ EMPTY VECTOR ]";
    }
    
    std::cout << results << std::endl;
}

