#include <stdlib.h>

#define VECTOR_INIT_CAPACITY 6
#define UNDEFINED -1
#define SUCCESS 0

#define VECTOR_INIT(vec) vector vec;\
 vector_init(&vec)

// Store and track the stored data
typedef struct sVectorList
{
    void **items;
    int capacity;
    int total;
} sVectorList;

// Structure contain the function pointer
typedef struct sVector vector;
struct sVector
{
    sVectorList vectorList;
    // function pointers
    int (*pfVectorTotal)(vector *);
    int (*pfVectorResize)(vector *, int);
    int (*pfVectorAdd)(vector *, void *, int (*pfVectorResize)(vector *, int));
    int (*pfVectorSet)(vector *, int, void *);
    void *(*pfVectorGet)(vector *, int);
    int (*pfVectorDelete)(vector *, int,  int (*vectorResize)(vector *, int));
    int (*pfVectorFree)(vector *);
};

void vector_init(vector *);
static int vectorResize(vector *v, int capacity);
int vectorPushBack(vector *v, void *item, int (*pfVectorResize)(vector *, int));
int vectorSet(vector *v, int index, void *item);
void *vectorGet(vector *v, int index);
int vectorDelete(vector *v, int index,  int (*vectorResize)(vector *, int));
int vectorFree(vector *v);
int vectorTotal(vector *v);



