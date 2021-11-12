#include "vector.h"

void vector_init(vector *v)
{
    // init function pointers
    v->pfVectorTotal = vectorTotal;
    v->pfVectorResize = vectorResize;
    v->pfVectorAdd = vectorPushBack;
    v->pfVectorSet = vectorSet;
    v->pfVectorGet = vectorGet;
    v->pfVectorFree = vectorFree;
    v->pfVectorDelete = vectorDelete;
    // inittialize the capacity and allocate the memory
    v->vectorList.capacity = VECTOR_INIT_CAPACITY;
    v->vectorList.total = 0;
    v->vectorList.items = malloc(sizeof(void *) * v->vectorList.capacity);
}

static int vectorResize(vector *v, int capacity)
{
    int status = UNDEFINED;
    if (v)
    {
        void **items = realloc(v->vectorList.items, sizeof(void *) * capacity);
        if (items)
        {
            v->vectorList.items = items;
            v->vectorList.capacity = capacity;
            status = SUCCESS;
        }
    }
    return status;
}

int vectorPushBack(vector *v, void *item, int (*pfVectorResize)(vector *, int))
{
    int status = UNDEFINED;
    if (v)
    {
        sVectorList vl = v->vectorList;
        if (vl.capacity == vl.total)
        {
            status = pfVectorResize(v, vl.capacity * 2);
            if(status != UNDEFINED)
            {
                vl.items[vl.total++] = item;
            }
        }
        else
        {
            vl.items[v->vectorList.total++] = item;
            status = SUCCESS;
        }
        return status;
    }
    return status;
}

int vectorSet(vector *v, int index, void *item)
{
    int status = UNDEFINED;
    if (v)
    {
        if ((index >= 0) && (index < v->vectorList.total))
        {
            v->vectorList.items[index] = item;
            status = SUCCESS;
        }
    }
    return status;
}

void *vectorGet(vector *v, int index)
{
    void *readData = NULL;
    if(v)
    {
        if ((index >= 0) && (index < v->vectorList.total))
        {
            readData = v->vectorList.items[index];
        }
    }
    return readData;
}

int vectorDelete(vector *v, int index, int (*pfVectorResize)(vector *, int))
{
    int  status = UNDEFINED;
    int i = 0;
    if(v)
    {
        if ((index < 0) || (index >= v->vectorList.total))
            return status;
        v->vectorList.items[index] = NULL;
        for (i = index; (i < v->vectorList.total - 1); ++i)
        {
            v->vectorList.items[i] = v->vectorList.items[i + 1];
            v->vectorList.items[i + 1] = NULL;
        }
        v->vectorList.total--;
        if ((v->vectorList.total > 0) && ((v->vectorList.total) == (v->vectorList.capacity / 4)))
        {
            pfVectorResize(v, v->vectorList.capacity / 2);
        }
        status = SUCCESS;
    }
    return status;
}

int vectorFree(vector *v)
{
    int  status = UNDEFINED;
    if(v)
    {
        free(v->vectorList.items);
        v->vectorList.items = NULL;
        status = SUCCESS;
    }
    return status;
}


int vectorTotal(vector *v)
{
    int totalCount = UNDEFINED;
    if(v)
    {
        totalCount = v->vectorList.total;
    }
    return totalCount;
}