 #include<stdio.h>
#include<stdlib.h> 

struct Box

{
int h, w, d;
};

int min (int x, int y)

{ return (x < y)? x : y; }


int max (int x, int y)

 
{ return (x > y)? x : y; }

int compare (const void *a, const void * b)

{

return ( (*(Box *)b).d * (*(Box *)b).w ) -



( (*(Box *)a).d * (*(Box *)a).w );

}

int maxStackHeight( Box arr[], int n )

{ 

Box rot[3*n];

int index = 0;

for (int i = 0; i < n; i++)
{
rot[index].h = arr[i].h;

rot[index].d = max(arr[i].d, arr[i].w);

rot[index].w = min(arr[i].d, arr[i].w);


index++;
 
// First rotation of box

rot[index].h = arr[i].w;

rot[index].d = max(arr[i].h, arr[i].d);

rot[index].w = min(arr[i].h, arr[i].d);

index++;

// Second rotation of box

rot[index].h = arr[i].d;

rot[index].d = max(arr[i].h, arr[i].w);

rot[index].w = min(arr[i].h, arr[i].w);

index++;

}

n = 3*n;

/* Sort the array 'rot[]' in non-increasing order

of base area */

qsort (rot, n, sizeof(rot[0]), compare);

// Uncomment following two lines to print all rotations

// for (int i = 0; i < n; i++ )

//	printf("%d x %d x %d\n", rot[i].h, rot[i].w, rot[i].d);

/* Initialize msh values for all indexes

msh[i] --> Maximum possible Stack Height with box i on top */

int msh[n];

for (int i = 0; i < n; i++ ) 

msh[i] = rot[i].h;

/* Compute optimized msh values in bottom up manner */

for (int i = 1; i < n; i++ )

for (int j = 0; j < i; j++ )

if ( rot[i].w < rot[j].w &&

rot[i].d < rot[j].d &&

msh[i] < msh[j] + rot[i].h

)
{
msh[i] = msh[j] + rot[i].h;
}
 

/* Pick maximum of all msh values */

int max = -1;

for ( int i = 0; i < n; i++ )

if ( max < msh[i] )
max = msh[i];

return max;

}
/* Driver program to test above function */

int main()

{
Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12function

int n = sizeof(arr)/sizeof(arr[0]);
 
printf("The maximum possible height of stack is %d\n",

maxStackHeight (arr, n) );

return 0;

}
