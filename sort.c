#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int comparator(char *x, char *y);
void quicksort(char **str, int size);
void bubblesort(char **str, int size);
void insertion(char **str, int size);
void mergesort(char **str, int n, int m);
void merge(char **arr, int n, int j, int m);


void main(int argc, char **argv) {

 FILE *file; 
 if ((file = fopen(argv[2],"r")) == NULL) { //открываем файл и проверяем.
  printf("Не получается открыть файл.\n");
  exit(1);
 }

 int size = atoi(argv[1]); //получаем количество строк,которое нужно проверять.
 char ch = 0;
 int sum = 0;  
 while(ch!=EOF) { //узнаем реальное количество строк.
  ch = fgetc(file);
  if(ch == '\n') { 
  sum++;
  } 
 }
 
 if (size > sum) { //если реальное количество строк меньше того количества,которое нужно прочитать.
  size = sum;
 }

 rewind(file);

 int *len = malloc(sizeof(int)*(size)); // выделяем память под количество символов в каждой строке.
 
 int i = 0, k = 0,f = 0; 	
 while(f!=size) { //заполняем массив количествами символов в каждой строке.
  ch = fgetc(file);	
  k++;
  if (ch == '\n' || ch == '\0') {
   len[i] = k;
   k = 0;
   i++;
   f++;
  }	
 }
 

 char **str = malloc(sizeof(char*)*(size));//выделяем память для самих строками.

 rewind(file);

 int p = 0;
 while(p < size) { //заполняем массив строками(по символу).
  int t = 0;
  str[p] = malloc(sizeof(char)*(len[p]));
  for(t = 0; t < len[p]-1; t++) {
   str[p][t] = fgetc(file);
  }
  ch = fgetc(file);
  str[p][t] = '\0';
  p++;
 }

 fclose(file);

printf("\nвыберите способ сортировки:\n1) bubble sort\n2) insertion sort\n3) quick sort\n4) merge sort\n"); 

 int t = 0,w = 0;
 while(!w) { //пользователь выбирает способ сортировки.
  scanf("%d",&t);
  switch(t) {
   case 1:
   bubblesort(str,size);
   w = 1;
   break;
      
   case 2:
   insertion(str,size);
   w = 1;
   break;

   case 3: 
   quicksort(str,size-1); 
   w = 1;    
   break;
  
   case 4:
   mergesort(str,0,size-1);
   w = 1;
   break;

   default:
   printf("такого варианта нет\n");
   break;
  }
 }
 
 printf("Отсортированный массив:\n"); //программа выводит отсортированный массив.
 for (i = 0; i < size; i++) {
  printf("%s\n", str[i]);
 }

 for (i = 0; i < size; i++)//освобождаем всю выделенную память.
  free(str[i]);

 free(len);
 free(str);
}

int comparator (char *x, char *y) { //компаратор для строк.
 int i = 0;
 while((x[i]!= '\0')&&(y[i]!= '\0')) {
  if (x[i] > y[i]) {
   return 1;
  }
  if (x[i] < y[i]) {
   return 0;
  }
  i++;
 }
 if (x[i] == '\0') {
  return 0;
 }
 if (y[i] == '\0') {
  return 1;
 }
 }


void bubblesort(char **str, int size) { //сортировка пузыриком.
 int x = 0,y = 0;
 for (x = 0; x < size-1; x++) {
  for (y = 0; y < size-1; y++) {
   if (comparator(str[y], str[y+1]) > 0) {
    char *strN = str[y];
    str[y] = str[y+1];
    str[y+1] = strN;
   }
  }
 }
}

void insertion(char **str, int size) { //сортировка вставками.
 int x = 0,y = 0;
 for(x = 1; x < size; x++) {
  for(y = x; y > 0 && comparator(str[y-1], str[y]) > 0; y--) {
   char *strN = str[y];
   str[y] = str[y-1];
   str[y-1] = strN;
  }
 }
}

void quicksort(char **str, int size) { //быстрая сортировка.
 char *elem;
 elem = str[size / 2];
 int x = 0, y = size;
 while(x <= y) {
  while(comparator(elem, str[x]))
   x++;
  while(comparator(str[y], elem))
   y--;
  if (x <= y) {
   char *strN = str[x];
   str[x] = str[y];
   str[y] = strN;
   x++;
   y--;
  }
 }
 if (y > 0)
  quicksort(str, y);
 if (size > x)
  quicksort(str + x, size - x);
}

void mergesort(char **str, int n, int m) {//Сортировка слиянием.
 if (n < m) {
  int q = (m+n)/2;
  mergesort(str, n, q);
  mergesort(str, q+1, m); 
  merge(str, n, q, m);
 }
}

void merge(char **str, int n, int q, int m) {
 int i, j, k;
 int n1 = q-n+1;
 int n2 = m-q;

 char *Left[n1], *Right[n2]; 
 for (i = 0; i < n1; i++) {
  Left[i] = str[n+i];
 }
 for (j = 0; j < n2; j++) {
  Right[j] = str[q+1+j];
 }

 i = 0; 
 j = 0;
 k = n;
 while (i < n1 && j < n2) {
  if (comparator(Left[i], Right[j]) <= 0) {
   str[k] = Left[i];
   i++;
  }
  else{
   str[k] = Right[j];
   j++;
  }
  k++;
 }

 while (i < n1) {
  str[k] = Left[i];
  i++;
  k++;
 }

 while (j < n2) {
  str[k] = Right[j];
  j++;
  k++;
 }
}

