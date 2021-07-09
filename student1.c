#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
int N=0;
int size = 0; /// Size of the dynamic array.
int capacity = 0; /// Capacity of dynamic array.


/**String maker function that read string from user*/
char * getString(){ 
    char temp[50];
    scanf("%*c");
    fgets(temp, sizeof(temp), stdin);
    char* str= (char*) malloc(strlen(temp));
    for (int i=0;i<strlen(temp);i+=1)
        str[i]=temp[i];
    str[strlen(temp)-1]='\0';
    return str;}


typedef struct    //define student structure
{
    char *name;
    int id;
    int day;int month;int year;   //date of birth
    int student_score;
}student;

student read_st()
{
    student st;
     printf("student name:");
     st.name=getString();
     printf("student id:");  scanf("%d",&st.id);
     printf("student date of birth:\n");
     printf("day:"); scanf("%d",&st.day);
     printf("month:"); scanf("%d",&st.month);
     printf("year:"); scanf("%d",&st.year);
     printf("student last year score:");  scanf("%d",&st.student_score);
     return st;
}

typedef struct node_tmp
{   student st;
	struct node_tmp*next;
}node;

    node*head = NULL;
	node*tail = NULL;


node*newNode(student st)
{   node*nodeP;
	nodeP=(node*)malloc(sizeof(node));
	nodeP->st = st;
	nodeP->next = NULL;
	return nodeP;
}

void insert_end(student st)
{
	node*nodeP;
	nodeP = newNode(st);
	if(head == NULL)
	{head = nodeP;
     tail = nodeP;}
	else
	{tail->next= nodeP;
     tail= tail->next;}
     N++;
}

void insert_begin(student st)
{
	node*nodeP;
	nodeP = newNode(st);
	if(head == NULL)
	{head = nodeP;
     tail = nodeP;}
	else
	{nodeP->next=head;
     head=nodeP;}
     N++;
}


void insert_mid(student st,int location)
{int index=location-1;
	node*nodeP;
	nodeP = newNode(st);
	if(head == NULL)
	{head = nodeP;
     tail = nodeP;}
	else
	{if(index>N) {printf("error\n");return;}
	else if(index==0){insert_begin(st);return;}
    else if(index==N){insert_end(st);return;}
	else
    {node*ptr=head; node*pre; int count=0;
	 while(count<index)
     {pre=ptr;
     ptr=ptr->next;
     count++;}
     nodeP->next=ptr;
     pre->next=nodeP;
	}}N++;
}

void display(int location)
{int index=location-1;
    node*ptr=head;int n=0;
while(n<index)
{ptr=ptr->next;
n++;}
printf("%s\n",ptr->st.name);
}

void display_list(node*head)
{node*ptr=head;int n=0;
while(n<N)
{printf("%s\n",ptr->st.name);
    ptr=ptr->next;
n++;}
}


student *add (student *array);
student *insert (student *array, student new_student, int pos);
student *ArrayList (int array_size);

/**Change string to lowercase*/
char *lower (char *str){

  char* new_str ="";
  for (int i = 0; i < strlen (str); i += 1){
    printf("%c",tolower(str[i]));
    new_str = new_str+tolower (str[i]);
  }

  return new_str;
}


/**Read student data*/
student read(student* array)
{

     fflush(stdin);
     //getString();

     student st;

     printf("student name:");
     st.name=getString();

     printf("student id:");  scanf("%d",&st.id);

     while(sizeof(st.id) != 4) scanf("%d",&st.id);

     printf("student date of birth:\n");
     printf("day:"); scanf("%d",&st.day);
     while(sizeof(st.id) != 4) scanf("%d",&st.day);

     printf("month:"); scanf("%d",&st.month);
     while(sizeof(st.id) != 4) scanf("%d",&st.year);

     printf("year:"); scanf("%d",&st.year);
     while(sizeof(st.id) != 4) scanf("%d",&st.year);

     printf("student last year score:");  scanf("%d",&st.student_score);

     return st;
}




