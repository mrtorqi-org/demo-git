//program 1 Create a menu driven program to perform operations (Create, Insert, Delete, Search) on Array.
#include<stdio.h>
#include<stdlib.h>
int choice,j,i=0,a[50],b[10],s;
void insert();
void delete();
void sort();
void search();
void display();
int menu();
int main()
{
	printf("\nEnter the size of array :");
	scanf("%d",&s);
	printf("\nEnter the elements of array :\n");
	for(i=0;i<s;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n---Array Operations---");
	printf("\n1.Insert");
	printf("\n2.Delete");
	printf("\n3.Sort");
	printf("\n4.Search");
	printf("\n5.Display");
	printf("\n6.Exit\n");
	while(1)
	{
		printf("\nEnter your choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert();
			break;
			case 2:delete();
			break;
			case 3:sort();
			break;
			case 4:search();
			break;
			case 5:display();
			break;
			case 6:exit(1);
		}
	}
	return 0;
}

void search()
{
	int ele,loc,flag=0;
	printf("\nEnter the element to be searched :");
	scanf("%d",&ele);
	for(i=0;i<s;i++)
	{
		if(ele==a[i])
		{
			printf("Element found at :");
			printf("%d",i+1);
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("Element not found\n");
	}
}

void sort()
{
	printf("\nCurrent array: ");
	for(i=0;i<s;i++)
		printf("\t%d",a[i]);
	for(i=0;i<s;i++)
	{
		for(j=i+1;j<s;j++)
		{
			if(a[i]>a[j])
			{
				a[i]=a[i]+a[j];
				a[j]=a[i]-a[j];
				a[i]=a[i]-a[j];
			}
		}
	}
	printf("\nsorted array: ");
	for(i=0;i<s;i++)
		printf("\t%d",a[i]);
}

void insert()
{
    int loc, ele;
    printf("\nEnter the location: ");
    scanf("%d", &loc);
    printf("Enter the element to be inserted: ");
    scanf("%d", &ele);

    if(loc < 1 || loc > s + 1) {
        printf("Invalid location!\n");
        return;
    }

    for(i = s; i >= loc; i--)
        a[i] = a[i - 1];

    a[loc - 1] = ele;
    s++;

    printf("Element inserted\nNew array after insertion:");
    for(i = 0; i < s; i++)
        printf("\t%d", a[i]);
}

void delete()
{
	int loc;
	printf("Enter the location: ");
	scanf("%d",&loc);
	if(loc<1 || loc>s)
			printf("Invalid location, Please enter a valid position\n");
	else
	{
		for(i=loc-1;i<s-1;i++)
			a[i]=a[i+1];
	}
	printf("Element deleted");
	printf("\nNew array after deletion: ");
	s--;
	for(i=0;i<s;i++)
		printf("\t%d",a[i]);
}

void display()
{
	int i;
	if(s==0)
	{
		printf("\nNo elements to display!");
		return;
	}
	printf("\nArray elements are: ");
	for(i=0;i<s;i++)
		printf("\t%d",a[i]);
}
