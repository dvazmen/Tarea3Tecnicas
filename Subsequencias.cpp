#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>

template <class T>
std::vector<std::vector<int>> generaMatriz(std::vector<T> Set1, std::vector<T> Set2)
{
   std::vector<std::vector<int>> miMatriz(Set1.size()+1, std::vector<int>(Set2.size()+1));
   for(int i=1; i<=Set1.size(); i++)
   {
       for(int j=1; j<=Set2.size(); j++)
       {
           if(Set1[i-1] == Set2[j-1])
               miMatriz[i][j] = 1 + miMatriz[i-1][j-1];
           else
               miMatriz[i][j] = std::max(miMatriz[i-1][j], miMatriz[i][j-1]);
       }
   }
   return miMatriz;
}

template <class T>
void getSeq(std::vector<std::vector<int>> miMatriz, std::vector<T> Set1, std::vector<T> Set2)
{
   size_t fila = Set1.size();
   size_t columna = Set2.size();
   std::stack<T> miStack;
   while(fila != 0 && columna != 0)
   {
       if(miMatriz[fila-1][columna] == miMatriz[fila][columna-1])
       {
           miStack.push(Set1[fila-1]);
           columna--;
           fila--;
       }
       else
       {
           if(miMatriz[fila-1][columna] > miMatriz[fila][columna-1])
               fila--;
           else
               columna--;
       }
   }
   while(!miStack.empty())
   {
       std::cout << miStack.top() << " " << std::flush;
       miStack.pop();
   }
   std::cout << std::endl;
}

void imprimeMatriz(std::vector<std::vector<int>> miMatriz)
{
   for(int i=0; i<miMatriz.size(); i++)
   {
       for(int j=0; j<miMatriz[0].size(); j++)
       {
           std::cout << miMatriz[i][j] << " ";
       }
       std::cout << std::endl;
   }
}

int main()
{
   std::vector<char> vec1 = {'b','f','s','f','s','b','b','b','f','t','t','f','b'};
   std::vector<char> vec2 = {'b','b','f','s','f','t','s','b','b','f','f','t','f','b','s'};

   std::cout << "El primer string es: " << std::endl;
   for(int i =0; i < vec1.size(); i++)
   {
     std::cout << vec1[i] << " ";
   }
   std::cout << std::endl;

   std::cout << "El segundo string es: " << std::endl;
   for(int i =0; i < vec1.size(); i++)
   {
     std::cout << vec2[i] << " ";
   }
   std::cout << std::endl;


   std::vector<std::vector<int>> matriz = generaMatriz(vec1, vec2);
   std::cout << "La subsecuencia de longitud máxima es: ";
   getSeq(matriz, vec1, vec2);

   return 0;
}
