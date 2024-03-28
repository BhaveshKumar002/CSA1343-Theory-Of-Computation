#include <stdio.h>
#include <string.h>
int main()
{
	char s[10];
	int i,k,c=0;
	printf("Use Only 0's or 1's\n");
	printf("Enter a string : ");
	scanf("%s",s);
	k=strlen(s);
	for(i=0;i<k;i++)
    {
    	if(s[i] == '0' || s[i] == '1')
    		c = c+1;
	}
	if (c == k)
	{
		if(s[0]=='0'&& s[k-1]=='1')
			printf("string accepted");
		else
			printf("not accepted");
	}
	else 
		printf("Invalid");
		
	return 0;
}
