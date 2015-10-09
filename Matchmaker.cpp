#include <iostream>
#include <vector>

bool mejorMatch(int m, int indiceHom, std::vector<std::vector<int>> hombres, std::vector<std::vector<int>> mujeres,std::vector<int> calificaH, int hombreP)
{
    int contadorH = 0;
    for(int i=0; i<mujeres[m].size(); i++)
    {
        if(mujeres[m][i] == hombreP)
            contadorH = i;
    }
    for(int i = 0; i < contadorH; i++)
    {
        if(mujeres[m][i] == indiceHom)
            return true;
    }
    return false;
}

int getMujer(int m,std::vector<int> calificaM, std::vector<std::vector<int>> hombres)
{
    for(int i=0; i<hombres.size(); i++)
    {
        if(calificaM[i] == m)
            return i;
    }
    return -1;
}

int mujeresSinEvaluar(std::vector<std::vector<int>> hombres, std::vector<std::vector<bool>> prospectoH,int &prospectoM,int c)
{
    for(int i = 0; i < prospectoH[c].size(); i++)
    {
        if(prospectoH[c][i] == false)
        {
            prospectoM = i;
            return hombres[c][i];
        }
    }
    return -1;
}

bool getHombresDisp(std::vector<bool> hombresDisp, int & m)
{
    int j = 0;
    for(auto i : hombresDisp)
    {
        if(i == true)
        {
            m = j;
            return true;
        }
        j++;
    }
    return false;
}

int getHombreP(int m, std::vector<int> calificaH, std::vector<int> calificaM, std::vector<std::vector<int>> hombres)
{
    for(int i=0; i<hombres.size(); i++)
    {
        if(calificaM[i] == m)
            return calificaH[i];
    }
    return -1;
}



int main()
{
    std::vector<int> calificaH;
    std::vector<int> calificaM;
    std::vector<std::vector<int>> hombres = {{3,0,1,2},{1,3,0,2},{2,0,1,3},{0,1,2,3}};
    std::vector<std::vector<int>> mujeres = {{0,3,1,2},{3,2,1,0},{1,2,3,0},{3,1,0,2}};
    std::vector<bool> mujeresDisp(hombres.size(), true);
    std::vector<bool> hombresDisp(hombres.size(), true);
    std::vector<std::vector<bool>> prospectoH(hombres.size(), std::vector<bool>(hombres.size(), false));
    int mRef = 0;




    while(getHombresDisp(hombresDisp, mRef))
    {
        int m = mRef;
        int prospectoM = 0;
        int indiceMuj = mujeresSinEvaluar(hombres, prospectoH, prospectoM, m);
        prospectoH[m][prospectoM] = true;
        if(mujeresDisp[indiceMuj])
        {
            calificaH.push_back(m);
            calificaM.push_back(indiceMuj);
            mujeresDisp[indiceMuj] = false;
            hombresDisp[m] = false;
        }
        else
        {
            int hombreP = getHombreP(indiceMuj, calificaH, calificaM, hombres);
            if(mejorMatch(indiceMuj, m, hombres, mujeres, calificaH, hombreP))
            {
                int contadorM = getMujer(indiceMuj, calificaM, hombres);
                calificaH[contadorM] = m;
                mujeresDisp[indiceMuj] = false;
                hombresDisp[m] = false;
                hombresDisp[hombreP] = true;
            }
        }
    }
    for(int i=0; i<hombres.size(); i++)
    {
        std::cout << "La Srta. no. " << calificaM[i]+1 << " con el caballero no. " << calificaH[i]+1 << std::endl;
    }
    return 0;
}
