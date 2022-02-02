#include<iostream>
using namespace std;
template<class T>
class vector
{
private:
    T*buffer;
    int my_size;
    int my_capacity;
public:
    vector();
    vector(T a);
    vector(int size, const T  initial);
    vector(const vector<T> &v);
    T operator[](int index);   
    void display();
    T at(int index);
    void empty();
    void resize(int size);
    void shrink_to_fit();
    void assign(int n, T ele);
    T*data();
    T*begin();
    T*end();
    T front();
    T back();
    int size();
    int capacity();
    void push_back(T a);
    void pop_back();
    void reverse();
    void insert(T pos, T ele);
    void erase(int pos);
    void emplace(T pos,T ele);
    void emplace_back(T ele);
    void clear();
    ~vector();
};

template<class T>
vector<T>::vector()
{
    my_size = 0;
    my_capacity = 1;
    buffer = new T[my_capacity];
}

template<class T>
vector<T>::vector(T size)
{
    my_size = size;
    my_capacity = size;
    buffer = new T[my_size];
}

template<class T>
vector<T>::vector(const vector<T> &v)
{
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T[my_size];  
    for (int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];  
}

template<class T>
vector<T>::vector(int size, const T  initial)
{
    my_size = size;
    my_capacity = size;
    buffer = new T [size];
    for (unsigned int i = 0; i < size; i++)
    {
        buffer[i] = initial;
    }
}
template<class T>
T vector<T>::at(int index)
{
    if(index>=0 && index<my_size)
    {
        return *(buffer+index);
    }
}
template<class T>
void vector<T>::empty()
{
    if(my_size==0)
    {
        cout<<"The given vector is empty!\n";
    }
    else
    {
        cout<<"The given vector is not empty!\n";
    }
}
template<class T>
void vector<T>::resize(int x)
{
    my_size = x;
}
template<class T>
void vector<T>::shrink_to_fit()
{
    my_capacity = my_size;
}
template<class T>
T*vector<T>::data()
{
    return buffer;
}
template<class T>
void vector<T>::reverse()
{
    int i,j;
    for(i=0, j=my_size-1;i<j;i++,j--)
    {
        T temp;
        temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
    }
}

template<class T>
T vector<T>::operator[](int index)
{
    if(index>=my_size)
    {
        cout<<"Error: Index out of boundary!"<<endl;
    }
    else
    {
        return *(buffer+index);
    }
}

template<class T>
void vector<T>::display()
{
    cout<<"The vector is: ";
    for(int i=0;i<my_size;i++)
    {
        cout<<buffer[i]<<" ";
    }
    cout<<endl;
}

template<class T>
void vector<T>::assign(int n, T ele)
{
    buffer = new T[n];
    for(int i=0;i<n;i++)
    {
        buffer[i] = ele;
    }
}

template<class T>
T*vector<T>::begin()
{
    return buffer;
}

template<class T>
T*vector<T>::end()
{
    return buffer + size();
}

template<class T>
T vector<T>::front()
{
    return buffer[0];
}

template<class T>
T vector<T>::back()
{
    return buffer[my_size-1];
}

template<class T>
int vector<T>::size()
{
    return my_size;
}

template<class T>
int vector<T>::capacity()
{
    return my_capacity;
}

template<class T>
void vector<T>::push_back(T  ele)
{
    if (my_size == my_capacity) 
    {
        T* temp = new T[2 * my_capacity];
 
        // copying old array elements to new array
        for (int i = 0; i < my_capacity; i++) 
        {
            temp[i] = buffer[i];
        }
        // deleting previous array
        delete[] buffer;
        my_capacity *= 2;
        buffer = temp;
    }
 
    // Inserting data
    buffer[my_size] = ele;
    my_size++;
}

template<class T>
void vector<T>::insert(T pos, T ele)
{
    if (my_size == my_capacity) 
    {
        T* temp = new T[2 * my_capacity];
 
        // copying old array elements to new array
        for (int i = 0; i < my_capacity; i++) 
        {
            temp[i] = buffer[i];
        }
        // deleting previous array
        delete[] buffer;
        my_capacity *= 2;
        buffer = temp;
    }
    for(int i=my_size-1;i>=pos;i--)
    {
        buffer[i+1] = buffer[i];
    }
    buffer[pos] = ele;
    my_size++;
}
template<class T>
void vector<T>::erase(int pos)
{
    for(int i=pos;i<=buffer[my_size-1];i++)
    {
        buffer[i] = buffer[i+1];
    }
    my_size--;
}
template<class T>
void vector<T>::emplace(T pos, T ele)
{
    if (my_size == my_capacity) 
    {
        T* temp = new T[2 * my_capacity];
 
        // copying old array elements to new array
        for (int i = 0; i < my_capacity; i++) 
        {
            temp[i] = buffer[i];
        }
        // deleting previous array
        delete[] buffer;
        my_capacity *= 2;
        buffer = temp;
    }
    for(int i=my_size-1;i>=pos;i--)
    {
        buffer[i+1] = buffer[i];
    }
    buffer[pos] = ele;
    my_size++;
}

template<class T>
void vector<T>::emplace_back(T ele)
{
    if (my_size == my_capacity) 
    {
        T* temp = new T[2 * my_capacity];
 
        // copying old array elements to new array
        for (int i = 0; i < my_capacity; i++) 
        {
            temp[i] = buffer[i];
        }
        // deleting previous array
        delete[] buffer;
        my_capacity *= 2;
        buffer = temp;
    }
 
    // Inserting data
    buffer[my_size] = ele;
    my_size++;
}

template<class T>
void vector<T>::pop_back()
{
    if (my_size == my_capacity) 
    {
        T* temp = new T[my_capacity/2];
 
        // copying old array elements to new array
        for (int i = 0; i < my_capacity; i++) 
        {
            temp[i] = buffer[i];
        }
        // deleting previous array
        delete[] buffer;
        my_capacity = my_capacity/2;
        buffer = temp;
    }
    my_size--;
}

template<class T>
void vector<T>::clear()
{
    my_size = 0;
    my_capacity = 1;
    buffer = new T[my_capacity];
}

template<class T>
vector<T>::~vector()
{
    delete [] buffer;
}
//driver code
int main()
{
    vector<int>v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.display();
    v.insert(0,100);
    v.display();
    v.emplace_back(1000);
    v.display();
    vector<int>v2(5,6);
    v2.display();
    cout<<v2.capacity()<<endl;
    v2.resize(3);
    v2.display();
    v2.shrink_to_fit();
    cout<<v2.capacity()<<endl;
    v.pop_back();
    v.display();
    return 0;
}
