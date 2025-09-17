#include <stdio.h>
#define MAX 0xA

typedef struct{
    int Arr[MAX];
    int size;
}ArrayList;

void display(ArrayList list)
{
    // Displayyy
    if(list.size==0){
        printf("List is Empty\n");
    }else{
        for(int i=0; i<list.size-1; i++){
            printf("%d->", list.Arr[i]);
        }
        printf("%d", list.Arr[list.size-1]);
        printf("\n\n");
    }
}

// Delete the first element
int DeleteFirst(ArrayList *list)
{
    // Delete the first element
    if(list->size == 0){
        printf("Cannot delete from empty list\n");
        return -1; // Error code
    }
    
    int deletedValue = list->Arr[0];
    
    // Shift all elements to the left
    for(int i = 0; i < list->size - 1; i++){
        list->Arr[i] = list->Arr[i + 1];
    }
    
    list->size--;
    return deletedValue;
}

// Delete the last element
int DeleteLast(ArrayList *list)
{
    if(list->size == 0){
        printf("Cannot delete from empty list\n");
        return -1; // Error code
    }
    
    int deletedValue = list->Arr[list->size - 1];
    list->size--;
    return deletedValue;
}

// Delete element at specific position
int DeletePosition(ArrayList *list, int position)
{
    if(list->size == 0){
        printf("Cannot delete from empty list\n");
        return -1;
    }
    
    if(position < 0 || position >= list->size){
        printf("Invalid position\n");
        return -1;
    }
    
    int deletedValue = list->Arr[position];
    
    // Shift elements to fill the gap
    for(int i = position; i < list->size - 1; i++){
        list->Arr[i] = list->Arr[i + 1];
    }
    
    list->size--;
    return deletedValue;
}

// Delete all unique elements (elements that appear only once)
void DeleteAllUnique(ArrayList *list)
{
    if(list->size == 0){
        printf("List is empty\n");
        return;
    }
    
    int newSize = 0;
    int tempArr[MAX];
    
    // Count occurrences of each element
    for(int i = 0; i < list->size; i++){
        int count = 0;
        
        // Count how many times current element appears
        for(int j = 0; j < list->size; j++){
            if(list->Arr[i] == list->Arr[j]){
                count++;
            }
        }
        
        // Keep only non-unique elements (appear more than once)
        if(count > 1){
            tempArr[newSize++] = list->Arr[i];
        }
    }
    
    // Copy back to original array
    for(int i = 0; i < newSize; i++){
        list->Arr[i] = tempArr[i];
    }
    
    list->size = newSize;
}

// Helper function to insert elements for testing
void insert(ArrayList *list, int value)
{
    if(list->size < MAX){
        list->Arr[list->size++] = value;
    } else {
        printf("List is full\n");
    }
}

void main()
{
    ArrayList list;
    list.size = 0;
    
    // Test the functions
    printf("Inserting elements...\n");
    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    insert(&list, 2);
    insert(&list, 4);
    insert(&list, 3);
    insert(&list, 3);
    insert(&list, 5);
    
    printf("Original list: ");
    display(list);
    
    printf("Deleting first element (%d)\n", DeleteFirst(&list));
    printf("List after DeleteFirst: ");
    display(list);
    
    printf("Deleting last element (%d)\n", DeleteLast(&list));
    printf("List after DeleteLast: ");
    display(list);
    
    printf("Deleting element at position 2 (%d)\n", DeletePosition(&list, 2));
    printf("List after DeletePosition(2): ");
    display(list);
    
    // Reset list for DeleteAllUnique test
    list.size = 0;
    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    insert(&list, 2);
    insert(&list, 4);
    insert(&list, 3);
    insert(&list, 3);
    insert(&list, 5);
    
    printf("Reset list for DeleteAllUnique test: ");
    display(list);
    
    DeleteAllUnique(&list);
    printf("List after DeleteAllUnique: ");
    display(list);
}