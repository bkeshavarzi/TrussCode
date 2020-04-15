#ifndef MATERIAL_H
#define MATERIAL_H


class Material
{
    public:
        Material();
        Material(double);
        double GetE();
        virtual ~Material();

    protected:

    private:
        double E;
};

#endif // MATERIAL_H
