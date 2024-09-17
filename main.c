#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* elements;
    int size;
} ImmutableList;


ImmutableList* create_list(int* elements, int size) {
    ImmutableList* list = (ImmutableList*)malloc(sizeof(ImmutableList));
    list->size = size;
    list->elements = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        list->elements[i] = elements[i];
    }

    return list;
}


ImmutableList* add_element(ImmutableList* list, int index, int value) {
    if (index < 0 || index > list->size) {
        printf("Index out of bounds\n");
        return NULL;
    }


    ImmutableList* new_list = (ImmutableList*)malloc(sizeof(ImmutableList));
    new_list->size = list->size + 1;
    new_list->elements = (int*)malloc(new_list->size * sizeof(int));

    for (int i = 0; i < index; i++) {
        new_list->elements[i] = list->elements[i];
    }

    new_list->elements[index] = value;

    for (int i = index; i < list->size; i++) {
        new_list->elements[i + 1] = list->elements[i];
    }

    return new_list;
}


ImmutableList* remove_element(ImmutableList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        return NULL;
    }


    ImmutableList* new_list = (ImmutableList*)malloc(sizeof(ImmutableList));
    new_list->size = list->size - 1;
    new_list->elements = (int*)malloc(new_list->size * sizeof(int));

    for (int i = 0; i < index; i++) {
        new_list->elements[i] = list->elements[i];
    }

    for (int i = index + 1; i < list->size; i++) {
        new_list->elements[i - 1] = list->elements[i];
    }

    return new_list;
}


int get_element(ImmutableList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        return -1;
    }

    return list->elements[index];
}


void print_list(ImmutableList* list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->elements[i]);
    }
    printf("\n");
}


void free_list(ImmutableList* list) {
    free(list->elements);
    free(list);
}

int main() {
    int initial_elements[] = {1, 2, 3, 4};
    ImmutableList* list = create_list(initial_elements, 4);

    printf("Current List: ");
    print_list(list);


    ImmutableList* new_list = add_element(list, 2, 99);
    printf("New_List(after adding new elemnts): ");
    print_list(new_list);


    ImmutableList* updated_list = remove_element(new_list, 3);
    printf("List After remote elemnts: ");
    print_list(updated_list);


    int element = get_element(updated_list, 3);
    printf("Elements by number 2: %d\n", element);

    free_list(list);
    free_list(new_list);
    free_list(updated_list);

    return 0;
}
