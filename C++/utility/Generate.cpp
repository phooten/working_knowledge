#include"Generate.h"

Generate::Generate(){
    m_arrPtr = NULL;
    m_arrayLength = 0;

}

Generate::~Generate(){
    if(m_arrPtr != NULL)
        delete [] m_arrPtr;
    
}

int* Generate::Array(int length=DEFAULT_LENGTH, int max=DEFAULT_MAX){
    // Variables
    int randNum;
    m_arrayLength = length;
    m_arrPtr = new int[m_arrayLength];      // Gets deleted in main 
    

    // Fills array with random numbers
    for(int i = 0; i < length; i++){
        randNum = rand() % max;
        m_arrPtr[i] = randNum; 
    }
    
    return m_arrPtr;
}

void Generate::PrintArray(){
    if(m_arrPtr == NULL){
        std::cout << "EMPTY ARRAY\n";
        return;
    }

    for(int i = 0; i < m_arrayLength - 1; i++){
        std::cout << m_arrPtr[i] << ", ";
    }
    std::cout << m_arrPtr[m_arrayLength];
    std::cout << "\n";
}
