#include "vector.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i =0;
    //init vector
    VECTOR_INIT(v);
    //Add data in vector
    v.pfVectorAdd(&v,"aticleworld.com\n", v.pfVectorResize);
    v.pfVectorAdd(&v,"amlendra\n", v.pfVectorResize);
    v.pfVectorAdd(&v,"Pooja\n", v.pfVectorResize);
    //print the data and type cast it
    for (i = 0; i < v.pfVectorTotal(&v); i++)
    {
        printf("%s", (char*)v.pfVectorGet(&v, i));
    }
    //Set the data at index 0
    v.pfVectorSet(&v,0,"Apoorv\n");
    printf("\n\n\nVector list after changes\n\n\n");
    //print the data and type cast it
    for (i = 0; i < v.pfVectorTotal(&v); i++)
    {
        printf("%s", (char*)v.pfVectorGet(&v, i));
    }
    return 0;
}