#include <stdio.h>
#include <math.h>
void print_heap(int arr[], int n) {
    int height = ceil(log2(n));
    int i, j, k;

    for (i = 0, k = 1; i <= height; i++) {
        for (j = 0; j < pow(2, height - i) - 1; j++) {
            printf("  ");
        }

        for (j = 0; j < pow(2, i); j++, k++) {
            if (k > n) {
                break;
            }
            printf("%2d", arr[k - 1]);
            for (int l = 0; l < pow(2, height - i + 2) - 1; l++) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void build_heap(int a[],int size){

for(int i=(size-1)/2;i>=0;i--){

    max_heapify(a,size,i);
}


}

void max_heapify(int a[],int size,int i){
int left_child=(2*i)+1;
int right_child=(2*i)+2;
int max = i;

if(left_child<size && a[left_child]>a[max]){
    max=left_child;
}

if(right_child<size && a[right_child]>a[max]){
    max=right_child;
}

if(max != i){

    swap(&a[i],&a[max]);
    printf("\n\n");
    print_heap(a,size);
    max_heapify(a,size,max);

}


}

void swap(int *x,int *y){
int temp=*x;
*x=*y;
*y=temp;
}


int main() {
int a[]={1,2,3,4,5,6,7};
int size= sizeof(a)/sizeof(a[0]);
print_heap(a,size);
build_heap(a,size);

    return 0;
}
