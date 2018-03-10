#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void InsertSort(int *arr,int len)
{
	int i;
	int j;
	int tmp;

	for(i=1;i<len;i++)
	{
		tmp=arr[i];
		for(j=i-1;j>=0;j--)
		{
			if(arr[j]>tmp)
			{
				arr[j+1]=arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j+1]=tmp;
	}
}

int SearchSecond(int *arr,int len)
{
	int i;
	int tmp;
	int max;
	int second;

	max=arr[0];

	for(i=0;i<len;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
			tmp=arr[0];
			arr[0]=arr[i];
			arr[i]=tmp;
		}
	}

	if(len>1)
	{
		second=arr[1];
		for(i=1;i<len;i++)
		{
			if(arr[i]>second)
			{
				second=arr[i];
			}
		}
	}
	else
	{
		second=arr[0];
	}

	return second;
}

void Fork(int *arr,int len)
{
	int i;

	if(fork()==0)
	{
		printf("%d\n",SearchSecond(arr,len));
	}

	else
	{
		InsertSort(arr,len);
		for(i=0;i<len;i++)
		{
			printf("%d",arr[i]);
		}
		printf("\n");
	}
}

int main()
{
	int arr[]={9,4,5,2,4,1,3,7,8,6};
	int len=sizeof(arr)/sizeof(arr[0]);

	Fork(arr,len);
	return 0;
}
