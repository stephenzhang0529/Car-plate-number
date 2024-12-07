#ifndef SQLIST_H
#define SQLIST_H
#include <iostream>

#define MaxSize 100

using namespace std;

template<class Data>
class SeqList
{
private:
    Data* datas;    // 顺序表中的元素
    int size;      // 顺序表的长度
    int capacity;  // 顺序表当前容量
public:
    SeqList();
    ~SeqList();                         //析构函数
    int Size();                         // 求顺序表的长度
    bool SqList_push(Data e);           // 插入元素
    Data* SqList_at(int idx);            // 获取指定元素
    Data* SqList_front();                // 获取首位元素
    Data* SqList_back();                 // 获取末位元素
    bool SqList_delete(int idx);          // 删除顺序表中第i号元素
    bool SqList_empty();                // 判断是否为空
    bool SqList_grow();                 // 扩展顺序表
};

template<class Data>
SeqList<Data>::SeqList()
{
    datas = new Data[MaxSize];
    size = 0;
    capacity = MaxSize;
}

template<class Data>
SeqList<Data>::~SeqList()
{
    delete[]datas;
}

template<class Data>
int SeqList<Data>::Size()
{
    return size;
}

template<class Data>
bool SeqList<Data>::SqList_grow()
{
    int newCapacity = capacity * 1.5;    //扩大1.5倍
    Data* temp = new Data[newCapacity];

    for (int i = 0; i < size; i++)
        temp[i] = datas[i];

    delete[] datas;
    datas = temp;
    capacity = newCapacity;
    return true;
}

template<class Data>
bool SeqList<Data>::SqList_push(Data e)
{
    //判断顺序表是否已满,若已满则扩容失败
    if (capacity == size && !SqList_grow())
    {
        return false;
    }
    datas[size] = e;
    size++;

    return true;
}

template<class Data>
Data* SeqList<Data>::SqList_at(int idx)
{
    if (idx < 0 || idx >= size) // 检查索引范围
        return nullptr;
    return &datas[idx];
}

template<class Data>
Data* SeqList<Data>::SqList_front()
{
    return &datas[0];
}

template<class Data>
Data* SeqList<Data>::SqList_back()
{
    return &datas[size - 1];
}

template<class Data>
bool SeqList<Data>::SqList_delete(int idx)
{
    if (idx < 0 || idx >= size) // 检查索引范围
        return false;

    for (int i = idx + 1; i < size; i++)
    {
        datas[i - 1] = datas[i];
    }
    size -= 1;
    return true;
}

template<class Data>
bool SeqList<Data>::SqList_empty()
{
    return size == 0;
}

#endif // SQLIST_H
