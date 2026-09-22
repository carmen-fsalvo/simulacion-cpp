// Función para realizar derivadas numéricas con vectores. Requiere <vector>.
std::vector<double> derivNum(std::vector<double> f, double h)
{
    size_t length = f.size();
    std::vector<double> df(length,0);
    for (size_t i = 0; i < length; i++)
    {
        if (i == 0)
        {
            df.at(i) = (f.at(i+1) - f.at(i))/h;
        }
        else if (i == length - 1)
        {
            df.at(i) = (f.at(i) - f.at(i-1))/h;
        }
        else
        {
            df.at(i) = (f.at(i+1) - f.at(i-1))/(2*h);
        }
    }
    return df;
}