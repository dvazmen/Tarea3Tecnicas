#include <iostream>
#include <vector>
#include <math.h>


int main() {

    std::vector<std::string> parrafo;
    std::vector<int> largoPalabra;
    std::vector<std::string> linea;

    parrafo.push_back("Mexicanos");
    largoPalabra.push_back(9);
    parrafo.push_back("al");
    largoPalabra.push_back(2);
    parrafo.push_back("grito");
    largoPalabra.push_back(5);
    parrafo.push_back("de");
    largoPalabra.push_back(2);
    parrafo.push_back("guerra");
    largoPalabra.push_back(6);
    parrafo.push_back("el");
    largoPalabra.push_back(2);
    parrafo.push_back("acero");
    largoPalabra.push_back(5);
    parrafo.push_back("aprestad");
    largoPalabra.push_back(8);
    parrafo.push_back("y");
    largoPalabra.push_back(1);
    parrafo.push_back("el");
    largoPalabra.push_back(2);
    parrafo.push_back("bridón");
    largoPalabra.push_back(6);

    parrafo.push_back("Guerra");
    largoPalabra.push_back(6);
    parrafo.push_back("guerra");
    largoPalabra.push_back(6);
    parrafo.push_back("en");
    largoPalabra.push_back(2);
    parrafo.push_back("el");
    largoPalabra.push_back(2);
    parrafo.push_back("monte");
    largoPalabra.push_back(5);
    parrafo.push_back("en");
    largoPalabra.push_back(2);
    parrafo.push_back("el");
    largoPalabra.push_back(2);
    parrafo.push_back("valle");
    largoPalabra.push_back(5);
    parrafo.push_back("los");
    largoPalabra.push_back(3);
    parrafo.push_back("cañones");
    largoPalabra.push_back(7);
    parrafo.push_back("horrísonos");
    largoPalabra.push_back(10);
    parrafo.push_back("truenen");
    largoPalabra.push_back(7);


    float maxLength=20;
    float condicion=1;
    float length=0;
    float actualLength=0;
    float excess;
    float distAmpliar;
    float distReduce;
    int i=0;
    int j=0;
    bool lineaLista=true;


    for(j=0; j<parrafo.size(); j++){
        if(lineaLista){
            i=j;
            lineaLista = false;
            linea.clear();
            length=0;
        }

        length += largoPalabra[j];
        actualLength = length + ((j-i)*condicion);
        if(actualLength > maxLength){
            excess = actualLength-maxLength;
            distReduce = condicion -(excess/(j-i));
            distAmpliar = condicion + (maxLength-((length-largoPalabra[j])+(condicion*(j-i-1))))/(j-i-1);

            if(((fabs(distAmpliar-condicion)*(j-i-1))>(fabs(distReduce-condicion)*(j-i))) && distReduce > 0)
            {

                linea.push_back(parrafo[j]);
                for(auto c : linea)
                {
                    std::cout<<c<<" ";
                }
                std::cout<< "  --Espacio Reducido: "<< distReduce;
                std::cout<<std::endl;
                lineaLista=true;
            }
            else
            {
                for(auto c : linea)
                {
                    std::cout<<c<<" ";
                }
                std::cout<<"  --Espacio Ampliado:" << distAmpliar;
                std::cout<<std::endl;
                j--;
                lineaLista=true;
            }

        }
        linea.push_back(parrafo[j]);
    }

    for(auto c : linea)
    {
        std::cout<< c <<" ";
    }
    std::cout<< "\n";

    return 0;
}
