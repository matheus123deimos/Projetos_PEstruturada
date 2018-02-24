#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iostream>

int main()
{	
	int j1,j2,i;
	char *p1,*p2;
	std::vector<int> v1;
	std::vector<int> v2;
	std::vector<char> result;
	
	for(;;){
		
		fflush(stdin);
		scanf("%d %d",&j1,&j2);
		fflush(stdin);
		char d1[j1],d2[j2];
		if(j1 == 0 && j2 == 0)
		{
			result.push_back('F');
			break;
		} 
		
		gets(d1);fflush(stdin);gets(d2);
		
		p1 = strtok(d1," ");
		
		while(p1 != NULL){
			
			v1.push_back(atoi(p1));
			p1 = strtok(NULL," ");
		}
		
		p2 = strtok(d2," ");
		while(p2 != NULL){
				v2.push_back(atoi(p2));
				p2 = strtok(NULL," ");
		}
			
		std::sort(v1.begin(),v1.end());
		std::sort(v2.begin(),v2.end());
		
		if(v1[0] == v2[1] || (v1[0] == v2[0] && v2[0] == v2[1])) result.push_back('N');
		else result.push_back('Y');
		
	}for(i = 0;result[i] != 'F';i++) printf("%c\n",result[i]);
}
