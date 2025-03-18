#include <stdio.h>
#include <stdlib.h>

void print_integer_array(int* array)
{
  int inloop=1;
  if(array[0]!=-1)
  printf("%d", array[0]);
  for(inloop=1; ;inloop++)
  {
   if(array[inloop]!=-1)
    printf(", %d", array[inloop]); 
   else
    break;
  }
  printf("\n");
}


void enqueue(int* queue, int value)
{

    int counter,loop,inside_index=0;
    int *new_qu;


    for(counter=0; ;counter++)
    {
        if(queue[counter]!=-1)
            continue;
        else
        {
            counter++;
            break;
        }
    }

    new_qu=(int*)malloc((counter++)*sizeof(int));
    counter++;

    for(loop=0;loop<counter;loop++)
    {
        if(queue[inside_index]!=-1)
        {
            new_qu[loop]=queue[inside_index++];
        }
        else
        {
            new_qu[loop++]=value;
            new_qu[loop]=-1;
        }
    }
    queue=realloc(queue,counter);
    for(loop=0;loop<counter;loop++)
    {
        queue[loop]=new_qu[loop];
    }
    free(new_qu);

 
}


int dequeue(int* queue)
{
    int loop, counter, deque_val,new_index=0;
    int *new_que;
    for(counter=0;;counter++)
    {
        if(queue[counter]!=-1)
        continue;
        else
        {
            counter++;
            break;
        }
    }
    counter--;

    if(queue[0]!=-1)
    deque_val=queue[0];

    new_que=(int*)malloc(counter*sizeof(int));

    for(loop=1;;loop++)
    {
        if(queue[loop]!=-1)
        {
            new_que[new_index++]=queue[loop];
        }
        else
        {
            new_que[new_index++]= queue[loop];
            break;
        }
    }

    queue=realloc(queue,counter);
    for(loop=0;loop<counter;loop++)
    {
        queue[loop]=new_que[loop];
    }
    free(new_que);



    return deque_val;
}


int front(int* queue)
{
    return queue[0];
}


int* merge(int* queue1, int* queue2)
{
    int * merge_que;
    int index1=0, index2=0, length1, length2, size, infor=0;

    for(length1=0;;length1++)
    {
        if(queue1[length1]!=-1)
            continue;
        else
        {
            length1++;
            break;
        }
    }




    for(length2=0;;length2++)
    {
        if(queue2[length2]!=-1)
            continue;
        else
        {
            length2++;
            break;
        }
    }

    size=length1+length2-1;
    merge_que=(int*)malloc(size*sizeof(int));

    while(queue1[index1]!=-1 && queue2[index2]!=-1 && infor<(size-1))
    {
        if(queue1[index1]<queue2[index2])  
            merge_que[infor++]=queue1[index1++];

        else if(queue1[index1]>queue2[index2])
            merge_que[infor++]=queue2[index2++];
        else
        {

            merge_que[infor++]= queue1[index1++];
            merge_que[infor++]=queue2[index2++];
        }
    }

    if(queue2[index2]==-1 && queue1[index1]!=-1)
    {
        while(queue1[index1]!=-1)
        {
            merge_que[infor++]=queue1[index1++];
        }
    }

    else if(queue1[index1]==-1 && queue2[index2]!=-1)
    {
        while(queue2[index2]!=-1)
        {
            merge_que[infor++]= queue2[index2++];
        }
    }
    merge_que[infor]=-1;

    return merge_que;

}



