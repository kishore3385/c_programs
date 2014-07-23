/*Given a text string and a pattern string, this code finds all the indices in the text string where the pattern or anagram of pattern occur
for example
Input text string[] = "ABCDGABCDA"
Input pattern string[] = "ABCD"
Output: anagram found at index 0
anagram found at index 5
anagram found at index 6
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

//#define DEBUG

#define ALPHALEN 	(26)

int getweight(char* p,int* alphap , int len)
{
	int i,weight =0;
	int index;

	
	for(i = 0; i < len ; i++)
	{
	

		index =  ((int) (*p)-65);
		if(index < ALPHALEN)
		{
			weight += alphap[index];
		}
		else
		{
			printf("wrong index\n");
		}
	#ifdef DEBUG
	printf("character is %c and index is %d and weight is %d\n",*p,((int)(*p) -65),alphap[index]);
	#endif
			
		p++;
	}
	return weight;
}


void findAnagram(char* tp,char* pp,int* alphap)
{
	int tlen = strlen(tp);
	int plen = strlen(pp);
	int index = 0;
	int i;
	
	int pweight = getweight(pp,alphap,plen);
	int tweight = 0;
	#ifdef DEBUG
	printf("weight of pattern is %d\n",pweight);
	#endif
	
	
	for(i = 0 ; i < tlen-plen+1 ;i++)
	{
		tweight = getweight(tp,alphap,plen);
		
		if(tweight == pweight)
		{
			printf("anagram found at index %d\n",index);
		}
		index++;
		tp++;
	}
	
}

int main()
{
	char text[20];
	char patt[20];
	
	int alphaArray[ALPHALEN];
	
	int i = 0;
	
	printf("ENter the text\n");
	scanf("%s",&text[0]);
	
	printf("Enter pattern\n");
	scanf("%s",&patt[0]);
	
	printf("enterd text is %s and pattern is %s\n",text,patt);
	
	for(i = 0 ; i <	ALPHALEN ; i++)
	{
		alphaArray[i] = pow(2,i);
		//printf("alphaArray is %d\n",alphaArray[i]);
	}	
	findAnagram(&text[0],&patt[0],&alphaArray[0]);
	
	return;
}