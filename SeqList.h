#ifndef SQLIST_H
#define SQLIST_H
#include <iostream>

#define MaxSize 100

using namespace std;

template<class Data>
class SeqList
{
private:
    Data* datas;    // ˳����е�Ԫ��
    int size;      // ˳���ĳ���
    int capacity;  // ˳���ǰ����
public:
    SeqList();
    ~SeqList();                         //��������
    int Size();                         // ��˳���ĳ���
    bool SqList_push(Data e);           // ����Ԫ��
    Data* SqList_at(int idx);            // ��ȡָ��Ԫ��
    Data* SqList_front();                // ��ȡ��λԪ��
    Data* SqList_back();                 // ��ȡĩλԪ��
    bool SqList_delete(int idx);          // ɾ��˳����е�i��Ԫ��
    bool SqList_empty();                // �ж��Ƿ�Ϊ��
    bool SqList_grow();                 // ��չ˳���
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
    int newCapacity = capacity * 1.5;    //����1.5��
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
    //�ж�˳����Ƿ�����,������������ʧ��
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
    if (idx < 0 || idx >= size) // ���������Χ
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
    if (idx < 0 || idx >= size) // ���������Χ
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
