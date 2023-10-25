/*////////////////////////////////
        列表（类似vector）
/////////////////////////////////*/

#include <stdio.h>
#include <stdlib.h>
typedef struct  {
    int *arr;       // 数组元素
    int capacity;   // 列表容量
    int size;       // 列表大小
    int extenRatio; // 列表每次扩容的倍数
} MyList;

// 构造函数
MyList *newMyList() {
    MyList *nums = malloc(sizeof(MyList));
    nums->capacity = 10;
    nums->arr = malloc(sizeof(int) * nums->capacity);
    nums->size = 0;
    nums->extenRatio = 2;
    return nums;
}

// 析构函数
void delMyList(MyList *nums) {
    free(nums->arr);
    free(nums);
}

/* 列表扩容 */
void extendCapacity(MyList *nums) {
    // 分配空间
    int newCapacity = capacity(nums) * nums->extenRatio;
    int *extend = (int *)malloc(sizeof(int) * newCapacity);
    int *temp = nums->arr;

    // 复制旧的数据到新的列表中
    for(int i = 0; i < size(nums); i++) {
        extend[i] = nums->arr[i];
    }
    // 释放旧的数据
    free(temp);
    // 更新新的数据
    nums->arr = extend;
    nums->capacity = newCapacity;
}

////////////成员函数////////////
/* 获取列表长度 */
int size(MyList *nums) {
    return nums->size;
}

/* 获取列表容量 */
int capacity(MyList *nums) {
    return nums->capacity;
}

/* 访问元素 */
int get(MyList*nums, int index) {
    return nums->arr[index];
}

/* 更新元素 */
void set(MyList *nums, int index, int num) {
    nums->arr[index] = num;
}

/* 添加尾部元素 */
void add(MyList *nums, int num) {
    if(size(nums) == capacity(nums)) {
        extendCapacity(nums); // 扩容
    }
    nums->arr[size(nums)] = num;
    nums->size++;
}

/* 中间插入元素 */
void insert(MyList *nums, int index, int num) {
    // 元素超出容量的时候扩容
    if(size(nums) == capacity(nums)) {
        extendCapacity(nums);
    }
    for (int i = size(nums); i > index; --i) {
        nums->arr[i] = nums->arr[i -1];
    }
    nums->arr[index] = num;
    nums->size++;
}

/* 删除元素 */
int removeNum(MyList *nums, int index) {
    int num = nums->arr[index];
    for(int i = index; i < size(nums) - 1; i++) {
        nums->arr[i] = nums->arr[i+1];
    }
    nums->size--;
    return num;
}

/* 列表转换为Array用于打印 */
int *toArray(MyList *nums) {
    return nums->arr;
}

int main() {
    MyList *mylist = newMyList();
    for(int i = 0; i < 20; i++){
        add(mylist, i);
    }
    void *arr = toArray(mylist);
    int *t = arr;
    for(int i = 0; i < mylist->size; i++){
        printf("%d ", t[i]);
    }
    return 0;
}