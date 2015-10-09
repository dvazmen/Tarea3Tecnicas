#include <iostream>
#include <vector>


int main ()
{
  std::vector<int> gasolineras;
  std::vector<int> cargas;

  gasolineras.push_back(250);
  gasolineras.push_back(175);
  gasolineras.push_back(300);
  gasolineras.push_back(125);


  int rangoIni = 400;
  int rangoRes = rangoIni;
  int kilometro = 0;

  for (int i = 0; i<gasolineras.size()-1; i++)
  {
    kilometro += gasolineras[i]; //Se suman las distancias para saber en que kilometro está
    if (rangoRes - (gasolineras[i+1] + gasolineras[i]) <=0 )
    {
      cargas.push_back(kilometro);
      rangoRes = rangoIni;
    }
    else
      rangoRes -= gasolineras[i];
  }



  if (cargas.size()!=0)
  {
    for (int i=0; i<cargas.size(); i++)
    {
      std::cout << "Se hizo una parada en la gasolinera del kilómetro " << cargas[i] << std::endl;
    }
  }
  else
    std::cout << "No se hicieron paradas" << std::endl;

  return 0;

};
