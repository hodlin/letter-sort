#include <QCoreApplication>
#include <main.h>

using namespace std;

const char in_f_name[] = "/home/dmytro/QtProjects/letter_sort/input.txt";
const char out_f_name[] = "/home/dmytro/QtProjects/letter_sort/output.txt";

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    size_t set_size;
    set_size = input_size(in_f_name);
    //cout << set_size;

    char *set = new char [set_size];
    for (unsigned int i=0; i<set_size; i++)
        set[i] = NULL;

    read_set(in_f_name, set);

    selection_sort(set, set_size);

    write_set(out_f_name, set, set_size);

    delete []set;

    return a.exec();
}

size_t input_size(const char *f_name)
{
    /**
     * Detectin size of input file
     *
     * @f_name const char name of input file
     *
     * @return count size_t Number of letters in input file
     */
    size_t count = 0;
    char S;

    ifstream f(f_name);
    while (!f.eof())
    {
        f.get(S);
        if (S != ' ')
            count++;
    }
    f.close();
    return count;
}

void read_set(const char *f_name, char* set)
{
    /**
     * Reading set of letters
     *
     * Filling up 'set' with the letters from input file
     *
     * @f_name  const char*  Name of input file
     * @set     char*        Initialised array of corresponding type
     *
     * @return void
     */
    char S;
    ifstream f(f_name);
    int i = 0;
    while (!f.eof())
    {
        f.get(S);
        if (S != ' ')
        {
            set[i] = S;
            i++;
        }
    }
    f.close();
}

void selection_sort(char* set, size_t set_size)
{
    /**
     * Selection sort
     *
     * Implemets backward selection sort algorithm on set of letters
     *
     * @set       char*   Filled set of letters from input file
     * @set_size  size_t  Length of 'set' array
     *
     * @return void
     */
    char temp;

    for (unsigned int i = 0; i<set_size; i++)
    {
        for(unsigned int j = i+1; j<set_size; j++)
        {
            if (set[i]<set[j])
            {
                temp = set[i];
                set[i] = set[j];
                set[j] = temp;
            }
        }
    }
}

void write_set(const char *f_name, char* set, size_t set_size)
{
    /**
     * Writing array to file
     *
     * @f_name      const char* Name of output file
     * @set         char*       Array of sorted letters
     * @set_size    size_t      Length of array of letters
     *
     * @return void
     */
    ofstream f(f_name);
    for (unsigned int i = 0; i<set_size; i++)
    {
        f << set[i] << ' ';
    }
    f.close();
}
