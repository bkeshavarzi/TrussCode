#include "Material.h"

Material::Material()
{
    E=2e9;
}
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
