using namespace std;

void chasing(int **A[], int a, int *B[], int b, int C[], int c)
{
    fstream *archivo = new fstream("prueba.txt", ios_base::in);
    string linea;
    if (!archivo->is_open())
    {
        cout << "Archivo fallo en leer" << endl;
    }
    else
    {
        int i = 0;
        while (getline(*archivo, linea))
        {
            i++;
            stringstream stream(linea);
            string caracter;
            bool continuar = true;
            while (getline(stream, caracter, ' ') && continuar)
            {
                if (caracter[0] != 0)
                {
                    bool correcto = false;
                    if (caracter == "A")
                    {
                        string m;
                        while (getline(stream, m, ' ') && !correcto)
                        {
                            if (m[0] != 0)
                            {
                                char *pivot;
                                strtol(m.c_str(), &pivot, 10);
                                if (*pivot == 0)
                                {
                                    if (stoi(m) < a && stoi(m) >= 0)
                                    {
                                        string second;
                                        while (getline(stream, second, ' ') && !correcto)
                                        {
                                            if (second[0] != 0)
                                            {
                                                if (second == "B")
                                                {
                                                    string n;
                                                    while (getline(stream, n, ' ') && !correcto)
                                                    {
                                                        if (n[0] != 0)
                                                        {
                                                            char *pivot;
                                                            strtol(n.c_str(), &pivot, 10);
                                                            if (*pivot == 0)
                                                            {
                                                                if (stoi(n) < b && stoi(n) >= 0)
                                                                {
                                                                    string aditional;
                                                                    bool sigue = false;
                                                                    while (getline(stream, aditional, ' ') && aditional != " ")
                                                                    {
                                                                        sigue = true;
                                                                    }
                                                                    if (!sigue)
                                                                    {
                                                                        A[stoi(m)] = &B[stoi(n)];
                                                                        cout << "1" << endl;
                                                                        correcto = true;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (caracter == "B")
                    {
                        string m;
                        while (getline(stream, m, ' ') && !correcto)
                        {
                            if (m[0] != 0)
                            {
                                char *pivot;
                                strtol(m.c_str(), &pivot, 10);
                                if (*pivot == 0)
                                {
                                    if (stoi(m) < b && stoi(m) >= 0)
                                    {
                                        string second;
                                        while (getline(stream, second, ' ') && !correcto)
                                        {
                                            if (second[0] != 0)
                                            {
                                                if (second == "C")
                                                {
                                                    string n;
                                                    while (getline(stream, n, ' ') && !correcto)
                                                    {
                                                        if (n[0] != 0)
                                                        {
                                                            char *pivot;
                                                            strtol(n.c_str(), &pivot, 10);
                                                            if (*pivot == 0)
                                                            {
                                                                if (stoi(n) < c && stoi(n) >= 0)
                                                                {
                                                                    string aditional;
                                                                    bool sigue = false;
                                                                    while (getline(stream, aditional, ' ') && aditional != " ")
                                                                    {
                                                                        sigue = true;
                                                                    }
                                                                    if (!sigue)
                                                                    {
                                                                        B[stoi(m)] = &C[stoi(n)];
                                                                        cout << "1" << endl;
                                                                        correcto = true;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (!correcto)
                    {
                        cout << "0" << endl;
                        continuar = false;
                    }
                }
            }
        }
    }
}