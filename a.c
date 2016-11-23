#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

void bubblesort(char **str, int size);
void insertion(char **str, int size);
int cmp(const void *a, const void *b);
void mergesort(char **str, int n, int m);
void merge(char **arr, int n, int j, int m);


void main(int argc, char **argv){

 FILE *file; 
 if ( (file = fopen(argv[2],"r")) == NULL){
  printf("Не получается открыть файл.\n");
  exit(1);
 }//открытие файла и проверка

 int size = atoi(argv[1]);
 char ch = 0;
 int sum = 0;  
 while(ch!=EOF){
  ch = fgetc(file);
  if(ch == '\n'){
  sum++;
  } 
 }
 
 if (size > sum){
  size = sum;
 }//на случай если количество реальных строк отличается от количества нужных

 rewind(file);

 int *len = malloc(sizeof(int)*(size)); // выделяем память для массива с количеством символов в каждой строке
 
 int i = 0, k = 0,f = 0; 	
 while(f!=size){
  ch = fgetc(file);	
  k++;
  if (ch == '\n' || ch == '\0'){
   len[i] = k;
   k = 0;
   i++;
   f++;
  }	
 }//заполняем массив количествами символов строках

 

 char **str = malloc(sizeof(char*)*(size));//выделяем память для масива с самими строками

 rewind(file);

 int p = 0;
 while(p < size){
  int t = 0;
  str[p] = malloc(sizeof(char)*(len[p])); // выделяем память под саму строку
  for(t = 0; t < len[p]-1; t++){
   str[p][t] = fgetc(file);
  }
  ch = fgetc(file);
  str[p][t] = '\0';
  p++;
 }//заполняем **str строками по символу

 fclose(file);

 printf("\nвыберите способ сортировки:\n1) bubble sort\n2) insertion sort\n3) quick sort\n4) merge sort\n");

 int t = 0,w = 0;
 while(!w){
  scanf("%d",&t);
  switch(t){
   case 1:
   bubblesort(str,size);
   w = 1;
   break;
      
   case 2:
   insertion(str,size);
   w = 1;
   break;

   case 3: 
   qsort(str,size,sizeof(char*),cmp); 
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
 }//пользователь выбирает способ сортировки
 
 printf("Отсортированный массив:\n");
 for (i = 0; i < size; i++){
  printf("%s\n", str[i]);
 }//программа выводит отсортированный массив

 for (i = 0; i < size; i++)
  free(str[i]);

 free(len);
 free(str);
}

void bubblesort(char **str, int size){
 int x = 0,y = 0;
 for (x = 0; x < size-1; x++){
  for (y = 0; y < size-1; y++){
   if (strcmp(str[y], str[y+1]) > 0){
    char *strN = str[y];
    str[y] = str[y+1];
    str[y+1] = strN;
   }
  }
 }
}// пузырик

void insertion(char **str, int size){
 int x = 0,y = 0;
 for(x = 1; x < size; x++){
  for(y = x; y > 0 && strcmp(str[y-1], str[y]) > 0; y--){
   char *strN = str[y];
   str[y] = str[y-1];
   str[y-1] = strN;
  }
 }
}//сортировка вставками

int cmp (const void *a, const void *b){
 char *ta = *(char**)a;
 char *tb = *(char**)b;
 return strcmp(ta,tb);
}//компаратор для быстрой сортировки

void mergesort(char **str, int n, int m){
 if (n < m){
  int q = (m+n)/2;
  mergesort(str, n, q);
  mergesort(str, q+1, m); 
  merge(str, n, q, m);
 }
}

void merge(char **str, int n, int q, int m){
 int i, j, k;
 int n1 = q-n+1;
 int n2 = m-q;

 char *Left[n1], *Right[n2]; 
 for (i = 0; i < n1; i++){
  Left[i] = str[n+i];
 }
 for (j = 0; j < n2; j++){
  Right[j] = str[q+1+j];
 }

 i = 0; 
 j = 0;
 k = n;
 while (i < n1 && j < n2){
  if (strcmp(Left[i], Right[j]) <= 0){
   str[k] = Left[i];
   i++;
  }
  else{
   str[k] = Right[j];
   j++;
  }
  k++;
 }

 while (i < n1){
  str[k] = Left[i];
  i++;
  k++;
 }

 while (j < n2){
  str[k] = Right[j];
  j++;
  k++;
 }
}

