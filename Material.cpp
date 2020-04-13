#include "Material.h"

Material::Material(double El)
{
    E=El;
}
double Material::GetE()
{
    return E;
}
Material::~Material()
{
    //dtor
}
