/*struktutra ot danni, koito sa podredeni podred v pametta - masiv
index - koeficient na otmestvane s golemina na tipa ot danni ot nachalniq pointer
pri uvelichavane na kapaciteta se zadelq nova pamet, masivut se kopira v novata pamet i se osvobojdava starata
snake case - pop_back
kebap - pop-back
pascal - PopBack
camael = popBack
moje da e .cpp i .cc */
#include <iostream>

using namespace std;

struct vector_t {
    int* data;
    size_t size;
    size_t capacity;
};

typedef struct vector_t vector_t;

vector_t* init();
void destroy(vector_t* vector);
void push_back(vector_t* vector, int value);
void resize(vector_t* vector);
int pop_back(vector_t* vector);
int at(vector_t* vector, int index);
int pop(vector_t* vector, int value);
void insert(vector_t* vector, int index, int value);

int main() {

    return 0;
}

vector_t* init() {
    vector_t* vector = new vector_t;
    vector->capacity = 2;
    vector->size = 0;
    vector->data = new int[vector->capacity];

    return vector;
}

void destroy(vector_t* vector) {
    delete[] vector->data;
    delete vector;
}

void push_back(vector_t* v, int value) {
    if(v->size == v->capacity)
        resize(v, v->capacity * 2);

    v->data[v->size++] = value;
}

void resize(vector_t *v, size_t newCapacity) {
    v->capacity = newCapacity;

    int* newArr = new int[v->capacity];

    for(size_t i = 0; i < v->size; i++)
        newArr[i] = v->data[i]; // *(v->data + i)

    delete[] v->data;
    v->data = newArr;
}

int pop_back(vector_t* v) {
    if(v->size == 0)
        return NULL;

    int value = v->data[v->size-1];

    if(v->size <= v->capacity / 2)
        resize(v, v->capacity / 2);

    return value;
}

int at(vector_t* v, int index) {

    if(index >= v->size)
        return NULL;
    
    if(index < 0) {
        if(-index <= v->size) 
            return NULL;
            
        return v->data[v->size + index];
    }
    
    return v->data[index];
}

int pop(vector_t* v, int value) {
    int* dynarrtemp = new int[v->size-1];
    bool found = false;

    for (int i = 0; i < v->size; i++) {
        if (dynamicArray[i] == value)
            found = true;
        if (found)
        dynarrtemp[i] = dynamicArray[i + 1];
        else
            dynarrtemp[i] = dynamicArray[i];
    }

    delete [] v->data;
    v->data = dynarrtemp;
    v->size--;
    if(v->size <= v->capacity / 2)
        resize(v, v->capacity / 2);
    
    return found;
}

void insert(vector_t* v, int index, int value) {
    if(index < 0 || index > v->size)
        return;

    if(v->size+1 == v->capacity)
        resize(v, v->capacity * 2);

    for(int i = v->size; i > index; i--)
        v->data[i] = v->data[i-1];

    v->data[index] = value;
    v->size++;
}