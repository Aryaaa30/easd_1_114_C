//1. Karena Algoritma sangat dibutuhkan untuk menyelesaikan suatu permasalahan, dengan diterapkannya suatu algoritma
//   pada suatu masalah maka akan memudahkannya  untuk menyelesaikan masalah tersebut, yaitu dengan cara mencari solusi 
//   yang terbaik dan yang paling efisien dari masalah tersebut.


//2. 

//3. Faktor-faktor yang mempengaruhi efesiensi suatu program algoritma antara lain : ruang penyimpanan (memory), 
//   waktu penegerjaan (cepat), dan proses pemrograman (baik dan benar)

//4. Menurut saya, Quick sort, Karena proses pemrogramannya lebih 

//5. Quadratic :bubble sort, insertion sort, merge sort
//   loglincar : selection sort, shell sort, quick sort

//6. selection sort :


#include <iostream>
using namespace std;

int arya[34];
int cmp_count = 0;
int mov_count = 0;
int n;

void input() {
    while (true)
    {
        cout << "Masukkan Panjang Element Array : ";
        cin >> n;

        if (n <= 34)
            break;
        else
            cout << "\nMaksimum Panjang Array Adalah 34" << endl;
    }
    cout << "\n===================" << endl;
    cout << "\nEnter Array Element" << endl;
    cout << "\n===================" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "<" << (i + 1) << ">";
        cin >> arya[i];
    }
}

void swap(int x, int y)
{
    int temp;

    temp = arya[x];
    arya[x] = arya[y];
    arya[y] = temp;
}

void q_short(int low, int high)
{
    int pivot, i, AA;
    if (low > high)
        return;

    pivot = arya[low];

    i = low + 1;
    AA = high;

    while (i <= AA)
    {
        while ((arya[i] <= pivot) && (i <= high))
        {
            i++;
            cmp_count++;
        }
        cmp_count++;

        while ((arya[AA] > pivot) && (AA >= low))
        {
            AA--;
            cmp_count++;
        }
        cmp_count++;

        if (i < AA)
        {
            swap(low, AA);
            mov_count++;
        }
    }
    if (low < AA)
    {
        swap(low, AA);
        mov_count++;
    }
    q_short(low, AA - 1);
    q_short(AA + 1, high);
}

void display() {
    cout << "\n============" << endl;
    cout << "\nSotred Array" << endl;
    cout << "\n============" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arya[i] << " ";
    }

    cout << "\n\nNumber of comparasions : " << cmp_count << endl;
    cout << "Number of data movement : " << mov_count << endl;
}

int main()
{
    input();
    q_short(0, n - 1);
    display();
    system("pause");

    return 0;
}