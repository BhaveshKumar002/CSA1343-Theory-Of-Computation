#include <stdio.h>
#include <string.h>
int main()
{
	char s[10];
	int i,k,c=0;
	printf("Use Only a's or b's\n");
	printf("Enter a string : ");
	scanf("%s",s);
	k=strlen(s);
	for(i=0;i<k;i++)
    {
    	if(s[i] == 'a' || s[i] == 'b')
    		c = c+1;
	}
	if (c == k)
	{
		if(s[0]=='a'&& s[k-1]=='a')
			printf("string accepted");
		else
			printf("not accepted");
	}
	else 
		printf("Invalid");
		
	return 0;
}
