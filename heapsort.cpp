#include<stdio.h>
#include<stdlib.h>
int heapsize;
void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int left(int i){
    return 2*i+1;
}
int right(int i){
    return 2*i+2;
}

void max_heapify(int * a, int i)
{
    int l=left(i);
    int r=right(i);
    int largest=i;
    if (l<heapsize&&a[l]>a[largest])
        largest=l;
    if (r<heapsize&&a[r]>a[largest])
        largest=r;
    if (largest!=i){
        swap(&a[i],&a[largest]);
        max_heapify(a,largest);
    }
}
void build_max_heap(int n,int *a){
    heapsize=n;
    for (int i=n/2;i>=0;i--){
        max_heapify(a,i);
    }
}
void heapsort(int n,int *a){
    build_max_heap(n,a);
    for (int i=n-1;i>=0;i--){
        swap(&a[i],&a[0]);
        heapsize--;
        max_heapify(a,0);
    }
}
int main(void){
    int a[9]={6,23,8,3,5,1,87,44,27};
    int n=9;
    heapsort(n,a);
    for (int i=0;i<=8;i++){
        printf("%d ",a[i]);
    }
    system("pause");
    return 0;
}