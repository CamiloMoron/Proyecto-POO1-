#include "Producto.h"

class Categoria
{
    private:

        int codcategoria;
        string nomcategoria;
    public:

        Categoria (int codcategoria = 0, string nomcategoria = " ") : codcategoria (codcategoria), nomcategoria (nomcategoria)
        {

        }
        int getCodCat ()
        {
            return this-> codcategoria;
        }
        string getNomCat ()
        {
            return this->nomcategoria;
        }

};
