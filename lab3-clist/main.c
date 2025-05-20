#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int *data;
  int length;
  int capacity;
} List;

List *new_list(int initial_capacity)
{
  List *list = malloc(sizeof(List));

  if (list == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  *list = (List){
      .data = malloc(sizeof(int) * initial_capacity),
      .length = 0,
      .capacity = initial_capacity,
  };

  // list->data = malloc(sizeof(int) * initial_capacity);
  // list->length = 0;
  // // (*list).length = 0;
  // list->capacity = initial_capacity;

  return list;
}

void free_list(List *list)
{
  free(list->data);
  free(list);
}

void list_append(List *list, int value)
{
  // check if the list is full
  if (list->length >= list->capacity)
  {
    list->capacity *= 2; // double the capacity

    // re-allocate memory for the data array
    list->data = realloc(list->data, sizeof(int) * list->capacity);

    // check if reallocation was successful
    if (list->data == NULL)
    {
      fprintf(stderr, "Memory reallocation failed\n");
      exit(EXIT_FAILURE);
    }
  }
  list->data[list->length++] = value;
}

void list_remove_last(List *list)
{
  list->length--;
}

int *list_get(List *list, int index)
{
  if (index < 0 || index >= list->length)
  {
    fprintf(stderr, "Index out of bounds\n");
    exit(EXIT_FAILURE);
  }

  // return &list->data[index];
  return list->data + index;
}

void list_set(List *list, int index, int value)
{
  if (index < 0 || index >= list->length)
  {
    fprintf(stderr, "Index out of bounds\n");
    exit(EXIT_FAILURE);
  }

  list->data[index] = value;
}

char *list_to_string(List *list)
{
  char *result = malloc(2);
  result[0] = '[';
  result[1] = '\0';
  for (int i = 0; i < list->length; i++)
  {
    char buffer[20];
    snprintf(buffer, sizeof(buffer), "%d", list->data[i]);
    result = realloc(result, strlen(result) + strlen(buffer) + 3);
    strcat(result, buffer);
    if (i < list->length - 1)
      strcat(result, ", ");
  }
  return strcat(result, "]");
}

int main()
{
  List *list = new_list(2);
  list_append(list, 1);
  list_append(list, 2);
  list_append(list, 3);
  list_append(list, 4);
  list_append(list, 5);

  printf("List: %s\n", list_to_string(list));

  printf("Element at index 2: %d\n", *list_get(list, 2));

  list_remove_last(list);
  printf("List after removing last element: %s\n", list_to_string(list));

  free_list(list);

  return 0;
}