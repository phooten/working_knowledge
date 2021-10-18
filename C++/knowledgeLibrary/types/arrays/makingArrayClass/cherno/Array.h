#ifndef ARRAY_H
#define ARRAY_H


template<typename T, size_t S>   
class Array{
public:
    constexpr size_t Size() const { return S; }                         // Returns Size
    T& operator[](size_t index){ return m_Data[index]; }                // allows acces with indices
    const T& operator[](size_t index) const { return m_Data[index]; }   // allows reading const Arrays

    T* Data() { return m_Data; }
    const T* Data() const { return m_Data; }

private:
    // Variables
    T m_Data[S];

};



#endif // ARRAY_H