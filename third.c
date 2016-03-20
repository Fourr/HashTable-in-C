#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include"third.h"
/*struct node
{
        int num;
        struct node *next;
};
//int q=0;
typedef struct node node;
*/node **hashm =NULL;
node *createNode(int n)
{
 
        node *bust  = (node *) malloc(sizeof(node) );

        bust->num = n;

        bust->next = NULL;
        return bust;
}
void createTable()
{
hashm = (node**) calloc(1,sizeof(node*)* 10000);
return;
}

void insert(node* a)
{
int h;
int j;
h = a->num;
h = abs(h);
j =h%10000;
node *temp = NULL;
//printf("%d\n", a->num);
if(hashm[j] == NULL)
	{
	hashm[j] = a;
	//printf("%d\n",hashm[h]->num);
//	printf("Inserted %d at %d\n" , hashm[j]->num,j);
	printf("inserted\n");
	return;
	}
else 
	{

	
	for(temp=hashm[j]; temp!=NULL; temp=temp->next)
	{	//printf("got here\n");
		if(h==temp->num)
		{
	//	printf("duplicate of %d\n", h);
		printf("duplicate\n");
		return;
		}	
	}   
//	  printf("%d hashed at %d\n",a->num,j);
		a->next=hashm[j];
		hashm[j] = a;
//			printf("%d and %d\n", a->num, a->next->num);
//		

//	printf("Inserteed %d at %d\n", hashm[j]->num, j);
	printf("inserted\n");
	return;
	}	



return;
}

void search(int b)
{
int h;
h = abs(h);
node *temp = NULL;
h =abs(b)%10000;
//int q =0;
if(hashm[h] ==NULL)
{// printf("%d absent\n",b);
printf("absent\n");
return;
}
for(temp=hashm[h]; temp !=NULL; temp = temp->next)
{	//q++;
	if(b==temp->num)
	{
//	printf("%d is present at %d\n",temp->num,h);
	printf("present\n");
	 return;
	
	}
}
	//printf("%d\n",q);
//	printf("%d is absentt\n",b);
	printf("absent\n");
	return;
	
}







              
int main(int argc, char** argv)

{

        FILE *fp;

        char data[1024];

        fp = fopen(argv[1], "r");

        int i;

        int n;

        node *ptr;

	
createTable();
        if (fp == NULL)

        {

                printf("error\n");

                return -1;

        } else {
                do{

                        i = fscanf(fp, "%s",data );
                        if (i == -1){
                                break;
                        }

                        if(strcmp(data, "i") !=0 && strcmp(data, "s")!=0){

			//	printf("%s", data);
                                printf("error\n");
				fscanf(fp, "%s", data);
                                	      }
                        if (strcmp(data, "i") == 0)
                        {

                                fscanf(fp,"%s", data);
                                n = atoi(data);
                                if(isdigit(n) != -1){
                                        ptr = createNode(n);
                                        insert(ptr);
					//printf("Inserted\n");
                                }
                                else{
                                        printf("error\n");
                                        return 0;
                                }

                        }

                        if (strcmp(data,"s") ==0)
                        {
                                fscanf(fp,"%s",data);
                                n = atoi(data);
                                if(isdigit(n)!= -1){

                                        search(n);
				//printf("present\n");
                                }
                                else{
                                      //  printf("Absent\n");
                                        return 0;
                                }
                        }


                }while(i!=EOF);
        }

       // print();
        fclose(fp);
       // free(root);
        return 0;
}


