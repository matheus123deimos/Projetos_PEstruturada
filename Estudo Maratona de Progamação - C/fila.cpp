#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int caixas,clientes,i,j,k,menor;
std::vector<int> caixa;
std::vector<int> cliente0;
std::vector<int> cliente1;
std::vector<int> VI0;
std::vector<int> aux1;
std::vector<int> aux2;
std::vector<int>::iterator it;
int contador = 0;
int main()
{	

	while (true) {
		
		std::string cai,cli;
		
    	if (!std::cin) break;
    	fflush(stdin);
   		std::cin >> caixas >> clientes;
   		getline(std::cin,cai);
   		getline(std::cin,cli);
   		
   		for(i = 0,j=0;;i=i+2,j++)
   		{
   			caixa.push_back(cai[i] - '0');
   			if(i+1==caixas) break;
		}
		for(i = 0,j=0;;i=i+2,j++)
   		{
   			cliente0.push_back(cli[i] - '0');
   			if(i+1==clientes) break;
		}
		std::sort(caixa.begin(),caixa.end());
		
		for(i=0;i<caixas || i<clientes;i++){
			
			cliente1.push_back(cliente0[i]*caixa[i]);
			cliente0.erase(cliente0.begin()+i);
		}
		
		do{
			std::vector<int> aux1(cliente1);
			std::sort(aux1.begin(),aux1.end());
			menor = aux1[0];
			contador+=menor;
			for(i=0;i<cliente1.size();i++)
			{   
				int x = cliente1[i];
				if(!(x-menor)) VI0.push_back(i);
				cliente1.erase(cliente1.begin()+i);
				cliente1.insert(cliente1.begin()+i,x-menor);
			}
			
			if(VI0[0] == 0 && VI0.size() == 1)
			{
				cliente1.erase(cliente1.begin());
				cliente1.insert(cliente1.begin()+0,cliente0[0]);
				cliente0.erase(cliente0.begin());
			}
			
			else if(VI0[0] == 0 && VI0.size() > 1){
				
					cliente1.erase(cliente1.begin());
					cliente1.insert(cliente1.begin()+0,cliente0[0]);
					cliente0.erase(cliente0.begin());
					
					for(i=0;i<VI0.size();i++) aux2.push_back(cliente0[i]);
					std::sort(aux2.begin(),aux2.end());
					for(i=1;i<aux2.size();i++)
					{
						cliente1.erase(VI0.begin() + i);
						cliente1.insert(VI0.begin()+i,aux2[aux2.size()-1]);
						cliente0.erase(VI0.begin() + i);
					}
			}	
			
			else if(VI0.size() > 1){
					
					for(i=0;i<VI0.size();i++) aux2.push_back(cliente0[i]);
					std::sort(aux2.begin(),aux2.end());
					for(i=1;i<aux2.size();i++)
					{
						cliente1.erase(VI0.begin() + i);
						cliente1.insert(VI0.begin()+i,aux2[aux2.size()-1]);
						cliente0.erase(VI0.begin() + i);
					}
			}	
			k = 0; 
			for(i=0;i<VI0.size();i++)
			{
				if(VI0[i] == 0) k++;
			}
		}while(k || cliente0.size());
   
	}
	
}