/** Print student data*/
void print_student(student* st){

    printf("Name    |  Id  | Day  | Month |  Year  |  Score\n");
    printf("__________________________________________________\n");


    for (int i=0;i<size;i+=1){
        printf("%7s |  %2d  |  %2d  |  %2d   |  %4d  |  %3d\n", st[i].name, st[i].id, st[i].day
               , st[i].month, st[i].year, st[i].student_score);
        printf("---------------------------------------------------\n");
    }
}
int main()
{

    printf("Welcome sir!\n");
    int n, l, pos=0;
    student *student_list;


	printf("For linked list press 1 for dynamic array press 2 \n");
    int option;
    scanf("%d",&option);

    while ((option!=1)&&(option!=2)){
        printf("Please enter 1 or 2 \n" );
        scanf("%d",&option);
    }

    printf("Please enter number of students: ");
    scanf("%d",&n);

    if (option==2){
          student_list = ArrayList (n);	/// Make dynamic array of initial size n
    }

    for(int i=0;i<n;i+=1)
    {
             printf("Enter data of student number %d \n",i+1);
                if (option==1){
                     insert_end(read_st());
                }else if(option==2)
                    /// Read the data
                    student_list[i]=read(student_list);



    }


    student_list=add(student_list);
    print_student(student_list);


if (option==1)
    {int option2=1;
    while (option2!=3){
    printf("press 1 to insert more students \n");
    printf("press 2 to display the students' list \n");
    printf("press 3 to exit \n");
        scanf("%d",&option2);
    while ((option2!=1)&&(option2!=2)&&(option2!=3)){
        printf("please enter 1,2 or 3 \n" );
        scanf("%d",&option2);}
     if(option2==1){
    printf("press 1 to insert a student at the beginning of the list \n");
    printf("press 2 to insert a student at the a certain location in the list \n");
    printf("press 3 to insert a student at the end of the list \n");
    int insert_option;
    scanf("%d",&insert_option);
    while ((insert_option!=1)&&(insert_option!=2)&&(insert_option!=3)&&(insert_option!=4)){
        printf("please enter 1,2,3 or 4 \n" );
        scanf("%d",&insert_option);}
     if (insert_option==1) insert_begin(read_st());
     if (insert_option==2) {
            printf("please enter location of the new student \n" );
            int location;
         scanf("%d",&location);
    while (location>N+1||location<1){
        printf("error..please enter a positive integer smaller than or equal %d \n",N+1);
        scanf("%d",&location);}
        insert_mid(read_st(),location);
        }

     if (insert_option==3) insert_end(read_st());}
     if(option2==2)display_list(head);
     if(option2==3) break;
    }}



    return 0;
}



/**
    Make a dynamic array of size array size
    array_size: the size of the ArrayList
    Return int pointer to the dynamic array in heap
*/

student *
ArrayList (int array_size){

  if(array_size==0) array_size=1;

  student *dymanic_array = (student *) malloc (array_size * sizeof (student));

  if(size==0){
      size = array_size;
      capacity = size;
  }

  return dymanic_array;
}


/**
    Insert extra element in array in specific position
    array: the array that we want to add extra
            element in it
    Return integer pointer to the new array in heap
*/
student *insert (student *array, student new_student, int pos){

    if (pos > size){
        printf("Please enter position smaller than %d\n", size);
        return add(array);
    }else if (pos == 0){
        printf("Please enter position greater  than zero\n");
        return add(array);
    }

    student *temp_vector = ArrayList (capacity);

    /// insert the new element at the pos
    int j=0, i=0;
    while (i<size){
        if(pos==j+1){
            temp_vector[j]=new_student;
            j+=1;
        }else{
            temp_vector[j]=array[i];
            j+=1;
            i+=1;
        }
    }

    ///Update the size of the array
    size = size + 1;

    return temp_vector;
}

/**
    Add extra element in array at any location (beginning, end or middle)
    array: the array that we want to add extra
            element in it
    Return student pointer to the new array in heap
*/

student *add (student *array){

    int pos=0, loc;
    student new_student;

    if (size == capacity){
        array = (student *) realloc (array, capacity * 2 * sizeof (*array));
        capacity = capacity * 2;
    }


    /// Choose location
    while(pos<=0 || pos>3){
        printf ("Would you like to add at\n1-Beginning\n2-End\n3-Middle\n");
        scanf ("%d", &pos);		// get the position
    }


    if(pos==3){
        printf("\nWhere would you like to insert the student in\n");
        scanf ("%d", &loc);		// get the position
    }

    printf ("\nEnter the student data\n");
    new_student=read(array);

    if (pos==1){
        int start=clock();
        student *begin=insert(array, new_student, 1);
        printf("Total time is: %f\n", (double)(clock()-start)/CLOCKS_PER_SEC);
        return begin;
    }
    else if (pos==2){
        int start=clock();
        array[size] = new_student;
        size+=1;
        printf("Total time is: %f\n", (double)(clock()-start)/CLOCKS_PER_SEC);
        return array;
    }else if(pos==3){
        double start=clock();
        student *middle=insert(array, new_student, loc);
        printf("Total time is: %f milli second\n", (double)(clock()-start)/CLOCKS_PER_SEC*10e3);
        return middle;
    }
    return array;
}
