matrix<double> cmatrixLU(matrix<double> A, matrix<double>b)
{
    valarray<double> B;
    B = b(0);
    valarray<double> sol;
    A.solve(B, sol);
    matrix<double> solutionV(b.rowno(), 1);
    solutionV(0) = B;
    return solutionV;
}